#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

// Counts the number of users depending on their category
void user_category_count(tItemL *userdata, tList L, int *num_users_basic, int *num_users_pro) {
    tPosL pos;
    *num_users_basic = 0;
    *num_users_pro = 0;

    for (pos = first(L); pos != LNULL; pos = next(pos, L)) {
        *userdata = getItem(pos, L);
        if (userdata->userCategory == basic) {
            (*num_users_basic)++;
        } else {
            (*num_users_pro)++;
        }
    }
}
// Defines the category of a user depending on the given parameter
bool basic_or_pro (tItemL *userdata, char* category){

    if (strcmp(category,"basic")!=0 && strcmp(category,"pro")!=0)
        return false; //if the input is incorrect
    else
        if (strcmp(category,"basic")==0) {
            userdata->userCategory = basic;
        }
        else{
            userdata->userCategory=pro;
        }
    return true;

}

// Turns the enum category into a string for better operating
void enum_to_string (tItemL *userdata, char* category){
    if (userdata->userCategory == basic)
        strcpy(category, "basic");
    else
        strcpy(category, "pro");
}

//Adds a new user to the list
void new_user (char* user, char* category, tList *L){
    tItemL userdata;
    strcpy(userdata.userName, user);

    if (findItem(user, *L)==LNULL && basic_or_pro(&userdata, category)==true) {

        userdata.numPlay = 0;

        if (insertItem(userdata, LNULL, L)!=false) //check insertItem for false
            printf("* New: user %s category %s\n", userdata.userName, category);
        else
            printf("+ Error: New not possible\n");
    }
    else
        printf("+ Error: New not possible\n");

}

// Establishes a count for the number of songs a user has played (differentiates from premium and basic users)
void numplay_count (tItemL *userdata, tList L, int *numplays_basic, int *numplays_pro) {
    tPosL pos;
    *numplays_basic = 0;
    *numplays_pro = 0;

    for (pos = first(L); pos != LNULL; pos = next(pos, L)) {
        *userdata = getItem(pos, L);
        if (userdata->userCategory == basic) {
            *numplays_basic += userdata->numPlay;
        } else {
            *numplays_pro += userdata->numPlay;
        }
    }
}


//Prints the stats
void print_stats(tList *L){

    tPosL pos;
    tItemL userdata;
    int num_users_basic, num_users_pro;
    int numplays_basic, numplays_pro;
    char category[6];
    float average_basic, average_pro;
    if (!isEmptyList(*L)) {
        pos = first(*L);
        while (pos != LNULL) {
            userdata = getItem(pos, *L);
            enum_to_string(&userdata, category);
            printf("User %s category %s numplays %d\n", userdata.userName, category, userdata.numPlay);
            pos = next(pos, *L);
        }
        user_category_count (&userdata, *L, &num_users_basic, &num_users_pro);
        numplay_count (&userdata, *L, &numplays_basic, &numplays_pro);
        if (num_users_basic != 0)
            average_basic= (float)numplays_basic/(float)num_users_basic;
        else
            average_basic = 0;
        if (num_users_pro!=0)
            average_pro= (float)numplays_pro/(float)num_users_pro;
        else
            average_pro = 0;
        printf("Category  Users  Plays  Average\n");
        printf("Basic         %d      %d     %.2f\n", num_users_basic, numplays_basic, average_basic);
        printf("Pro           %d      %d     %.2f\n", num_users_pro, numplays_pro, average_pro);
    }
    else //if the list is empty
        printf("+ Error: Stats not possible\n");
}

void delete_user (char* user, tList *L){
    char category[6];
    tItemL userdata;
    tPosL pos = findItem(user, *L);
    if(pos==LNULL)
        printf("+ Error: Delete not possible\n");
    else {
        userdata = getItem(pos, *L);
        deleteAtPosition(pos, L);
        enum_to_string(&userdata, category);
       printf("* Delete: user %s category %s numplays %d\n", userdata.userName, category, userdata.numPlay);
    }
}

// Adds one play to the user numplays count
void add_play (char* user, char* song, tList *L){
    tItemL userdata;
    tPosL pos = findItem(user, *L);
    if (pos==LNULL)
        printf("+ Error: Play not possible\n");
    else{
        userdata = getItem(pos, *L);
        userdata.numPlay = userdata.numPlay+1;
        updateItem (userdata, pos, L);

        printf("* Play: user %s plays song %s numplays %d\n", user, song, userdata.numPlay);}
}

// Upgrades an user from basic to pro
void upgrade(char* user, tList *L) {
    tPosL pos = findItem(user, *L);
    tItemL userdata = getItem(pos, *L);
    char category[6];
    enum_to_string(&userdata, category);

    if (pos==LNULL || userdata.userCategory == pro || isEmptyList(*L)==true)
        printf("+ Error: Upgrade not possible");

    else {
        userdata.userCategory=pro;
        updateItem(userdata, pos, L);
        printf("* Upgrade: user %s category pro\n", userdata.userName);
    }


}


//*****************************************************************************************************************//

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList* L) {
    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            new_user(param1, param2, L);
            break;

        case 'D':
            printf("********************\n");
            printf("%s %c: user %s\n", commandNumber, command, param1);
            delete_user(param1, L);
            break;
        case 'U':
            printf("********************\n");
            printf("%s %c: user %s\n", commandNumber, command, param1);
            upgrade(param1, L);

            break;
        case 'P':
            printf("********************\n");
            printf("%s %c: user %s song %s\n",commandNumber, command, param1, param2);
            add_play(param1, param2, L);
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c:\n", commandNumber, command);
            print_stats(L);

            break;
        default:

            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    tList L;
    createEmptyList (&L);
    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, &L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}

