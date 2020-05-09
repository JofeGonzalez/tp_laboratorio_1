/*
 ============================================================================
 Name        : ArrayEmployees.h
 Author      : Jose Gonzalez
 Version     : 2.0
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int ID;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

/** \brief To indicate that all positions in the array are empty,
 *		   this function put the flag (isEmpty) in TRUE in all
 *		   positions of the array.
 *	\param Employee* list Pointer to array of employees.
 *	\param int len length of the array.
 *	\return -1 if Error, 0 if OK.
 */
int initEmployees(Employee *list, int len);

/** \brief Search next isEmpty = 1 in the array.
 *	\param Employee* list Pointer to array of employees.
 *	\param int len length of the array.
 *	return ID.
 */
int findFreeSpace(Employee *list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 free space] - (0) if Ok
 */
Employee addEmployee(Employee *list, int len, int id, char name[],
		char lastName[], float salary, int sector);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 free space] - (0) if Ok
 */
int chargeEmployeeData(Employee *list, int len, int id);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */
int findEmployeeById(Employee *list, int len, int id);

/** \brief modify an employee´s data
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return (-1) if Error, 0 if OK.
 */
int changeEmployeeData(Employee *list, int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee *list, int len, int id);

/** \brief Sort the elements un the array of the employees, the argument order indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP. [0] indicate DOWN.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee *list, int len, int order);

/** \brief Calculate the sum of wages and the average of all
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP. [0] indicate DOWN.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int salaryEmployee(Employee *list, int len);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee *list, int len);
