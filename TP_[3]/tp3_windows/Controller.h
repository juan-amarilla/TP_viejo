// amarilla juan sebastian 1C

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"
#include "IngresarDatos.h"
#include "OtrasFunciones.h"

/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
///
/// @param char* path
/// @param LinkedList* pArrayListEmployee
/// @return retorna -1 si no logro nada, 0 si algo paso en el proceso o 1 si salio bien
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
///
/// @param char* path
/// @param LinkedList* pArrayListEmployee
/// @return retorna -1 si no logro nada, 0 si algo paso en el proceso o 1 si salio bien
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_addEmployee(LinkedList*)
/// @brief su funcion es dar de alta un empleado
///
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien, 0 si en el proceso algo paso o -1 si salio mal
int controller_addEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_editEmployee(LinkedList*)
/// @brief su funcion es modificar un empleado
///
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien, 0 si en el proceso algo paso o -1 si salio mal
int controller_editEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_removeEmployee(LinkedList*)
/// @brief su funcion es remover un empleado
///
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien, 0 si en el proceso algo paso o -1 si salio mal
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_ListEmployee(LinkedList*)
/// @brief su funcion es listar los empleados
///
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien, 0 si en el proceso algo paso o -1 si salio mal
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_sortEmployee(LinkedList*)
/// @brief su funcion es ordenar los empleados
///
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien, 0 si en el proceso algo paso o -1 si salio mal
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief su funcion es guardar los datos de los empleados en formato texto
///
/// @param char* path
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien, 0 si en el proceso algo paso o -1 si salio mal
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief su funcion es guardar los datos de los empleados en formato binario
///
/// @param char* path
/// @param LinkedList* pArrayListEmployee
/// @return retorna 1 si salio bien, 0 si en el proceso algo paso o -1 si salio mal
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


