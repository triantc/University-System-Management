![MIT License](https://img.shields.io/badge/License-MIT-blue.svg)

# 🏛️ University System Management

This project is a **University Management System** built in **C++**. It allows users to manage and manipulate data about professors, students, courses, and semesters. The system offers functionalities such as adding, modifying, and deleting records, assigning professors to courses, enrolling students, tracking student performance, and more. 

## Features

- **Manage Professors**: Add, modify, or delete professor records.
- **Manage Students**: Add, modify, or delete student records.
- **Course Management**: Add, modify, or delete courses in the system.
- **Enroll Students in Courses**: Assign students to the appropriate courses.
- **Assign Professors to Courses**: Professors can be assigned to the courses they will teach.
- **Student Progress**: View students who have passed specific courses.
- **Semester Management**: Advance semesters and manage the academic calendar.
- **Student Grades**: View and manage student grades for each course.
- **Graduation Eligibility**: Check which students are eligible for graduation based on their grades and course progress.
- **Comprehensive Reports**: Print detailed reports about students, professors, and courses in the system.

## Data Management

- The system loads data from files such as `students.txt`, `professors.txt`, and `courses.txt` to initialize the records.
- Data can be added or modified through the menu options, and the system will update the respective files.

## File Structure

- **app.cpp**: Main program logic and the execution flow.
- **course.cpp**: Contains code for managing courses.
- **person.cpp**: Defines common functionality for students and professors.
- **professor.cpp**: Handles operations related to professors.
- **student.cpp**: Handles operations related to students.
- **semester.cpp**: Contains logic for managing semesters.
- **menu_functions.cpp**: Functions for displaying and handling menu options.
- **Makefile**: Build instructions to compile the project.
- **students.txt**: Contains student records.
- **professors.txt**: Contains professor records.
- **courses.txt**: Contains course records.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
