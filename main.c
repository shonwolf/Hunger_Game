/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "person.h"
#include "utils.h"
#include "sorting.h"
#include "game.h"

int main() {
	Person* head = InitTheHungerGame();
	PrintCircle(head);
	InsertLaters(head);
	PrintCircle(head);
	head = RemoveCowards(head);
	PrintCircle(head);
	head = SortCircleByName(head);
	PrintCircle(head);
	head = SortCircleByID(head);
	PrintCircle(head);
	LetTheHungerGameBegin(head);
	return 0;
}
