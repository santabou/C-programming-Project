#include <stdio.h>
#include "function.c"

int main()
{
    printf("Welcome to Student Database Management System!\n");
    FILE* data = fopen("data", "r+");
    if (data == NULL)
    {
        printf("Cannot find database file. Creating a blank database\n");
        fclose(data);
        FILE* create = fopen("data", "w");
        fclose(create);
        data = fopen("data", "r+");
    }

    Node* first = (Node*) malloc(sizeof(Node));
    Node* last = readFile(data, first);

    while(1)
    {
        printf("MENU\n");
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
                last = create(last);
                break;
            case 3:
                delete();
                break;
            case 4:
                edit();
                break;
            case 5:
                saveFile(data, first);
                exit(0);
            default:
                printf("Invalid Selection!\n");
        }
    }
}