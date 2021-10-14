// amarilla juan sebastian 1C

#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<len;i++)
	{
		list[i].isEmpty = VACIO;

		if(i == (len - 1))
		{
			retorno = 0;
		}
	}

    return retorno;
}

int verificarEmpleado(Employee lista[], int tam)
{
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty == OCUPADO)
		{
			retorno = 0;
		}

	}

	return retorno;

}

int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno;
	int i;
	char cadenaAuxiliar[1000];

	retorno = -1;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == VACIO)
		{
             pedirCadenaValidado(cadenaAuxiliar, "Ingrese un nombre valido. \n", name);
             pedirCadenaValidado(cadenaAuxiliar, "Ingrese un apellido valido. \n", lastName);
             pedirFlotanteValidado(cadenaAuxiliar,"Ingrese un salario valido. \n", &salary);
             pedirEnteroValidado(cadenaAuxiliar,  "Ingrese un sector numerico valido. \n", &sector);

             list[i].id = id;
             strcpy(list[i].name, name);
             strcpy(list[i].lastName, lastName);
             mayusculasAutomaticos(list[i].name);
             mayusculasAutomaticos(list[i].lastName);
             list[i].salary = salary;
             list[i].sector = sector;
             list[i].isEmpty = OCUPADO;
             retorno = 0;
             break;

		}

	}

	return retorno;
}

int modificarEmpleado(Employee lista[], int tam)
{
      int retorno;
      int opcion;
      int id;
      char cadena[1000];
      int posicion;
      int estado;

      retorno = -1;

      pedirEnteroValidado(cadena,"¿Quiere modificar un empleado? ingrese el numero: 1-SI o 2-NO \n", &opcion);

      if(opcion == 1)
      {
         pedirEnteroValidado(cadena,  "Ingrese la ID del empleado para la modificacion. \n", &id);
         posicion = findEmployeeById(lista, tam, id);

         if(posicion != -1)
         {


              printf("1-Modificar nombre. \n");
              printf("2-Modificar apellido. \n");
              printf("3-Modificar salario. \n");
              printf("4-Modificar sector. \n");
              printf("5-Salir. \n");
              pedirEnteroValidado(cadena,"Ingrese una opcion valida. \n",&opcion);

              switch(opcion)
              {
                  case 1:
                  pedirCadenaValidado(cadena, "Ingrese un nombre valido. \n", lista[posicion].name);
                  mayusculasAutomaticos(lista[posicion].name);
                  retorno = 0;
                  break;

                  case 2:
                  pedirCadenaValidado(cadena, "Ingrese un apellido valido. \n", lista[posicion].lastName);
                  mayusculasAutomaticos(lista[posicion].lastName);
                  retorno = 0;
                  break;

                  case 3:
                  pedirFlotanteValidado(cadena,"Ingrese un salario valido. \n", &lista[posicion].salary);
                  retorno = 0;
                  break;

                  case 4:
                  pedirEnteroValidado(cadena,  "Ingrese un sector numerico valido. \n", &lista[posicion].sector);
                  retorno = 0;
                  break;

                  case 5:
                  estado = 0;
                  mensajeEstado(estado,"Saliste del menu de modificacion con exito. \n","Error. \n");
                  break;

                  default:
                  estado = -1;
                  mensajeEstado(estado,"Saliste del menu de modificacion con exito. \n","Error. \n");
                  break;

              }


           }

           else
           {
        	   printf("No se pudo modificar. \n");
           }
       }

    return retorno;
}

int findEmployeeById(Employee* list, int len, int id)
{
	int i;
	int posicionAuxiliar;

	posicionAuxiliar = -1;

	for(i=0;i<len;i++)
	{
		if(list[i].id == id && list[i].isEmpty == OCUPADO)
		{
			posicionAuxiliar = i;
			break;

		}

	}

	return posicionAuxiliar;

}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno;
	int opcion;
	int posicion;
	char cadena[51];

	retorno = -1;

	pedirEnteroValidado(cadena,"¿Quiere dar de baja un empleado? ingrese el numero: 1-SI o 2-NO \n", &opcion);

	if(opcion == 1)
	{
		pedirEnteroValidado(cadena,  "Ingrese la ID del empleado para la baja. \n", &id);
		posicion = findEmployeeById(list, len, id);

		if(posicion != -1)
		{
			list[posicion].isEmpty = VACIO;
			retorno = 0;

		}

		else
		{
		   printf("No se pudo dar de baja. \n");

		}

	}

	return retorno;

}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno;
	int i;
	int j;
	Employee empleadoAuxiliar;

	retorno = -1;

	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(strcmp(list[i].lastName, list[j].lastName) > order)
			{
				empleadoAuxiliar = list[i];
				list[i] = list[j];
				list[j] = empleadoAuxiliar;
				retorno = 0;

			}

			else
			{
				if((strcmp(list[i].lastName, list[j].lastName) == order) && (list[i].sector>list[j].sector))
				{
					empleadoAuxiliar = list[i];
					list[i] = list[j];
					list[j] = empleadoAuxiliar;
					retorno = 0;

				}
			}
		}

	}

	return retorno;

}

int printEmployees(Employee* list, int lenght)
{
	int retorno;
	int i;
	float totalSalario;
	float promedio;
	int contador[2]={};

	retorno = -1;
	totalSalario = 0;

	printf(" _______________________________________________________________________________________________________\n");
	printf("|ID         |NOMBRE               |APELLIDO             |SALARIO           |SECTOR                      |\n");
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

    for(i=0;i<lenght;i++)
    {
    	if(list[i].isEmpty == OCUPADO)
    	{
    		 printf("|           |                     |                     |                  |                     \t|\n");
             printf("%5d %22s %25s %18.2f %20d\n\n",    list[i].id,
            		                                    list[i].name,
					                                    list[i].lastName,
					                                    list[i].salary,
										                list[i].sector);

             totalSalario += list[i].salary;
             contador[0]++;

             if(retorno == -1)
             {
            	 retorno = 0;
             }
    	}

    }

    if(contador[0] > 0)
    {
    	promedio = totalSalario / contador[0];
    }

    for(i=0;i<lenght;i++)
    {
        if(list[i].salary > promedio && list[i].isEmpty == OCUPADO)
        {
        	contador[1]++;
        }
    }

    printf("El total de salario es: %.2f \n", totalSalario);

    if(contador[0] > 0)
    {
    	printf("El promedio de salario es: %.2f \n", promedio);
    }

    else
    {
    	printf("No hay ningun promedio de salario. \n");
    }

    if(contador[1] > 0)
    {
    	printf("La cantidad de empleados que superan el salario promedio: %d \n\n", contador[1]);
    }

    else
    {
    	printf("Ninguno supera el salario promedio. \n\n");
    }


	return retorno;

}
