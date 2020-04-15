/*
 ============================================================================
 Name        : funcionesCalculadora.h
 Author      : Jose Gonzalez
 Version     : 1.2
 Copyright   :
 Description : Funciones utilizadas para una calculadora
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * \brief Obtiene dos numeros por consola y los suma.
 * \param float a, float b numeros a sumar.
 * \return resultado de la suma.
 *
 */
float suma(float a,float b){
	float resultado;
	resultado=a+b;
	return resultado;
}
/**
 * \brief Obtiene dos numeros por consola y los resta.
 * \param float a, float b numeros a restar.
 * \return resultado de la resta.
 *
 */
float resta(float a,float b){
	float resultado;
	resultado=a-b;
	return resultado;
}
/**
 * \brief Obtiene dos numeros por consola y los multiplica.
 * \param float a, float b numeros a multiplicar.
 * \return resultado de la multiplicacion.
 *
 */
float multiplicacion(float a,float b){
	float resultado;
	resultado=a*b;
	return resultado;
}
/**
 * \brief Obtiene dos numeros por consola y los dividir.
 * \param float a, float b numeros a dividir.
 * \return resultado de la division.
 *
 */
float division(float a,float b){
	float resultado;
	if(b==0){
		perror("No es posible dividir por cero");
		exit(0);
	}
	resultado=a/b;
	return resultado;
}
/**
 * \brief Obtiene un numero y le calcula su factorial.
 * \param int a, numero a calcular su factorial.
 * \return factorial del numero ingresado.
 *
 */
int factorial(int a){
	int entero;
	int resultadoA;
	int i;

	resultadoA=1;

	entero=(int)a;
	for(i=1; i<entero+1; i++){
			resultadoA=resultadoA*i;
	}
	return resultadoA;
}
