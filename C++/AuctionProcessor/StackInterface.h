/*  Program by Jessa K. West
    Auction Processor Program: Stack Interface
    
        Concepts: OOP modular design with encapsulation, inheritance / polymorphism, and custom linked list implementation of the stack data structure; used pointers for memory management and file I/O processing 
*/ 

#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface {
    public:
        virtual bool isEmpty()const noexcept = 0;
        virtual bool push(const ItemType& newItem) = 0;
        virtual bool pop() = 0;
        virtual ItemType peek() const = 0;
        virtual ~StackInterface() = default;
};

#endif