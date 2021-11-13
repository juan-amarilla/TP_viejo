// amarilla juan sebastian 1C

#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @fn void menu()
/// @brief su funcion es mostrar un menu de opciones
///
void menu();

/// @fn void menuModificacion()
/// @brief su funcion es mostrar un menu de opciones para modificar algo
///
void menuModificacion();

/// @fn void mensajeEstado(int, char[], char[], char[])
/// @brief su funcion es mostrar uno de los tres mensajes
///
/// @param int estado
/// @param char valido[]
/// @param char errorProceso[]
/// @param char noValido[]
void mensajeEstado(int estado, char valido[], char errorProceso[], char noValido[]);

/// @fn void mayusculasAutomaticos(char[], int)
/// @brief su funcion es crear mayusculas automaticos
///
/// @param char cadena[]
/// @param int tam
void mayusculasAutomaticos(char cadena[], int tam);

#endif /* OTRASFUNCIONES_H_ */
