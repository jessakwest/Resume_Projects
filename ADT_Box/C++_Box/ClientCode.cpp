/*  Program by Jessa K. West
    ADT Box Program: Client Code
    
    Concepts: abstraction, encapsulation, polymorphism through data type templates and interfaces,
    data structures (arrays, linked lists) and algorithms (bubble sort, merge sort, binary search)
*/ 

#include "Array/BoxArray.h"
#include "LinkedList/BoxLinked.h"
void box_operations(BoxInterface<int>&);
void fill_box(BoxInterface<int>&);
void display_box(const BoxInterface<int>&);


int main() {
    std::cout << "\nAbstract Data Type (ADT) Box Program by Jessa K. West\n";

    //Array Implementation
    BoxArray<int> box_array;
    std::cout << "Array Implementation of ADT Box:\n";
    box_operations(box_array);

    //Linked List Implementation
    BoxLinked<int> box_linked;
    std::cout << "\n\nLinked List Implementation of ADT Box:\n";
    box_operations(box_linked);

    std::cout << "\nEnd of Program.";
}

void box_operations(BoxInterface<int>& box) {

    std::cout << "Is the box empty? " << (box.isEmpty() ? "True" : "False") << std::endl;
    std::cout << "Filling box w integer values...";
    fill_box(box);
    std::cout << "Current size of box: " << box.getSize() << std::endl;
    std::cout << "Display values in box: ";
    display_box(box);
    std::cout << "Does box contain value (1)? " << (box.contains(1) ? "Yes" : "No") << std::endl;
    std::cout << "Removing the value (1) from box...\n";
    box.remove(1);
    std::cout << "Current size of box: " << box.getSize() << std::endl;
    std::cout << "Does box contain value (1)? " << (box.contains(1) ? "Yes" : "No") << std::endl;
}

void fill_box(BoxInterface<int>& box) {
    int newValues[] = {1, 10, 100, 1000};
    for (int i = 0; i < 4; i++) {
        box.add(newValues[i]);
    }
    std::cout << "4 values added to box.\n";
}

void display_box(const BoxInterface<int>& box) {
    std::vector<int> values = box.toVector();
    for (const auto& value: values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
