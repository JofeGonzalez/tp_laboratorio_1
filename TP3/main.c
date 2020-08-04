#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	int option = 0;
	LinkedList *listaEmpleados = ll_newLinkedList();
	do {
		printf("1. Carga de datos de empleados en modo texto.\n"
				"2. Carga de datos de empleados en modo binario.\n"
				"3. Alta de empleado.\n"
				"4. Modificar datos de empleado.\n"
				"5. Baja de empleado.\n"
				"6. Listar empleados. \n"
				"7. Ordenar empleados.\n"
				"8. Guardar los datos en modo texto.\n"
				"9. Guardar los datos en modo binario.\n"
				"10. Salir\n");
		utn_getNumero(&option, "Ingrese la opcion deseada\n",
				"Error. Intente de nuevo\n", 1, 10, 3);
		switch (option) {
		case 1:
			controller_loadFromText("data.csv", listaEmpleados);
			break;
		case 2:
			controller_loadFromBinary("data.csv", listaEmpleados);
			break;
		case 3:
			if (!controller_addEmployee(listaEmpleados)) {
				printf("Alta exitosa\n");
			}
			break;
		case 4:
			if (!controller_editEmployee(listaEmpleados)) {
				printf("Modificado exitosamente\n");
			}
			break;
		case 5:
			if (!controller_removeEmployee(listaEmpleados)) {
				printf("Removido exitosamente \n");
			}
			break;
		case 6:
			if (controller_ListEmployee(listaEmpleados) != 0) {
				printf("No se pudo imprimir la lista de empleados\n");
			}
			break;
		case 7:
			controller_sortEmployee(listaEmpleados);
			break;
		case 8:
			if (controller_saveAsText("textFile.csv", listaEmpleados) == 0) {
				printf("Guardado exitosamente\n");
			} else {
				printf("No se pudo guardar\n");
			}
			break;
		case 9:
			if (controller_saveAsBinary("binaryFile.csv", listaEmpleados)
					== 0) {
				printf("Guardado exitosamente\n");
			} else {
				printf("No se pudo guardar\n");
			}
			break;
		}
	} while (option != 10);
	return 0;
}

