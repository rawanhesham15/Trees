#ifndef DATASTRUCTURES_BST_H
#define DATASTRUCTURES_BST_H

#include <bits/stdc++.h>

#include "node.cpp"
#include "Student.cpp"

using namespace std;

class BST
{
private:
    vector<Student> myStudents;
    map<string, int> departments;

public:
    // pointer refers to the first element in the tree.
    node *root;

    // default constructor.
    BST(vector<Student> students);

    // returns pointer to the last node, because we do not need to start from root each time.
    node *insertNode(node *r, int item);

    void insertNode(int item);

    // print pre-order: root - left - right.
    void printTreePre(node *r);

    // find max element in tree.
    node *findMax(node *r);

    node *deleteNode(node *r, int key);

    void deleteStudent(int id);

    node *search(node *r, int key);

    bool search(int key);

    void addStudent();

    // Stores inorder traversal of the BST
    void storeSorted(node *root, int arr[], int &i);

    // This function sorts arr[0..n-1] using Tree Sort by id
    void treeSort();

    void printDepartments();

    void addDepartment(string dep);

    void removeStudent();

    void print(int id);
};

#endif // DATASTRUCTURES_BST_H
