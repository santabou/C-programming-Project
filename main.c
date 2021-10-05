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

int main()
{
    menu();
}