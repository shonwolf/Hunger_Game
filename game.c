/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include "person.h"
// this define put the maximum chars that the user can enter for every person or his kid name in the array
#define MAXIMUM_LENGTH 80
// this define have the string that printed when the user is asked if he want to add a person to the game
#define ADD_MESSEGE "Add a person to the game? (0|1)\n"
// this define have the string that printed when the user is asked if he want to add person that late to the game
#define ADD_LATE_MESSEGE "Are you late? (0|1)\n"
// this define have the string that printed when the user is asked to insert his best friend ID
#define BEST_FRIEND_ID_MESSEGE "Insert your best friend's ID:\n"
// this define have the string that printed when the user entered if that no exist in any person in the linked list
#define WRONG_ID_MESSEGE "No Such ID: %d\n"
// this define have the string that printed when the user is asked if there is a coward person in the linked list
#define REMOVE_COWARD_MESSEGE "Is there a coward in here? (0|1)\n"
// this define have the string that printed when the user is asked to insert the coward ID
#define COWARD_ID_MESSEGE "Insert your ID, you, lame pudding-heart coward:\n"
// this define have the string that printed the coward name
#define DECLARE_COWARD_MESSEGE "Let the world know that you are a coward, %s!\n"
// this define have the string that printed when the person win the game and his name
#define WIN_MESSEGE "Ah, ha, ha, ha, stayin' alive, stayin' alive! Ah, ha, ha, ha, \"%s\" stayin' alive!\n"
// this define have the string that printed the name of the person that kills, the name of the person that being killed
#define WHO_KILLS_WHO "%s kills %s"
// this define have the string that printed when the person that killed have kid and printed there names
#define AND_KID_MESSEGE " and %s"

Person* InitTheHungerGame();
void InsertLaters(Person* head);
Person* RemoveCowards(Person* head);
void LetTheHungerGameBegin(Person* head);
void FreeAllPersons(Person* head);

/************************************************************************************************************
* Function Name: InitTheHungerGame
* Input: nothing.
* Output: 'Person' pointer, and question if to add more persons to the game.
* Function Operation: the function ask the user if he want to add person to the game (1 for yes, 0 for no), 
					  if he want to add its ask details of the person he want to inside by using the 
					  function 'CreatePerson' for the first time and by using the function 
					  'head->CreateNext' for the other times.
					  if there won't be call to the function 'LetTheHungerGameBegin'its won't free any
					  person because we need this memmorys until the game start.
************************************************************************************************************/
Person* InitTheHungerGame()
{
	int userAnswer;
	int checkFirst = 0;
	Person* head = NULL;
	Person* firstPerson = NULL;
	printf(ADD_MESSEGE);
	scanf("%d", &userAnswer);
	// if the user entered 1 its ask him to put information to the person he want to add to the game for every person
	while (userAnswer == 1)
	{
		checkFirst++;
		// if this is the first person thats the user input to the linked list its put him in the first place 
		if (checkFirst == 1)
		{
			head = CreatePerson();
			firstPerson = head;
			if (head == NULL)
			{
				return NULL;
			}
		}
		// if this isn't the first person that get in the linked list its put him in the last struct in the linked list
		else
		{
			head->CreateNext(head, 0);
			if (head->next == NULL)
			{

				/*
				if there was a problem in creating the person its free all the persons from the linked listby calling
				the function 'FreeAllPersons'
				*/
				FreeAllPersons(firstPerson);
				head = NULL;
				break;
			}
			head = head->next;
		}
		printf(ADD_MESSEGE);
		scanf("%d", &userAnswer);
	}// end of while loop
	head = firstPerson;
	firstPerson = NULL;
	return head;
}

/************************************************************************************************************
* Function Name: InsertLaters
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: questions to the user about the bast friend's ID of the person he want to inside and about the
		  datails of the person.
* Function Operation: the function ask the user if he want to add late person and if he insert 1 its ask
					  the best friend's ID of the person and details about him by calling the function
					  'head->CreateNext' and insert him after his best friend in the linked list.
************************************************************************************************************/
void InsertLaters(Person* head)
{
	int userAnswer;
	int bestFriendId;
	Person* firstPerson = head;
	// if the linked list is empty its doesn't do anything
	if (head == NULL)
	{
		return;
	}
	printf(ADD_LATE_MESSEGE);
	scanf("%d", &userAnswer);
	// if the user entered 1 its ask him to put information to the late person he want to add to the game
	while (userAnswer == 1)
	{
		printf(BEST_FRIEND_ID_MESSEGE);
		scanf("%d", &bestFriendId);
		// get to the place of the best friend of the late person in the linked list
		while (head->id != bestFriendId)
		{
			head = head->next;
			if (head == NULL)
			{
				break;
			}
		}
		// if there isn't such ID like the one that the user enterd
		if (head == NULL)
		{
			printf(WRONG_ID_MESSEGE, bestFriendId);
			printf(ADD_LATE_MESSEGE);
			scanf("%d", &userAnswer);
			// put back in head the first place in the linked list
			head = firstPerson;
			continue;
		}
		// call the function 'CreateNext' and she put the person with his details after his best friend
		head->CreateNext(head, 1, head->next);
		// if its couldn't add another person to the linked list its stop asking for insert later
		if (head == NULL)
		{
			break;
		}
		// put back in head the first place in the linked list
		head = firstPerson;
		printf(ADD_LATE_MESSEGE);
		scanf("%d", &userAnswer);
	}// end of while loop
	firstPerson = NULL;
}

