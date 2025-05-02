/*  Program by Jessa K. West
    Employee BST Program: Employee Class Code
    
     Concepts: Designed & implemented a generic, smart-pointer based Binary Search Tree with custom objects, operator overloading, and recursive algorithms
*/

#ifndef EMPLOYEE_
#define EMPLOYEE_

#include <string>

class Employee {
    private:
        std::string name;
        int id;
    public:
        Employee() : name(""), id(0) {}
        Employee(std::string n, int i) : name(n), id(i) {}
        void setName(std::string n) { name = n; }
        std::string getName() const { return name; }
        void setID(int i) { id = i; }
        int getID() const { return id; }

        //overload operators
        bool operator < (const Employee& other) const {
            return id < other.id;
        }
        bool operator > (const Employee& other) const {
            return id > other.id;
        }
        bool operator == (const Employee& other) const {
            return id == other.id;
        }
};
#endif