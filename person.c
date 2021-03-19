
/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include "utils.h"
#include "person.h"
// this define put the maximum chars that the user can enter for every person or his kid name in the array
#define MAXIMUM_LENGTH 80
// this define have the string that printed to the user in order for him to entered the name of the person
#define NAME_MESSEGE "Name:\n"
// this define have the string that printed to the user in order for him to entered the ID of the person
#define ID_MESSEGE "ID:\n"
// this define have the string that printed to the user in order for him to entered the number of kids of the person
#define KIDS_NUMBER_MESSEGE "Num of kids:\n"
// this define have the string that printed to the user in order for him to entered the of the person's kid name
#define KID_NAME_MESSEGE "Kid #%d name:\n"
// this define have the string that printed when the name of the person is printed
#define NAME_PRINTED_MESSEGE "Name: %s\n"
// this define have the string that printed when the ID of the person is printed
#define ID_PRINTED_MESSEGE "ID: %d\n"
// this define have the string that printed when the person's kid name is printed
#define KID_NAME_PRINTED_MESSEGE "Kid #%d: %s\n"

Person* CreatePerson();
void InitPersonValues(Person* person);
struct Person* SelfDestructPerson(Person* person);
void CreateNextPerson(struct Person* this, int isNextNext, ...);
void PrintPerson(Person* person);
void KillNextPerson(struct Person* this);

/************************************************************************************************************
* Function Name: CreatePerson
* Input: nothing.
* Output: the function ask the user for datails about the persons he want to inside the game. and than
	      return the first 'Person' pointer in the linked list.
* Function Operation: the function create memmory to the first person in the linked list and than initialize
					  all the fields in the struct 'Person' for the person in 0, -1, NULL and functions by
					  calling the function 'InitPersonValues' and than start to receive all the data from
					  the user and initialize the person with that data.
************************************************************************************************************/
Person* CreatePerson()
{
	char dummy;
	char nameEntered[MAXIMUM_LENGTH];
	int lenNameEntered;
	int i;
	// make a new pointer of 'Person'
	Person* person = (Person*)malloc(sizeof(Person));
	// if there wasn't memmory to do 'malloc' its return NULL
	if (person == NULL)
	{
		return NULL;
	}
	// put 0, -1, NULL, and point to functions in the values of the person by calling the function 'InitPersonValues'
	InitPersonValues(person);
	printf(NAME_MESSEGE);
	scanf("%c", &dummy);
	scanf("%s", &nameEntered);
	lenNameEntered = strlen(nameEntered);
	// create the array in the size of the name that the user entered by usuing malloc
	person->name = (char*)malloc((lenNameEntered + 1) * sizeof(char));
	// if there wasn't memmory to do 'malloc' its free the memmory of the person and return NULL
	if (person->name == NULL)
	{
		free(person);
		return NULL;
	}
	// put in the name in the struct 'Person' the name that the user entered
	strcpy(person->name, nameEntered);
	printf(ID_MESSEGE);
	scanf("%d", &person->id);
	// check how much kids this person have
	printf(KIDS_NUMBER_MESSEGE);
	scanf("%d", &person->numOfKids);
	// get the enter that the user do after he insert the number of kids
	scanf("%c", &dummy);
	// if the function get id or number of kids that lower than 0 its put tham in there absolute value
	AbsoluteValue(person);
	// create the array in the size of the number of kids that the user entered by usuing malloc
	person->kids = (char**)malloc(person->numOfKids * sizeof(char*));
	// if there wasn't memmory to do 'malloc' its free the person name and free memmory of the person and return NULL
	if (person->kids == NULL)
	{
		// free the memmory thats the name of the person took
		free(person->name);
		free(person);
		return NULL;
	}
	// if that person have at least 1 kid its get in the loop and for every kids its ask his name and save it
	for (i = 0; i < person->numOfKids; i++)
	{
		printf(KID_NAME_MESSEGE, i + 1);
		scanf("%s", &nameEntered);
		lenNameEntered = strlen(nameEntered);
		person->kids[i] = (char*)malloc((lenNameEntered + 1) * sizeof(char));

		/*
		if there wasn't memmory for 'malloc', free the person name and array of kids and its free the memmory
		of the person and return NULL
		*/
		if (person->kids[i] == NULL)
		{
			// free the memmory thats the name of the person took
			free(person->name);
			// free the memmory thats the pointers to the names of the kids took
			free(person->kids);
			free(person);
			return NULL;
		}
		strcpy(person->kids[i], nameEntered);
	}// end of for loop
	return person;
}

