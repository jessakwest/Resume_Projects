/*  Program by Jessa K. West
    ADT Box Program: Node Header & Implementation File
    
    Concepts: abstraction, encapsulation, polymorphism through data type templates and interfaces,
    data structures (dynamic arrays, linked lists) and algorithms (bubble sort, merge sort, binary search)
*/ 

#ifndef NODE_
#define NODE_

template<class value_type>
class Node {
    private:
        value_type data;
        Node<value_type> * next;

    public:
        Node() : data(), next(nullptr) {}
        Node(const value_type& value) : data(value), next(nullptr) {}
        Node(const value_type& value, Node<value_type>* nextptr) : data(value), next(nextptr) {}
        void setItem(const value_type& value) { data = value; }
        void setNext(Node<value_type>* nextptr) {next = nextptr; }
        value_type getItem() const { return data; }
        Node<value_type>* getNext() const  { return next; }
        ~Node() { }
};
#endif
