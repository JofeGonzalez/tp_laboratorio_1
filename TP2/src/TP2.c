/*
 ============================================================================
 Name        : TP2.c
 Author      : Jose Gonzalez
 Version     : 3.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MAX_EMPLOYEES 5

int main(void) {
	setbuf(stdout, NULL);
	Employee aEmployees[MAX_EMPLOYEES];
	int firstOption;
	char secondOption;
	char thirdOption;
	int fourthOption;
	int fifthOption;
	char answer = 'n';
	int id = 0;
	int changeDataID;
	int removeDataID;
	int findEmployeeDone;
	int removeEmployeeDone;
	int addEmployeeCondition = 0;
	int changeVerifierIDData = 0;
	int removeVerifierIDData = 0;

	initEmployees(aEmployees, MAX_EMPLOYEES);
	do {
		printf("Que desea hacer?\n");
		printf("1. Dar de Alta a un empleado\n");
		printf("2. Modificar un empleado\n");
		printf("3. Dar de Baja a un empleado\n");
		printf("4. Informar:\n");
		printf("	1) Lista de empleados ordenados por Apellido y Sector\n");
		printf(
				"	2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
		scanf("%d", &firstOption);
		setbuf(stdin, NULL);
		switch (firstOption) {
		case 1:
			if (chargeEmployeeData(aEmployees, MAX_EMPLOYEES, id)) {
				printf("Alta Realizada\n");
				id++;
			}
			addEmployeeCondition++;
			break;
		case 2:
			if (addEmployeeCondition > 0) {
				printf("Ingrese el ID del empleado\n");
				scanf("%d", &changeDataID);
				changeDataID = changeDataID - 1;
				setbuf(stdin, NULL);
				if (changeDataID != ' ' || changeDataID != '\0') {
					changeVerifierIDData = 1;
				}
				if (changeVerifierIDData == 1) {
					findEmployeeDone = findEmployeeById(aEmployees,
					MAX_EMPLOYEES, changeDataID);
					if (findEmployeeDone != -1) {
						printf(
								"Quiere modificar los datos del empleado? (s or n)\n");
						scanf("%c", &secondOption);
						setbuf(stdin, NULL);
						switch (secondOption) {
						case 's':
							if (changeEmployeeData(aEmployees, MAX_EMPLOYEES,
									changeDataID)) {
								printf("Modificacion Realizada");
							}
							break;
						case 'n':
							printf("Modificacion no Realizada");
							break;
						default:
							printf("La opcion ingresada no es valida");
							break;
						}
					} else {
						printf("No se pudo Encontrar el empleado");
					}
				} else {
					printf("No ingreso un ID");
				}
			} else {
				printf(
						"No se puede modificar un empleado sin haber agregado uno antes\n");
			}
			break;
		case 3:
			if (addEmployeeCondition > 0) {
				printf("Ingrese el ID del empleado\n");
				scanf("%d", &removeDataID);
				removeDataID=removeDataID-1;
				setbuf(stdin, NULL);
				if (removeDataID != ' ' || removeDataID != '\0') {
					removeVerifierIDData = 1;
				}
				if (removeVerifierIDData == 1) {
					findEmployeeById(aEmployees, MAX_EMPLOYEES, removeDataID);
					printf("Quiere dar de baja al empleado? (s or n)\n");
					scanf("%c", &thirdOption);
					setbuf(stdin, NULL);
					switch (thirdOption) {
					case 's':
						removeEmployeeDone = removeEmployee(aEmployees,
						MAX_EMPLOYEES, removeDataID);
						if (removeEmployeeDone == 0) {
							printf("Baja Realizada\n");
						} else {
							printf("No se pudo realizar la baja");
						}
						break;
					case 'n':
						printf("Baja no Realizada");
						break;
					default:
						printf("La opcion ingresada no es valida");
						break;
					}
				}
			} else {
				printf(
						"No puede dar de baja a un empleado sin antes agregar uno.\n");
			}
			break;
		case 4:
			if (addEmployeeCondition > 0) {
				printf("Que desea informar?\n");
				scanf("%d", &fourthOption);
				setbuf(stdin, NULL);
				switch (fourthOption) {
				case 1:
					fifthOption =
							getInt(
									"Desde ordenar de forma ascendente(1) o descendente(0)?");
					switch (fifthOption) {
					case 0:
						sortEmployees(aEmployees, MAX_EMPLOYEES, 0);
						break;
					case 1:
						sortEmployees(aEmployees, MAX_EMPLOYEES, 1);
						break;
					default:
						printf(
								"La opcion ingresada no es valida. Por favor intente de nuevo");
						break;
					}
					break;
				case 2:
					salaryEmployee(aEmployees, MAX_EMPLOYEES);
					break;
				default:
					printf(
							"La opcion ingresada no es valida. Por favor intente de nuevo");
					break;
				}
				break;
				default:
				printf(
						"La opcion ingresada no es valida. Por favor intente de nuevo\n");
			} else {
				printf(
						"No se puede informar ya que no se han ingresado empleados\n");
			}
			break;
		}
		printf("Desea realizar otra operacion?");
		scanf("%c", &answer);
		setbuf(stdin, NULL);
	} while (answer == 's');
}
