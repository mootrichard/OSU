// Author: Richard Moot
// Date: February 28, 2016
// Description: A todo list app that utilizes a priority heap for tracking todo items
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
  char desc[100], fName[100];
  FILE* filePtr;
  int priority;
  TaskP newTask;

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
	  switch (cmd)
	  {
		  case 'l':
			  printf("Please enter the filename: "); // Prompt for a filename
			  scanf("%s", fName); // Read in filename to our temporary holder
			  while (getchar() != '\n'); // Clear out extra newline
			  filePtr = fopen(fName, "r"); // Attempt to open designated filename
			  if (filePtr != NULL) { // Make sure we successfully opened the file
				  loadList(mainList, filePtr);
				  fclose(filePtr);
				  printf("%s has been successfully loaded.\n", fName); // Inform user we were successful
			  }
			  else printf("Error opening file.\n"); // Error handling to let them know opening that file failed

			  break;
		  case 's':
			  printf("Please enter the filename: "); // Request user to specify a destination filename
			  scanf("%s", fName);
			  while (getchar() != '\n'); // Removing extraneous newline
			  filePtr = fopen(fName, "w");
			  if (filePtr != NULL){ // Ensuring that the file opened for writing
				  saveList(mainList, filePtr);
				  fclose(filePtr);
				  printf("%s has been successfully saved.\n", fName); // Confirming the file successfully saved
			  }
			  else{
				  printf("There was an error and %s was not saved.", fName); // Error handling in case the file did not save
				  return;
			  }

			  break;
		  case 'a':
			  printf("Enter your task description: "); // Request designated task description
			  scanf("%s", desc);
			  while (getchar() != '\n'); // Removing extraneous newline
			  do{ // Continually requesting a task priority until the get within range
				  printf("Enter your task priority (0-999): ");
				  scanf("%d", &priority);
			  } while (!(priority >= 0 && priority <= 9999));
			  while (getchar() != '\n');

			  newTask = createTask(priority, desc); 
			  addHeap(mainList, newTask, compare); // Adding task into heap
			  printf("%s has been added to your list\n", desc); // Confirming successful addition

			  break;
		  case 'g':
			  if (sizeDynArr(mainList) > 0){
				  newTask = getMinHeap(mainList);
				  printf("Your first task is: %s\n", newTask->description); // Returning their first task
			  }
			  else{
				  printf("Your todo list is empty.\n"); // Informing them the list is currently empty
			  }
			  break;
		  case 'r':
			  if (sizeDynArr(mainList) > 0){
				  newTask = getMinHeap(mainList);
				  printf("You have removed %s from your list", newTask->description);
				  removeMinHeap(mainList, compare); // Removing their first task
			  }
			  else {
				  printf("Your todo list is empty.\n"); // Informing them the list is currently empty
			  }
			  break;
		  case 'p':
			  printList(mainList); // Printing out list
			  break;
		  case 'e':
			  printf("Farewell! \n");
			  break;
	  }
      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
