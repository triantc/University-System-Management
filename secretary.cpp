#include "secretary.h"
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

Secretary::Secretary() {}

Secretary::~Secretary() {
    // Clean up allocated memory for students
    for (auto& studentPair : studentsMap) {
        delete studentPair.second;
    }
    studentsMap.clear();

    // Clean up allocated memory for professors
    for (auto& professorPair : professorsMap) {
        delete professorPair.second;
    }
    professorsMap.clear();

    // Clean up allocated memory for courses
    for (auto& course : courses) {
        delete course;
    }
    courses.clear();
}

map<int, Student*> Secretary::getStudentsMap() const {
    return studentsMap;
}

void Secretary::addProfessor(const string& name, int age,
     int id, const vector<Course*>& courses) {
    professorsMap[id] = new Professor(name, age, id, courses);
}

void Secretary::addStudent(const string& name, int age, int id,
     int semester, const map<Course*, pair<int, int>>& passedCourses) {
    studentsMap[id] = new Student(name, age, id, semester, passedCourses);
}

void Secretary::addCourse(const string& name, int ects, bool mandatory, int semester) {
    Course* newCourse = new Course(name, ects, mandatory, semester);
    courses.push_back(newCourse);
}

void Secretary::deleteProfessor(int id) {
    auto it = professorsMap.find(id);
    if (it != professorsMap.end()) {
        delete it->second;
        professorsMap.erase(it);
        cout << "Professor with ID " << id << " deleted successfully." << std::endl;
    } else {
        cerr << "Error: Professor with ID " << id << " not found." << std::endl;
    }
}

void Secretary::deleteStudent(int id) {
    auto it = studentsMap.find(id);
    if (it != studentsMap.end()) {
        delete it->second;
        studentsMap.erase(it);
        cout << "Student with ID " << id << " deleted successfully." << endl;
    } else {
        cerr << "Error: Student with ID " << id << " not found." << endl;
    }
}

void Secretary::deleteCourse(const string& courseName) {
    // Delete the course from each student
    for (auto& studentEntry : studentsMap) {
        Student* student = studentEntry.second;
        student->deleteCourse(courseName);
    }

    // Delete the course from each professor
    for (auto& professorEntry : professorsMap) {
        Professor* professor = professorEntry.second;
        professor->deleteCourse(courseName);
    }

    auto it = find_if(courses.begin(), courses.end(), [&courseName](Course* course) {
        return course->getName() == courseName;
    });

    if (it != courses.end()) {
        Course* courseToDelete = *it;
        courses.erase(it);
        delete courseToDelete;

        cout << "Course '" << courseName << "' deleted successfully." << endl;
    } else {
        cerr << "Error: Course '" << courseName << "' not found." << endl;
    }
}

Student* Secretary::findStudentById(int studentId) const {
    auto it = studentsMap.find(studentId);
    return (it != studentsMap.end()) ? it->second : nullptr;
}

Professor* Secretary::findProfessorById(int professorId) const {
    auto it = professorsMap.find(professorId);
    return (it != professorsMap.end()) ? it->second : nullptr;
}

Course* Secretary::findCourseByName(const string& courseName) const{
    for (Course* course : courses)
        if (course->getName() == courseName)
            return course;
    return nullptr; // Course not found
}

void Secretary::deleteCourseFromProfessors(const string& courseName) {
    for (auto& professorEntry : professorsMap) {
        Professor* professor = professorEntry.second;
        professor->deleteCourse(courseName);
    }
}

void Secretary::professorStatisticsForSemester(Professor* professor) const {
    cout << "Professor: " << professor->getName() << endl;
    cout << "Statistics: " << endl;

    const Semester& semester = globalSemester;
    const map<Course*, vector<Student*>>& semesterEnrollments = semester.getEnrollments();

    for (const Course* course : professor->getCourses()) {
        cout << "Course: " << course->getName() << endl;

        // Check if the course has enrollments for the current semester
        auto enrollmentIter = semesterEnrollments.find(const_cast<Course*>(course));
        if (enrollmentIter != semesterEnrollments.end()) {
            const vector<Student*>& enrollments = enrollmentIter->second;

            // Print enrollment information
            for (const Student* student : enrollments) {
                cout << "Students enrolled: \n";
                cout << "ID:" << student->getId() << " - Name:" << student->getName() << endl;
            }
        } else {
            cout << "No enrollments for this course in the current semester." << endl;
        }
        cout << endl;
    }
}

