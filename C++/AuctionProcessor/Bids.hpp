/*  Program by Jessa K. West
    Auction Processor Program: Bids Class Code
    
    Concepts: OOP modular design with encapsulation, inheritance / polymorphism, and custom linked list implementation of the stack data structure; used pointers for memory management and file I/O processing
*/ 


#ifndef BIDS_
#define BIDS_
#include <string>

class Bids {
    private:
        std::string item;
        int bidAmount;
        int badgeNumber;
    
    public:
        Bids(std::string name, int badge, int bid) : item(name), badgeNumber(badge), bidAmount(bid) {}

        //Getters
        std::string getItemName() { return item; }
        int getBadge() { return badgeNumber; }
        int getBid() { return bidAmount; }
};

#endif