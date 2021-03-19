/******************************************
*Student name: Shon Wolf
* Student Id: 208581660
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#ifndef UTILS_H
#define UTILS_H

#include "person.h"

/************************************************************************************************************
* Function Name: PrintCircle
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: the function print all the persons and all their details details (by calling the function
'head->Print') in a unik format.
* Function Operation: the function print all the persons and all thier details (by calling the function
'head->Print') in a unik format. first she prints '----------', than the person
name, id, and kids names (if he have) and than prints another '----------'.
************************************************************************************************************/
void PrintCircle(Person* head);

/************************************************************************************************************
* Function Name: AbsoluteValue
* Input: 'Person' pointer (valid values: pointer of 'Person').
* Output: nothing.
* Function Operation: if the id or the name thats the user entered is lower than 0 the function put tham in
there absolute value.
************************************************************************************************************/
void AbsoluteValue(Person* person);

#endif
