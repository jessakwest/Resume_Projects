/*  Program by Jessa K. West
    Payroll Processor Program: Class Employee Header File
    
    Concepts:  designed using object-oriented principles; employed maps for data storage and 
    file I/O techniques to generate readable reports and process data from input text files
*/ 

#ifndef EMPLOYEE_
#define EMPLOYEE_

#include <string>
#include <cstring>

class Employee {
    private:
        //Employee Memeber Variables
        int employeeID;
        std::string employeeName;
        char employeeType;
        float payRate;
        int numOfDependents;

        float hoursWorked;

        float taxTotal;
        float insuranceTotal;
        float grossPay;
        float netPay;

    public:
        Employee();
        Employee(int id, std::string name, char type, float rate, int dependents, float hours);
        
        //setters
        bool setHours(float hours);
        
        //getters for member variables
        int getID();
        std::string getName();
        int getType();
        float getRate();
        int getDependents();
        float getHours();

        //getters for pay variables
        float getTaxTotal();
        float getInsuranceTotal();
        float getGrossPay();
        float getNetPay();

        //cacluating mehtods
        float calculateTaxTotal();
        float calculateInsuranceTotal();
        float calculateGrossPay();
        float calculateNetPay();        
};

Employee::Employee()
    : employeeID(0), employeeName(""), payRate(0.0), numOfDependents(0), hoursWorked(0.0) {}

Employee::Employee(int id, std::string name, char type, float rate, int dependents, float hours)
    : employeeID(id), employeeName(name), payRate(rate), numOfDependents(dependents), hoursWorked(hours) {}

bool Employee::setHours(float hours) { 
    hoursWorked = hours;
    return true;
}

int Employee::getID() {return employeeID; }
std::string Employee::getName() {return employeeName; }
int Employee::getType() {return employeeType; }
float Employee::getRate() {return payRate; }
int Employee::getDependents() {return numOfDependents; }
float Employee::getHours() {return hoursWorked; }
float Employee::getTaxTotal() { return taxTotal; }
float Employee::getInsuranceTotal()  {return insuranceTotal; }
float Employee::getGrossPay() { return grossPay; }
float Employee::getNetPay() { return netPay; }

float Employee::calculateTaxTotal() {
    taxTotal = grossPay * 0.15;
    return taxTotal;
}

float Employee::calculateInsuranceTotal() {
    insuranceTotal = numOfDependents * 30.0;
    return insuranceTotal;
}

float Employee::calculateGrossPay() {
    float overtimeHours;
    float overtimePay;

    if (employeeType == 0 && hoursWorked > 40.0) {
        overtimeHours = (hoursWorked - 40.0);
        overtimePay = (1.5 * payRate);
        grossPay = (40.0 * payRate) + (overtimeHours * overtimePay);
    }
    else {
        grossPay = (hoursWorked * payRate);
    }
    return grossPay;
}

float Employee::calculateNetPay() {
    netPay = grossPay - taxTotal - insuranceTotal;
    return netPay;
}

#endif