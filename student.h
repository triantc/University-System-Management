#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "person.h"
#include "secretary.h"
#include "course.h"
#include <map>
class Course;
using namespace std;

class Student : public Person {
    int semester;
    // Map <course, pair<semester it was passed, grade>>
    map<Course*, pair<int, int>> passedCourses; 
public:
    Student();
    Student(const string& name, int age, int id, int semester,
            const map<Course*, pair<int, int>>& passedCourses);
    ~Student();

    void setSemester(int semester);
    void setPassedCourses(const map<Course*, pair<int, int>>& passedCourses);
    int getSemester() const;
    const map<Course*, pair<int, int>>& getPassedCourses() const;

    friend istream& operator>>(istream& is, Student& student);
    friend ostream& operator<<(ostream& os, const Student& student);

    void deleteCourse(const string& courseName);
};

#endif