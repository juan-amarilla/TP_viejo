// amarilla juan sebastian 1C

#include "Parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* empleado;
	char cadena[4][TAM_CARACTER];
	int cantidad;

	empleado = NULL;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", cadena[0], cadena[1], cadena[2], cadena[3]);

	while(!feof(pFile))
	{
		cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", cadena[0], cadena[1], cadena[2], cadena[3]);

		if(cantidad == 4)
		{
			empleado = employee_newParametros(cadena[0], cadena[1], cadena[2], cadena[3]);
			ll_add(pArrayListEmployee,  empleado);
			retorno = 1;
		}

		else
		{
			retorno = -1;
			break;
		}

	}

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* empleado;
	int cantidad;

	empleado = NULL;

	while(!feof(pFile))
	{
		empleado = employee_new();

		if(empleado != NULL)
		{
			cantidad = fread(empleado, sizeof(Employee), 1, pFile);

			if(cantidad == 1)
			{
				ll_add(pArrayListEmployee,  empleado);
				retorno = 1;
			}

			else
			{
				break;
			}
		}

		else
		{
			break;
		}

	}

	return retorno;
}
