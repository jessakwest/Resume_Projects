/*  Program by Jessa K. West
    Postal Package Program: Shipping Fees Header & Implementation Code
    
     Concepts: OOP design using encapsulation of custom classes & structs; applied Standard Library Utilties (vector, iomanip); user interaction & data validation
*/

#ifndef SHIPPING_FEES_
#define SHIPPING_FEES_

#include <vector>
#include <iostream>

struct ShippingFees {
    int weight;
    float fee;
};

class ShippingFeeTable {
    private:
        std::vector<ShippingFees> fees;
    public:
        ShippingFeeTable() : fees { {1, 1.50}, {2, 2.10}, {3, 4.00}, {5, 6.75},
                                          {7, 9.90},{10, 14.95}, {13, 19.40}, {16, 24.20}, 
                                          {20, 27.30}, {25, 31.90}, {30, 38.50}, {35, 43.50}, 
                                          {40, 44.80}, {45, 47.40}, {50, 55.20} } { }

        float getFeeForWeight(int packageWeight) const {
            for (const auto& fee : fees) {
                if (packageWeight <= fee.weight) {
                    return fee.fee;
                }
            }
            return 0.0f;
        }

        void displayFeeTable() {
            std::cout << std::endl << "Shipping Fees Based on Weight" << std::endl;
            std::cout << "--------------------------" << std::endl;
            for (const auto& fee: fees){
                std::cout << "Weight: " << fee.weight << "\tFee: $" << fee.fee << std::endl;
            }
            std::cout << std::endl;
        }

};

#endif