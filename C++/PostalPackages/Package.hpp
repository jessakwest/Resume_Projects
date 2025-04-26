/*  Program by Jessa K. West
    Postal Package Program: Package Header & Implementation Code
    
     Concepts: OOP design using encapsulation of custom classes & structs; applied Standard Library Utilties (vector, iomanip); user interaction & data validation
*/

#ifndef PACKAGE_
#define PACKAGE_
#include <string>

class Package {
    private:
        int weight, length, height, width, largestSide, girth;
        bool status; //true if approved, false if rejected

        void findLargestSide() { largestSide = std::max({height, length, width}); }
        void calculateGirth() { girth = 2 * (height + length + width - largestSide); }
        void checkStatus() { //bool status: true if approved, false if rejected
            status = (weight <= 50 && length <= 72 && height <= 72 && width <= 72 && girth <= 120);
        }
    public:
        Package() {}
        void process(int packageWeight, int packageLength, int packageHeight, int packageWidth) {
            weight =  packageWeight;
            length = packageLength;
            height = packageHeight;
            width = packageWidth;
            findLargestSide();
            calculateGirth();
            checkStatus();
        }
        bool getStatus() { return status; }
        int getWeight() { return weight; }
};
#endif