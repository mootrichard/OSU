/*
 * Author: Richard Moot
 * Title: smallsh
 * Description:
 *  A lightweight shell that will manage change directory (cd), manage a status (status),
 *  and exit (exit). Created for CS344.
 * Date: 2016-17-11
 */

#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFF_LIMIT 2048

// Initializing background process array of pid's
int bg_child_processes[100] = {0};
int num_bg_children = 0;

// Forward defining function signatures

// Functions for handling children processes and cleaning them up
void check_children();
void push_child_process(int child);
void kill_children();
void clean_up (const char devnull[], char *in_name, char *out_name, char** args);

// Functions for mananging loop and running commands
void run_loop();
int get_line(char* line);
char* allocate_filename(char **arg, unsigned int name_length);
void run_line(char *line, unsigned int length);
void shell_exit(char **args);

// Global shell status
int shell_status = 0;

/*!
 *  Main loop for running program
 */
int main() {
    signal(SIGINT, kill_children);
    signal(SIGCHLD, check_children);
    run_loop();
    return 0;
}

/*!
 *  void push_child_process(int child)
 *
 *  @params:
 *      @child - process ID of child to add to set of background processes
 *  @return:
 *      No return value, but does alter bg_child_processes & num_bgchildren
 */
void push_child_process(int child) {
    if(num_bg_children == 100){
        printf("Exceeded background process limit, terminating");
        kill_children();
        exit(6);
    }
    bg_child_processes[num_bg_children] = child;
    num_bg_children++;
}


/*!
 *  void kill_children()
 *  @param:
 *      None
 *  @return:
 *      None - cycles through background processes to terminate them
 */
void kill_children() {
    int child_status;
    for (int i = num_bg_children-1; i > 0; i--) {
        kill(bg_child_processes[i], SIGKILL);
        waitpid(bg_child_processes[i], &child_status, 0);
    }
}


/*!
 *  void check_children()
 *  @params:
 *      None
*/
void check_children() {
    int child_status;
    int pid = waitpid(0, &child_status, 0);
    bool was_bgd = false;

    for (int i = 0; i < num_bg_children; i++) {
        if (pid == bg_child_processes[i]) {
            was_bgd = true;
        }
    }

    if (was_bgd) {
        printf("\n%d\n%d\n", pid, WEXITSTATUS(child_status));
        fflush(stdout);
    }
}
/*!
 * int get_line(char* line)
 * @param:
 *      line - pointer to line buffer for writing the next line to
 * @return
 *      length of string if there is one, otherwise 0
 */
int get_line(char* line){
    printf(":");
    fflush(stdout);

    if(fgets(line, BUFF_LIMIT, stdin) != NULL){
        return strlen(line);
    }
    return 0;
}

/*!
 *  void run_loop()
 *  @params:
 *      None
 *  @return:
 *      None - just runs the loop for the program till it hits the end of the file
 */
void run_loop() {
    char line[BUFF_LIMIT] = {0};
    int line_len;
    while ((line_len = get_line(line)) > 0) {
        run_line(line, (unsigned int)line_len);
    }
}

/*!
 * void shell_exit(char **args)
 * @param:
 *      args - arguments that were previously allocated
 * @return:
 *      none, frees up malloc() args, exits shell
 */
void shell_exit(char **args){
    kill_children();
    free(args);
    exit(0);
};

/*!
 * void run_line(char *line, unsigned int length)
 * @param:
 *      line - pointer to next line of commands
 *      length - length of the next line of commands
 * @return:
 *      None - function for running all commands being sent in
 */
