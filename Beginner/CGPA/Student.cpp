#include "headers/Student.h"

class Student{
    public:
        Student() = default;
        Student(std::string studentId): StudentId(studentId) {}

        std::string StudentId;
        std::vector<std::vector<PickedClass>> Semesters;

        void AddCurrentSemester()
        {
             std::cout << "How many Classes did you had?" << std::endl;
            short unsigned int numClasses;
            std::cin >> numClasses;

            std::vector<PickedClass> courses;
            for (short unsigned int i = 0; i < numClasses; ++i) {
                PickedClass newClass;
                std::cout << "Enter the name of class " << (i + 1) << ": ";
                std::cin >> newClass.Name;
                std::cout << "Enter the credit for " << newClass.Name << ": ";
                std::cin >> newClass.Credit;
                std::cout << "Enter the final grade for " << newClass.Name << " (1-5): ";
                std::cin >> newClass.FinalGrade;

                courses.push_back(newClass);
            }

            if (!courses.empty()) {
                AddSemester(courses);
            }
        }
        void CalculateStatistics()
        {
            std::vector<float> semesterGPAs;
            for (const auto& semester : Semesters) {
                float gpa = CalculateGPA(semester);
                semesterGPAs.push_back(gpa);
            }

            float cgpa = CalculateCGPA(semesterGPAs);

            std::cout << "Semester GPAs:" << std::endl;
            for (size_t i = 0; i < semesterGPAs.size(); ++i) {
                std::cout << "Semester " << (i + 1) << ": " << semesterGPAs[i] << std::endl;
            }
            std::cout << "Cumulative GPA (CGPA): " << cgpa << std::endl;
        }

        void ShowDetailedSemesterInfo(int semesterIndex)
        {
            const auto& semester = Semesters[semesterIndex];
            std::cout << "Detailed Information for Semester " << (semesterIndex + 1) << ":\n";
            int attemptedCredits = 0;
            int earnedCredits = 0;
            for (const auto& course : semester) {
                std::cout << "Class Name: " << course.Name << "\n";
                std::cout << "Credit: " << course.Credit << "\n";
                std::cout << "Final Grade: " << course.FinalGrade << "\n";
                std::cout << "--------------------------\n";
                attemptedCredits += course.Credit;
                if (course.FinalGrade >= 2.0f) {
                    earnedCredits += course.Credit;
                }
            }
            std::cout << "GPA: " << CalculateGPA(semester) << "\n";
            std::cout << "Attempted credits: " << attemptedCredits << "\n";
            std::cout << "Earned credits: " << earnedCredits << "\n";
            std::cout << "Credit sucess rate" << earnedCredits / attemptedCredits << "\n";
        }

    private:
        void AddSemester(const std::vector<PickedClass>& courses)
        {
            Semesters.push_back(courses);
        }
        float CalculateGPA(const std::vector<PickedClass>& currentSemester)
        {
            float totalPoints = 0.0f;
            int totalCredits = 0;

            for (const auto& course : currentSemester) {
                if (course.FinalGrade < 2) {
                    continue; // Skip invalid grades
                }
                totalPoints += course.FinalGrade * course.Credit;
                totalCredits += course.Credit;
            }

            if (totalCredits == 0) {
                return 0.0f; // Avoid division by zero
            }

            return totalPoints / totalCredits;
        }
        float CalculateCGPA(const std::vector<float>& semesterGPAs)
        {
            if (semesterGPAs.empty()) {
                return 0.0f;
            }

            float totalGPA = 0.0f;
            for (const auto& gpa : semesterGPAs) {
                totalGPA += gpa;
            }

            return totalGPA / semesterGPAs.size();
        }
};
