#include "MaxHeap.h"
#include "Student.cpp"

#include <bits/stdc++.h>

using namespace std;

MaxHeap::MaxHeap(vector<Student> students)
{
    for (size_t i = 0; i < students.size(); i++)
    {
        insert(students[i]);
        myStudents.push_back(students[i]);
    }
}

void MaxHeap::insert(Student s)
{
    heap_.push_back(s);
    heapifyUp(heap_.size() - 1);
}

Student MaxHeap::extractMax()
{
    Student max = heap_[0];
    heap_[0] = heap_[heap_.size() - 1];
    heap_.pop_back();
    heapifyDown(0);
    return max;
}

bool MaxHeap::isEmpty() { return heap_.empty(); }

void MaxHeap::heapifyUp(int index)
{
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (heap_[index].getGpa() > heap_[parentIndex].getGpa())
        {
            std::swap(heap_[index], heap_[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

void MaxHeap::heapifyDown(int index)
{
    while (index < heap_.size())
    {
        int maxIndex = index;
        int leftChildIndex = index * 2 + 1, rightChildIndex = index * 2 + 2;
        if (leftChildIndex < heap_.size() &&
            heap_[leftChildIndex].getGpa() > heap_[maxIndex].getGpa())
        {
            maxIndex = leftChildIndex;
        }
        if (rightChildIndex < heap_.size() &&
            heap_[rightChildIndex].getGpa() > heap_[maxIndex].getGpa())
        {
            maxIndex = rightChildIndex;
        }
        if (index != maxIndex)
        {
            swap(heap_[index], heap_[maxIndex]);
            index = maxIndex;
        }
        else
        {
            break;
        }
    }
}

void MaxHeap::addStudent()
{
    Student st;
    int id;
    cout << "Enter ID: ";
    cin >> id;
    string name, dep;
    double gpa;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter GPA: ";
    cin >> gpa;
    cout << "Enter Department: ";
    cin >> dep;
    st.setId(id);
    st.setName(name);
    st.setGpa(gpa);
    st.setDepartment(dep);
    insert(st);
    cout << "The Student is Added.\n";
}

void MaxHeap::print(MaxHeap studentHeap)
{
    while (!studentHeap.isEmpty())
    {
        Student s = studentHeap.extractMax();
        cout << "[" << s.getId() << ", " << s.getName() << ", " << s.getGpa() << ", "
             << s.getDepartment() << "]\n";
    }
}

void MaxHeap::printDepartment(MaxHeap studentHeap)
{
    int cs = 0, is = 0, it = 0, ds = 0;
    while (!studentHeap.isEmpty())
    {
        Student s = studentHeap.extractMax();
        if (s.getDepartment() == "CS")
        {
            cs++;
        }
        else if (s.getDepartment() == "IS")
        {
            is++;
        }
        else if (s.getDepartment() == "IT")
        {
            it++;
        }
        else if (s.getDepartment() == "DS")
        {
            ds++;
        }
    }
    cout << "CS " << cs << " Students\n";
    cout << "IS " << is << " Students\n";
    cout << "IT " << it << " Students\n";
    cout << "DS " << ds << " Students\n";
}