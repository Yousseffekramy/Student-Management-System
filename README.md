# Project Overview: Student Management System
## Outline
This project is a C-based Student Management System designed to store, update, and manage student records. It uses linked lists for dynamic data management, allowing for efficient handling of student details, including ID, name, age, and GPA.

## Tools
- GCC (GNU Compiler Collection)
- Any text editor (e.g., VS Code, Sublime Text)

<p align="center"> (Preferred Eclipse IDE for Embedded C) </p>

## Design Specifications
The Student Management System includes several key features:

### Core Features
- `Add Student:` Allows the addition of new student records.
- `Display Students:` Displays all stored student information.
- `Search Student by ID:` Searches for a student using their ID.
- `Update Student:` Updates a student's record based on ID.
- `Calculate Average GPA:` Computes the average GPA of all students.
- `Delete Student:` Removes a student's record from the system.
  
### Data Structures
- `Student Structure:` Stores student information such as ID, name, age, and GPA.
- `Linked List:` Manages the student records dynamically, allowing for easy addition, deletion, and traversal of records.

### Functions
- `addStudent:` Adds a student to the list.
- `displayStudents:` Prints all student records.
- `searchStudentByID:` Finds a student by their ID.
- `updateStudent:` Modifies the details of an existing student.
- `calculateAverageGPA:` Returns the average GPA of all students.
- `deleteStudent:` Removes a student from the records by ID.

### Code Files
- [Main File Code](/main.c) 
- [System Functions Implementation](/System_Functions.c)
- [Header File with Declarations](/System_Functions.h)
  
### Resources
This system serves as a basic framework for managing student data in a C environment. It can be expanded to include more complex features as needed.
