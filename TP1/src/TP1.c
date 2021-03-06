/*
 ============================================================================
 Name        : TP1.c
 Author      : Jose Gonzalez
 Version     : 2.0
 Copyright   :
 Description : TP1 (Calculadora)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

int main() {
	setbuf(stdout, NULL);
	float numero1 = 0;
	float numero2 = 0;
	float respuestaSuma;
	float respuestaResta;
	float respuestaDivision;
	float respuestaMultiplicacion;
	float respuestaFactorialA;
	float respuestaFactorialB;
	int opcion;
	int opcionOperaciones;
	int opcionResultados;
	char pregunta = 's';
	int auxiliarNumero1; //Saber si se ingreso el primer numero
	int auxiliarNumero2; //Saber si se ingreso el segundo numero
	int auxiliarSuma; //Saber si se calculo la suma
	int auxiliarResta; //Saber si se calculo la resta
	int auxiliarDivision; //Saber si se calculo la division
	int auxiliarMultiplicacion; //Saber si se calculo la multiplicacion
	int auxiliarFactorial; //Saber si se calcularon los factoriales
	do {
		printf("1. Ingresar 1er operando (A= %.2f)\n", numero1);
		printf("2. Ingresar 2do operando (B= %.2f)\n", numero2);
		printf("3. Calcular operaciones\n");
		printf("	1) Calcular la suma (A+B)\n");
		printf("	2) Calcular la resta (A-B)\n");
		printf("	3) Calcular la division (A/B)\n");
		printf("	4) Calcular la multiplicacion (A*B)\n");
		printf("	5) Calcular el factorial (A! y B!)\n");
		printf("	6) Calcular todas las opciones\n");
		printf("4. Informar resultados\n");
		printf("	1) El resultado de A+B es: \n");
		printf("	2) El resultado de A-B es: \n");
		printf("	3) El resultado de A/B es: \n");
		printf("	4) El resultado de A*B es: \n");
		printf("	5) El factorial de A es:  y El factorial de B es: \n");
		printf("	6) El resultado de todas las operaciones es: \n");
		printf("5. Salir\n");
		printf("Que desea hacer?\n");
		scanf("%d", &opcion);
		setbuf(stdin, NULL);
		switch (opcion) {
		case 1:
			printf("Ingrese un numero");
			scanf("%f", &numero1);
			setbuf(stdin, NULL);
			auxiliarNumero1 = 1;
			break;
		case 2:
			printf("Ingrese un numero");
			scanf("%f", &numero2);
			setbuf(stdin, NULL);
			auxiliarNumero2 = 1;
			break;
		case 3:
			if (auxiliarNumero1 != 1 || auxiliarNumero2 != 1) {
				printf("No ingreso ambos numeros");
			} else {
				printf("Ingrese la operacion a realizar: \n");
				scanf("%d", &opcionOperaciones);
				setbuf(stdin, NULL);
				switch (opcionOperaciones) {
				case 1:
						respuestaSuma = suma(numero1, numero2);
						auxiliarSuma = 1;
					break;
				case 2:
						respuestaResta = resta(numero1, numero2);
						auxiliarResta = 1;
					break;
				case 3:
						respuestaDivision = division(numero1, numero2);
						auxiliarDivision = 1;
					break;
				case 4:
						respuestaMultiplicacion = multiplicacion(numero1, numero2);
						auxiliarMultiplicacion = 1;
					break;
				case 5:
						respuestaFactorialA = factorial(numero1);
						respuestaFactorialB = factorial(numero2);
						auxiliarFactorial = 1;
					break;
				case 6:
						respuestaSuma = suma(numero1, numero2);
						respuestaResta = resta(numero1, numero2);
						respuestaDivision = division(numero1, numero2);
						respuestaMultiplicacion = multiplicacion(numero1, numero2);
						respuestaFactorialA = factorial(numero1);
						respuestaFactorialB = factorial(numero2);

					break;
				default:
					printf("Opcion no valida\n");
					break;
				}
			}
				break;
		case 4:
			printf("Ingrese el resultado a imprimir: \n");
			scanf("%d", &opcionResultados);
			setbuf(stdin, NULL);
			switch (opcionResultados) {
			case 1:
				if (auxiliarSuma == 1) {
					printf("El resultado de A+B es: %f\n", respuestaSuma);
				} else {
					printf("No se calculo la suma previamente");
				}
				break;
			case 2:
				if (auxiliarResta == 1) {
					printf("El resultado de A-B es: %f\n", respuestaResta);
				} else {
					printf("No se calculo la resta previamente");
				}
				break;
			case 3:
				if (auxiliarDivision == 1) {
					printf("El resultado de A/B es: %f\n", respuestaDivision);
				} else {
					printf("No se calculo la division previamente");
				}
				break;
			case 4:
				if (auxiliarMultiplicacion == 1) {
					printf("El resultado de A*B es: %f\n",
							respuestaMultiplicacion);
				} else {
					printf("No se calculo la multiplicacion previamente");
				}
				break;
			case 5:
				if (auxiliarFactorial == 1) {
					printf(
							"El factorial de A es: %.0f y el factorial de B es: %.0f\n",
							respuestaFactorialA, respuestaFactorialB);
				} else {
					printf("No se calcularon los factoriales previamente");
				}
				break;
			case 6:
				if (auxiliarSuma == 1 && auxiliarResta == 1
						&& auxiliarDivision == 1 && auxiliarMultiplicacion == 1
						&& auxiliarFactorial == 1) {
					printf("El resultado de A+B es: %f\n", respuestaSuma);
					printf("El resultado de A-B es: %f\n", respuestaResta);
					printf("El resultado de A/B es: %f\n", respuestaDivision);
					printf("El resultado de A*B es: %f\n",
							respuestaMultiplicacion);
					printf(
							"El factorial de A es: %.0f y el factorial de B es: %.0f\n",
							respuestaFactorialA, respuestaFactorialB);
				} else {
					printf("No se calculo alguna operacion previamente");
				}
				break;
			default:
				printf("Opcion no valida\n");
				break;
			}
			break;
		case 5:
			exit(-1);
		default:
			printf("Opcion no valida\n");
		}
		printf("\nDesea realizar otra operacion?");
		scanf("%c", &pregunta);
		setbuf(stdin, NULL);
	} while (pregunta == 's');
}
