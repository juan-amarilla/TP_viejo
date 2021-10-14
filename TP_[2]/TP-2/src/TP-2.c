/*
============================================================================
amarilla juan sebastian 1C

Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector

3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.

Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"
#include "IngresarDatos.h"
#include "OtrasFunciones.h"
#define TAM 1000
#define CARACTERES 51
#define CARACTER 1000

int main(void)
{

	Employee lista[TAM];
	int opcion;
	int retorno;
	int id;
	int idAuxiliar;
	float salario;
	int sector;
	char cadena[CARACTER];
	char nombre[CARACTERES];
	char apellido[CARACTERES];

	id = 0;
	salario = 0;
	sector = 0;
	idAuxiliar = 0;

	setbuf(stdout, NULL);

	retorno = initEmployees(lista, TAM);
	mensajeEstado(retorno, "Inicializacion de estado de empleados con exito. \n", "Error. \n");

	do
	{
		menu();
		pedirEnteroValidado(cadena, "Ingrese una opcion valida: \n", &opcion);

		switch(opcion)
		{
		   case 1:
		   id++;
		   retorno = addEmployees(lista, TAM, id,  nombre, apellido, salario, sector);
		   mensajeEstado(retorno, "Ingreso de empleado con exito. \n", "Ingreso de empleado sin exito \n");
		   if(retorno == -1)
		   {
			   id--;

		   }
		   break;

		   case 2:
		   retorno = verificarEmpleado(lista, TAM);
		   if(retorno == 0)
		   {
			   retorno = modificarEmpleado(lista, TAM);
			   mensajeEstado(retorno, "Modificacion del empleado con exito. \n", "Modificacion del empleado sin exito. \n");

		   }
		   else
		   {
			   mensajeEstado(retorno, "Modificacion del empleado con exito. \n", "Ningun empleado cargado. \n");
		   }
		   break;

		   case 3:
		   retorno = verificarEmpleado(lista, TAM);
		   if(retorno == 0)
		   {
			   retorno = removeEmployee(lista, TAM, idAuxiliar);
			   mensajeEstado(retorno, "Baja del empleado con exito. \n", "Baja del empleado sin exito. \n");
		   }
		   else
		   {
			   mensajeEstado(retorno, "Baja del empleado con exito. \n", "Ningun empleado cargado. \n");
		   }
		   break;

		   case 4:
		   retorno = verificarEmpleado(lista, TAM);
		   if(retorno == 0)
		   {
			   retorno = sortEmployees(lista, TAM, 0);
			   mensajeEstado(retorno, "Ordenamiento con exito. \n", "Ordenamiento sin exito. \n");
			   retorno = printEmployees(lista, TAM);
			   mensajeEstado(retorno, "Listado con exito. \n", "Listado sin exito. \n");

		   }
		   else
		   {
			   mensajeEstado(retorno, "Listado con exito. \n", "Ningun empleado cargado. \n");
		   }
		   break;

		   case 5:
		   retorno = 0;
		   mensajeEstado(retorno, "Gracias por usar mi programa. \n", "Error: la opcion debe ser valida. \n");
		   break;

		   default:
		   retorno = -1;
		   mensajeEstado(retorno, "Gracias por usar mi programa. \n", "Error: la opcion debe ser valida. \n");
		   break;

		}

	} while (opcion != 5);

	return 0;
}
