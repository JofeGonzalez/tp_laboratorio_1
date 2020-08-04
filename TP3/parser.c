#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	char nombre[64];
	char horasTrabajadas[64];
	char sueldo[64];
	char id[64];
	int i = 0;
	Employee *nEmployee;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,
			sueldo);
	do {

		if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,
				horasTrabajadas, sueldo) == 4) {
			nEmployee = employee_newParametros(id, nombre, horasTrabajadas,
					sueldo);
			i++;
			if (nEmployee != NULL && i != 0) {
				ll_add(pArrayListEmployee, (Employee*) nEmployee);
				return 0;
			}
		} else {
			break;
		}
	} while (!feof(pFile));
	return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee nEmployee;
	Employee *auxEmployee;
	int empty = 1;
	do {
		empty = fread(&nEmployee, sizeof(Employee), 1, pFile);
		if (empty == 1) {
			auxEmployee = employee_newParametrosBinario(nEmployee.id,
					nEmployee.nombre, nEmployee.horasTrabajadas,
					nEmployee.sueldo);
			ll_add(pArrayListEmployee, (Employee*) auxEmployee);
			return 0;
		}

	} while (feof(pFile) == 0);

	return 1;
}
