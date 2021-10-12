#include <stdio.h>
enum gender{male, female};

typedef struct
{
    int id;
    enum gender gender;
    char first_name[20];
    char last_name[20];
    char program[40];
}Student;

typedef struct Node
{
    Student student;
    struct Node* next;
}Node;
// for linked list in main

// find a student from student ID. Return NULL if not found.
Node* findStudent(int student_id, Node* first)
{
    Node* find = first;
    while(find != NULL)
    {
        if(find->student.id == student_id)
            return find;
        else
            find = find->next;
    }
    return NULL;
}

// read the database file(Fileheader + Student structs) and link them into a linked list, return a pointer to the last node
Node* readFile(FILE* file, Node* first)
{
    Node* last = first;
    if(!feof(file))
    {
        fread(&(first->student), sizeof(Student), 1, file);
        first->next = (Node*) malloc(sizeof(Node));
        Node* ptr = first->next;
        while(!feof(file))
        {
            fread(&(ptr->student), sizeof(Student), 1, file);
            ptr->next = (Node*) malloc(sizeof(Node));
            last = ptr;
            ptr = ptr->next;
        }
        free(ptr);
    }
    return last;
}

// save the linked list into the database file
void saveFile(FILE* file, Node* first)
{
    Node* nodeptr = first;
    while(nodeptr != NULL)
    {
        fwrite(nodeptr, sizeof(Student), 1, file);
        nodeptr = nodeptr->next;
    }
}

int getint()
{
    int character;
    char bufferString[20];
    int i = 0;
    while((character = getchar()) != '\n')
    {
        bufferString[i] = (char) character;
        ++i;
        if(i >= 18)
            break;
    }
    bufferString[i] = '\0';
    return (int) strtol(bufferString, NULL, 10);
}

enum gender getgender()
    {
        int c;
        if((c = getchar()) != '\n')
        {
            if(c == 'M')
                return male;
            else if(c == 'F')
                return female;
            else
            {
                printf("Invalid gender input\n");
                return -1;
            }
        }
        printf("Blank input\n");
        return -1;
    }

void getstring(char* string, int len)
{
    int c;
    int count = 0;
    while((c = getchar()) != '\n')
    {
        string[count] = (char) c;
        if(count >= len)
            break;
        ++count;
    }
    string[count] = '\0';
}

