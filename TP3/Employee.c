#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"
static int isValidNombre(char *cadena, int longitud);
Employee* employee_new() {
	Employee *auxPointer = NULL;
	auxPointer = (Employee*) malloc(sizeof(Employee));
	return auxPointer;
}
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *auxEmployee = NULL;
	auxEmployee = employee_new();
	if (auxEmployee != NULL) {
		auxEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
		auxEmployee->id = atoi(idStr);
		strncpy(auxEmployee->nombre, nombreStr, 128);
		auxEmployee->sueldo = atof(sueldoStr);
	} else {
		employee_delete(auxEmployee);
		auxEmployee = NULL;
	}
	return auxEmployee;
}
Employee* employee_newParametrosBinario(int id, char *nombreStr,
		int horasTrabajadas, float sueldo) {
	Employee *auxEmployee = NULL;
	auxEmployee = employee_new();
	if (auxEmployee != NULL) {
		auxEmployee->id = id;
		strncpy(auxEmployee->nombre, nombreStr, 128);
		auxEmployee->horasTrabajadas = horasTrabajadas;
		auxEmployee->sueldo = sueldo;

	} else {
		employee_delete(auxEmployee);
		auxEmployee = NULL;
	}
	return auxEmployee;
}

void employee_delete(Employee *auxEmployee) {
	if (auxEmployee != NULL) {
		free(auxEmployee);
	}
}

int employee_setId(Employee *this, int id) {
	if (this != NULL && id > 0) {
		this->id = id;
		return 0;
	}
	return -1;
}
int employee_getId(Employee *this, int *id) {
	if (this != NULL && id != NULL) {
		*id = this->id;
		return 0;
	}
	return -1;
}

int employee_setNombre(Employee *this, char *nombre) {
	if (this != NULL && nombre != NULL) {
		if (isValidNombre(nombre, 32)) {
			strncpy(this->nombre, nombre, 32);
			return 0;
		}
	}
	return -1;
}
int employee_getNombre(Employee *this, char *nombre) {
	if (this != NULL && nombre != NULL) {
		strncpy(nombre, this->nombre, 32);
		return 0;
	}
	return -1;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {

	if (this != NULL && horasTrabajadas > 0) {
		this->horasTrabajadas = horasTrabajadas;
		return 0;

	}
	return -1;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	if (this != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		return 0;

	}
	return -1;
}

int employee_setSueldo(Employee *this, float sueldo) {
	if (this != NULL && sueldo >= 0) {
		this->sueldo = sueldo;
		return 0;
	}
	return -1;
}
int employee_getSueldo(Employee *this, float *sueldo) {
	if (this != NULL) {
		*sueldo = this->sueldo;
		return 0;
	}
	return -1;
}

int printEmployee(Employee *this) {
	if (this != NULL) {
		printf("%d   %s   %d   $%.2f\n", this->id, this->nombre,
				this->horasTrabajadas, this->sueldo);
		return 0;
	}
	return -1;
}
int employee_SortByName(void *name1, void *name2) {
	char auxName1[32];
	char auxName2[32];
	employee_getNombre((Employee*)name1, auxName1);
	employee_getNombre((Employee*)name2, auxName2);
	if(name1!=NULL && name2!=NULL)
	{
		return strcmp(auxName1, auxName2);
	}
	return 0;
}

static int isValidNombre(char *cadena, int longitud) {
	int i = 0;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')) {
				return 0;
				break;
			}
		}
	}
	return -1;
}
