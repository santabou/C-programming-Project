#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
    printf("Welcome to Student Database Management System!\n");
    Node* first;
    Node* last;
    FILE* data = fopen("data", "r");
    if (data == NULL)
    {
        first = (Node*) malloc(sizeof(Node));
        printf("Cannot find database file.\n");
        fclose(data);
        printf("Creating first student data\n");
        printf("Enter student ID: ");
        first->student.id = getint();

        while(1)
        {
            printf("Enter gender(M for male || F for female): ");
            first->student.gender = getgender();
            if(first->student.gender == -1)
                continue;
            else
                break;
        }
        printf("Enter the student's first name: ");
        getstring(first->student.first_name, 20);
        printf("Enter the student's last name: ");
        getstring(first->student.last_name, 20);
        printf("Enter the student's programme: ");
        getstring(first->student.program, 40);
        last = first;
    }
    else
    {
        first = (Node*) malloc(sizeof(Node));
        last = readFile(data, first);
        fclose(data);
    }

    while(1)
    {
        printf("\nMENU\n");
        printf("Enter a number to proceed:\n");
        printf("1. View student data\n");
        printf("2. Create new student data\n");
        printf("3. Delete student data\n");
        printf("4. Edit student data\n");
        printf("5. Save & Exit\n");
        printf("6. Output to CSV\n\n");

        int c;
        int selection;
        printf("Your selection: ");
        while((c = getchar()) != '\n')
            selection = c - '0';

        switch(selection){
            case 1:
                view(first);
                break;
            case 2:
                last = create(first, last);
                break;
            case 3:
                delete(&first, &last);
                break;
            case 4:
                edit(first);
                break;
            case 5:
                data = fopen("data", "w");
                saveFile(data, first);
                fclose(data);
                printf("Exiting program.");
                exit(0);
            case 6:
                data = fopen("output.csv", "w");
                outputCSV(data, first);
                break;
            default:
                printf("Invalid Selection!\n");
        }
        printf("\n\nReturning to main menu. \n");
    }
}