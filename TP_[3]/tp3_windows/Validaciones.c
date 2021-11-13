// amarilla juan sebastian 1C

#include "Validaciones.h"

int validarNumeroEntero(int* numeroEntero, char numero[])
{
	int i;
	int retorno;
	int entero;

	i = 0;
	retorno = 1;

	while (numero[i] != '\0')
	{
		if(isdigit(numero[i]) != 1)
		{
			retorno=-1;
			break;
		}

		i++;

	}

	if(retorno==1)
	{
		entero=atoi(numero);
		*numeroEntero=entero;

	}


	return retorno;
}

int validarLetras(char cadena[])
{
	int retorno;
	int i;

	retorno = 1;
	i = 0;

	while(cadena[i]!='\0')
	{
		 if(isalpha(cadena[i]) == 0)
		 {
		    if(isspace(cadena[i]) != 0)
			{
		    	i++;
		    	continue;
		    }

		    retorno=-1;
		    break;
		  }

		  i++;
	}

	return retorno;
}

int validarNombre(char cadena[], char nombre[])
{
	int retorno;
	int i;

	retorno = 1;
	i = 0;

	while(cadena[i]!='\0')
	{
	     if(isalpha(cadena[i]) == 0)
	     {
	    	   if(isspace(cadena[i]) != 0)
		       {
	    		   i++;
	    		   continue;
			   }

	    	   retorno=-1;
	           break;
	     }

	     i++;
	}

	if(retorno==1)
	{
	   strcpy(nombre, cadena);

	}

	return retorno;
}
