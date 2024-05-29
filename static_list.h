#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"

/* Write your code here... */

#define LNULL (-1)
#define MAX 1000


//Position of an element in a list
typedef int tPosL;

//Represents a list of users
typedef struct tList {
    tPosL lastPos;
    tItemL data[MAX];
}tList;

void createEmptyList (tList* L);

bool isEmptyList(tList L);

tPosL first(tList L);

tPosL last(tList L);

tPosL previous (tPosL p, tList L);

tPosL next (tPosL p, tList L);

bool insertItem(tItemL d, tPosL p, tList* L);

void deleteAtPosition (tPosL p, tList* L);

tItemL getItem(tPosL p, tList L);

void updateItem (tItemL d, tPosL p, tList* L);

tPosL findItem(tUserName , tList L);


#endif
