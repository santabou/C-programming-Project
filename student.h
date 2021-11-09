//
// Created by Jetanat Sihanatkathakul on 9/11/2021 AD.
//

#ifndef STUDENT_DATABASE_MANAGEMENT_STUDENT_H
#define STUDENT_DATABASE_MANAGEMENT_STUDENT_H

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

Node* findStudent(int, Node*);
Node* findDeleteStudent(int, Node*);
Node* readFile(FILE*, Node*);
void saveFile(FILE*, Node*);
int getint(void);
enum gender getgender(void);
void getstring(char*, int);
void view(Node*);
Node* create(Node*, Node*);
void delete(Node**, Node**);
void edit(Node*);
void outputCSV(FILE*, Node*);
#endif //STUDENT_DATABASE_MANAGEMENT_STUDENT_H
