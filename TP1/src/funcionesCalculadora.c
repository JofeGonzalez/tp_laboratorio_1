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


float suma(float a,float b){
	float resultado;
	resultado=a+b;
	return resultado;
}

float resta(float a,float b){
	float resultado;
	resultado=a-b;
	return resultado;
}

float multiplicacion(float a,float b){
	float resultado;
	resultado=a*b;
	return resultado;
}

float division(float a,float b){
	float resultado;
	if(b==0){
		perror("No es posible dividir por cero");
		exit(0);
	}
	resultado=a/b;
	return resultado;
}

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
