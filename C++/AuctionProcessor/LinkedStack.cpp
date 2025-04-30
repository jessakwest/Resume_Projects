/*  Program by Jessa K. West
    Auction Processor Program: Linked Stack Implementation Code
    
    Concepts: OOP modular design with encapsulation, inheritance / polymorphism, and custom linked list implementation of the stack data structure; used pointers for memory management and file I/O processing
*/ 


#include "LinkedStack.h"
#include <cassert> 

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& stack) {
    Node<ItemType>* oldPtr = stack.topPtr;

    if (oldPtr == nullptr)
        topPtr = nullptr;
    else {
        topPtr = new Node<ItemType>();
        topPtr->setItem(oldPtr->getItem());

        Node<ItemType>* newPtr = topPtr;
        oldPtr = oldPtr->getNext();

        while(oldPtr) {
            ItemType nextItem = oldPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newPtr->setNext(newNodePtr);
            newPtr = newPtr->getNext();
            oldPtr = oldPtr->getNext();
        }
        newPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack () {
    while (!isEmpty())
        pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const noexcept {
    return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    bool success = false;

    if(!isEmpty()) {
        Node<ItemType>* deletePtr = topPtr;
        topPtr = topPtr->getNext();

        deletePtr->setNext(nullptr);
        delete deletePtr;
        deletePtr = nullptr;
        
        success = true;
    }
    return success;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    assert(!isEmpty());  // Enforce precondition during debugging
    return topPtr->getItem();
}