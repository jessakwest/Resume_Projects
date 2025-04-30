/*  Program by Jessa K. West
    Auction Processor Program: Node Header & Implementation File

    Concepts: OOP modular design with encapsulation, inheritance / polymorphism, and custom linked list implementation of the stack data structure; used pointers for memory management and file I/O processing
*/ 

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node {
    private:
        ItemType item;
        Node<ItemType>* next;
    
    public:
        Node() : next(nullptr) {}
        Node(const ItemType& newItem) : item(newItem), next(nullptr) {}
        Node(const ItemType& newItem, Node<ItemType>* nextptr) : item(newItem), next(nextptr) {}

        void setItem(const ItemType& newItem) { item = newItem; }
        void setNext(Node<ItemType>* nextptr) { next = nextptr; }

        ItemType getItem() const { return item; }
        Node<ItemType>* getNext() const { return next; }
};

#endif