#include <stdio.h>
#include "function.c"
#include "base.c"

int main()
{
    printf("Welcome to Student Database Management System!\n");
    for(FILE* data = fopen("data", "r"); data == NULL;)
    {
        printf("Cannot find database file. Creating a blank database");
        fclose(data);
        FILE* create = fopen("data", "w");
        FileHeader blank = {0};
        fwrite(&blank, sizeof(FileHeader), 1, create);
        fclose(create);
        data = fopen("data", "r");
    }

    while(1)
    {
        menu();
    }
}