/*  Program by Jessa K. West
    ADT Box Program: Box Interface Header File

    Concepts: abstraction, encapsulation, polymorphism through data type templates and interfaces,
    data structures (arrays, linked lists) and algorithms (bubble sort, merge sort, recursive binary search)
*/ 

#ifndef BOX_INTERFACE
#define BOX_INTERFACE

template<class value_type>
class BoxInterface {
    public:
        virtual int getSize() const = 0;
        virtual bool isEmpty() const = 0;
        virtual bool add(const value_type& new_value) = 0;
        virtual bool remove(const value_type& value) = 0;
        virtual void clear() = 0;
        virtual int getFrequency(const value_type& value) const = 0;
        virtual bool contains(const value_type& value) const = 0;
        virtual bool sortBox() = 0;
        virtual int binarySearch(const value_type& value) = 0;
        virtual std::vector<value_type> toVector() const = 0;
        virtual ~BoxInterface() { }
};
#endif