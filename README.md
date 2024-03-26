# Student Record Management System

This is a simple C++ program that implements a Student Record Management System using a singly linked list. It allows you to create, delete, search, and view student records. The program provides a menu-based interface to interact with the records.

## Class Definition

``` c++
class node {
public:
    int studentId;
    string name;
    string grade;
    node* next;
};
```

This class defines a node that represents a single student record. It contains three fields: `studentId` (for the unique identifier of the student), `name` (for the student's name), grade (for the student's grade), and a `next` pointer to the next node in the linked list.

## Function Definitions

```c++
bool check(int x);
```

This function checks whether a record with the given `studentId` already exists in the linked list or not. If a record with the same `studentId` is found, it returns true; otherwise, it returns `false`.

```c++
void insertRecord(int studentId, string name, string grade);
```
