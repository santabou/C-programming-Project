#include <stdio.h>
#include "function.c"

int main()
{
    printf("Welcome to Student Database Management System!\n");
    Node* first;
    Node* last;
    FILE* data = fopen("data", "r");
    if (data == NULL)
    {
        printf("Cannot find database file.\n");
        fclose(data);
        first = (Node*) malloc(sizeof(Node));
        last = first; //<< 1 node
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
        printf("5. Save & Exit\n\n");

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
                edit();
                break;
            case 5:
                data = fopen("data", "w");
                saveFile(data, first);
                fclose(data);
                printf("Exiting program.");
                exit(0);
            default:
                printf("Invalid Selection!\n");
        }
        printf("\n\nReturning to main menu. \n");
    }
}