#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
#include "course.h"
#include "person.h"
#include "student.h"
#include "secretary.h"
#include <vector>
using namespace std;
class Course;
class Secretary;

class Professor : public Person {
    vector<Course*> courses;
public:
    Professor();
    Professor(const string& name, int age, int id, const vector<Course*>& courses);
    ~Professor();

    void setCourses(const vector<Course*>& courses);
    const vector<Course*>& getCourses() const;

    friend istream& operator>>(istream& is, Professor& professor);
    friend ostream& operator<<(ostream& os, const Professor& professor);

    void deleteCourse(const string& courseName);
    void addCourse(Course* course);
};

extern Secretary globalSecretary;

#endif