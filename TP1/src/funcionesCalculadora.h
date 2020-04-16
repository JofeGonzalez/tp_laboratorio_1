/*
 ============================================================================
 Name        : funcionesCalculadora.h
 Author      : Jose Gonzalez
 Version     : 1.0
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
float suma(float a,float b);
/**
 * \brief Obtiene dos numeros por consola y los resta.
 * \param float a, float b numeros a restar.
 * \return resultado de la resta.
 *
 */
float resta(float a,float b);
/**
 * \brief Obtiene dos numeros por consola y los multiplica.
 * \param float a, float b numeros a multiplicar.
 * \return resultado de la multiplicacion.
 *
 */
float multiplicacion(float a,float b);
/**
 * \brief Obtiene dos numeros por consola y los dividir.
 * \param float a, float b numeros a dividir.
 * \return resultado de la division.
 *
 */
float division(float a,float b);
/**
 * \brief Obtiene un numero y le calcula su factorial.
 * \param int a, numero a calcular su factorial.
 * \return factorial del numero ingresado.
 *
 */
int factorial(int a);

