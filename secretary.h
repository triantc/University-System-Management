#ifndef SECRETARY_H
#define SECRETARY_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "student.h"
#include "professor.h"
#include "semester.h"
#include "course.h"
class Professor;
class Course;
class Student;

using namespace std;

class Secretary {
    map<int, Student*> studentsMap;     // Map for storing students based on their ID
    map<int, Professor*> professorsMap; // Map for storing professors based on their ID
    vector<Course*> courses;

public:
    Secretary();
    ~Secretary();

    map<int, Student*> getStudentsMap() const;

    Student* findStudentById(int studentId) const;
    Professor* findProfessorById(int professorId) const;
    Course* findCourseByName(const string& courseName) const;

    void addCourse(const string& name, int ects, bool mandatory, int semester);
    void addStudent(const string& name, int age, int id,
     int semester, const map<Course*, pair<int, int>>& passedCourses);
    void addProfessor(const string& name, int age,
     int id, const vector<Course*>& courses);
    void deleteProfessor(int id);
    void deleteStudent(int id);
    void deleteCourse(const string& courseName);

    // Functions for menu options
    void professorStatisticsForSemester(Professor* professor) const;
    void deleteCourseFromProfessors(const string& courseName);
    void printEligibleForGraduation() const;
    void printCourseInfoOnSemester(const string& courseName, int semester) const;

    // Function for loading data from files
    void loadDataFromFile();
    // Function for printing all info of secretary
    void printAllInfo() const;
};

extern Secretary globalSecretary;
extern Semester globalSemester;

#endif