/*  Program by Jessa K. West
    Payroll Processor Program: Client Code
    
    Concepts:  designed using object-oriented principles; employed vectors for data storage and 
    file I/O techniques to generate readable reports and process data from input text files
*/ 

#include "Employee.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>


void loadEmployeeSheet(std::vector<Employee>& employeeInfo, int& employeeCount);
void loadHoursSheet(std::vector<Employee>& employeeInfo);
void processPayroll(std::vector<Employee>& employeeInfo, int& employeeCount);



int main() {
    std::cout << "\nPayroll Processor Program by Jessa K. West\n\n";

    //Vector to hold the EmployeeInfo
    std::vector<Employee> employeeInfo;
    int employeeCount = 0;


    std::cout << "Uploading Employee Info...";
    loadEmployeeSheet(employeeInfo, employeeCount);
    std::cout << "Loading Complete.\n";

    std::cout << "Uploading This Week's Hours...";
    loadHoursSheet(employeeInfo);
    std::cout << "Loading Complete.\n";

    std::cout << "Processing Payroll Report...";
    processPayroll(employeeInfo, employeeCount);
    std::cout << "Report Completed & Exported.\n\n";

    std::cout << "End of Program.\n";
} // end main()

void loadEmployeeSheet(std::vector<Employee>& employeeInfo, int& employeeCount) {
    std::ifstream employeeFile("EmployeeInfo.txt");
    std::string line;
    
    if (employeeFile) {
        while (std::getline(employeeFile, line)) {
            std::istringstream iss(line);

            //temp varaibles
            int id, dependents;
            char type;
            std::string firstName, lastName;
            float rate;

            iss >> id >> firstName >> lastName >> rate >> dependents >> type;
            std::string fullName = firstName + " " + lastName;
            
            Employee employeeToAdd(id, fullName, type, rate, dependents, 0.0);
            employeeInfo.push_back(employeeToAdd);
            employeeCount++;
        }
    }
    else {
        std::cout << "File could not be found or could not be opened.'\n\n";
    }

    employeeFile.close();
} // end loadEmployeeSheet()

void loadHoursSheet(std::vector<Employee>& employeeInfo) {
    std::ifstream hoursFile("EmployeeHours.txt");
    int id;
    float hours;

    if (hoursFile) {
        while (hoursFile >> id >> hours) {
            for (auto& employee : employeeInfo) {
                if (employee.getID() == id) {
                    employee.setHours(hours);
                    employee.calculateGrossPay();
                    employee.calculateTaxTotal();
                    employee.calculateInsuranceTotal();
                    employee.calculateNetPay();
                }
            }
        }
    }
    else {
        std::cout << "File could not be found or could not be opened.'\n\n";
    }

} // end loadHoursSheet()

void processPayroll(std::vector<Employee>& employeeInfo, int& employeeCount) {
    //calculate total gross pay & net pay
    float totalGross, totalNet = 0.0;

    for (auto& employee : employeeInfo) {
        totalGross += employee.getGrossPay();
        totalNet += employee.getNetPay();
    }

    std::ofstream reportFile("PayrollReport.txt");
    reportFile << std::fixed << std::setprecision(2);
    reportFile.imbue(std::locale("en_US.UTF-8"));
    
    reportFile << "\t \t \t \t Payroll Report" << "\n";
    reportFile << "--------------------------------------------------------------------" << "\n";

    //column headers for report file
    reportFile << std::left << std::setw(5) << "ID" << std::left << std::setw(19) << "Name" << std::left << std::setw(10) 
    << "Tax" << std::left << std::setw(12) << "Insurance" << std::left << std::setw(12) << "Gross Pay" << std::left 
    << std::setw(10) << "Net Pay" << "\n";
    reportFile << "--------------------------------------------------------------------" << "\n";
    
    for (auto& employee : employeeInfo) {
        reportFile << std::left << std::setw(4) << employee.getID() 
                   << std::left << std::setw(20) << employee.getName()
                   << std::left << std::setw(10) << employee.getTaxTotal()
                   << std::left << std::setw(12) << employee.getInsuranceTotal()
                   << std::left << std::setw(12) << employee.getGrossPay() 
                   << std::left << std::setw(10) << employee.getNetPay() << "\n";
    } 
    reportFile << "--------------------------------------------------------------------" << "\n";
    reportFile << "Total Employees: " << employeeCount << "\n";
    reportFile << "Total Gross Pay: $" << totalGross << "\n";
    reportFile << "Total Net Pay: $" << totalNet << "\n";

    reportFile.close();
}
