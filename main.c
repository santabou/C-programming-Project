#include <stdio.h>
#include <stdlib.h>
#include "function.c"

enum gender{male, female};

typedef struct
{
    int id;
    enum gender gender;
    char first_name[20];
    char last_name[20];
    char program[20];
}Student;

typedef struct
{
    Student student;
    Student* next;
}Node;

void menu();
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

int main()
{
    menu();
}