// amarilla juan sebastian 1C

#ifndef INGRESARDATOS_H_
#define INGRESARDATOS_H_

#include "Validaciones.h"
#include <stdio.h>
#define TAM_CARACTER 128

/// @fn void pedirEnteroValidado(char[], char[], int*)
/// @brief su funcion es pedir un entero validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param int* numero
void pedirEnteroValidado(char cadena[], char mensaje[], int* numero);

/// @fn void pedirNombre(char[], char[], char[])
/// @brief su funcion es pedir un nombre validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param char nombre[]
void pedirNombre(char cadena[], char mensaje[], char nombre[]);


#endif /* INGRESARDATOS_H_ */
