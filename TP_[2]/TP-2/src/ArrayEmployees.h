// amarilla juan sebastian 1C

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "OtrasFunciones.h"
#include "IngresarDatos.h"
#include <string.h>
#define OCUPADO 0
#define VACIO 1

struct
{
  int id;
  char name[51];
  char lastName[51];
  float salary;
  int sector;
  int isEmpty;

}typedef Employee;

/// @fn int initEmployees(Employee*, int)
/// @brief su funcion es inicializar los isEmpty en VACIO
///
/// @param Employee* list
/// @param int len
/// @return retorna 0 si salio bien o -1 si salio mal
int initEmployees(Employee* list, int len);

/// @fn int addEmployees(Employee*, int, int, char[], char[], float, int)
/// @brief su funcion es dar de alta un empleado
///
/// @param Employee* list
/// @param int len
/// @param int id
/// @param char name[]
/// @param char lastName[]
/// @param float salary
/// @param int sector
/// @return retorna 0 si salio bien o -1 si salio mal
int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/// @fn int findEmployeeById(Employee*, int, int)
/// @brief su funcion es encontrar la id del empleado
///
/// @param Employee* list
/// @param int len
/// @param int id
/// @return retorna la posicion si salio bien o -1 si salio mal
int findEmployeeById(Employee* list, int len, int id);

/// @fn int removeEmployee(Employee*, int, int)
/// @brief su funcion es eliminar de manera logica un empleado
///
/// @param Employee* list
/// @param int len
/// @param int id
/// @return retorna 0 si salio bien o -1 si salio mal
int removeEmployee(Employee* list, int len, int id);

/// @fn int sortEmployees(Employee*, int, int)
/// @brief su funcion es ordenar alfabeticamente el apellido y luego por sector la lista de empleados
///
/// @param Employee* list
/// @param int len
/// @param int order
/// @return retorna 0 si salio bien o -1 si salio mal
int sortEmployees(Employee* list, int len, int order);

/// @fn int printEmployees(Employee*, int)
/// @brief su funcion es listar todos los empleados
///
/// @param Employee* list
/// @param int lenght
/// @return retorna 0 si salio bien o -1 si salio mal
int printEmployees(Employee* list, int lenght);

/// @fn int modificarEmpleado(Employee[], int)
/// @brief su funcion es modificar un empleado ya sea nombre, apellido, salario o sector
///
/// @param Employee lista[]
/// @param int tam
/// @return retorna 0 si salio bien o -1 si salio mal
int modificarEmpleado(Employee lista[], int tam);

/// @fn int verificarEmpleado(Employee[], int)
/// @brief su funcion es verificar si un empleado esta cargado o no
///
/// @param Employee lista[]
/// @param int tam
/// @return retorna 0 si salio bien o -1 si salio mal
int verificarEmpleado(Employee lista[], int tam);

#endif /* ARRAYEMPLOYEES_H_ */
