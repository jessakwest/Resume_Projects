/*  Program by Jessa K. West
    Postal Package Program: Client Code
    
    Concepts: OOP design using encapsulation of custom classes & structs; applied Standard Library Utilties (vector, iomanip); user interaction & data validation
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include "ShippingFees.hpp"

void packageMenu(ShippingFeeTable feeTable);
void processPackage(std::string location, float serviceFee, ShippingFeeTable feeTable, int& countTransactions, int& countAccepted, int& countRejected, float& totalCost);
void getPackageInfo(int& packageWeight, std::string& packageStatus, int& countAccepted, int& countRejected);
void calculateCost(int& packageWeight, std::string packageStatus, ShippingFeeTable feeTable, float& serviceFee, float& packageCost, float& totalCost);
void displayTransactionInfo(std::string& location, int& packageWeight, std::string& packageStatus, float& packageCost, int& countTransactions);
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
    int countTransactions = 0;
    int countAccepted = 0;
    int countRejected = 0;

    while(true && cmd != 'X') {
        std::cout << "Enter Package Destination for Package #" << countTransactions + 1 << " (T(exas), O(ut of State), I(nternational), S to Display Shipping Fee Table, or X to Exit): ";
        std::cin >> cmd;
        cmd = std::toupper(cmd);

        switch(cmd) {
            case 'T':
                processPackage("Texas", 0.0f, feeTable, countTransactions, countAccepted, countRejected, totalCost);
                break;
            case 'O':
                processPackage("Out of State", 35.0f, feeTable, countTransactions, countAccepted, countRejected, totalCost);
                break;
            case 'I':
                processPackage("International", 50.0f, feeTable, countTransactions, countAccepted, countRejected, totalCost);
                break;
            case 'S':
                feeTable.displayFeeTable();
                break;
            case 'X':
                displaySummary(countAccepted, countRejected, totalCost);
                break;
            default:
                std::cout << "Invalid input. Try again" << std::endl;
                break;
        }
    }
}

void processPackage(std::string location, float serviceFee, ShippingFeeTable feeTable, int& countTransactions, int& countAccepted, int& countRejected, float& totalCost) {
    int packageWeight;
    std::string packageStatus;
    float packageCost = serviceFee; //initiate with the service fee

    countTransactions++;
    getPackageInfo(packageWeight, packageStatus, countAccepted, countRejected);
    calculateCost(packageWeight, packageStatus, feeTable, serviceFee, packageCost, totalCost);
    displayTransactionInfo(location, packageWeight, packageStatus, packageCost, countTransactions);
}

void getPackageInfo(int& packageWeight, std::string& packageStatus, int& countAccepted, int& countRejected) {
    float packageLength, packageWidth, packageHeight, largestSide, packageGirth = 0.0;

    std::cout << std::endl << "Use pounds & inches measurements for package dimmensions below." << std::endl;

    std::cout << "Weight: ";
    std::cin >> packageWeight;
    std::cout << "Length: ";
    std::cin >> packageLength;
    std::cout << "Width: ";
    std::cin >> packageWidth;
    std::cout << "Height: ";
    std::cin >> packageHeight;
    
    //Find Largest Side
    if (packageLength > packageWidth && packageLength > packageHeight)
        largestSide = packageLength;
    else if (packageHeight > packageWidth && packageHeight > packageLength)
        largestSide = packageHeight;
    else
        largestSide = packageWidth;

    //calculate package girth
    packageGirth = 2 * (packageLength + packageHeight + packageWidth - largestSide);

    //check if package meets requirements
    if (packageWeight > 50 || packageLength > 72 || packageHeight > 72 || packageWidth > 72 || packageGirth > 120) {
        packageStatus = "Rejected";
        countRejected++;
    }
    else { //package accepted
        packageStatus = "Accepted";
        countAccepted++;
    }
}

void calculateCost(int& packageWeight, std::string packageStatus, ShippingFeeTable feeTable, float& serviceFee, float& packageCost, float& totalCost) {
    //add shipping fee based on table
    if (packageStatus == "Accepted") {
        packageCost += feeTable.getFeeForWeight(packageWeight);
    }
    else { //"Rejected"
        packageCost = 0.0;
    }
    totalCost += packageCost;
}

void displayTransactionInfo(std::string& location, int& packageWeight, std::string& packageStatus, float& packageCost, int& countTransactions) {
    std::cout << std::endl << "Transation #" << countTransactions << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << std::left << std::setw(10) << "Location: " << std::left << std::setw(10) << location << std::endl;
    std::cout << std::left << std::setw(10) << "Status: " << std::left << std::setw(10) << packageStatus << std::endl;
    std::cout << std::left << std::setw(10) << "Weight: " << std::left << packageWeight << " pound(s)" << std::endl;

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

    if (totalCost > 0)
        std::cout << std::left << std::setw(29) << "Total Cost:" << std::left << "$" << totalCost << std::endl;
    else
        std::cout << std::left << std::setw(29) << "Cost:" << std::left << "N/A" << std::endl;
}