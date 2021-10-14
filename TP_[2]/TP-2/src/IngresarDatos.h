// amarilla juan sebastian 1C

#ifndef INGRESARDATOS_H_
#define INGRESARDATOS_H_

#include "Validaciones.h"
#include <stdio.h>

/// @fn void pedirEnteroValidado(char[], char[], int*)
/// @brief su funcion es ingresar un entero validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param int* numero
void pedirEnteroValidado(char cadena[], char mensaje[], int* numero);

/// @fn void pedirFlotanteValidado(char[], char[], float*)
/// @brief su funcion es ingresar un flotante validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param float* numero
void pedirFlotanteValidado(char cadena[], char mensaje[], float* numero);

/// @fn void pedirCadenaValidado(char[], char[], char[])
/// @brief su funcion es ingresar una cadena de letras validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param char cadenaValidado[]
void pedirCadenaValidado(char cadena[], char mensaje[], char cadenaValidado[]);

#endif /* INGRESARDATOS_H_ */
