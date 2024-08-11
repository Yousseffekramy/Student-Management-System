/*
 ===================================================================================================
 Name        : main.c
 Author      : Youssef Ekramy
 Description :  The Student Management System is a C program designed to manage student
				information efficiently. It allows the user to perform various operations such as
				adding new students, displaying all students, searching for a student by ID,
				updating student details, calculating the average GPA, and finding the student
				with the highest GPA.

				This system utilizes fundamental programming concepts including conditions,
				loops, strings, structs, and pointers, besides the ability to use data structures
				efficiently like the linked list.
 Created on  : Aug 11, 2024
 ===================================================================================================
 */

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/
#include<stdio.h>
#include"System_Functions.h"


/*******************************************************************************
 *                 		       Main Console GUI                                *
 *******************************************************************************/
int main(void)
{
	/* To prevent buffering */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int user_input;
	do
	{
		/* MENU of User_input Choice */
		printf("====================================================\n");
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search for a Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Student with Highest GPA\n");
		printf("8. Exit/Terminate the program\n");
		printf("====================================================\n");
		printf("Enter choice:");
		scanf(" %d",&user_input);

		/* Select the mode according to the user input */
		switch(user_input){
			/* 1. Add Student */
			case 1:
			{
				struct student newStudent;
				printf("====================================================\n");
				printf("Enter Student ID: ");
				scanf(" %d",&newStudent.id);
				printf("Enter Student Name: ");
				scanf(" %s", newStudent.name);
				printf("Enter Student Age: ");
				scanf(" %d", &newStudent.age);
				printf("Enter Student GPA: ");
				scanf(" %f", &newStudent.gpa);
				addStudent(&newStudent);
				break;
			}

			/* 2. Display Students */
			case 2:
			{
				printf("====================================================\n");
				displayStudents();
				break;
			}

			/* 3. Search for a Student by ID */
			case 3:
			{
				printf("====================================================\n");
				int user_input_ID;
				printf("Enter Student ID: ");
				scanf(" %d",&user_input_ID);
				printf("====================================================\n");
				searchStudentByID(user_input_ID);
				break;
			}

			/* 4. Update Student Information */
			case 4:
			{
				printf("====================================================\n");
				int user_input_ID;
				printf("Enter Student ID: ");
				scanf(" %d",&user_input_ID);
				printf("====================================================\n");
				updateStudent(user_input_ID);
				break;
			}

			/* 5. Delete Student */
			case 5:
			{
				printf("====================================================\n");
				int user_input_ID;
				printf("Enter Student ID: ");
				scanf(" %d",&user_input_ID);
				printf("====================================================\n");
				deleteStudent(user_input_ID);
				break;
			}

			/* 6. Calculate Average GPA */
			case 6:
			{
				printf("====================================================\n");
				printf("The average Students GPA : %f \n",calculateAverageGPA());
				break;
			}

			/* 7. Search for Student with Highest GPA */
			case 7:
			{
				printf("=====================================================\n");
				searchHighestGPA();
				break;
			}

			/* 8. Exit / Terminate the program */
			case 8:
			{
				return 0;
			}

			/* Handling user input choice not in range [1:8] */
			default:
			{
				printf("====================================================\n");
				printf("ERROR! This user input choice is not valid.\n");
			}
		}
	} while(1);
}//End of main function
