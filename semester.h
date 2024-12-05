#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Course;
class Student;

class Semester {
    // Map of courses to students enrolled in a course
    // Gets cleared when the semester is over
    map<Course*, vector<Student*>> enrollments;

public:
    int year;
    bool isFallSemester; // true for fall, false for spring

    Semester();
    Semester(int year, bool isFall);

    bool isFall() const;
    void setFall(bool isFall);

    void enrollStudentInCourse(Student* student, Course* course);
    void removeStudentFromCourse(Student* student, Course* course);
    const map<Course*, vector<Student*>>& getEnrollments() const;

    void clearEnrollments();
    void printSemester() const;
    void printEnrollments() const;
};

extern Semester globalSemester;

#endif
