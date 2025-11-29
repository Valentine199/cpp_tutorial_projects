#pragma once
#include "School.h"
#include "Student.h"


Student* SearchStudent(const std::string& studentId, School& school);
Student* CreateNewStudent(const std::string& studentId, School& school);