/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include "person.h"
// this define have the string that printed dashed lines
#define DASHED_LINES "----------\n"

void PrintCircle(Person* head);

/************************************************************************************************************
* Function Name: PrintCircle
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: the function print all the persons and all their details details (by calling the function
		  'head->Print') in a unik format.
* Function Operation: the function print all the persons and all thier details (by calling the function
					  'head->Print') in a unik format. first she prints '----------', than the person
					  name, id, and kids names (if he have) and than prints another '----------'.
************************************************************************************************************/
void PrintCircle(Person* head)
{
	Person* firstPerson = head;
	// if the linked list is empty
	if (head == NULL)
	{
		return;
	}
	// while the linked list is not over its print every person by calling the fucntion 'head->Print'
	while (head != NULL)
	{
		printf(DASHED_LINES);
		// print the current person in the linked list
		head->Print(head);
		head = head->next;
	}
	printf(DASHED_LINES);
	head = firstPerson;
	firstPerson = NULL;
}

/************************************************************************************************************
* Function Name: AbsoluteValue
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: nothing.
* Function Operation: if the id or the name thats the user entered is lower than 0 the function put tham in
there absolute value.
************************************************************************************************************/
void AbsoluteValue(Person* person)
{
	// if the user enterd id that lower than 0 its put the id in his absolute value
	if (person->id < 0)
	{
		person->id = person->id * -1;
	}
	// if the user enterd number of kids that lower than 0 its put the id in his absolute value
	if (person->numOfKids < 0)
	{
		person->numOfKids = person->numOfKids * -1;
	}
}