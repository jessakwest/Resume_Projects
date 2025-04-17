/*  Program by Jessa K. West
    ADT Box Program: Box Linked List Header File
    
    Concepts: abstraction, encapsulation, polymorphism through data type templates and interfaces,
    data structures (dynamic arrays, linked lists) and algorithms (bubble sort, merge sort, binary search)
*/ 

#ifndef BOX_LINKED_
#define BOX_LINKED_
#include "../BoxInterface.h"
#include "Node.hpp"
#include <vector>

template<class value_type>
class BoxLinked : public BoxInterface<value_type> {
    
private:
    //Private Variables
    Node<value_type>* headptr;
    int itemCount;

public:
    //Constructor & Destructor
    BoxLinked();
    ~BoxLinked();

    //Interface Methods
    int getSize() const;
    bool isEmpty() const;
    bool add(const value_type& newValue);
    bool remove(const value_type& value);
    void clear();
    int getFrequency(const value_type& value) const;
    bool contains(const value_type& value) const;
    
    bool sortBox();
    int binarySearch(const value_type& value);
    std::vector<value_type> toVector() const;    
};

#include "BoxLinked.cpp"
#endif