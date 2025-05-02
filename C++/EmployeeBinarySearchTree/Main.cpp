/*  Program by Jessa K. West
    Employee BST Program: Main / Client Code
    
     Concepts: Designed & implemented a generic, smart-pointer based Binary Search Tree with custom objects, operator overloading, and recursive algorithms
*/

#include "BinaryTree.h"
#include "Employee.hpp"
#include <iostream>
#include <string>

void populateEmployeeTree(BinaryTree<Employee>& employeeTree);
void displayEmployees(BinaryTree<Employee> employeeTree);
void findEmployee(BinaryTree<Employee> employeeTree);
void getEmployeeName(BinaryTree<Employee> employeeTree);

int main() {
    std::cout << "\nEmployee Binary Search Tree Program by Jessa K. West\n----\n";

    BinaryTree<Employee> employeeTree;
    populateEmployeeTree(employeeTree);
    displayEmployees(employeeTree);
    findEmployee(employeeTree);
    getEmployeeName(employeeTree);

    std::cout << "End of Program.\n";
}

void populateEmployeeTree(BinaryTree<Employee>& employeeTree) {
    employeeTree.add(Employee("Emily Davis", 110));
    employeeTree.add(Employee("Rebecca Brown", 117));
    employeeTree.add(Employee("Lucy Lowe", 212));
    employeeTree.add(Employee("Emma Wilson", 215));
    employeeTree.add(Employee("Sarah Johnson", 221));
    employeeTree.add(Employee("Allison Smith", 305));
    employeeTree.add(Employee("Sophia Thomas", 312));
    employeeTree.add(Employee("Olivia Taylor", 322));
}

void displayEmployees(BinaryTree<Employee> employeeTree) {
    std::cout << "List of Employees by ID\n----\n";
    std::vector<Employee> employees = employeeTree.display();
    for(const auto& employee : employees) {
        std::cout << "Employee " << employee.getID() << ": " << employee.getName() << std::endl;
    }
}

void findEmployee(BinaryTree<Employee> employeeTree) {
    std::cout << "----\nFind Emplyee 212 and 999\n----\n";
    std::cout << "#212: " << (employeeTree.containsID(212) ? "Found" : "Not found") << std::endl;
    std::cout << "#999: " << (employeeTree.containsID(999) ? "Found" : "Not Found") << std::endl;
}

void getEmployeeName(BinaryTree<Employee> employeeTree) {
    std::cout << "----\nEmployee 322's Name: ";
    std::cout << employeeTree.getNameFromID(322) << "\n----\n";

}

