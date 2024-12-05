#include <iostream>
#include <fstream>
#include "professor.h"
#include "semester.h"
#include "menu_functions.h"
using namespace std;

void PRINT_MENU() {
    cout << "\n==== University System Menu ====" << endl;
    cout << "1. Add/Modify/Delete Professor\n"
            << "2. Add/Modify/Delete Student\n"
            << "3. Add/Modify/Delete Course\n"
            << "4. Assign Professors to a Course\n"
            << "5. Enroll Student in a Course\n"
            << "6. Save Students who Passed a Course\n"
            << "7. Print Semester Statistics for Professors\n"
            << "8. Print Student Grades for a Specific Semester\n"
            << "9. Print Students Eligible for Graduation\n"
            << "10. Advance Semester (more info when pressed)\n"	
            << "11. Print All Current Semester Info (Students/Professors/Courses)\n"
            << "0. Exit\n";
    cout << "Enter the number of your choice: ";
}

void ADD_MOD_DELETE_PROF() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Add Professor\n"
             << "2. Modify Professor\n"
             << "3. Delete Professor\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                // Add Professor
                Professor professor;
                cin >> professor;
                cout << "Professor added successfully." << endl;
                break;
            }
            case 2: {
                // Modify Professor
                int id;
                cout << "Enter the ID of the professor you want to modify: ";
                cin >> id;
                cin.ignore();  // Consume the newline character

                Professor* profToModify = globalSecretary.findProfessorById(id);
                if (profToModify) {
                    // Professor found, modify the details
                    cout << "Current details of Professor with ID " << id << ":" << endl;
                    cout << *profToModify;
                    globalSecretary.deleteProfessor(id);
                    // Prompt for modifications
                    Professor professor;
                    cout << "Enter new details for Professor (if something does not need"
                     " to be changed please enter the info again as shown above):" << endl;
                    cin >> professor;
                    cout << "Professor modified successfully." << endl;
                } else {
                    cout << "Professor with ID " << id << " not found." << endl;
                }
                break;
            }
            case 3: {
                // Delete Professor
                int id;
                cout << "Enter the ID of the professor you want to delete: ";
                cin >> id;
                cin.ignore();  // Consume the newline character

                Professor* profToDelete = globalSecretary.findProfessorById(id);
                if (profToDelete) {
                    // Professor found, display details and confirm deletion
                    cout << "Details of Professor with ID " << id << ":" << endl;
                    cout << *profToDelete;

                    // Confirm deletion
                    char confirmDelete;
                    cout << "Are you sure you want to delete this professor? (y/n): ";
                    cin >> confirmDelete;

                    if (confirmDelete == 'y' || confirmDelete == 'Y') {
                        globalSecretary.deleteProfessor(id);
                        cout << "Professor deleted successfully." << endl;
                    } else {
                        cout << "Deletion canceled." << endl;
                    }
                } else {
                    cout << "Professor with ID " << id << " not found." << endl;
                }
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void ADD_MOD_DELETE_STUDENT() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Add Student\n"
             << "2. Modify Student\n"
             << "3. Delete Student\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                // Add Student
                Student student;
                cin >> student;
                cout << "Student added successfully." << endl;
                break;
            }
            case 2: {
                // Modify Student
                int id;
                cout << "Enter the ID of the student you want to modify: ";
                cin >> id;
                cin.ignore();  // Consume the newline character

                Student* studentToModify = globalSecretary.findStudentById(id);
                if (studentToModify) {
                    // Student found, modify the details
                    cout << "Current details of Student with ID " << id << ":" << endl;
                    cout << *studentToModify;
                    globalSecretary.deleteStudent(id);
                    // Prompt for modifications
                    Student student;
                    cout << "Enter new details for Student (if something does not need"
                     " to be changed please enter the info again as shown above):" << endl;
                    cin >> student;
                    cout << "Student modified successfully." << endl;
                } else {
                    cout << "Student with ID " << id << " not found." << endl;
                }
                break;
            }
            case 3: {
                // Delete Student
                int id;
                cout << "Enter the ID of the student you want to delete: ";
                cin >> id;
                cin.ignore();  // Consume the newline character

                Student* studentToDelete = globalSecretary.findStudentById(id);
                if (studentToDelete) {
                    // Student found, display details and confirm deletion
                    cout << "Details of Student with ID " << id << ":" << endl;
                    cout << *studentToDelete;

                    // Confirm deletion
                    char confirmDelete;
                    cout << "Are you sure you want to delete this student? (y/n): ";
                    cin >> confirmDelete;

                    if (confirmDelete == 'y' || confirmDelete == 'Y') {
                        globalSecretary.deleteStudent(id);
                        cout << "Student deleted successfully." << endl;
                    } else {
                        cout << "Deletion canceled." << endl;
                    }
                } else {
                    cout << "Student with ID " << id << " not found." << endl;
                }
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void ADD_MOD_DELETE_COURSE() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Add Course\n"
             << "2. Modify Course\n"
             << "3. Delete Course\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                // Add Course
                Course course;
                cin >> course;
                cout << "Course added successfully." << endl;
                break;
            }
            case 2: {
                // Modify Course
                string name;
                cout << "Enter the name of the course you want to modify: ";
                getline(cin, name);

                Course* courseToModify = globalSecretary.findCourseByName(name);
                if (courseToModify) {
                    // Course found, modify the details
                    cout << "Current details of Course '" << name << "':" << endl;
                    cout << *courseToModify;
                    globalSecretary.deleteCourse(name);
                    // Prompt for modifications
                    Course course;
                    cout << "Enter new details for Course (if something does not need"
                         " to be changed please enter the info again as shown above):" << endl;
                    cin >> course;
                    cout << "Course modified successfully." << endl;
                } else {
                    cout << "Course '" << name << "' not found." << endl;
                }
                break;
            }
            case 3: {
                // Delete Course
                string name;
                cout << "Enter the name of the course you want to delete: ";
                getline(cin, name);

                Course* courseToDelete = globalSecretary.findCourseByName(name);
                if (courseToDelete) {
                    // Course found, display details and confirm deletion
                    cout << "Details of Course '" << name << "':" << endl;
                    cout << *courseToDelete;

                    // Confirm deletion
                    char confirmDelete;
                    cout << "The course will also be deleted from the passed courses "
                     "of all students. Are you sure you want to delete this course? (y/n): ";
                    cin >> confirmDelete;

                    if (confirmDelete == 'y' || confirmDelete == 'Y') {
                        globalSecretary.deleteCourse(name);
                        cout << "Course deleted successfully." << endl;
                    } else {
                        cout << "Deletion canceled." << endl;
                    }
                } else {
                    cout << "Course '" << name << "' not found." << endl;
                }
                break;
            }
            case 0: {
                globalSecretary.printAllInfo();
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void ASSIGN_PROF_TO_COURSE() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Assign a professor\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                string courseName;
                cout << "Enter the name of the course: ";
                cin.ignore();
                getline(cin, courseName);

                Course* course = globalSecretary.findCourseByName(courseName);

                if (course) {
                    int numProfessors;
                    cout << "Enter the number of professors to assign to the course: ";
                    cin >> numProfessors;

                    // Remove the course from all professors first
                    globalSecretary.deleteCourseFromProfessors(courseName);

                    for (int i = 0; i < numProfessors; ++i) {
                        int professorId;
                        cout << "Enter the ID of professor " << i + 1 << ": ";
                        cin >> professorId;

                        Professor* professor = globalSecretary.findProfessorById(professorId);

                        if (professor) {
                            // Add the course to the selected professor
                            professor->addCourse(course);
                            cout << "Professor with ID " << professorId << " assigned to the course successfully." << endl;
                        } else {
                            cerr << "Error: Professor with ID " << professorId << " not found." << endl;
                        }
                    }
                } else {
                    cerr << "Error: Course '" << courseName << "' not found." << endl;
                }
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    
}

