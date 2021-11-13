// amarilla juan sebastian 1C

#include "Employee.h"

Employee* employee_new()
{
	Employee* empleado;

	empleado = (Employee*) malloc(sizeof(Employee));

	if(empleado != NULL)
	{
		empleado->id = 0;
		strcpy(empleado->nombre, "");
		empleado->horasTrabajadas = 0;
		empleado->sueldo = 0;

	}

	return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	int estado;
	Employee* empleado;

	estado = -1;
	empleado = (Employee*) malloc(sizeof(Employee));


	if(empleado != NULL)
	{
		if(employee_setId(empleado, atoi(idStr)) == 1 && employee_setNombre(empleado, nombreStr) == 1 && employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr)) == 1 && employee_setSueldo(empleado, atoi(sueldoStr)) == 1)
		{
			estado = 1;
		}

	}

	if(estado == -1)
	{
		free(empleado);
        empleado=NULL;
	}

	return empleado;

}

int employee_setId(Employee* this,int id)
{
	int retorno;

	retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;

	}

	return retorno;

}

int employee_getId(Employee* this,int* id)
{
	int retorno;

	retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;

	}

	return retorno;

}

int verificarId(LinkedList* pArrayListEmployee, Employee* this, int id)
{
	int i;
	int tam;
	char cadena[TAM_CARACTER];

	tam = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && this != NULL)
	{
		for(i = 0; i<tam; i++)
		{
			this = ll_get(pArrayListEmployee, i);

			while(this->id == id)
			{
				pedirEnteroValidado(cadena, "Ingrese id no existente: \n", &id);
			}

		}
	}

	return id;

}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if(this != NULL && validarLetras(nombre) == 1)
	{
        strcpy(this->nombre, nombre);
		retorno = 1;

	}

	return retorno;

}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL)
	{
        strcpy(nombre, this->nombre);
		retorno = 1;

	}

	return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;

	retorno = 0;

	if(this != NULL && horasTrabajadas > 0)
	{
			this->horasTrabajadas = horasTrabajadas;
			retorno = 1;

	}

	return retorno;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;

	retorno = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;

	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;

	retorno = 0;

	if(this != NULL && sueldo > 0)
	{
			this->sueldo = sueldo;
			retorno = 1;

	}

	return retorno;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;

	retorno = 0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}
