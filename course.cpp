#include "course.h"
using namespace std;

Course::Course()
    : name(""), ects(0), mandatory(false), semester(0) {}

Course::Course(const string& name, int ects, bool mandatory, int semester)
    : name(name), ects(ects), mandatory(mandatory), semester(semester) {}

Course::~Course() {
}

void Course::setName(const string& name) {
    this->name = name;
}

void Course::setEcts(int ects) {
    this->ects = ects;
}

void Course::setMandatory(bool mandatory) {
    this->mandatory = mandatory;
}

void Course::setSemester(int semester) {
    this->semester = semester;
}

const string& Course::getName() const {
    return name;
}

int Course::getEcts() const {
    return ects;
}

bool Course::getMandatory() const {
    return mandatory;
}

int Course::getSemester() const {
    return semester;
}

istream& operator>>(istream& is, Course& course) {
    string name;
    int ects;
    bool mandatory;
    int semester;

    cout << "Enter Course Name: ";
    getline(is, name);

    cout << "Enter ECTS: ";
    is >> ects;

    cout << "Is the course mandatory? (1 for Yes, 0 for No): ";
    is >> mandatory;

    cout << "Enter Semester: ";
    is >> semester;
    cin.ignore();  // Consume the newline character

    globalSecretary.addCourse(name, ects, mandatory, semester);
    return is;
}

ostream& operator<<(ostream& os, const Course& course) {
    os << "Course Name: " << course.getName() << endl;
    os << "ECTS: " << course.getEcts() << endl;
    os << "Mandatory: " << (course.getMandatory() ? "Yes" : "No") << endl;
    os << "Semester: " << course.getSemester() << endl;

    return os;
}
