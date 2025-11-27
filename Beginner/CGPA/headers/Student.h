#include <string>
#include <vector>

class Student{
    public:
        Student() = default;
        Student(std::string name): Name(name) {}

        std::string Name;
        std::vector<std::vector<std::string>> Semesters;

        void AddCurrentSemester();

    private:
        void AddSemester(const std::vector<std::string>& courses);
        void CalculateGPA();
        void CalculateCGPA();
};