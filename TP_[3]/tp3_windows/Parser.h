

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#define TAM_CARACTER 128

/// @fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// @brief su funcion es parsear en formato texto
///
/// @param FILE* pFile
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien o -1 si salio mal
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// @brief su funcion es parsear en formato binario
///
/// @param FILE* pFile
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien o -1 si salio mal
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
