// amarilla juan sebastian 1C

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/// @fn int validarNumeroEntero(int*, char[])
/// @brief su funcion es validar si es un numero entero
///
/// @param int* numeroEntero
/// @param char numero[]
/// @return retorna 1 si salio bien o -1 si salio mal
int validarNumeroEntero(int* numeroEntero, char numero[]);

/// @fn int validarLetras(char[])
/// @brief su funcion es validar si la cadena son letras o son letras y espacios
///
/// @param char cadena[]
/// @return retorna 1 si salio bien o -1 si salio mal
int validarLetras(char cadena[]);

/// @fn int validarNombre(char[], char[])
/// @brief su funcion es validar si la cadena es un nombre y luego devolver el nombre validado por parametro
///
/// @param char cadena[]
/// @param char nombre[]
/// @return retorna 1 si salio bien o -1 si salio mal
int validarNombre(char cadena[], char nombre[]);

#endif /* VALIDACIONES_H_ */
