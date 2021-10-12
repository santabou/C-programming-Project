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
    while(find->next != NULL)
    {
        if(find->student.id == student_id)
            return find;
        else
            find = find->next;
    }
    if(find->student.id == student_id)
        return find;
    return NULL;
}

// read the database file(Fileheader + Student structs) and link them into a linked list, return a pointer to the last node
Node* readFile(FILE* file, Node* first)
{
    Node* last = first;
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
    return last;
}

// save the linked list into the database file(Fileheader + student structs)
void saveFile(FILE* file, Node* first)
{
    Node* nodeptr = first;
    while(nodeptr->next != NULL)
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

