#include <stdio.h>
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

int main()
{
    printf("Welcome to Student Database Management System!");
    for(FILE* data = fopen("data", "r"); data == NULL;)
    {
        printf("Cannot find database file. Creating a blank database");
        fclose(data);
        fopen("data", "w");
        data = fopen("data", "r");
    }
    while(1)
    {
        menu();
    }
}