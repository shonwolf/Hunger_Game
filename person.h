/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#ifndef PERSON_H
#define PERSON_H

struct Person {
	char* name;
	int id;
	int numOfKids;
	char** kids;
	struct Person* next;
	void(*Print)(struct Person* this);
	void(*KillNext)(struct Person* this);
	struct Person* (*SelfDestruct)(struct Person* this);
	void(*CreateNext)(struct Person* this, int isNextNext, ...);
};

typedef struct Person Person;

//use only once
Person* CreatePerson();
void InitPersonValues(Person* person);

#endif

