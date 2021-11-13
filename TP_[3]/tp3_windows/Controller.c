// amarilla juan sebastian 1C

#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
    FILE* controlador;
    int tam;

    tam = ll_len(pArrayListEmployee);

    retorno = -1;

    if(path != NULL && pArrayListEmployee != NULL && tam == 0)
    {
    	if((controlador = fopen(path, "r")) != NULL)
    	{
    	    retorno = parser_EmployeeFromText(controlador, pArrayListEmployee);
    	}

    	else
    	{
    	    retorno = 0;
    	}

    	fclose(controlador);
    }

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* controlador;
	int tam;

	retorno = -1;

	tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL && tam == 0)
	{
		if((controlador = fopen(path, "rb")) != NULL)
		{
			retorno = parser_EmployeeFromBinary(controlador, pArrayListEmployee);
		}

		else
		{
			retorno = 0;
		}

		fclose(controlador);
	}

	return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	char nombre[TAM_CARACTER];
	int horas;
	int sueldo;
	char cadena[TAM_CARACTER];
	Employee* empleado;

	retorno = -1;
	empleado = NULL;

	empleado = employee_new();

	if(pArrayListEmployee != NULL && empleado != NULL)
	{
		retorno = 0;

		pedirEnteroValidado(cadena, "Ingrese id: \n", &id);
		id = verificarId(pArrayListEmployee, empleado, id);
		pedirNombre(cadena, "Ingrese nombre: \n", nombre);
		mayusculasAutomaticos(nombre, TAM_CARACTER);
		pedirEnteroValidado(cadena, "Ingrese las horas trabajadas: \n", &horas);
		pedirEnteroValidado(cadena, "Ingrese el salario: \n", &sueldo);

		if(employee_setId(empleado, id) == 1 &&  employee_setNombre(empleado, nombre) == 1 && employee_setHorasTrabajadas(empleado, horas) == 1 && employee_setSueldo(empleado, sueldo) == 1)
		{
			retorno = 1;
			ll_add(pArrayListEmployee, empleado);
		}
	}

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	int tam;
	int i;
	int opcion;
	int horas;
	int sueldo;
	Employee* empleado;
	char nombre[TAM_CARACTER];
	char cadena[TAM_CARACTER];

	empleado = NULL;
	retorno = -1;

	pedirEnteroValidado(cadena, "Esta seguro de modificar un empleado, ingrese el numero? 1-SI (DISTINTO A UNO)-NO \n", &opcion);

	if(opcion == 1 && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		pedirEnteroValidado(cadena, "Ingrese id para la modificacion: \n", &id);

		for(i=0;i<tam;i++)
		{
			retorno = 0;

			empleado=ll_get(pArrayListEmployee, i);

			if(empleado->id == id && empleado->id > 0)
			{
				do
				{
					menuModificacion();
					pedirEnteroValidado(cadena, "Ingrese una opcion para modificar: \n", &opcion);

					switch(opcion)
					{
					  case 1:
					  pedirNombre(cadena, "Ingrese nombre: \n", nombre);
					  mayusculasAutomaticos(nombre, TAM_CARACTER);
					  employee_setNombre(empleado, nombre);
					  retorno = 1;
					  break;

					  case 2:
					  pedirEnteroValidado(cadena, "Ingrese las horas trabajadas: \n", &horas);
					  employee_setHorasTrabajadas(empleado, horas);
					  retorno = 1;
					  break;

					  case 3:
					  pedirEnteroValidado(cadena, "Ingrese sueldo: \n", &sueldo);
					  employee_setSueldo(empleado, sueldo);
					  retorno = 1;
					  break;

					  case 4:
					  retorno = 1;
					  mensajeEstado(retorno, "Salida con exito. \n", "Error, algo paso en el proceso. \n", "Modificacion sin exito. \n");
					  break;

					  default:
					  retorno = -1;
					  mensajeEstado(retorno, "Gracias por usar mi programa. \n", "Error, algo paso en el proceso. \n", "Opcion no valida. \n");
					  break;

					}

				} while(opcion != 4);

			}
		}

	}

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int opcion;
    int id;
    int i;
    int tam;
    char cadena[TAM_CARACTER];
    Employee* empleado;

	retorno = -1;
	empleado = NULL;

	pedirEnteroValidado(cadena, "Esta seguro de dar de baja? ingrese el numero: 1-SI (DISTINTO A UNO)-NO \n", &opcion);

	if(opcion == 1 && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		pedirEnteroValidado(cadena, "Ingrese id para la baja: \n", &id);

		for(i=0;i<tam;i++)
		{
			retorno = 0;
			empleado = ll_get(pArrayListEmployee, i);

			if(empleado->id == id && empleado->id > 0)
			{
				ll_remove(pArrayListEmployee, i);
				retorno = 1;
				break;

			}
		}

	}

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
    int i;
    int tam;
    Employee* empleado;

    retorno = -1;
    empleado = NULL;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && tam > 0)
    {
    	retorno = 0;

    	printf("_______________________________________________________________________________________________________________________\n");
    	printf("|ID\t\t|NOMBRE\t\t\t\t|HORAS TRABAJADAS\t\t|SUELDO\t\t\t\t\t|\n");
    	printf("-----------------------------------------------------------------------------------------------------------------------\n");

    	for(i=0;i<tam;i++)
    	{
    		empleado = ll_get(pArrayListEmployee, i);

    		if(empleado->id > 0)
    		{
    			retorno = 1;
    			printf("|%5d\t\t|%15s\t\t|%20d\t\t|%25d\t\t|\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);

    		}

    	}

    }

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
    int i;
    int j;
    int tam;
    Employee* empleado;
    Employee* auxiliar;

    retorno = -1;
    empleado = NULL;
    auxiliar = NULL;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && tam > 0)
    {
    	retorno = 0;

    	for(i=0;i<tam-1;i++)
    	{
    		for(j=i+1;j<tam;j++)
    		{
    			empleado = ll_get(pArrayListEmployee, i);
    			auxiliar = ll_get(pArrayListEmployee, j);

    			if(strcmp(empleado->nombre, auxiliar->nombre) > 0)
    			{
    				retorno = 1;
    				ll_set(pArrayListEmployee, i, auxiliar);
    				ll_set(pArrayListEmployee, j, empleado);
    			}
    		}

    	}

    }

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* controlador;
	Employee* empleado;
	int tam;
	int i;

	empleado = NULL;
	retorno = -1;

	if((controlador=fopen(path, "w")) != NULL && path != NULL && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		fprintf(controlador, "id, nombre, horas trabajadas, salario \n");

		for(i = 0; i<tam; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			retorno = 0;

			if(empleado->id > 0)
			{
				retorno = 1;
				fprintf(controlador, "%d, %s, %d, %d \n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
			}
		}

	}

	fclose(controlador);

    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* controlador;
	Employee* empleado;
	int tam;
	int i;

	empleado = NULL;
	retorno = -1;

	tam = ll_len(pArrayListEmployee);

	if(tam > 0 && path != NULL && pArrayListEmployee != NULL)
	{
		if((controlador=fopen(path, "wb")) != NULL)
		{
			rewind(controlador);

			for(i = 0; i<tam; i++)
			{
				empleado = ll_get(pArrayListEmployee, i);
				retorno = 0;

				if(empleado-> id > 0)
				{
					fwrite(empleado, sizeof(Employee), 1, controlador);
					retorno = 1;

				}

			}

		}

	}

	fclose(controlador);

	return retorno;
}

