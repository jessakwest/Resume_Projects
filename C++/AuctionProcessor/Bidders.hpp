/*  Program by Jessa K. West
    Auction Processor Program: Bidders Class
    
    Concepts: OOP modular design with encapsulation, inheritance / polymorphism, and custom linked list implementation of the stack data structure; used pointers for memory management and file I/O processing
*/ 

#ifndef BIDDERS_
#define BIDDERS_
#include <string>

class Bidders {
    private:
        std::string name;
        int badge;
    
    public:
        Bidders() : name(""), badge(0) {}
        Bidders(std::string biddersName, int badgeNumber) : name(biddersName), badge(badgeNumber) {}

        void setName(std::string biddersName) { name = biddersName; }
        void setBadge(int badgeNumber) { badge = badgeNumber; }
        std::string getName() const { return name; }
        int getBadge() const { return badge; }
};

#endif