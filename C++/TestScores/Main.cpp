/*  Program by Jessa K. West
    Test Score Program: Main / Client Code
    
    Concepts: OOP principles of encapsulation; leverages vectors for dynamic data management
*/

#include "Class.hpp"
#include <iomanip>


int main() {
    //format numbers throughout program
    std::cout << std::fixed << std::setprecision(2);

    std::vector<Student> students = {
        Student("Anna", 90, 72, 85),
        Student("Bobby", 60, 78, 82),
        Student("Cathy", 95, 90, 92),
        Student("Dave", 60, 70, 80)
    };

    Class classInfo(students.size());

    for (const auto& student : students) {
        classInfo.updateGradeDistribution(student.letterGrade);
    }

    classInfo.calculateClassAverage(students);

    for(const auto& student: students) {
        student.display();
    }

    classInfo.displaySummay();
}
