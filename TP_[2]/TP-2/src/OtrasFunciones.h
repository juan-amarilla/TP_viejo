// amarilla juan sebastian 1C

#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_

#include <stdio.h>
#include "ArrayEmployees.h"

/// @fn void menu()
/// @brief su funcion es mostrar un menu de opciones
///
void menu();

/// @fn void mensajeEstado(int, char[], char[])
/// @brief su funcion es mostrar uno de los dos mensajes
///
/// @param int estado
/// @param char mensaje[]
/// @param char error[]
void mensajeEstado(int estado, char mensaje[], char error[]);

/// @fn void mayusculasAutomaticos(char[])
/// @brief su funcion es lograr mayusculas automaticos ya sea al inicio o despues de un espacio
///
/// @param char apellidoNombre[]
void mayusculasAutomaticos(char apellidoNombre[]);

#endif /* OTRASFUNCIONES_H_ */
