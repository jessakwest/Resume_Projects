/*  Program by Jessa K. West
    Test Score Program: Class Student header & implementation code
    
    Concepts: OOP principles of encapsulation; leverages vectors for dynamic data management
*/ 

#include <string>
#include <iostream>


class Student {
    public:
        std::string name;
        int test1, test2, test3, testAverage;
        char letterGrade;

        Student(const std::string& name, float test1, float test2, float test3) : name(name), test1(test1), test2(test2), test3(test3) {
            calculateAverage();
            assignLetterGrade();
        }
    
        void calculateAverage() {
            testAverage = (test1 + test2 + test3) / 3.0;
        }

        void assignLetterGrade() {
            if (testAverage >= 90) letterGrade = 'A';
            else if (testAverage >= 80) letterGrade = 'B';
            else if (testAverage >= 70) letterGrade = 'C';
            else if (testAverage >= 60) letterGrade = 'D';
            else letterGrade = 'F';
        }

        void display() const {
            std::cout << std::endl << "Name: " << name << std::endl;
            std::cout << "Test 1: " << test1 << std::endl;
            std::cout << "Test 2: " << test2 << std::endl;
            std::cout << "Test 3: " << test3 << std::endl;
            std::cout << "Test Average: " << testAverage << std::endl;
            std::cout << "Letter Grade: " << letterGrade << std::endl << std::endl;
        }
};