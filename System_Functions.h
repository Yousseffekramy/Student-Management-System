/*
 ===================================================================================================
 Name        : System_Functions.h
 Author      : Youssef Ekramy
 Description : Functions Declarations in the Student Management System
 Created on  : Aug 11, 2024
 ===================================================================================================
 */

#ifndef SYSTEM_FUNCTIONS_H_
#define SYSTEM_FUNCTIONS_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 *                   Declaration of Preprocessor Directives                    *
 *******************************************************************************/
// #define NULL (void*)0
#define NAME_SIZE 50

/*******************************************************************************
 *                      Declaration of Student Structure                       *
 *******************************************************************************/
struct student{
	int id;						/* Student ID */
	char name[NAME_SIZE];		/* Student Name */
	int age;					/* Student Age */
	float gpa;					/* Student GPA */
};

/*******************************************************************************
 *                       Declaration of Node Structure                         *
 *******************************************************************************/
struct node{
	struct student data;
	struct node* next;
};

extern struct node* head;  		/* Declaration of head */
extern struct node* Current;	/* Declaration of Current*/
/*******************************************************************************
 *                      Declaration of System Functions                        *
 *******************************************************************************/

/*
 * Description:
	• It adds a new student to the linked list. It first checks if the student's ID
	  already exists.
	• If the ID exists, it prints an error message and returns. If the ID does not
	  exist, it attempts to allocate memory for a new node.
	• If memory allocation fails, it prints an error message and returns.
	• If memory allocation is successful, it copies the student data to the new
	  node and adds the node to the end of the linked list.
 */
void addStudent(const struct student *const ptr);

/*
 * Description:
	• Displays all students in the linked list.
	• If the list is empty, it prints a message indicating no students are present.
	  Otherwise, it traverses the list and prints the details of each student.
 */
void displayStudents(void);

/*
 * Description:
	• It searches for a student by their ID in the linked list.
	• If the student is found, it prints their details.
	• If the student is not found, it prints a message indicating the student was
	  not found
 */
void searchStudentByID(int id);

/*
 * Description:
	• Updates the details of a student with a given ID in the linked list.
	• If the student is found, then update the student's information (student
	  name, age, gpa).
	• If the student is not found, it prints a message indicating the student was
	  not found
 */
void updateStudent(int id);

/*
 * Description:
	• Calculates and returns the average GPA of all students in the linked list.
	• It traverses the list to sum the GPAs of all students and counts the number
	  of students.
	• If the list is empty, it returns 0.0.
	• Otherwise, it computes and returns the average GPA by dividing the total
	  sum of GPAs by the number of students.
 */
float calculateAverageGPA(void);

/*
 * Description:
	• Searches for the student with the highest GPA in the linked list.
	• It traverses the list, keeping track of the student with the highest GPA
	  encountered.
	• If the list is empty, it prints a message indicating that there are no students.
	• After finding the student with the highest GPA, it prints the details of that
	  student.
 */
void searchHighestGPA(void);

/*
 * Description:
	• Iterates through the linked list of students starting with the Head of it to
	  find the student with the given ID.
	• If the student is found, it adjusts the pointers to remove the node from the
	  list, frees the memory allocated for the node, and prints a success message.
	• If the student is not found, it prints a message indicating the student was
	  not found.
 */
void deleteStudent(int id);



#endif /* SYSTEM_FUNCTIONS_H_ */
