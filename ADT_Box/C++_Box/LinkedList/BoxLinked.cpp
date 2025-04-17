/*  Program by Jessa K. West
    ADT Box Progrma: Box Linked List Implementation File
    
    Concepts: abstraction, encapsulation, polymorphism through data type templates and interfaces,
    data structures (arrays, linked lists) and algorithms (bubble sort, merge sort, binary search)
*/ 

#include "BoxLinked.h"
#include <iostream>
#include <cstddef>
#include <string>

template<class value_type>
BoxLinked<value_type>::BoxLinked(): headptr(nullptr), itemCount (0) {}

template<class value_type>
int BoxLinked<value_type>::getSize() const { return itemCount; }

template<class value_type>
bool BoxLinked<value_type>::isEmpty() const { return headptr == nullptr; }

template<class value_type>
bool BoxLinked<value_type>::add(const value_type& newValue) {
    //By default, adds to beginning of linked list
    //Creates new node pointing to head ptr, then update head ptr to point to the new node before deleting the temp ptr that pointed to the new node
    Node<value_type>* newNode = new Node<value_type>(newValue, headptr);
    headptr = newNode;
    newNode = nullptr;
    return true;
}

template<class value_type>
bool BoxLinked<value_type>::remove(const value_type& value) {
    //if empty, return false
    if (!headptr) { return false; }

    Node<value_type>* currentptr = headptr;
    Node<value_type>* previousptr = nullptr;

    while (currentptr) {
        //if value found, reassigning pointers
        if(currentptr->getItem() == value) {
            if(previousptr == nullptr) {
                headptr = currentptr->getNext();
            }
            else {
                previousptr->setNext(currentptr->getNext());
            }
            delete currentptr;
            itemCount --;
            return true;
        }
        previousptr = currentptr;
        currentptr = currentptr->getNext();
    }
    return false;
}

template<class value_type>
void BoxLinked<value_type>::clear() {
    while (headptr != nullptr) {
        Node<value_type>* temp_ptr = headptr;
        headptr = headptr->getNext();
        delete temp_ptr;
    }
    itemCount = 0;
}

template<class value_type>
int BoxLinked<value_type>::getFrequency(const value_type& value) const {
    int frequency = 0;
    Node<value_type>* currentptr = headptr;

    while(currentptr) {
        if (currentptr->getItem() == value) {
            frequency++;
        }
        currentptr = currentptr->getNext();
    }
    return frequency;
}

template<class value_type>
bool BoxLinked<value_type>::contains(const value_type& value) const {
    bool found = false;
    Node<value_type>* currentptr = headptr;

    while(currentptr) {
        if (currentptr->getItem() == value) {
            found = true;
        }
        currentptr = currentptr->getNext();
    }
    return found;
}

template<class value_type>
bool BoxLinked<value_type>::sortBox() {
    //ADD SORTING TYPE ALGORITHMS
    return false;
}

template<class value_type>
int BoxLinked<value_type>::binarySearch(const value_type& value) {
    //ADD RECURSIVE BINARY SEARCH
    return -1;
}

template<class value_type>
std::vector<value_type> BoxLinked<value_type>::toVector() const {
    std::vector<value_type> boxElements;
    Node<value_type>* currentptr = headptr;
    while (currentptr) {
        boxElements.push_back(currentptr->getItem());
        currentptr = currentptr->getNext();
    }
    return boxElements;
}

template<class value_type>
BoxLinked<value_type>::~BoxLinked() { clear(); }