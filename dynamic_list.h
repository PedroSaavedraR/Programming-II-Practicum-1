#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"


#define LNULL NULL
#define MAX 1000


//Position of an element in a list
typedef struct tNode* tPosL;

struct tNode{
    tItemL data;
    tPosL next; //Pointer to a node
};

//Represents a list of users
typedef tPosL tList;

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
