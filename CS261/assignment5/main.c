#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
  char desc[100], fName[100], *remover;
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
			  printf("Please enter the filename: ");
			  scanf("%s", fName);
			  while (getchar() != '\n');
			  filePtr = fopen(fName, "r");
			  if (filePtr != NULL) {
				  loadList(mainList, filePtr);
				  fclose(filePtr);
				  printf("%s has been successfully loaded.\n", fName);
			  }
			  else printf("Error opening file.\n");

			  break;
		  case 's':
			  printf("Please enter the filename: ");
			  scanf("%s", fName);
			  while (getchar() != '\n');
			  filePtr = fopen(fName, "w");
			  if (filePtr != NULL){
				  saveList(mainList, filePtr);
				  fclose(filePtr);
				  printf("%s has been successfully saved.\n", fName);
			  }
			  else{
				  printf("There was an error and %s was not saved.", fName);
				  return;
			  }

			  break;
		  case 'a':
			  printf("Enter your task description: ");
			  scanf("%s", desc);
			  while (getchar() != '\n');
			  do{
				  printf("Enter your task priority (0-999): ");
				  scanf("%d", &priority);
			  } while (!(priority >= 0 && priority <= 9999));
			  while (getchar() != '\n');

			  newTask = createTask(priority, desc);
			  addHeap(mainList, newTask, compare);
			  printf("%s has been added to your list\n", desc);

			  break;
		  case 'g':
			  if (sizeDynArr(mainList) > 0){
				  newTask = getMinHeap(mainList);
				  printf("Your first task is: %s\n", newTask->description);
			  }
			  else{
				  printf("Your todo list is empty.\n");
			  }
			  break;
		  case 'r':
			  if (sizeDynArr(mainList) > 0){
				  newTask = getMinHeap(mainList);
				  printf("You have removed %s from your list", newTask->description);
				  removeMinHeap(mainList, compare);
			  }
			  else {
				  printf("Your todo list is empty.\n");
			  }
			  break;
		  case 'p':
			  printList(mainList);
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
