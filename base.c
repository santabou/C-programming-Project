enum gender{male, female};

typedef struct
{
    int numberOfStudents;
}FileHeader;
// file = Fileheader followed by series of Student struct

typedef struct
{
    int id;
    enum gender gender;
    char first_name[20];
    char last_name[20];
    char program[20];
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
    return NULL;
}

// read the database file(Fileheader + Student structs) and link them into a linked list
Node* readFile(FILE* file)
{
    //TODO
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
