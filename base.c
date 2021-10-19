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
    Node* ptr = first;
    while(!feof(file))
    {
        fread(&(ptr->student), sizeof(Student), 1, file);
        if(feof(file))
            break;
        ptr->next = (Node*) malloc(sizeof(Node));
        last = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    last->next = NULL;
    return last;
}

// save the linked list into the database file
void saveFile(FILE* file, Node* first)
{
    Node* nodeptr = first;
    while(nodeptr != NULL)
    {
        if(nodeptr->student.id == 0)
        {
            nodeptr = nodeptr->next;
            continue;
        }
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
        enum gender gender;
        if((c = getchar()) == 'M')
            gender = male;
        else if(c == 'F')
            gender = female;
        else
        {
            printf("Invalid gender input\n");
            return -1;
        }
        if(getchar() == '\n')
            return gender;
        else
        {
            printf("Invalid gender input\n");
            return -1;
        }
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

