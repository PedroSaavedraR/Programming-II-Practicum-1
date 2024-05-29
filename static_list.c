#include "static_list.h"
#include "string.h"

/*
• Goal: to create an empty list
• Inputs: Name of the list
• Outputs: none
• Preconditions: the name of the list must not have been previously used
• Postconditions: The list is initialised and has no elements */
void createEmptyList (tList* L){
    L->lastPos=LNULL;
}

/*
• Goal: to determine whether the list is empty or not
• Inputs: name of the list
• Outputs: true if the list is empty and false if not
• Preconditions: the list must exist
• Postconditions: */
bool isEmptyList(tList L){
    return (L.lastPos == LNULL);
}

/*
• Goal: to return the position of the first element of the list.
• Inputs: name of the list
• Outputs: returns 0, as it is the first position
• Preconditions: the list must not be empty
• Postconditions:*/
tPosL first(tList L){
    return 0;
}
/*
• Goal: to return the position of the last element of the list
• Inputs: name of the list
• Outputs: last position
• Preconditions: the list must not be empty
• Postconditions:*/
int last(tList L){
    return L.lastPos;
}
/*
• Goal: to return the position preceding the one the user indicates (or LNULL if the specified position has no previous element).
• Inputs: Position and name of the list
• Outputs: previous position to the one given
• Preconditions: The indicated position must be a valid position in the list
• Postconditions:*/
tPosL previous (tPosL p, tList L){
    return --p;
}

/*
• Goal: to return the position following the one the user indicates (or LNULL if the specified position has no next element)
• Inputs: Position and name of the list
• Outputs: following position to the one given
• Preconditions: The indicated position is a valid position in the list
• Postconditions:*/
tPosL next (tPosL p, tList L){
    if (p==L.lastPos)
        return LNULL; //there is no next if the given element is the last
    else
        return ++p;
}
/*
• Goal: to insert an element containing the provided data in the list
• Inputs: the item to insert, the position and the name of the list
• Outputs: true if the item was correctly inserted, false otherwise
• Preconditions: The specified position is a valid position in the list or a LNULL position
• Postconditions: The positions of the elements in the list following that of the inserted
one may have changed */
bool insertItem(tItemL d, tPosL p, tList* L){
    tPosL i;
    if (L->lastPos==MAX-1){
        return false; //no space left
    }
    else{
        L->lastPos++; //if there is space, one more position is needed
        if (p==LNULL){
            L->data[L->lastPos]=d; //new data is added in the last position
        }
        else{
            for(i=L->lastPos; i>=p+1;i--)
                L->data[i]= L->data[i-1];
            L->data[p] = d;
        }
        return true;
    }
}
/*
• Goal: to delete the element at the given position from the list
• Inputs: position and name of the list
• Outputs:
• Preconditions: The indicated position is a valid position in the list
• Postconditions: The positions of the elements in the list following that of the deleted
one may have changed */
void deleteAtPosition (tPosL p, tList* L){
    tPosL i;
    L->lastPos--;
    for(i=p;i<=L->lastPos; i++)
        L->data[i] = L->data[i+1]; //everything after the position inputted is shifted one position to the right
}

/*
• Goal: to retrieve the content of the element at the indicated position
• Inputs: position and name of the list
• Outputs: the searched item
• Preconditions: The indicated position is a valid position in the list
• Postconditions:*/
tItemL getItem(tPosL p, tList L){
    return L.data[p];
}

/*
• Goal: to modify the content of the element at the indicated position
• Inputs: The item to modify, the position and the name of the list
• Outputs:
• Preconditions: The indicated position is a valid position in the list
• Postconditions: The order of the elements in the list has not been modified */
void updateItem(tItemL d, tPosL p, tList* L){
    L->data[p]=d;
}

/*
• Goal: to return the position of the first element in the list whose username matches the one indicated (or LNULL if there is no such element)
• Inputs: Username and name of the list
• Outputs: the position of the element or LNULL if the list is empty or if the user is not stored in the list<a
• Preconditions: the list must be initialized
• Postconditions:*/
tPosL findItem(tUserName d, tList L){
    tPosL p;
    if(L.lastPos == LNULL)
        return LNULL; // If the list is empty, there is no item to be found
    else{
        for(p=0; (p<L.lastPos)&&(strcmp(d,L.data[p].userName)!=0);p++);

        if (strcmp(d,L.data[p].userName)==0) //comparing the strings
            return p;

        else //if the user is not found
            return LNULL; //the user does not exist
    }
}