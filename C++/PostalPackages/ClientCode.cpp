/*  Program by Jessa K. West
    Postal Package Program: Client Code
    
     Concepts: OOP design using encapsulation of custom classes & structs; applied Standard Library Utilties (vector, iomanip); user interaction & data validation
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include "ShippingFees.hpp"
#include "Package.hpp"
#include "Destination.hpp"

void packageMenu(ShippingFeeTable feeTable);
void processPackage(std::string location, float serviceFee, ShippingFeeTable& feeTable, int& transactionCount, int& countAccepted, int& countRejected, float& totalCost);
void getPackageInfo(Package& newPackage, int& countAccepted, int& countRejected);
void calculateCost(ShippingFeeTable& feeTable, Package& newPackage, float& packageCost, float& totalCost);
void displayTransactionInfo(Package& newPackage, std::string& location, float& packageCost, int& transactionCount);
void displaySummary(int& countAccepted, int& countRejected, float& totalCost);

int main() {
    std::cout << "\nPostal Package Program by Jessa K. West\n\n";
    
    //format numbers throughout program
    std::cout << std::fixed << std::setprecision(2);

    ShippingFeeTable feeTable;
    packageMenu(feeTable);

    std::cout << std::endl << "End of Program." << std::endl;
}

void packageMenu(ShippingFeeTable feeTable) {
    char cmd;
    float totalCost = 0.0;
    int transactionCount = 1;
    int countAccepted = 0;
    int countRejected = 0;

    while(true && cmd != 'X') {
        std::cout << "Enter Package Destination for Package #" << transactionCount << "\nT(exas), O(ut of State), I(nternational), S to Display Shipping Fee Table, or X to Exit: ";
        std::cin >> cmd;

        if (std::toupper(cmd) == 'S') {
            feeTable.displayFeeTable();
            continue;
        }

        Destination destination = getDestinationFromInput(cmd);

        switch(destination) {
            case Destination::Texas:
                processPackage("Texas", 0.0f, feeTable, transactionCount, countAccepted, countRejected, totalCost);
                break;
            case Destination::OutOfState:
                processPackage("Out of State", 35.0f, feeTable, transactionCount, countAccepted, countRejected, totalCost);
                break;
            case Destination::International:
                processPackage("International", 50.0f, feeTable, transactionCount, countAccepted, countRejected, totalCost);
                break;
            case Destination::Exit:
                displaySummary(countAccepted, countRejected, totalCost);
                return;
        }
    }
}

void processPackage(std::string location, float serviceFee, ShippingFeeTable& feeTable, int& transactionCount, int& countAccepted, int& countRejected, float& totalCost) {
    Package newPackage;
    float packageCost = serviceFee; //initiate with the service fee

    getPackageInfo(newPackage, countAccepted, countRejected);
    calculateCost(feeTable, newPackage, packageCost, totalCost);
    displayTransactionInfo(newPackage, location, packageCost, transactionCount);
    transactionCount++;
}

void getPackageInfo(Package& newPackage, int& countAccepted, int& countRejected) {
    float packageWeight, packageLength, packageWidth, packageHeight = 0.0;

    std::cout << std::endl << "Use pounds & inches measurements for package dimmensions below." << std::endl;

    std::cout << "Weight: ";
    std::cin >> packageWeight;
    std::cout << "Length: ";
    std::cin >> packageLength;
    std::cout << "Width: ";
    std::cin >> packageWidth;
    std::cout << "Height: ";
    std::cin >> packageHeight;

    newPackage.process(packageWeight, packageLength, packageHeight, packageWidth);

    //check if package meets requirements
    if (newPackage.getStatus())
        countAccepted++;
    else
        countRejected++;
}

void calculateCost(ShippingFeeTable& feeTable, Package& newPackage, float& packageCost, float& totalCost) {
    //add shipping fee based on table
    if (newPackage.getStatus()) {
        packageCost += feeTable.getFeeForWeight(newPackage.getWeight());
    }
    else { 
        packageCost = 0.0;
    }
    totalCost += packageCost;
}

void displayTransactionInfo(Package& newPackage, std::string& location, float& packageCost, int& transactionCount) {
    std::cout << std::endl << "Transation #" << transactionCount << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << std::left << std::setw(10) << "Location: " << std::left << std::setw(10) << location << std::endl;
    std::cout << std::left << std::setw(10) << "Status: " << std::left << std::setw(10) << newPackage.getStatus() << std::endl;
    std::cout << std::left << std::setw(10) << "Weight: " << std::left << newPackage.getWeight() << " pound(s)" << std::endl;

    if (packageCost > 0.0)
        std::cout << std::left << std::setw(10) << "Cost:" << std::left << "$" << packageCost << std::endl << std::endl;
    else
        std::cout << std::left << std::setw(10) << "Cost:" << std::left << "N/A" << std::endl << std::endl;
}

void displaySummary(int& countAccepted, int& countRejected, float& totalCost) {
    std::cout << std::endl << "Shipping Summary" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << std::left << std::setw(10) << "Number of accepted packages: " << std::left << std::setw(30) << countAccepted << std::endl;
    std::cout << std::left << std::setw(10) << "Number of rejected packages: " << std::left << std::setw(30) << countRejected << std::endl;

    if (totalCost > 0.0)
        std::cout << std::left << std::setw(29) << "Total shipping cost:" << std::left << "$" << totalCost << std::endl;
    else
        std::cout << std::left << std::setw(29) << "Cost:" << std::left << "N/A" << std::endl;
}