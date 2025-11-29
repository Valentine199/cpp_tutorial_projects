#include "headers/logic.h"

Student* SearchStudent(const std::string& studentId, School& school)
{
    for (auto& student : school.Students) {
        if (student.StudentId == studentId) {
            
            return &student;
        }
    }
    return nullptr;
}

Student* CreateNewStudent(const std::string& studentId, School& school)
{
    Student newStudent;
    newStudent.StudentId = studentId;
    school.Students.push_back(newStudent);

    return &school.Students.back();
}

