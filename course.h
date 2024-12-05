#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include "professor.h"
using namespace std;

class Course {
    string name;
    int ects;
    bool mandatory;
    int semester;

public:
    Course();
    Course(const string& name, int ects, bool mandatory, int semester);
    ~Course();

    void setName(const string& name);
    void setEcts(int ects);
    void setMandatory(bool mandatory);
    void setSemester(int semester);

    const string& getName() const;
    int getEcts() const;
    bool getMandatory() const;
    int getSemester() const;

    friend istream& operator>>(istream& is, Course& course);
    friend ostream& operator<<(ostream& os, const Course& course);
};

#endif