// amarilla juan sebastian 1C

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "IngresarDatos.h"
#include "LinkedList.h"
#define TAM_CARACTER 128

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// @fn Employee employee_new*()
/// @brief su funcion es crear un empleado vacio
///
/// @return retorna el empleado
Employee* employee_new();

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief su funcion es colocar los datos de un empleado
///
/// @param char* idStr
/// @param char* nombreStr
/// @param char* horasTrabajadasStr
/// @param char* sueldoStr
/// @return retorna el empleado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

void employee_delete();

/// @fn int employee_setId(Employee*, int)
/// @brief su funcion es colocar un id
///
/// @param Employee* this
/// @param int id
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_setId(Employee* this,int id);

/// @fn int employee_getId(Employee*, int*)
/// @brief su funcion es copiar un id
///
/// @param Employee* this
/// @param int* id
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_getId(Employee* this,int* id);

/// @fn int verificarId(LinkedList*, Employee*, int)
/// @brief verifica si esa id existe
///
/// @param LinkedList* pArrayListEmployee
/// @param Employee* this
/// @param int id
/// @return retorna la id no existente
int verificarId(LinkedList* pArrayListEmployee, Employee* this, int id);

/// @fn int employee_setNombre(Employee*, char*)
/// @brief su funcion es colocar un nombre
///
/// @param Employee* this
/// @param char* nombre
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_setNombre(Employee* this,char* nombre);

/// @fn int employee_getNombre(Employee*, char*)
/// @brief su funcion es copiar un nombre
///
/// @param Employee* this
/// @param char* nombre
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_getNombre(Employee* this,char* nombre);

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief su funcion es colocar las horas trabajadas
///
/// @param Employee* this
/// @param int horasTrabajadas
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief su funcion es copiar las horas trabajadas
///
/// @param Employee* this
/// @param int* horasTrabajadas
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @fn int employee_setSueldo(Employee*, int)
/// @brief su funcion es colocar sueldo
///
/// @param Employee* this
/// @param int sueldo
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_setSueldo(Employee* this,int sueldo);

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief su funcion es copiar sueldo
///
/// @param Employee* this
/// @param int* sueldo
/// @return retorna 1 si salio bien o 0 si no se logro
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
