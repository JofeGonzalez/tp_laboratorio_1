#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int r = 0;
	FILE *pFile = NULL;
	if (pArrayListEmployee != NULL && path != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			r = parser_EmployeeFromText(pFile, pArrayListEmployee);
			if (r != 0) {
				printf("Error al leer el archivo\n");
				fclose(pFile);
			} else {
				printf("Archivo leido con exito\n");
			}
		} else {
			printf("Error. El archivo no pudo ser leido\n");
		}
	}
	return r;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	setbuf(stdin,NULL);
	int r = 0;
	FILE *pFile = NULL;
	if (pArrayListEmployee != NULL && path != NULL) {
		pFile = fopen(path, "rb");
		if (pFile != NULL) {
			r = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			if (r != 0) {
				printf("Error al leer el archivo\n");
				fclose(pFile);
			} else {
				printf("Archivo leido con exito\n");
			}
		} else {
			printf("Error. El archivo no pudo ser leido\n");
		}
	}
	return r;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	char auxName[32];
	int auxHours;
	int auxSalary;
	int auxId = ll_len(pArrayListEmployee) + 1;
	Employee *auxEmployee = employee_new();
	if (ll_len(pArrayListEmployee) == 0) {
		printf("No hay datos cargados");
	} else {
		if (pArrayListEmployee != NULL && auxEmployee != NULL) {
			if ((!utn_getNombre(auxName, 32, "Ingrese el nombre del empleado\n",
					"Error. Intente de nuevo\n", 3))
					&& (!utn_getNumero(&auxHours,
							"Ingrese la cantidad de horas trabajadas\n",
							"Error. Intente de nuevo\n", 0, 500, 3))
					&& (!utn_getNumero(&auxSalary,
							"Ingrese el salario del empleado\n",
							"Error. Intente de nuevo\n", 0, 100000, 3))) {
				if (!employee_setId(auxEmployee, auxId)
						&& !employee_setNombre(auxEmployee, auxName)
						&& !employee_setHorasTrabajadas(auxEmployee, auxHours)
						&& !employee_setSueldo(auxEmployee, auxSalary)) {
					ll_add(pArrayListEmployee, auxEmployee);
					return 0;
				}
			}
		}
	}
	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int id;
	int opcion;
	char name[128];
	int hours;
	int salary;
	int i;
	Employee *auxEmployee;

	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		if (!utn_getNumero(&id, "Ingrese el ID del empleado a modificar\n",
				"Error", 1, 5000, 2) && id <= ll_len(pArrayListEmployee)) {
			for (i = 0; id < ll_len(pArrayListEmployee); i++) {
				auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				if (auxEmployee->id == id) {
					printEmployee(auxEmployee);
					break;
				}
			}

			while (opcion != 4) {
				if (!utn_getNumero(&opcion, "Que desea modificar?\n"
						"1. Nombre\n"
						"2. Salario\n"
						"3. Horas\n"
						"4. Salir \n", "Error", 1, 4, 3)) {
					switch (opcion) {
					case 1:
						if (!utn_getNombre(name, 32, "Ingrese el nombre",
								"Error. Intente de nuevo", 2)) {
							employee_setNombre(auxEmployee, name);
							printf("Se ha cambiado el nombre exitosamente\n");
						}
						break;
					case 2:
						if (!utn_getNumero(&hours,
								"Ingrese la cantidad de horas trabajadas\n",
								"Error. Intente de nuevo", 1, 300, 3)) {
							employee_setHorasTrabajadas(auxEmployee, hours);
							printf(
									"Se ha modificado la cantidad de horas trabajadas exitosamente\n");
						}
						break;
					case 3:
						if (!utn_getNumero(&salary, "Ingrese el salario\n",
								"Error. Intente de nuevo", 500, 100000, 3)) {
							employee_setSueldo(auxEmployee, salary);
							printf(
									"Se ha modificado el salario exitosamente\n");
						}
						break;
					}
				}
				return 0;
			}
		}

	}
	return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int id;
	Employee *auxEmployee;
	int i;
	if (pArrayListEmployee != NULL) {
		if (!utn_getNumero(&id, "Ingrese el ID a eliminar\n",
				"Error. Intente de nuevo", 1, 3000, 3)
				&& id <= ll_len(pArrayListEmployee)) {
			for (i = 0; i < ll_len(pArrayListEmployee); i++) {
				auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				if (auxEmployee->id == id) {
					ll_remove(pArrayListEmployee, i);
					return 0;
				} else {
					printf("No se ha encontrado el ID\n");
				}
			}
		}
	}
	return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	Employee *auxiliarEmployee;
	int i=0;
	printf("ID   NOMBRE   HORASTRABAJADAS   SUELDO\n");
	for (i = 0; i < ll_len(pArrayListEmployee); i++) {
		auxiliarEmployee = (Employee*) ll_get(pArrayListEmployee, i);
		if (auxiliarEmployee != NULL) {
			printEmployee(auxiliarEmployee);
			return 0;
		}
	}
	return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int sortOption = 0;
	if (pArrayListEmployee != NULL) {
		if (!utn_getNumero(&sortOption, "Ingrese la opcion de ordenamiento\n"
				"1. Ascendente\n"
				"2.Descendente\n"
				"3.Salir.\n", "Error opcion incorrecta", 1, 3, 3)) {
			switch (sortOption) {
			case 1:
				ll_sort(pArrayListEmployee, employee_SortByName, 1);
				break;
			case 2:
				ll_sort(pArrayListEmployee, employee_SortByName, 0);
				break;
			}
		}
	}
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *newFile;
	int i = 0;
	Employee *auxEmployee;
	char name[32];
	float salary;
	int hours;
	int id;

	if (path != NULL && pArrayListEmployee != NULL) {
		newFile = fopen(path, "w+");
		for (i = 0; i < ll_len(pArrayListEmployee); i++) {
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &id);
			employee_getNombre(auxEmployee, name);
			employee_getHorasTrabajadas(auxEmployee, &hours);
			employee_getSueldo(auxEmployee, &salary);
			fprintf(newFile, "%d,%s,%d,%.2f\n", id, name, hours, salary);
			return 0;
		}
		fclose(newFile);
	}
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *newFile;
	int i = 0;
	Employee *auxEmployee;

	if (path != NULL && pArrayListEmployee != NULL) {
		newFile = fopen(path, "w+b");
		for (i = 0; i < ll_len(pArrayListEmployee); i++) {
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee, sizeof(Employee), 1, newFile);
			return 0;
		}
		fclose(newFile);
	}
	return 1;
}

