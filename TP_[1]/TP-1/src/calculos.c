//Amarilla Juan Sebastian 1C

#include "calculos.h"

float calcularSuma(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

float calcularResta(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}

float calcularDivision(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno / numeroDos;

	return resultado;
}

float calcularMultiplicacion(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

float calcularFactorial(float numero)
{
	int i;
	float factorial;

	factorial=1;

	for (i=numero;i>1;i--)
	{
       factorial = factorial * i;
    }

	return factorial;

}