void Secretary::loadDataFromFile() {
    ifstream coursesFile("courses.txt");
    if (!coursesFile.is_open()) {
        cerr << "Error: Unable to open file: " << "courses.txt" << endl;
        return;
    }

    string line;
    string name;
    int ects;
    bool mandatory;
    int semester;
    while (getline(coursesFile, line)) {
        name = line;

        coursesFile >> ects;
        coursesFile.ignore();

        coursesFile >> boolalpha >> mandatory;
        coursesFile.ignore();

        coursesFile >> semester;
        coursesFile.ignore();
        coursesFile.ignore();
        
        globalSecretary.addCourse(name, ects, mandatory, semester);
    }
    coursesFile.close();

    ifstream studentsFile("students.txt");
    if (!studentsFile.is_open()) {
        cerr << "Error: Unable to open file: " << "students.txt" << endl;
        return;
    }

    int age, id;
    while (getline(studentsFile, line)) {
        name = line;
        
        studentsFile >> age;
        studentsFile.ignore();

        studentsFile >> id;
        studentsFile.ignore();

        studentsFile >> semester;
        studentsFile.ignore();
        
        map<Course*, pair<int, int>> courseMap;

        while(getline(studentsFile, line))
        {
            if (line.empty()) {
                globalSecretary.addStudent(name, age, id, semester, courseMap);
                break;
            }
            string courseName;
            int semesterItWasPassed, grade;
            courseName = line;
            studentsFile >> semesterItWasPassed;
            studentsFile.ignore();
            studentsFile >> grade;
            studentsFile.ignore();
            courseMap[globalSecretary.findCourseByName(courseName)]
             = pair<int, int>(semesterItWasPassed, grade);
        }
        globalSecretary.addStudent(name, age, id, semester, courseMap);
    }
    studentsFile.close();

    ifstream professorsFile("professors.txt");
    if (!professorsFile.is_open()) {
        cerr << "Error: Unable to open file: " << "professors.txt" << endl;
        return;
    }

    while (getline(professorsFile, line)) {
        name = line;
        
        professorsFile >> age;
        professorsFile.ignore();

        professorsFile >> id;
        professorsFile.ignore();
        
        vector<Course*> courseVector;

        while(getline(professorsFile, line))
        {
            if (line.empty()) {
                globalSecretary.addProfessor(name, age, id, courseVector);
                break;
            }
            string courseName;
            int semesterItWasPassed;
            courseName = line;
            courseVector.push_back(globalSecretary.findCourseByName(courseName));
        }
        globalSecretary.addProfessor(name, age, id, courseVector);
    }
    professorsFile.close();
}

void Secretary::printAllInfo() const {
    cout << "\033[1;31mCOURSES\033[0m\n" << endl; // format to make text red and bold

    for (const Course* course : courses) {
        cout << "Course Name: " << course->getName() << endl;
        cout << "ECTS: " << course->getEcts() << endl;
        cout << "Mandatory: " << (course->getMandatory() ? "Yes" : "No") << endl;
        cout << "Semester: " << course->getSemester() << endl;
        cout << "------------------------" << endl;
    }

    cout << "\033[1;31mSTUDENTS\033[0m\n" << endl;

    for (const auto& studentPair : studentsMap) {
        const Student* student = studentPair.second;
        cout << "Name: " << student->getName() << endl;
        cout << "Age: " << student->getAge() << endl;
        cout << "ID: " << student->getId() << endl;
        cout << "Semester: " << student->getSemester() << endl;
        cout << "Passed Courses: " << endl;
        for (const auto& passedCoursePair : student->getPassedCourses()) {
            const Course* course = passedCoursePair.first;
            int semesterItWasPassed = passedCoursePair.second.first;
            int grade = passedCoursePair.second.second;
            cout << "Course Name: " << course->getName() << endl;
            cout << "Semester It Was Passed: " << semesterItWasPassed << endl;
            cout << "Grade: " << grade << endl;
        }
        cout << "------------------------" << endl;
    }

    cout << "\033[1;31mPROFESSORS\033[0m\n" << endl;

    for (const auto& professorPair : professorsMap) {
        const Professor* professor = professorPair.second;
        cout << "Name: " << professor->getName() << endl;
        cout << "Age: " << professor->getAge() << endl;
        cout << "ID: " << professor->getId() << endl;
        cout << "Courses: " << endl;
        for (const Course* course : professor->getCourses()) {
            cout << "Course Name: " << course->getName() << endl;
        }
        cout << "------------------------" << endl;
    }
    globalSemester.printSemester();
}

void Secretary::printEligibleForGraduation() const {

    for (const auto& pair : studentsMap) {
        const Student* student = pair.second;

        // Check if the student has passed all mandatory courses
        bool allMandatoryCoursesPassed = true;
        for (const Course* course : courses) {
            if (course->getMandatory()) {
                bool found = false;

                // Iterate through all passed courses of the student
                for (const auto& passedCourse : student->getPassedCourses()) {
                    if (passedCourse.first == course) {
                        // Student has passed this mandatory course
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    // Student hasn't passed a mandatory course
                    allMandatoryCoursesPassed = false;
                    break;
                }
            }
        }

        // Calculate total ECTS
        int totalEcts = 0;
        for (const auto& passedCourse : student->getPassedCourses())
            totalEcts += passedCourse.first->getEcts();

        // Check eligibility criteria
        if (allMandatoryCoursesPassed && totalEcts >= 20 && student->getSemester() >= 6) {
            // Print student ID, Name, and Total ECTS
            cout << "ID: " << student->getId() << ", Name: " << student->getName()
                 << ", Total ECTS: " << totalEcts << endl;
        }
    }

    cout << "End of Eligible Students List." << endl;
}

void Secretary::printCourseInfoOnSemester(const string& courseName, int semester) const {
    const Course* course = findCourseByName(courseName);
    if (course == nullptr) {
        cerr << "Error: Course '" << courseName << "' not found." << endl;
        return;
    }

    for (auto& pair : studentsMap) {
        Student* student = pair.second;
        for (auto& passedCourse : student->getPassedCourses()) {
            Course* passedCoursePtr = passedCourse.first;
            if (passedCoursePtr == course && passedCourse.second.first == semester) {
                cout << "Student ID: " << student->getId() << ", Name: " << student->getName()
                     << ", Grade: " << passedCourse.second.second << endl;
            }
        }
    }
}

Secretary globalSecretary;
extern Semester globalSemester;
