#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "OtrasFunciones.h"
#include "IngresarDatos.h"
#define TAM_CARACTER 128

/****************************************************
     amarilla juan sebastian 1C

     Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir

*****************************************************/



int main()
{
	int opcion;
	int retorno;
	char cadena[TAM_CARACTER];
	LinkedList* listaEmpleados;

	setbuf(stdout, NULL);

	opcion = 0;

    listaEmpleados = ll_newLinkedList();

    do
    {
    	menu();
    	pedirEnteroValidado(cadena, "Ingrese una opcion valida: \n", &opcion);

        switch(opcion)
        {
            case 1:
            retorno = controller_loadFromText("data.csv",listaEmpleados);
            mensajeEstado(retorno, "Carga de texto con exito. \n", "Error, algo paso en el proceso. \n", "Carga de texto sin exito. \n");
            break;

            case 2:
            retorno = controller_loadFromBinary("data.bin", listaEmpleados);
            mensajeEstado(retorno, "Carga de binario con exito. \n", "Error, algo paso en el proceso. \n", "Carga de binario sin exito. \n");
            break;

            case 3:
            retorno = controller_addEmployee(listaEmpleados);
            mensajeEstado(retorno, "Alta con exito. \n", "Error, algo paso en el proceso. \n", "Alta sin exito. \n");
            break;

            case 4:
            retorno = controller_editEmployee(listaEmpleados);
            mensajeEstado(retorno, "Modificacion con exito. \n", "Error, algo paso en el proceso. \n", "Modificacion sin exito. \n");
            break;

            case 5:
            retorno = controller_removeEmployee(listaEmpleados);
            mensajeEstado(retorno, "Baja con exito. \n", "Error, algo paso en el proceso. \n", "Baja sin exito. \n");
            break;

            case 6:
            retorno = controller_ListEmployee(listaEmpleados);
            mensajeEstado(retorno, "Listado con exito. \n", "Error, algo paso en el proceso. \n", "Listado sin exito. \n");
            break;

            case 7:
            retorno = controller_sortEmployee(listaEmpleados);
            mensajeEstado(retorno, "Ordenamiento con exito. \n", "Error, algo paso en el proceso. \n", "Ordenamiento sin exito. \n");
            break;

            case 8:
            retorno = controller_saveAsText("data.csv", listaEmpleados);
            mensajeEstado(retorno, "Guardado de texto con exito. \n", "Error, algo paso en el proceso. \n", "Guardado de texto sin exito. \n");
            break;

            case 9:
            retorno = controller_saveAsBinary("data.bin", listaEmpleados);
            mensajeEstado(retorno, "Guardado de binario con exito. \n", "Error, algo paso en el proceso. \n", "Guardado de binario sin exito. \n");
            break;

            case 10:
            retorno = 1;
            mensajeEstado(retorno, "Gracias por usar mi programa. \n", "Error, algo paso en el proceso. \n", "Salida no exitosa. \n");
            break;

            default:
            retorno = -1;
            mensajeEstado(retorno, "Gracias por usar mi programa. \n", "Error, algo paso en el proceso. \n", "Opcion no valida. \n");
            break;
        }

    }while(opcion != 10);

    return 0;
}

