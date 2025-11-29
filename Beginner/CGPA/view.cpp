#include "headers/view.h"

School mySchool;
std::string studentId;
Student* currentStudent = nullptr;

void StudentLoginWindow()
{
    std::cout << "Welcome to the CGPA Management System" << std::endl;
    std::cout << "Enter your student ID" << std::endl;

    std::cin >> studentId;

    currentStudent = SearchStudent(studentId, mySchool);

    if (currentStudent) {
        std::cout << "Login successful. Welcome, Student " << currentStudent->StudentId << "!" << std::endl;
        StudentMenu();
    } else {
        HandleMissingStudent();
    }
    
}

void HandleMissingStudent()
{
    std::cout << "Student not found. Please check your ID and try again." << std::endl;
    std::cout << "Student id: " << studentId << std::endl;
    std::cout << "Do you want to create a New student? (y/n)" << std::endl;

    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        currentStudent = CreateNewStudent(studentId, mySchool);
        std::cout << "New student created with ID: " << currentStudent -> StudentId << std::endl;
        StudentMenu();
    } else {
        std::cout << "Returning to login." << std::endl;
        StudentLoginWindow();
    }
}

void StudentMenu()
{
    std::cout << "Student Menu for " << currentStudent->StudentId << std::endl;
    DisplayStudentMenuOptions();

    char choice;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3') {
        std::cout << "Invalid choice. Please select 1,2  or 3." << std::endl;
        DisplayStudentMenuOptions();
        std::cin >> choice;
    }

    if (choice == '1') {
        DisplayStatistics();
        StudentMenu();
    } else if (choice == '2') {
        currentStudent->AddCurrentSemester();
        std::cout << "Semester results added successfully." << std::endl;
        StudentMenu();
    }
}

void DisplayStatistics()
{
    currentStudent->CalculateStatistics(); //Might run multiple times but doesn't change as often
    std::cout << "Press 'q' or select the semester to show more details" << std::endl;
    char choice;
    std::cin >> choice;
    if (choice == 'q' || choice == 'Q') {
        StudentMenu();
    }
    else if (isdigit(choice))
    {
        int a = choice - '0';
        if (a >= 1 && a <= currentStudent->Semesters.size() + 1)
        {
            DisplayDetailedSemesterInfo(currentStudent, a - 1);
        }
        else
        {
            std::cout << "Invalid semester selection." << std::endl;
            DisplayStatistics();
        }
    }
    else
    {
        std::cout << "Invalid input." << std::endl;
        DisplayStatistics();
    }
}

void DisplayDetailedSemesterInfo(Student* currentStudent, int semesterIndex)
{
    
}

void DisplayStudentMenuOptions()
{
    std::cout << "1.) Check Statistics" << std::endl;
    std::cout << "2.) Add Semester Results" << std::endl;
    std::cout << "3.) Logout"<< std::endl;
}
