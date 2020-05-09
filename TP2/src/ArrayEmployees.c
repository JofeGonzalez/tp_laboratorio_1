/*
 ============================================================================
 Name        : ArrayEmployees.c
 Author      : Jose Gonzalez
 Version     : 2.0
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define L 51

int initEmployees(Employee *list, int len) {
	int i;
	int r = -1; //return
	if (len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 1;
			r = 0;
		}
	}
	return r;
}

int findFreeSpace(Employee *list, int len) {
	int ID = -1;
	int i;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == 1) {
			ID = i;
			break;
		}
	}
	return ID;
}

Employee addEmployee(Employee *list, int len, int id, char name[],
		char lastName[], float salary, int sector) {
	Employee newEmployee;
	newEmployee.ID = id;
	strcpy(newEmployee.name, name);
	strcpy(newEmployee.lastName, lastName);
	newEmployee.salary = salary;
	newEmployee.sector = sector;
	newEmployee.isEmpty = 0;
	return newEmployee;
}

int chargeEmployeeData(Employee *list, int len, int id) {
	int r = 0; //retorno
	int ID;
	char name[L];
	char lastName[L];
	char salary[L];
	char sector[L];
	float salaryAuxiliar;
	int sectorAuxiliar;
	ID = findFreeSpace(list, len);
	if (ID == -1) {
		printf("No hay espacios libres");
	} else {
		fflush(stdin);
		if (!getStringLetras("Ingrese el nombre del empleado: ", name)) {
			printf("El nombre debe contener solo letras");
		}
		fflush(stdin);
		if (!getStringLetras("Ingrese el apellido del empleado: ", lastName)) {
			printf("El apellido debe contener solo letras");
		}
		fflush(stdin);
		if (!getStringNumerosFlotantes("Ingrese el sueldo del empleado: ",
				salary)) {
			printf("La cantidad solo debe ser numerica");
		}
		salaryAuxiliar = atof(salary);
		fflush(stdin);
		if (!getStringNumeros("Ingrese el sector del empleado: ", sector)) {
			printf("El sector debe ser numerico");
		}
		sectorAuxiliar = atoi(sector);
		list[ID] = addEmployee(list, len, ID, name, lastName, salaryAuxiliar,
				sectorAuxiliar);
		r = 1;
	}
	return r;
}

int findEmployeeById(Employee *list, int len, int id) {
	if (id < 0 || id > 1000 || list[id].isEmpty == 1) {
		return -1;
	} else {
		printf("ID: %d\n", list[id].ID + 1);
		printf("Nombre: %s\n", list[id].name);
		printf("Apellido: %s\n", list[id].lastName);
		printf("Salario: %.2f\n", list[id].salary);
		printf("Sector: %d\n", list[id].sector);
	}
	return 0;
}

int changeEmployeeData(Employee *list, int len, int id) {
	int r = 0; //retorno
	int ID;
	char name[L];
	char lastName[L];
	char salary[L];
	char sector[L];
	float salaryAuxiliar;
	int sectorAuxiliar;
	ID = id;
	fflush(stdin);
	if (!getStringLetras("Ingrese el nombre del empleado: ", name)) {
		printf("El nombre debe contener solo letras");
	}
	fflush(stdin);
	if (!getStringLetras("Ingrese el apellido del empleado: ", lastName)) {
		printf("El apellido debe contener solo letras");
	}
	fflush(stdin);
	if (!getStringNumerosFlotantes("Ingrese el sueldo del empleado: ",
			salary)) {
		printf("La cantidad solo debe ser numerica");
	}
	salaryAuxiliar = atof(salary);
	fflush(stdin);
	if (!getStringNumeros("Ingrese el sector del empleado: ", sector)) {
		printf("El sector debe ser numerico");
	}
	sectorAuxiliar = atoi(sector);
	list[ID] = addEmployee(list, len, ID, name, lastName, salaryAuxiliar,
			sectorAuxiliar);
	r = 1;
	return r;
}

int removeEmployee(Employee *list, int len, int id) {

	list[id].isEmpty = 1;
	if (list[id].isEmpty == 1) {
		return 0;
	} else {
		return -1;
	}
}

int sortEmployees(Employee *list, int len, int order) {
	int i, j;
	Employee auxiliarLastName;
	Employee auxiliarSector;
	if (order == 0) {
		for (i = 0; i < len - 1; i++) {
			if (list[i].isEmpty != 0) {
				continue;
			}
			for (j = i + 1; j < len; j++) {
				if (list[j].isEmpty != 0) {
					continue;
				}
				if (strcmp(list[j].lastName, list[i].lastName) == 0) {
					auxiliarSector = list[i];
					list[i] = list[j];
					list[j] = auxiliarSector;
				} else {
					auxiliarLastName = list[j];
					list[j] = list[i];
					list[i] = auxiliarLastName;
				}
			}
		}
		printEmployees(list, len);
	} else {
		for (i = 0; i < len - 1; i++) {
			if (list[i].isEmpty == 0) {
				continue;
			}
			for (j = i + 1; j < len; j++) {
				if (list[j].isEmpty == 0) {
					continue;
				}
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {
					auxiliarSector = list[j];
					list[j] = list[i];
					list[i] = auxiliarSector;
				} else {
					auxiliarLastName = list[i];
					list[i] = list[j];
					list[j] = auxiliarLastName;
				}
			}
		}
		printEmployees(list, len);
	}
	return 0;
}

int salaryEmployee(Employee *list, int len) {
	int r = -1;
	int i;
	float totalSalary = 0;
	float promSalary = 0;
	int countEmployees = 0;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty != 1) {
			totalSalary = totalSalary + list[i].salary;
			countEmployees++;
		}
		r = 0;
	}
	promSalary = totalSalary / countEmployees;
	printf("La suma total de los salarios es: %f \n", totalSalary);
	printf("El promedio de los salarios es: %f \n", promSalary);
	return r;
}

int printEmployees(Employee *list, int len) {
	int i;
	printf("ID     Nombre     Apellido     Salario     Sector\n");
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty != 1) {
			printf("%d     %s    %s     %.2f    %d\n", list[i].ID + 1,
					list[i].name, list[i].lastName, list[i].salary,
					list[i].sector);
		}
	}
	return 0;
}

