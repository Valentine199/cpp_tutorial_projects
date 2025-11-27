#include <iostream>
#include "PickedClass.H"

int main() {
    PickedClass class1;
    class1.Name = "Mathematics";
    class1.Credit = 3;
    class1.FinalGrade = 5;

    std::cout << "Class Name: " << class1.Name << std::endl;
    std::cout << "Credit Hours: " << class1.Credit * 2 << std::endl;

    return 0;
}