#include <iostream>
#include "professor.h"
#include "course.h"
#include <algorithm>
using namespace std;

Professor::Professor() {
}

Professor::Professor(const string& name, int age, int id, const vector<Course*>& courses)
    : Person(name, age, id), courses(courses) {}

Professor::~Professor() {
}

void Professor::setCourses(const vector<Course*>& courses) {
    this->courses = courses;
}

const vector<Course*>& Professor::getCourses() const {
    return courses;
}

istream& operator>>(istream& is, Professor& professor) {
    string name;
    int age, id;

    cout << "Enter Professor's Name: ";
    getline(is, name);

    cout << "Enter Professor's Age: ";
    is >> age;

    cout << "Enter Professor's Id: ";
    is >> id;

    vector<Course*> courseVector;

    char hasCourses;
    cout << "Does the professor have courses? (y/n): ";
    is >> hasCourses;

    if (hasCourses == 'y' || hasCourses == 'Y') {
        int numCourses;
        cout << "Enter the number of courses: ";
        is >> numCourses;
        is.ignore();

        for (int i = 0; i < numCourses; ++i) {
            string courseName;
            cout << "Enter Course Name " << i + 1 << ": ";
            getline(is, courseName);

            Course* course = globalSecretary.findCourseByName(courseName);

            if (course) {
                courseVector.push_back(course);
            } else {
                cerr << "Error: Course not found, you should first add the course and then the professor: " << endl;
            }
        }
    }
    globalSecretary.addProfessor(name, age, id, courseVector);

    return is;
}

ostream& operator<<(ostream& os, const Professor& professor) {
    os << "Professor's Name: " << professor.getName() << endl;
    os << "Professor's Age: " << professor.getAge() << endl;
    os << "Professor's ID: " << professor.getId() << endl;

    const vector<Course*>& courses = professor.getCourses();
    os << "Courses Taught:" << endl;
    for (const Course* course : courses) {
        os << "  - " << course->getName() << endl;
    }

    return os;
}

void Professor::deleteCourse(const string& courseName) {
    auto it = find_if((courses).begin(), courses.end(), [&courseName](Course* course) {
        return course->getName() == courseName;
    });

    if (it != courses.end()) {
        courses.erase(it);
    }
}

void Professor::addCourse(Course* course) {
    courses.push_back(course);
}

extern Secretary globalSecretary;