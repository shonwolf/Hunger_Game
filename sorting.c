/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include "person.h"

Person* SortCircleByID(Person* head);
Person* FindPersonWithMinId(Person* head);
int SumNumPersons(Person* head);
Person* SortCircle(Person* head, struct Person* (*FindMin)());
Person* SortCircleByName(Person* head);
Person* FindPersonWithMinName(Person* head);

/************************************************************************************************************
* Function Name: SortCircleByID
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: return the linked list thats the function get sorterd by ID.
* Function Operation: the fucntion get linked list and check for this linked list who is the person
					  thats have the smallest ID by sending the function 'FindPersonWithMinId' to the
					  function 'SortCircle' thats move on all the linked list and made a new linked list
					  that sorted by ID using the poiter to the function 'FindPersonWithMinId' that she get.
************************************************************************************************************/
Person* SortCircleByID(Person* head)
{
	// if the linked list is empty
	if (head == NULL)
	{
		return head;
	}
	struct Person* (*personWithMinId)(struct Person* head);
	personWithMinId = FindPersonWithMinId;
	head = SortCircle(head, personWithMinId);
	return head;
}

/************************************************************************************************************
* Function Name: SortCircle
* Input: 'Person' pointer, pointer to function (valid values: pointer of 'Person', pointer to function
		 thats getting 'Person' and return 'Person').
* Output: return the linked list thats the function get sorterd by ID.
* Function Operation: the fucntion get linked list and pointer to function and check for this linked list
					  who is the person thats have the smallest ID or name (name by ASKII code) by calling
					  the function 'FindMin' (the pointr to function that the function get), than its
					  insert this person to new linked list and put out thats person from the old linked
					  list and so on until its finish to move on the number of persons in the linked list
					  and than its return the pointer to the first person in the new sorted linked list.
************************************************************************************************************/
Person* SortCircle(Person* head, struct Person* (*FindMin)())
{
	// check how much persons there are in the linked list by calling the function 'SumNumPersons'
	int sumPersons = SumNumPersons(head);
	// save the person with the minimul ID in a pointer by calling the function 'FindPersonWithMinId'
	Person* minId = FindMin(head);
	// insert the person with the smallest ID to the first place in the new sorted linked list
	Person* sortedLinkedList = minId;
	// save the pointer to the first place in the new sorterd linked list
	Person* firstInsortedLinkedList = sortedLinkedList;
	// if the minimul ID is the one thats in the first place its put in the first place the next person
	if (minId == head)
	{
		// delete the person with the minimul ID from the linked list
		head = head->next;
		minId = NULL;
	}
	// if the minimul ID is one thats in midule place its check witch place it is and delete him from the linked list
	else
	{
		Person* first = head;
		// check witch place is the place of the person with the minimul ID
		while (head->next != minId)
		{
			head = head->next;
		}
		// delete the person with the minimul ID from the linked list
		head->next = (head->next)->next;
		head = first;
	}

	/*
	go over the number of persons in the linked list and insert to the sorted linked list the persons from the
	old linked list sorted
	*/
	while (sumPersons - 1 > 0)
	{
		// save the person with the minimul ID in a pointer by calling the function 'FindPersonWithMinId'
		minId = FindMin(head);
		// insert the person with the next smallest ID to the next place in the new sorted linked list
		sortedLinkedList->next = minId;
		// if the minimul ID is the one thats in the first place its put in the first place the next person
		if (minId == head)
		{
			// delete the person with the minimul ID from the linked list
			head = head->next;
			minId = NULL;
		}
		// if the minimul ID is one thats in midule place, check witch place it is and delete him from the linked list
		else
		{
			Person* first = head;
			// check witch place is the place of the person with the minimul ID
			while (head->next != minId)
			{
				head = head->next;
			}
			// delete the person with the minimul ID from the linked list
			head->next = (head->next)->next;
			head = first;
		}
		sortedLinkedList = sortedLinkedList->next;
		sumPersons--;
	}// end of while loop
	sortedLinkedList = NULL;
	return firstInsortedLinkedList;
}

/************************************************************************************************************
* Function Name: FindPersonWithMinId
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: return the person with the minimul ID from the linked list thats the function get.
* Function Operation: the function go over all the ID of the persons in the linked list thats the function
				      get and return the person with the minimul ID.
************************************************************************************************************/
Person* FindPersonWithMinId(Person* head)
{
	Person* firstPerson = head;
	Person* minId = head;
	// go over all the persons in the linked list
	while (head != NULL)
	{
		// checks if the ID of this person is smallest than the ID thats was the smallest until now
		if (minId->id > head->id)
		{
			// if the ID is smaller its save this person 
			minId = head;
		}
		head = head->next;
	}
	head = firstPerson;
	firstPerson = NULL;
	return minId;
}

/************************************************************************************************************
* Function Name: SumNumPersons
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: return the number of persons thats are in the linked list.
* Function Operation: the function go over all the linked list and sum all the persons in it and return 
					  that number;
************************************************************************************************************/
int SumNumPersons(Person* head)
{
	Person* firstPerson = head;
	int sum = 0;
	// while its not the end of the linked list its add 1 to the sum and keep moving forward
	while (head != NULL)
	{
		sum++;
		head = head->next;
	}
	// return the pointer to point on the first place in the linked list
	head = firstPerson;
	firstPerson = NULL;
	return sum;
}

/************************************************************************************************************
* Function Name: SortCircleByName
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: return the linked list thats the function get sorterd by name.
* Function Operation: the fucntion get linked list and check for this linked list who is the person
					  thats have the smallest name (by ASKII code) by sending the function
					  'FindPersonWithMinName' to the function 'SortCircle' thats move on all the linked 
					  list and made a new linked list that sorted by name (by ASKII code) using the poiter
					  to the function 'FindPersonWithMinName' that she get.
************************************************************************************************************/
Person* SortCircleByName(Person* head)
{
	// if the linked list is empty
	if (head == NULL)
	{
		return head;
	}
	struct Person* (*personWithMinName)(struct Person* head);
	personWithMinName = FindPersonWithMinName;
	head = SortCircle(head, personWithMinName);
	return head;
}

/************************************************************************************************************
* Function Name: FindPersonWithMinName
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: return the person with the minimul name (by ASKII code) from the linked list thats the function
		  get.
* Function Operation: the function go over all the names of the persons in the linked list thats the
					  function get and return the person with the minimul name (by ASKII code).
************************************************************************************************************/
Person* FindPersonWithMinName(Person* head)
{
	Person* firstPerson = head;
	Person* minName = head;
	// go over all the persons in the linked list
	while (head != NULL)
	{
		// checks if the name of this person is smallest than the name thats was the smallest until now
		if (strcmp(minName->name, head->name) > 0)
		{
			// if the name is smaller its save this person 
			minName = head;
		}
		head = head->next;
	}
	head = firstPerson;
	firstPerson = NULL;
	return minName;
}