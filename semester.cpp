#include "semester.h"
#include "course.h"
#include "student.h"
#include <algorithm>
using namespace std;

Semester::Semester() : year(2024), isFallSemester(false) {}

Semester::Semester(int year, bool isFall) : year(year), isFallSemester(isFall) {}

bool Semester::isFall() const {
    return isFallSemester;
}

void Semester::setFall(bool isFall) {
    isFallSemester = isFall;
}

void Semester::enrollStudentInCourse(Student* student, Course* course) {
    enrollments[course].push_back(student);
}

void Semester::removeStudentFromCourse(Student* student, Course* course) {
    auto& students = enrollments[course];

    // Use remove to find and move the student to the end
    auto it = remove(students.begin(), students.end(), student);
    
    // Erase the moved element
    students.erase(it, students.end());
}

const map<Course*, vector<Student*>>& Semester::getEnrollments() const {
    return enrollments;
}

void Semester::printEnrollments() const {
    cout << "Enrollments for " << (isFallSemester ? "Fall" : "Spring") << " Semester:" << endl;

    for (const auto& entry : enrollments) {
        const Course* course = entry.first;
        const vector<Student*>& students = entry.second;

        cout << "Course: " << course->getName() << endl;
        cout << "Enrolled Students: ";

        for (const Student* student : students) {
            cout << student->getName() << " ";
        }

        cout << endl;
    }
}

void Semester::clearEnrollments() {
    enrollments.clear();
}

void Semester::printSemester() const {
    cout << "\033[1;31mSEMESTER\033[0m\n" << endl;  // format to make text red and bold
    cout << "Year: " << year << endl;
    cout << "Semester: " << (isFallSemester ? "Fall" : "Spring") << endl << endl;
}

Semester globalSemester;