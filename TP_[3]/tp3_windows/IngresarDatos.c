// amarilla juan sebastian 1C

#include "IngresarDatos.h"

void pedirEnteroValidado(char cadena[], char mensaje[], int* numero)
{
	int estado;

	if(numero != NULL && cadena != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);

		estado = validarNumeroEntero(numero, cadena);

		while(estado == -1 || strlen(cadena) == 0 || strlen(cadena) > TAM_CARACTER)
		{
			printf("Error: %s", mensaje);
			fflush(stdin);
			gets(cadena);
			estado = validarNumeroEntero(numero, cadena);
		}

	}
}

void pedirNombre(char cadena[], char mensaje[], char nombre[])
{
	int estado;

	estado = 0;

	if(cadena != NULL && nombre != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);

		if(strlen(cadena) <= TAM_CARACTER)
		{
			estado = validarNombre(cadena, nombre);
		}

		while(estado == 0 || strlen(cadena) == 0 ||  strlen(cadena) > TAM_CARACTER)
		{
			printf("Error: %s", mensaje);
			fflush(stdin);
			gets(cadena);

			if(strlen(cadena) <= TAM_CARACTER)
			{
				estado = validarNombre(cadena, nombre);
			}
		}

	}
}

