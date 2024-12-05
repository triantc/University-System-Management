#include "student.h"
using namespace std;

Student::Student() {
}

Student::Student(const string& name, int age, int id, int semester,
                 const map<Course*, pair<int, int>>& passedCourses)
    : Person(name, age, id), semester(semester), passedCourses(passedCourses) {}

Student::~Student() {
}

void Student::setSemester(int semester) {
    this->semester = semester;
}

void Student::setPassedCourses(const map<Course*, pair<int, int>>& passedCourses) {
    this->passedCourses = passedCourses;
}

int Student::getSemester() const {
    return semester;
}

const map<Course*, pair<int, int>>& Student::getPassedCourses() const {
    return passedCourses;
}

istream& operator>>(istream& is, Student& student) {
    string name;
    int age, id, semester;

    cout << "Enter Student's Name: ";
    getline(is, name);

    cout << "Enter Student's Age: ";
    is >> age;

    cout << "Enter Student's Id: ";
    is >> id;

    cout << "Enter Student's Semester: ";
    is >> semester;

    map<Course*, pair<int, int>> passedCourses;

    char passedCoursesYesNo;
    cout << "Has the student passed any courses? (y/n): ";
    is >> passedCoursesYesNo;
    is.ignore(); // Consume the newline character

    if (passedCoursesYesNo == 'y' || passedCoursesYesNo == 'Y') {
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
                int semesterItWasPassed, grade;
                cout << "Enter Semester it was passed in: ";
                is >> semesterItWasPassed;
                is.ignore();

                cout << "Enter Grade for the course: ";
                is >> grade;
                is.ignore();

                passedCourses[course] = make_pair(semesterItWasPassed, grade);
            } else {
                cerr << "Error: Course not found, you should first add the course and then make the student: " << endl;
            }
        }
    }
    globalSecretary.addStudent(name, age, id, semester, passedCourses);

    return is;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "Student's Name: " << student.getName() << endl;
    os << "Student's Age: " << student.getAge() << endl;
    os << "Student's ID: " << student.getId() << endl;
    os << "Current Semester: " << student.getSemester() << endl;

    const map<Course*, pair<int, int>>& passedCourses = student.getPassedCourses();

    if (!passedCourses.empty()) {
        os << "Passed Courses:" << endl;
        for (const auto& entry : passedCourses) {
            os << "  - Course Name: " << entry.first->getName()
               << ", Semester: " << entry.second.first // Semester it was passed
               << ", Grade: " << entry.second.second   // Grade for the course
               << endl;
        }
    } else {
        os << "No courses passed yet." << endl;
    }

    return os;
}

void Student::deleteCourse(const string& courseName) {
    auto it = passedCourses.find(globalSecretary.findCourseByName(courseName));

    if (it != passedCourses.end()) {
        // Found the course, erase it
        passedCourses.erase(it);
    }
}
