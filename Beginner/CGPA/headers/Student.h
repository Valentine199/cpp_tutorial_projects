#include <string>
#include <vector>
#include <iostream>
#include "PickedClass.h"

class Student{
    public:
        Student() = default;
        Student(std::string studentId): StudentId(studentId) {}

        std::string StudentId;
        std::vector<std::vector<PickedClass>> Semesters;

        void AddCurrentSemester();
        void CalculateStatistics();
        void ShowDetailedSemesterInfo(int semesterIndex);

    private:
        void AddSemester(const std::vector<PickedClass>& courses);
        float CalculateGPA(const std::vector<PickedClass>& currentSemester);
        float CalculateCGPA(const std::vector<float>& semesterGPAs);
};