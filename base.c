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
Node* findStudent(int student_id)
{
    //TODO
}

// read the database file(Fileheader + Student structs) and link them into a linked list
Node* readFile(FILE* file)
{
    //TODO
}

// save the linked list into the database file(Fileheader + student structs)
void saveFile(FILE* file, Node* nodePtr)
{
    //TODO
}