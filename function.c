#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "student.h"


void view(Node* first)
{
    printf("Enter student id: ");
    int student_id = getint();
    Node* ptr;
    if((ptr = findStudent(student_id, first)) != NULL)
    {
        printf("Student ID: %i\n", ptr->student.id);
        printf("Name: %s %s\n", ptr->student.first_name, ptr->student.last_name);
        if(ptr->student.gender == male)
            printf("Gender: Male\n");
        else
            printf("Gender: Female\n");
        printf("Programme: %s", ptr->student.program);
    }
    else
        printf("Student not found!\n");
}

Node* create(Node* first, Node* last)
{
    printf("Creating new student data\n");
    printf("Enter student ID: ");
    int id = getint();
    if(findStudent(id, first) != NULL)
    {
        printf("The student ID already exists.\nPlease use the edit function instead.\n");
        return last;
    }
    last->next = (Node*) malloc(sizeof(Node));
    if(last->next == NULL)
    {
        printf("Cannot allocate memory");
        return last;
    }
    last = last->next;
    char firstName[20], lastName[20], programme[40];
    enum gender gender;
    int genderInput;
    while(1)
    {
        printf("Enter gender(M for male || F for female): ");
        genderInput = getgender();
        if(genderInput == -1)
            continue;
        else
        {
            gender = genderInput;
            break;
        }
    }
    printf("Enter the student's first name: ");
    getstring(firstName, 20);
    printf("Enter the student's last name: ");
    getstring(lastName, 20);
    printf("Enter the student's programme: ");
    getstring(programme, 40);

    last->student.id = id;
    last->student.gender = gender;
    strcpy(last->student.first_name, firstName);
    strcpy(last->student.last_name, lastName);
    strcpy(last->student.program, programme);
    last->next = NULL;

    printf("Created student ID %i successfully\n", id);
    return last;
}

void delete(Node** firstptr, Node** lastptr){
    printf("Deleting student data\n");
    printf("Enter student ID: ");
    int id = getint();
    Node* del = findStudent(id, *firstptr);
    if(del == NULL)
    {
        printf("The student ID does not exists.\n");
        return;
    }
   if (del == *firstptr)
   {
       Node* temp = *firstptr;
       *firstptr = (*firstptr)->next;
       free(temp);

   }
   else if(del == *lastptr)
   {
       Node* delete = findDeleteStudent(id, *firstptr);
       *lastptr = delete;
       delete->next = NULL;
       free(del);
   }
   else
   {
       Node* delete = findDeleteStudent(id, *firstptr);
       Node* temp = delete->next;
       delete->next = delete->next->next;
       free(temp);
   }
   printf("Deleted student ID %i successfully\n", id);
}
void edit(Node* first){
    printf("Enter student ID: ");
    int id = getint();
    Node* ptr;

    if((ptr = findStudent(id, first)) == NULL)
    {
        printf("The student ID doesn't exists.\nPlease use the create function instead.\n");
        return;
    }
    
    while(1)
    {
        printf("\nEdit\n");
        printf("Enter a number to proceed:\n");
        printf("1. Edit student id\n");
        printf("2. Edit student gender\n");
        printf("3. Edit student's firstname\n");
        printf("4. Edit student's lastname\n");
        printf("5. Edit student programme\n");
        printf("6. Exit\n\n");

        int c;
        int selection;
        enum gender inputGender;
        printf("Your selection: ");
        while((c = getchar()) != '\n')
            selection = c - '0';

        switch(selection){
            case 1:
                printf("Enter new student id: ");
                ptr->student.id = getint();
                break;
            case 2:
                while(1)
                {
                    printf("Enter gender(M for male || F for female): ");
                    if((inputGender = getgender()) == -1)
                        continue;
                    else
                    {
                        ptr->student.gender = inputGender;
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter the student's firstname: ");
                getstring(ptr->student.first_name, 20);
                break;
            case 4:
                printf("Enter the student's lastname: ");
                getstring(ptr->student.last_name, 20);
                break;
            case 5:
                printf("Enter the student programme: ");
                getstring(ptr->student.program, 40);
                break;
            case 6:
                return;
            default:
                printf("Invalid Selection!\n");
        }
    }
}