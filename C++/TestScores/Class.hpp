/*  Program by Jessa K. West
    Test Score Program: Class Student header & implementation code
    
    Concepts: OOP principles of encapsulation; leverages vectors for dynamic data management
*/ 

#include "Student.hpp"
#include <vector>

class Class {
    private:
        int classSize;
        float classAverage;
        int totalA, totalB, totalC, totalD, totalF;

    public:
        Class(int count) : classSize(count), totalA(0), totalB(0), totalC(0), totalD(0), totalF(0) {}

        void updateGradeDistribution(char grade) {
            switch(grade) {
                case 'A': totalA++; break;
                case 'B': totalB++; break;
                case 'C': totalC++; break;
                case 'D': totalD++; break;
                case 'F': totalF++; break;
                default: break;
            }
        }

        void calculateClassAverage(const std::vector<Student>& students) {
            float totalScore = 0.0f;

            for(const auto& student : students){
                totalScore += student.testAverage;
            }

            classAverage = totalScore / classSize;
        }

        void displaySummay() const {
            std::cout << std::endl << "Class Size: " << classSize << std::endl;
            std::cout << "Class Average: " << classAverage << std::endl;
            std::cout << "Number of A's: " << totalA << std::endl;
            std::cout << "Number of B's: " << totalB << std::endl;
            std::cout << "Number of C's: " << totalC << std::endl;
            std::cout << "Number of D's: " << totalD << std::endl;
            std::cout << "Number of F's: " << totalF << std::endl << std::endl;
        }
};