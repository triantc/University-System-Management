#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cassert> // Testing
#include "secretary.h"
#include "professor.h"
#include "course.h"
#include "student.h"
#include "person.h"
#include "semester.h"
#include "menu_functions.h"
using namespace std;

int Person::count = 0;

int main() {

    // Load data from files and print it
    globalSecretary.loadDataFromFile();
    globalSecretary.printAllInfo();
    
    // Menu
    int choice;
    do {
        PRINT_MENU();
        cin >> choice;
        switch (choice) {
            case 1: {
                ADD_MOD_DELETE_PROF();
                break;
            }
            case 2: {
                ADD_MOD_DELETE_STUDENT();
                break;
            }
            case 3: {
                ADD_MOD_DELETE_COURSE();
                break;
            }
            case 4: {
                ASSIGN_PROF_TO_COURSE();
                break;
            }
            case 5: {
                ENROLL_STUDENT_IN_COURSE();
                break;
            }
            case 6: {
                PRINT_STUDENTS_WHO_PASSED_COURSE();
                break;
            }
            case 7: {
                PRINT_PROFESSOR_STATISTICS_FOR_SEMESTER();
                break;
            }
            case 8: {
                PRINT_STUDENT_GRADES();
                break;
            }
            case 9: {
                PRINT_ELIGIBLE_FOR_GRADUATION();
                break;
            }
            case 10: {
                ADVANCE_SEMESTER();
                break;
            }
            case 11: {
                PRINT_ALL_INFO();
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);


}