/************************************************************************************************************
* Function Name: InitPersonValues
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: nothing.
* Function Operation: the function initialize all the fields in the struct 'Person' for the person she gets
					  in 0 in the numOfKids,-1 in the id and NULL in the name and next. the fucntion 
					  also initialize the pointers to function by point on the fitting functions.
************************************************************************************************************/
void InitPersonValues(Person* person)
{
	person->name = NULL;
	person->id = -1;
	person->numOfKids = 0;
	person->next = NULL;
	// point the 'Print' on the function 'PrintPerson'
	person->Print = PrintPerson;
	// point the 'KillNext' on the function 'KillNextPerson'
	person->KillNext = KillNextPerson;
	// point the 'SelfDestruct' on the function 'SelfDestructPerson'
	person->SelfDestruct = SelfDestructPerson;
	// point the 'CreateNext' on the function 'CreateNextPerson'
	person->CreateNext = CreateNextPerson;
}

/************************************************************************************************************
* Function Name: SelfDestructPerson
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: return the pointer thats the person point to.
* Function Operation: free all the memmory from the person and than the person, first its free the name of
					  the person, than every name of the kids thats person have, than the array of pointers
					  to every array of kids name, than the pointer to the next person and that the person 
					  itself.
************************************************************************************************************/
struct Person* SelfDestructPerson(Person* person)
{
	int i;
	// free the memmory thats the name of the person took
	free(person->name);
	// free the memmory thats the kids name of the person took 
	for (i = 0; i < person->numOfKids; i++)
	{
		free((person->kids)[i]);
	}
	// free the memmory thats the pointers to the names of the kids took
	free(person->kids);
	// save the pointer to the next person
	Person* personNextPointer = person->next;
	// free the memmory thats the person took
	free(person);
	return personNextPointer;
}

/************************************************************************************************************
* Function Name: CreateNextPerson
* Input: 'Person' pointer, int number and maybe another 'Person' pointer
		 (valid values: pointer/s of 'Person' and number until the apper limit of int).
* Output: the function print questions to the user by calling the function 'CreatePerson'.
* Function Operation: the function print questions to the user by calling the function 'CreatePerson' and
					  if she gets 0 its create a new person and add him to the end of the linked list and
					  if its get 1 its create new late person and add him after the first 'Person' pointer
					  thats the function get.
************************************************************************************************************/
void CreateNextPerson(struct Person* this, int isNextNext, ...)
{
	// if this is while the curcle is initialize
	if (isNextNext == 0)
	{
		// find the last person in the linked list
		while (this->next != NULL)
		{
			this = this->next;
		}
		this->next = CreatePerson();
	}
	else
	{
		va_list personAfterLatePerson;
		va_start(personAfterLatePerson, isNextNext);
		Person* tempPerson = va_arg(personAfterLatePerson, Person*);
		// create the late person that the user want to add to the game
		Person* latePerson = CreatePerson();
		if (latePerson == NULL)
		{
			va_end(personAfterLatePerson);
			return;
		}
		// put the late person after his best friend
		this->next = latePerson;
		// put the person that was before in this place in the next place to the late person
		latePerson->next = tempPerson;
		va_end(personAfterLatePerson);
	}
}

/************************************************************************************************************
* Function Name: PrintPerson
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: the function print the person and all the person details.
* Function Operation: the function print the person name, id and all the kids names (if he have).
************************************************************************************************************/
void PrintPerson(Person* person)
{
	int i;
	printf(NAME_PRINTED_MESSEGE, person->name);
	printf(ID_PRINTED_MESSEGE, person->id);
	// print all the person's kids
	for (i = 0; i < person->numOfKids; i++)
	{
		printf(KID_NAME_PRINTED_MESSEGE, i + 1, person->kids[i]);
	}
}

/************************************************************************************************************
* Function Name: KillNextPerson
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: nothing.
* Function Operation: the function put in the place person thats after the person thats the function get
					  the person that after person thats after the person and delete the person that after
					  the person thats the function get by calling the function 'SelfDestruct'.
************************************************************************************************************/
void KillNextPerson(struct Person* this)
{
	this->next = (this->next)->SelfDestruct(this->next);
}