void run_line(char *line, unsigned int length) {
    // usage: command [arg1 arg2 ...] [< input_file] [> output_file] [&]

    // Setting aside space for arguments that we will pass to our line processor
    char **args = malloc(length * sizeof(char*));

    // Setting our delineator for our files and setting up devnull to be used later
    const char *arg_delin = " \n";
    const char devnull[] = "/dev/null";

    char *arg = NULL;
    char *in_name = NULL;
    char *out_name = NULL;
    bool is_background = false;

    unsigned int args_index = 1;

    char *command = strtok(line, arg_delin);

    // Looks like we do not have any arguments
    if (command == NULL) {
        clean_up(devnull, in_name, out_name, args);
        return;
    }

    // We have a command, setting it as first argument
    args[0] = command;

    if(args[0] == "#"){
        clean_up(devnull, in_name, out_name, args);
        return;
    }

    // Checking if this command is handled by this shell
    if (strcmp(command, "exit") == 0) {
        shell_exit(args);
    } 
    else if (strcmp(command, "cd") == 0) {
        char *dest = strtok(NULL, arg_delin);
        if (dest == NULL) {
            dest = getenv("HOME");
        }

        // Change directories
        if(chdir(dest) == -1) {
            perror("chdir");
            clean_up(devnull, in_name, out_name, args);
            return;
        }
        clean_up(devnull, in_name, out_name, args);
        return;
    }
        // Returning back the status number
    else if (strcmp(command, "status") == 0) {
        // Built in status command that prints status information.
        if (WIFEXITED(shell_status)) {
            printf("Exited: %d\n", WEXITSTATUS(shell_status));
            fflush(stdout);
        }
        
        // Print the signal it received.
        if (WIFSIGNALED(shell_status)) {
            printf("Stop signal: %d\n", WSTOPSIG(shell_status));
            fflush(stdout);
        }
        
        // Print the termination signal (if one exists).
        if (WTERMSIG(shell_status)) {
            printf("Termination signal: %d\n",
                   WTERMSIG(shell_status));
            fflush(stdout);
        }
        clean_up(devnull, in_name, out_name, args);
        return;
    }

    int input_file;
    int output_file;
    pid_t pid;

    // For each argument in the command.
    do {
        arg = strtok(NULL, arg_delin);

        // We have reached the end of the arguments array
        if (arg == NULL) {
            break;
        }
            // Handling in_name files redirection
        else if (strncmp(arg, "<", 1) == 0) {
            arg = strtok(NULL, arg_delin);
            if (arg == NULL) {
                printf("Invalid syntax. "
                               "No in_name file provided\n");
                clean_up(devnull, in_name, out_name, args);
                return;
            }
            in_name = allocate_filename(&arg, length);
            continue;
        }
            // Handling out_name file redirection
        else if (strncmp(arg, ">", 1) == 0) {
            arg = strtok(NULL, arg_delin);
            if (arg == NULL) {
                printf("Invalid syntax. "
                               "No out_name file provided\n");
                clean_up(devnull, in_name, out_name, args);
                return;
            }
            out_name = allocate_filename(&arg, length);
            continue;
        }
            // Handling background process command
        else if (strncmp(arg, "&", 1) == 0) {
            is_background = true;
            break;
        }

        // Adding argument to array of arguments
        args[args_index] = arg;
        args_index++;
    } while (arg != NULL);

    // Add the trailing null pointer for terminating arguments array
    args[args_index] = NULL;

    // If its a background process, we will simply send it to devnull
    if (is_background && in_name == NULL) {
        in_name = (char*)devnull;
    }
    if (is_background && out_name == NULL) {
        out_name = (char*)devnull;
    }

    // Here is where we fork a child process if we have a command not handled by our shell
    pid = fork();
    if (pid == 0) {
        // If the in_name file has been specified, set child's stdin
        // to in_name.
        if (in_name != NULL) {
            input_file = open(in_name, O_RDONLY);
            // Log reason for failure to open designated file
            if (input_file == -1) {
                perror("input_file");
                free(args);
                free(line);
                exit(1);

            } else {
                // Redirecting stdin to in_name file.
                dup2(input_file, STDIN_FILENO);
                close(input_file);
            }
        }
        if (out_name != NULL) {
            // Open the out_name file
            output_file = open(out_name, O_WRONLY | O_CREAT, 0744);

            // Logging out_name file open failure message
            if (output_file == -1) {
                perror("output_file");
                free(args);
                free(line);
                exit(1);
            }

            if (out_name != devnull) {
                if (chmod(out_name, S_IRUSR | S_IWUSR | S_IRGRP |
                                  S_IROTH) == -1) {
                    perror("chmod");
                }
            }

            // Redirecting out_name to stdout
            dup2(output_file, STDOUT_FILENO);
            close(output_file);
        }

        // Executing non-shell commands
        execvp(command, args);
        // Handling error if any occur to alert user
        perror("execvp");
        free(args);
        exit(1);
    } else {
        // Waiting for child process.
        if (!is_background) {
            waitpid(pid, &shell_status, 0);
        } else {
            // Add it to the list of background processes
            push_child_process(pid);
        }
    }
}

/*!
 * void clean_up (const char devnull[], char *in_name, char *out_name, char** args)
 * @param:
 *      devnull - place where we are placing out_name from background processes
 *      in_name - allocated string for in_name filename
 *      out_name - allocated string for out_name filename
 *      args - allocated array for storing command arugments
 * @return:
 *      None - simply cleans up areas and frees memory
 */
void clean_up (const char devnull[], char *in_name, char *out_name, char** args){
    // If the in_name is not the statically allocated
    // /dev/null, free it
    if (in_name != devnull) {
        free(in_name);
    }
    // If the out_name is not the statically allocated
    // /dev/null, free it
    if (out_name != devnull) {
        free(out_name);
    }
    // free the list of arguments.
    free(args);
    return;
}


/*!
 * char* allocate_filename(char **arg, unsigned int name_length)
 * @param:
 *      arg - name of the file
 *      name_length - maximum length the name could be
 * @return
 *      pointer to newly allocated filename
 */
char* allocate_filename(char **arg, unsigned int name_length) {
    size_t token_length = strnlen(*arg, name_length);
    char *token = malloc(token_length * sizeof(char));
    strncpy(token, *arg, token_length);
    return token;
}