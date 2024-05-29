#include "dynamic_list.h"
#include "stdlib.h"
#include "string.h"


/*
• Goal: to create a node by allocating memory
• Inputs: the variable for which memory will be allocated
• Outputs: TRUE if memory could be allocated for the new node and false otherwise
• Preconditions:
• Postconditions: */
bool createNode(tPosL *p){
    *p = malloc(sizeof(struct tNode)); //allocates memory for a new node
    return *p != LNULL; //if memory allocation was successful return true, else return false
}

/*
• Goal: to create an empty list
• Inputs: Name of the list
• Outputs: sets the address pointed to by L to NULL
• Preconditions: the name of the list must not have been previously used
• Postconditions: The list is initialised and has no elements */
void createEmptyList(tList *L){
    *L = LNULL; // sets the address pointed to by L to NULL
}

/*
• Goal: to determine whether the list is empty or not
• Inputs: name of the list
• Outputs: TRUE if the list is empty and FALSE if not
• Preconditions: the list must exist
• Postconditions: */
bool isEmptyList(tList L){
    return (L==LNULL); // if the first element is null, it is empty
}

/*
• Goal: to insert an element containing the provided data in the list
• Inputs: the item to insert, the address and the name of the list
• Outputs: true if the item was correctly inserted, false otherwise
• Preconditions: The specified address is a valid address in the list
• Postconditions: The elements in the list will rearrange */
bool insertItem (tItemL d, tPosL p, tList *L){
    tPosL q, r;
    if (!createNode(&q)) //if malloc failed
        return false;
    else{
        q->data = d;
        q->next = LNULL;
        if (*L == LNULL) //if the list is empty
            *L = q;
        else if (p == LNULL){ //if the position the user inserts is NULL
            for(r=*L; r->next != LNULL; r = r->next);
            r->next = q;
        }else if (p==*L){
        q->next = p;
        *L = q;

        }else { //for inserting in the middle
        q->data = p->data; //move data from p to q
        p->data =d;        // insert next data in p
        q->next = p->next;
        p->next = q;
        }
      return true;
    }
}

/*
• Goal: to retrieve the content of the element at the indicated address
• Inputs: address of the searched item and name of the list
• Outputs: the items at the given address (userName, numPlays and userCategory)
• Preconditions: The indicated address is a valid address in the list
• Postconditions:*/
tItemL getItem(tPosL p, tList L){
    return p->data;
}

/*
• Goal: to return the address (L) of the first element of the list.
• Inputs: name of the list
• Outputs: returns the address of L, as it is at first position
• Preconditions: the list must not be empty
• Postconditions:*/
tPosL first(tList L){
    return L;
}

/*
• Goal: to return the address of the last element in the list
• Inputs: name of the list
• Outputs: address of the last item in the list
• Preconditions: the list must not be empty
• Postconditions:*/
tPosL last (tList L){
    tPosL q;
    for (q = L; q->next != LNULL; q=q->next); //iterating through the list until the last item
    return q;
}

/*
• Goal: to return the address preceding the one the user indicates (or LNULL if the specified address has no previous element).
• Inputs: address of the element and name of the list
• Outputs: the address of the previous item to the one inputted
• Preconditions: The indicated position must be a valid position in the list
• Postconditions:*/
tPosL previous (tPosL p, tList L){
    tPosL q;
    if (p==L) //if p is the first element
        return LNULL; // as it is the first element, there is no previous
    else{
        for (q = L; q->next!=p; q=q->next); //searches in order until it reaches the element to find
        return q;
    }
}

/*
• Goal: to return the position next the one the user indicates (or LNULL if the specified position has no next element).
• Inputs: Position and name of the list
• Outputs: the address of the next item to the one inputted
• Preconditions: The indicated position must be a valid position in the list
• Postconditions:*/
tPosL next (tPosL p, tList L){
    return p->next;
}

/*
• Goal: to return the address of the first element in the list whose username matches the one indicated (or LNULL if there is no such element)
• Inputs: Username and name of the list
• Outputs: the address of the element or LNULL if the list is empty or if the user is not stored in the list
• Preconditions: the list must be initialized
• Postconditions:*/
tPosL findItem (tUserName d, tList L){
    tPosL p;
    for(p=L; (p!= LNULL)&&(strcmp(d,p->data.userName)!=0); p=p->next);
    return p;
}

/*
• Goal: to delete the element at the given address from the list
• Inputs: address of the element to delete and name of the list
• Outputs: the indicated element is deleted and the elements in the node have rearranged correctly
• Preconditions: The indicated address is a valid address in the list
• Postconditions: The addresses of the elements in the list following that of the deleted
one may have changed */
void deleteAtPosition (tPosL p, tList* L) {
    tPosL q;

    if(p==*L) //delete the first
        *L = (*L)->next;
    else if (p->next == LNULL) { // Deleting the last element
        for (q = *L; q->next != p; q = q->next); // Traverse to the node before p
        q->next = LNULL; // Update next pointer
    } else { //deleting from the middle
        q=p->next; // p ----- q
        p->data = q->data; //data from p is now data from next to p
        p->next = q->next; //data from next to p is now data from p->next->next
        p=q; //get rid of the duplicated node

    }
    free(p); // p can now be used again
}

/*
• Goal: to modify the content of the element in the indicated address
• Inputs: The new item, the address where it will be inserted and the name of the list
• Outputs: the item is updated
• Preconditions: The indicated address is a valid address in the list
• Postconditions: The order of the elements in the list has not been modified */
void updateItem (tItemL d, tPosL p, tList* L){
    p->data=d;
}