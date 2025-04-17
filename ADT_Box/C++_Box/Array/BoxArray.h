/*  Program by Jessa K. West
    ADT Box Program: Box Array Header File
    
    Concepts: abstraction, encapsulation, polymorphism through data type templates and interfaces,
    data structures (dynamic arrays, linked lists) and algorithms (bubble sort, merge sort, binary search)
*/ 

#ifndef BOX_ARRAY_
#define BOX_ARRAY_
#include <vector>
#include "../BoxInterface.h"

template<class value_type>
class BoxArray : public BoxInterface<value_type> {
    
private:
    //Private Variables
    static const int DEFAULT_SIZE = 30;
    value_type* items;
    int capacity;
    int itemCount;
    static const int first = 0;

    //Private Helper Methods
    int getIndex(const value_type& target) const;
    void recursiveHelper(int first, int last, const value_type& target, int& index);
    void resize();

public:
    //Constructor & Destructor
    BoxArray();
    ~BoxArray();

    //Interface Methods
    int getSize() const;
    bool isEmpty() const;
    bool add(const value_type& new_value);
    bool remove(const value_type& value);
    void clear();
    int getFrequency(const value_type& value) const;
    bool contains(const value_type& value) const;
    
    bool sortBox();
    int binarySearch(const value_type& value);
    std::vector<value_type> toVector() const;    
};

#include "BoxArray.cpp"
#endif