/************************************************************************************************************
* Function Name: RemoveCowards
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: questions if there is a coward and his ID and return the first place in the new linked list.
* Function Operation: the function ask the user if there is a coward in the game (1 for yes and 0 for no)
					  and if there is its ask for his ID and than its erase him from the linked list and 
					  free his memmory.
************************************************************************************************************/
Person* RemoveCowards(Person* head)
{
	int userAnswer;
	int cowardId;
	Person* firstPerson = head;
	// if the linked list is empty its doesn't do anything
	if (head == NULL)
	{
		return NULL;
	}
	printf(REMOVE_COWARD_MESSEGE);
	scanf("%d", &userAnswer);
	// if the user entered 1 its ask him to insert the ID of the coward person
	while (userAnswer == 1)
	{
		printf(COWARD_ID_MESSEGE);
		scanf("%d", &cowardId);
		// if the first person in the linked list is a coward its put him out of the list
		if (head->id == cowardId)
		{
			printf(DECLARE_COWARD_MESSEGE, head->name);
			// start the linked list from the second place in it and that how its delete the first person
			head = head->SelfDestruct(head);
			// if there are no more persons in the linked list its get out of the while loop
			if (head == NULL)
			{
				break;
			}
			firstPerson = head;
		}
		// if the coward is not the first person in the linked list
		else
		{
			// find the place before the place of the coward person
			while (head->next != NULL &&(head->next)->id != cowardId)
			{
				head = head->next;
				if (head->next == NULL)
				{
					break;
				}
			}
			// if there isn't such ID like the one that the user enterd
			if (head->next == NULL)
			{
				printf(WRONG_ID_MESSEGE, cowardId);
				printf(REMOVE_COWARD_MESSEGE);
				scanf("%d", &userAnswer);
				// put back in head the first place in the linked list
				head = firstPerson;
				continue;
			}
			printf(DECLARE_COWARD_MESSEGE, (head->next)->name);

			/*
			put the place that after the coward person after the place thats before the coward person in the linked
			list and that how its delete the coward person from the linked list
			*/
			head->next = (head->next)->SelfDestruct(head->next);
			head = firstPerson;
		}// end of else
		printf(REMOVE_COWARD_MESSEGE);
		scanf("%d", &userAnswer);
	}// end of while loop
	firstPerson = NULL;
	return head;
}

/************************************************************************************************************
* Function Name: LetTheHungerGameBegin
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: print post about the gameplay.
* Function Operation: the function checks if there is only one player in the game in if there is she print
					  thats he win, else the function kill every person thats next to the person at start
					  and than the second and so on until there is one player left and he is the one that 
					  win, she print every person that die and the person that kill him, and in the end she
					  prints the winner.
************************************************************************************************************/
void LetTheHungerGameBegin(Person* head)
{
	int i;
	Person* firstPerson = head;
	// if the linked list is empty
	if (head == NULL)
	{
		return;
	}
	// if there is only one person in the linked list he is the one that stay alive in the game
	if (head->next == NULL)
	{
		printf(WIN_MESSEGE, head->name);
		return;
	}
	// get to the lest person in the linked list
	while (head->next != NULL)
	{
		head = head->next;
	}

	/*
	point from the lest person of the linked list to the first person of the linked list and that how its create
	circle linked list
	*/
	head->next = firstPerson;
	while (firstPerson->next != firstPerson)
	{
		printf(WHO_KILLS_WHO, firstPerson->name, (firstPerson->next)->name);
		// if the person that killed have kids
		if ((firstPerson->next)->numOfKids > 0)
		{
			// print all the kids of the person that killed
			for (i = 0; i < (firstPerson->next)->numOfKids; i++)
			{
				printf(AND_KID_MESSEGE, (firstPerson->next)->kids[i]);
			}
		}
		printf("\n");
		// delete the person that after the current person
		firstPerson->KillNext(firstPerson);
		firstPerson = firstPerson->next;
	}
	printf(WIN_MESSEGE, firstPerson->name);
	head = firstPerson;
	firstPerson = NULL;
	head->SelfDestruct(head);
}

/************************************************************************************************************
* Function Name: FreeAllPersons
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: nothing.
* Function Operation: the function free all the memmory of all the persons in the linked list that start in
					  the pointer to the first person in her thats she get.
************************************************************************************************************/
void FreeAllPersons(Person* head)
{
	while (head != NULL)
	{
		head = head->SelfDestruct(head);
	}
}

