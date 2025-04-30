/*  Program by Jessa K. West
    Auction Processor Program: Client Code
    
    Concepts: OOP modular design with encapsulation, inheritance / polymorphism, and custom linked list implementation of the stack data structure; used pointers for memory management and file I/O processing
*/ 

#include "LinkedStack.h"
#include "Bidders.hpp"
#include "Bids.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

void populateBidderInfo(std::vector<Bidders>& biddersList);
void loadAuctionFile(LinkedStack<Bids>& bidInfo);
Bidders getWinnersInfo(LinkedStack<Bids>& bidInfo, std::vector<Bidders>&biddersList);

int main() {
    std::cout << "\nAuction Processor Program by Jessa K. West\n";

    std::vector<Bidders> biddersList;
    populateBidderInfo(biddersList);

    LinkedStack<Bids> bidInfo;
    Bids placeholder("item0", 0, 0);
    bidInfo.push(placeholder);
    loadAuctionFile(bidInfo);

    Bidders winner = getWinnersInfo(bidInfo, biddersList);
    std::cout << "\nWinner of the " << bidInfo.peek().getItemName() << " item is " << winner.getName() << "(Badge # " << winner.getBadge() << ") with the winning bid of $" << bidInfo.peek().getBid() << ". " << std::endl;

    std::cout << "\nEnd of Program.";
}

void populateBidderInfo(std::vector<Bidders>& biddersList) {
    biddersList = { Bidders("Emily Davis", 110),
                    Bidders("Rebecca Brown", 117),
                    Bidders("Lucy Lowe", 212),
                    Bidders("Emma Wilson", 215),
                    Bidders("Sarah Johnson", 221), 
                    Bidders("Allison Smith", 305),
                    Bidders("Sophia Thomas", 312),
                    Bidders("Olivia Taylor", 322), 
    };
}

void loadAuctionFile(LinkedStack<Bids>& bidInfo) {
    std::ifstream auctionFile("auctionItems.txt");
    std::string line;

    if (auctionFile) {
        while (std::getline(auctionFile, line)) {
            std::istringstream iss(line);

            //temp variables
            std::string item;
            int badge, bid;

            iss >> item >> badge >> bid;
            Bids bidToProcess(item, badge, bid);

            if(bidToProcess.getBid() > bidInfo.peek().getBid()){
                bidInfo.push(bidToProcess);
            }

        }
    }
    auctionFile.close();
    std::cout << "\nThe auction file for item " << bidInfo.peek().getItemName() << " has been processed.\n";
}

Bidders getWinnersInfo(LinkedStack<Bids>& bidInfo, std::vector<Bidders>&biddersList) {
    Bidders winner;
    
    Bids winningBid = bidInfo.peek();
    int winningBadge = winningBid.getBadge();

    for (const auto& bidder : biddersList) {
        if (bidder.getBadge() == winningBadge) {
            winner = bidder;
        }
    }

    return winner;
}