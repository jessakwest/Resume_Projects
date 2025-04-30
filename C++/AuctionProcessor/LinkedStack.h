/*  Program by Jessa K. West
    Auction Processor Program: LinkedStack Header File

    Concepts: OOP modular design with encapsulation, inheritance / polymorphism, and custom linked list implementation of the stack data structure; used pointers for memory management and file I/O processing
*/ 

#ifndef LINKED_STACK_
#define LINKED_STACK_
#include "StackInterface.h"
#include "Node.hpp"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
    private:
        Node<ItemType>* topPtr;

    public:
        LinkedStack();
        LinkedStack(const LinkedStack<ItemType>& stack);
        virtual ~LinkedStack();

        //Stack Interface Operations
        bool isEmpty() const noexcept;
        bool push(const ItemType& newItem);
        bool pop();
        ItemType peek() const;
};

#include "LinkedStack.cpp"
#endifs