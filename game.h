/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#ifndef GAME_H
#define GAME_H

#include "person.h"

Person* InitTheHungerGame();
void InsertLaters(Person* head);
Person* RemoveCowards(Person* head);
void LetTheHungerGameBegin(Person* head);

#endif

