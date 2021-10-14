// amarilla juan sebastian 1C

#include "OtrasFunciones.h"

void menu()
{
   printf("1-ALTA EMPLEADO.\n");
   printf("2-MODIFICAR EMPLEADO.\n");
   printf("3-BAJA EMPLEADO.\n");
   printf("4-INFORMAR DATOS. \n");
   printf("5-SALIR DEL PROGRAMA.\n");

}

void mensajeEstado(int estado, char mensaje[], char error[])
{
	if(estado == 0)
	{
	  printf("%s", mensaje);
	}

	else
	{
		printf("%s", error);
	}
}

void mayusculasAutomaticos(char apellidoNombre[])
{
	  int i;

	  strlwr(apellidoNombre);

	  for(i=0;i<51;i++)
	  {
		  if(isspace(apellidoNombre[i]) != 0)
		  {
			apellidoNombre[i+1]= toupper(apellidoNombre[i+1]);

		  }

		  if(i == 0)
		  {
			  apellidoNombre[i] = toupper(apellidoNombre[i]);

		  }

	  }


}
