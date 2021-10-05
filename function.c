// base functions
#include <stdio.h>
#include <stdlib.h>

void view();
void create();
void delete();
void edit();
void select();

void select()
{
    printf("Your selection: ");
    int selection = getchar();
    switch(selection){
        case 1:
            view();
            break;
        case 2:
            create();
            break;
        case 3:
            delete();
            break;
        case 4:
            edit();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Selection!");
            select();
    }
}

void menu()
{
    printf("MENU\n");
    printf("Enter a number to proceed:\n");
    printf("1. View student data\n");
    printf("2. Create new student data\n");
    printf("3. Delete student data\n");
    printf("4. Edit student data\n");
    printf("5. Exit\n\n");

    select();
}