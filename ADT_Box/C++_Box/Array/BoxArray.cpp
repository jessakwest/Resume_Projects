/*  Program by Jessa K. West
    ADT Box Progrma: Box Array Implementation File
    
    Concepts: abstraction, encapsulation, polymorphism through data type templates and interfaces,
    data structures (arrays, linked lists) and algorithms (bubble sort, merge sort, binary search)
*/ 

#include "BoxArray.h"
#include <iostream>
#include <cstddef>
#include <string>

template<class value_type>
BoxArray<value_type>::BoxArray(): itemCount(0), capacity(DEFAULT_SIZE) { 
    items = new value_type[capacity];
}

template<class value_type>
int BoxArray<value_type>::getSize() const { return itemCount; }

template<class value_type>
bool BoxArray<value_type>::isEmpty() const { return itemCount == 0; }

template<class value_type>
bool BoxArray<value_type>::add(const value_type& new_value) {
    //if array needs to be resized
    if (!itemCount < capacity)
        resize();

    items[itemCount] = new_value;
    itemCount++;
    return true; 
}

template<class value_type>
bool BoxArray<value_type>::remove(const value_type& value) {
    int locatedIndex = getIndex(value);
    bool removable = !isEmpty() && (locatedIndex > -1);

    if(removable) {
        for (int i = locatedIndex; i < itemCount - 1; ++i) {
            items[i] = items[i+1];
        }
        itemCount--;
    }
    return removable;
}

template<class value_type>
void BoxArray<value_type>::clear() {
    //reset item count, capacity, and items[]
    itemCount = 0;
    capacity = DEFAULT_SIZE;
    items = new value_type[capacity];
}

template<class value_type>
int BoxArray<value_type>::getFrequency(const value_type& value) const {
    int frequency = 0;
    int currentIndex = 0;
    while (currentIndex < itemCount) {
        if(items[currentIndex] == value) {
            frequency++;
        }
        currentIndex++;
    }
    return frequency;
}

template<class value_type>
bool BoxArray<value_type>::contains(const value_type& value) const {
    return getIndex(value) > -1;
}

template<class value_type>
bool BoxArray<value_type>::sortBox() {
    //ADD SORTING TYPE ALGORITHMS
    return false;
}

template<class value_type>
int BoxArray<value_type>::binarySearch(const value_type& value) {
    //ADD RECURSIVE BINARY SEARCH
    return -1;
}

template<class value_type>
std::vector<value_type> BoxArray<value_type>::toVector() const {
    std::vector<value_type> boxElements;

    for (int i = 0; i < itemCount; i++)
        boxElements.push_back(items[i]);

    return boxElements;
}

template<class value_type>
int BoxArray<value_type>::getIndex(const value_type& target) const {
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    //while not found & index wihtin bounds
    while (!found && (searchIndex < itemCount)) {
        if(items[searchIndex] == target) {
            found = true;
            result = searchIndex;
        }
        else { 
            searchIndex++;
        }
    }
    return result;
}

template<class value_type>
void BoxArray<value_type>::recursiveHelper(int first, int last, const value_type& target, int& index) {
    //ADD RECURSIVE HELPER
}

template<class value_type>
void BoxArray<value_type>::resize() {
    int newCapacity = capacity * 2;
    value_type* newItems = new value_type[newCapacity];

    for (int i = 0; i < itemCount; i++)
        newItems[i] = items[i];

    delete[] items;
    items = newItems;
    capacity = newCapacity;
}

template<class value_type>
BoxArray<value_type>::~BoxArray() {
    delete [] items;
}