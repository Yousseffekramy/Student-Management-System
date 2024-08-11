/*
 ===================================================================================================
 Name        : System_Functions.c
 Author      : Youssef Ekramy
 Description : Functions Definitions in the Student Management System
 Created on  : Aug 11, 2024
 ===================================================================================================
 */

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/
#include "System_Functions.h"

/*******************************************************************************
 *                      Declaration of System Pointers                         *
 *******************************************************************************/

struct node* head = NULL;			/* Declaration of Head */
struct node* Current = NULL;		/* Declaration of Current */

/*******************************************************************************
 *                      Definitions of System Functions                        *
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
void addStudent(const struct student *const ptr)
{
	/* Check this student already exists */
	Current = head;
	while(Current != NULL)
	{
		if(Current->data.id == ptr->id)
		{
			printf("This student already exists in our list.\n");
			return;
		}
		Current = Current -> next;
	}


	/* Allocate a node for the new student */
	struct node* newNode = (struct node*) malloc(sizeof(struct node));

	/* Memory allocation fails => it prints an error message and returns.*/
	if(newNode == NULL)
	{
		printf("ERROR! There is no space for the new student.\n");
		return;
	}

	/* Add data in the new node */
	newNode->data = *ptr;
	newNode->next = NULL;

	/* Add the node in its place in the linked list */
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		Current = head;
		while(Current->next != NULL)
		{
			Current = Current->next;
		}
		Current->next = newNode;
	}
	return;
}

/*
 * Description:
	• Displays all students in the linked list.
	• If the list is empty, it prints a message indicating no students are present.
	  Otherwise, it traverses the list and prints the details of each student.
 */
void displayStudents(void)
{
	if(head == NULL)
	{
		printf("There is no students that are present in our system.\n");
	}
	else
	{
		Current = head;
		while(Current != NULL)
		{
			printf("[ ID: %d, Name: %s, Age: %d, GPA: %f] \n",
					Current->data.id,Current->data.name,
					Current->data.age,Current->data.gpa);
			Current = Current -> next;
		}
	}
}

/*
 * Description:
	• It searches for a student by their ID in the linked list.
	• If the student is found, it prints their details.
	• If the student is not found, it prints a message indicating the student was
	  not found
 */
void searchStudentByID(int id)
{
	/* Check if the list is empty */
	if(head == NULL)
	{
		printf("There is no students that are present in our system.\n");
		return;
	}
	else
	{
		Current = head;

		/* Loop in the list and check its presence */
		while(Current != NULL)
		{
			if(Current->data.id == id)
			{
				printf("Student is found: \n");
				printf("ID: %d, Name: %s, Age: %d, GPA: %f \n",
						Current->data.id,Current->data.name,
						Current->data.age,Current->data.gpa);
				return;
			}
			Current = Current -> next;
		}
		printf("The student of ID: %d was not found.\n",id);
		return;
	}
}

/*
 * Description:
	• Updates the details of a student with a given ID in the linked list.
	• If the student is found, then update the student's information (student
	  name, age, gpa).
	• If the student is not found, it prints a message indicating the student was
	  not found
 */
void updateStudent(int id)
{
	/* Check if the list is empty */
	if(head == NULL)
	{
		printf("There is no students that are present in our system.\n");
		return;
	}
	else
	{
		Current = head;

		/* Loop in the list and check its presence */
		while(Current != NULL)
		{
			if(Current->data.id == id)
			{
				/* Update the new data */
				printf("Enter new Name: ");
				scanf(" %s", (Current->data.name));
				printf("Enter new Age: ");
				scanf(" %d", &(Current->data.age));
				printf("Enter new GPA: ");
				scanf(" %f", &(Current->data.gpa));
				printf("The Student Information is updated successfully.\n");
				return;
			}
			Current = Current -> next;
		}
		printf("The student of ID: %d was not found.\n",id);
		return;
	}
}

/*
 * Description:
	• Calculates and returns the average GPA of all students in the linked list.
	• It traverses the list to sum the GPAs of all students and counts the number
	  of students.
	• If the list is empty, it returns 0.0.
	• Otherwise, it computes and returns the average GPA by dividing the total
	  sum of GPAs by the number of students.
 */
float calculateAverageGPA(void)
{
	/* Check if the list is empty */
	if(head == NULL)
	{
		printf("There is no students that are present in our system.\n");
		return 0.0;
	}

	int counter = 0;
	float sum = 0;
	Current = head;

	while(Current != NULL)
	{
		sum += Current->data.gpa;
		counter++;
		Current = Current -> next;
	}

	return (sum/counter);
}

/*
 * Description:
	• Searches for the student with the highest GPA in the linked list.
	• It traverses the list, keeping track of the student with the highest GPA
	  encountered.
	• If the list is empty, it prints a message indicating that there are no students.
	• After finding the student with the highest GPA, it prints the details of that
	  student.
 */
void searchHighestGPA(void)
{
	/* Check if the list is empty */
	if(head == NULL)
	{
		printf("There is no students that are present in our system.\n");
		return ;
	}

	/* Logic for getting max GPA */
	int max = head->data.gpa;
	Current = head;
	while(Current != NULL)
	{
		if(max < Current->data.gpa)
		{
			max = Current ->data.gpa;
		}
		Current = Current -> next;
	}

	Current = head;
	while(Current != NULL)
	{
		if(max == Current->data.gpa)
		{
			printf("Student with the highest GPA: \n");
			printf("ID: %d, Name: %s, Age: %d, GPA: %f \n",
					Current->data.id,Current->data.name,
					Current->data.age,Current->data.gpa);
			return;
		}
		Current = Current -> next;
	}
}

/*
 * Description:
	• Iterates through the linked list of students starting with the Head of it to
	  find the student with the given ID.
	• If the student is found, it adjusts the pointers to remove the node from the
	  list, frees the memory allocated for the node, and prints a success message.
	• If the student is not found, it prints a message indicating the student was
	  not found.
 */
void deleteStudent(int id)
{
	/* Check if the list is empty */
	if(head == NULL)
	{
		printf("There is no students that are present in our system.\n");
		return;
	}
	else
	{
		Current = head;

		/* Loop in the list and check its presence */
		while(Current->next != NULL)
		{
			if(Current->next->data.id == id)
			{
				/* Delete the required student */
				struct node* nextElement = Current->next->next;
				free(Current->next);
				Current->next = nextElement;
				printf("The student is deleted from the list successfully.\n");
				return;
			}
			Current = Current -> next;
		}
		printf("The student of ID: %d was not found.\n",id);
		return;
	}

}


