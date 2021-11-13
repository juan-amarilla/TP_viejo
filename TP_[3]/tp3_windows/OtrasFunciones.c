// amarilla juan sebastian 1C

#include "OtrasFunciones.h"

void menu()
{
   printf("1-Cargar los datos de los empleados desde el archivo de texto.\n");
   printf("2-Cargar los datos de los empleados desde el archivo binario.\n");
   printf("3-Alta empleado.\n");
   printf("4-Modificar datos del empleado. \n");
   printf("5-Baja del empleado.\n");
   printf("6-Listar empleados.\n");
   printf("7-Ordenar empleados.\n");
   printf("8-Guardar los datos de los empleados en el archivo de texto.\n");
   printf("9-Guardar los datos de los empleados en el archivo binario.\n");
   printf("10-Salir.\n\n");

}

void menuModificacion()
{
   printf("1-Modificar nombre.\n");
   printf("2-Modificar horas trabajadas.\n");
   printf("3-Modificar sueldo.\n");
   printf("4-Salir. \n");

}

void mensajeEstado(int estado, char valido[], char errorProceso[], char noValido[])
{
	if(estado == 1)
	{
	  printf("%s", valido);
	}

	else
	{
		if(estado == 0)
		{
			printf("%s", errorProceso);
		}

		else
		{
			printf("%s", noValido);
		}
	}
}

void mayusculasAutomaticos(char cadena[], int tam)
{
     int i;

     strlwr(cadena);

	 for(i=0;i<tam;i++)
	 {
		 if(i == 0 && isalpha(cadena[i]) != 0)
		 {
		     cadena[i]= toupper(cadena[i]);
		 }

         if(isspace(cadena[i]) != 0 && isalpha(cadena[i+1]) != 0)
		 {
        	 cadena[i+1]= toupper(cadena[i+1]);

		 }
	 }
}
