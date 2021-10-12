#include <stdlib.h>
#include <string.h>
#include "base.c"

void view(Node*);
Node* create(Node*);
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
    enum gender gender;
    int genderInput;
    printf("Enter student ID: ");
    id = getint();
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

    printf("%i", last->student.id);

    return last;
}
void delete(){
    //TODO
}
void edit(){
    //TODO
}