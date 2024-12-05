#ifndef MENU_FUNCTIONS_H
#define MENU_FUNCTIONS_H
#include "secretary.h"

extern Secretary globalSecretary;
extern Semester globalSemester;

// MAIN PRINT
void PRINT_MENU();
// 1
void ADD_MOD_DELETE_PROF();
// 2
void ADD_MOD_DELETE_STUDENT();
// 3
void ADD_MOD_DELETE_COURSE();
// 4
void ASSIGN_PROF_TO_COURSE();
// 5
void ENROLL_STUDENT_IN_COURSE();
// 6
void PRINT_STUDENTS_WHO_PASSED_COURSE();
// 7
void PRINT_PROFESSOR_STATISTICS_FOR_SEMESTER();
// 8
void PRINT_STUDENT_GRADES();
// 9
void PRINT_ELIGIBLE_FOR_GRADUATION();
// 10
void ADVANCE_SEMESTER();
// 11
void PRINT_ALL_INFO();

#endif