// base functions\
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.c"

void view(Node*);
Node* create();
void delete();
void edit();


void view(Node* first)
{
    printf("Enter student id: ");
    int student_id = getint();
    Node* ptr;
    if((ptr = findStudent(student_id, first)) != NULL)
    {
        printf("Student ID: %i\n", ptr->student.id);
        printf("Name: ");
        printf(ptr->student.first_name);
        printf(ptr->student.last_name);
    }
    else
        printf("Student not found!\n");
}

Node* create(Node* last)
{
    last->next = (Node*) malloc(sizeof(Node));
    if(last->next == NULL)
    {
        printf("Cannot allocate memory");
        return NULL;
    }
    last = last->next;
    int id;
    char firstName[20], lastName[20], programme[40];
    int genderbuffer;
    enum gender gender;
    printf("Enter student ID: ");
    id = getint();
    while(1)
    {
        printf("Enter gender(1 for male/2 for female)");
        genderbuffer = getint();
        if(genderbuffer == 1)
        {
            gender = male;
            break;
        }
        else if(genderbuffer == 2)
        {
            gender = female;
            break;
        }
        else
        {
            printf("Invalid input");
        }
    }
    printf("Enter the student's first name: ");
    gets(firstName);
    printf("Enter the student's last name: ");
    gets(lastName);
    printf("Enter the student's programme: ");
    gets(programme);

    last->student.id = id;
    last->student.gender = gender;
    strcpy(last->student.first_name, firstName);
    strcpy(last->student.last_name, lastName);
    strcpy(last->student.program, programme);
    last->next = NULL;

    printf("%i", last->student.id);

    return last;
}
void delete(){
    //TODO
}
void edit(){
    //TODO
}