void ENROLL_STUDENT_IN_COURSE() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Enroll in a Course\n"
             << "2. Print enrollments\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                // Ask for the student's ID
                int studentId;
                cout << "Enter the student's ID: ";
                cin >> studentId;

                // Find the student
                Student* student = globalSecretary.findStudentById(studentId);
                if (student) {
                    // Ask for the course name
                    string courseName;
                    cout << "Enter the name of the course: ";
                    cin.ignore();  // Consume the newline character
                    getline(cin, courseName);

                    // Find the course
                    Course* course = globalSecretary.findCourseByName(courseName);
                    if (course) {
                        // Check if the student's semester is greater than or equal to the course's semester
                        if (student->getSemester() >= course->getSemester()) {
                            // Enroll the student in the course
                            globalSemester.enrollStudentInCourse(student, course);
                            cout << "Student enrolled successfully." << endl;
                        } else {
                            cerr << "Error: Student's semester is not sufficient for this course." << endl;
                        }
                    } else {
                        cerr << "Error: Course not found." << endl;
                    }
                } else {
                    cerr << "Error: Student not found." << endl;
                }
                break;
            }
            case 2: {
                globalSemester.printEnrollments();
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void PRINT_STUDENTS_WHO_PASSED_COURSE() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Print students who passed a course on a specific semester\n"
             << "2. Make a file and save the info there\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                // Ask for the professor's ID
                string courseName;
                int semester;
                cout << "Enter the name of the course you are interested about: ";
                getline(cin, courseName);
                cout << "Enter the semester you are interested about: ";
                cin >> semester;
                globalSecretary.printCourseInfoOnSemester(courseName, semester);
                break;
            }
            case 2: {
                // Ask for the professor's ID
                string courseName;
                int semester;
                cout << "Enter the name of the course you are interested in: ";
                getline(cin, courseName);
                cout << "Enter the semester you are interested in: ";
                cin >> semester;

                // Create a file and open it for writing
                ofstream outputFile("CourseInfo.txt");

                if (outputFile.is_open()) {
                    // Redirect cout to the file
                    streambuf* oldCoutBuffer = cout.rdbuf();
                    cout.rdbuf(outputFile.rdbuf());

                    // Call the function to print to the file
                    globalSecretary.printCourseInfoOnSemester(courseName, semester);

                    // Restore cout back to the original buffer
                    cout.rdbuf(oldCoutBuffer);

                    // Close the file
                    outputFile.close();
                    cout << "Information written to CourseInfo.txt." << endl;
                } else {
                    cout << "Error opening the file for writing." << endl;
                }
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void PRINT_PROFESSOR_STATISTICS_FOR_SEMESTER() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Print Statistics\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                // Ask for the professor's ID
                int professorId;
                cout << "Enter the ID of the professor whose statistics you want to print: ";
                cin >> professorId;

                // Find the professor with the given ID
                Professor* professor = globalSecretary.findProfessorById(professorId);

                if (professor) {
                    globalSecretary.professorStatisticsForSemester(professor);
                    
                } else {
                    cerr << "Error: Professor with ID " << professorId << " not found." << endl;
                }
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void PRINT_STUDENT_GRADES() {
    int choice;
    
    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Print Student Grades\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character
        switch (choice) {
            case 1: {
                // Ask for the student's ID
                int studentId;
                cout << "Enter the ID of the student whose grades you want to print: ";
                cin >> studentId;

                // Find the student with the given ID
                Student* student = globalSecretary.findStudentById(studentId);

                if (student) {
                    // Ask for the semester
                    int semester;
                    cout << "Enter the semester for which you want to print grades: ";
                    cin >> semester;

                    // Print grades for the specified semester
                    const map<Course*, pair<int, int>>& passedCourses = student->getPassedCourses();
                    cout << "\nGrades for Student ID: " << studentId << ", Name: " << student->getName() << ", Semester: " << semester << endl;

                    for (const auto& entry : passedCourses) {
                        if (entry.second.first == semester) {
                            cout << "  - Course Name: " << entry.first->getName()
                                << ", Grade: " << entry.second.second   // Grade for the course
                                << endl;
                        }
                    }
                } else {
                    cerr << "Error: Student with ID " << studentId << " not found." << endl;
                }
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void PRINT_ELIGIBLE_FOR_GRADUATION() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Print Possible Graduates\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                cout << "\n==== University System Menu ====" << endl;
                cout << "Students eligible for graduation are the students that have passed"
                " all mandatory courses, have gathered at least 20 ECTS and their semester >= 6:\n" << endl;

                globalSecretary.printEligibleForGraduation();
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void ADVANCE_SEMESTER() {
    int choice;
    
    do {
        cout << "\n==== University System Menu ====" << endl;
        globalSemester.printSemester();
        cout << "By pressing 1 you agree to:\n"
             << "-Add 1 to all student semester info\n"
             << "-Semester either becomes Fall or becomes Spring and goes to next year\n"
             << "-All enrollments get cleared\n\n"
             << "1. Go to next semester\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character
        switch (choice) {
            case 1: {

                if (globalSemester.isFall())
                    globalSemester.year++;
                globalSemester.setFall(!globalSemester.isFall());

                for (auto& pair : globalSecretary.getStudentsMap()) {
                    Student* student = pair.second;
                    student->setSemester(student->getSemester() + 1);
                }
                globalSemester.clearEnrollments();
                globalSemester.printSemester();
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void PRINT_ALL_INFO() {
    int choice;

    do {
        cout << "\n==== University System Menu ====" << endl;
        cout << "1. Print Info\n"
             << "0. Back\n";
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1: {
                globalSecretary.printAllInfo();
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

extern Secretary globalSecretary;
extern Semester globalSemester;