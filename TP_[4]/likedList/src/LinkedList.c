//amarilla juan sebastian 1C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this-> size = 0;
    	this-> pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno;

    retorno = -1;

    if(this != NULL)
    {
    	retorno = this->size;
    }

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	int tam;
	Node* nodo;

	nodo = NULL;

	if(this != NULL)
	{
		tam = ll_len(this);

		if(tam > 0 && nodeIndex >= 0 && nodeIndex < tam)
		{
			nodo = this->pFirstNode;

			for(i = 0; i<nodeIndex;i++)
			{
				nodo = nodo->pNextNode;
			}
		}
	}

    return nodo;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	int retorno;
	int tam;
	Node* nodo;
	Node* siguiente;
	Node* anterior;

	retorno = -1;

	if(this != NULL)
	{
		tam = ll_len(this);

		if(nodeIndex >= 0 && nodeIndex <= tam)
		{
			nodo = (Node*) malloc(sizeof(Node));

			if(nodo != NULL)
			{
				nodo->pElement = pElement;
				nodo->pNextNode = NULL;

				if(nodeIndex == 0)
				{
				  nodo->pNextNode = this->pFirstNode;
				  this->pFirstNode = nodo;
				}

				else
				{
					anterior = this->pFirstNode;
					siguiente = anterior->pNextNode;

					while(nodeIndex > 1)
					{
						anterior = siguiente;
						siguiente = anterior->pNextNode;
						nodeIndex--;
					}

					anterior->pNextNode = nodo;
					nodo->pNextNode = siguiente;
				}

				retorno = 0;
				this->size++;
			}
		}
	}

    return retorno;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno;
    int estado;
    int tam;

	retorno = -1;

	if(this != NULL)
	{
		tam = ll_len(this);
		estado = addNode(this, tam, pElement);

		if(estado == 0)
		{
			retorno = 0;
		}
	}

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno;
    Node* nodo;
    int tam;

    nodo = NULL;
    retorno = NULL;

    tam = ll_len(this);

    if(this != NULL && index >= 0 && index < tam)
    {
    	nodo = getNode(this, index);

    	if(nodo != NULL)
    	{
    		retorno = nodo->pElement;
    	}

    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno;
    Node* nodo;
    int tam;

    retorno = -1;
    nodo = NULL;

    tam = ll_len(this);

    if(this != NULL && index >= 0 && index < tam)
    {
    	nodo = getNode(this, index);

    	if(nodo != NULL)
    	{
    		nodo->pElement = pElement;
    		retorno = 0;
    	}

    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int retorno;
	int tam;
	Node* nodo;
	Node* siguiente;
	Node* anterior;

	retorno = -1;
	nodo = NULL;
	siguiente = NULL;
	anterior = NULL;

	tam = ll_len(this);

	if(this != NULL && index >= 0 && index < tam)
	{
		nodo = getNode(this, index);

		if(nodo != NULL && index > 0 && index < tam)
		{
			anterior = getNode(this, index-1);
			anterior->pNextNode = nodo->pNextNode;
            this->size--;
			free(nodo);
			retorno = 0;
		}

		else
		{
			if(nodo != NULL && index == 0)
			{
				siguiente = getNode(this, index+1);
				this->pFirstNode = siguiente;
				this->size--;
				free(nodo);
				retorno = 0;
			}

			else
			{
				if(nodo != NULL && index == tam)
				{
					anterior = getNode(this, index-1);
					anterior->pNextNode = NULL;
					this->size--;
					free(nodo);
					retorno = 0;

				}
			}

		}

	}

    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno;

    retorno = -1;

    if(this != NULL)
    {
    	while(ll_len(this) != 0)
    	{
    		ll_remove(this, 0);
    	}

    	retorno = 0;
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno;

    retorno = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	retorno = 0;
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno;
    int i;
    int tam;
    Node* nodo;

    retorno = -1;
    nodo = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);

    	for(i = 0; i<tam; i++)
    	{
    		nodo = getNode(this, i);

    		if(nodo->pElement == pElement)
    		{
    			retorno = i;
    			break;
    		}
    	}
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno;
    int tam;

    retorno = -1;

    if(this != NULL)
    {
    	tam = ll_len(this);

    	if(tam > 0)
    	{
    	    retorno = 0;
    	}

    	else
    	{
    		retorno = 1;
    	}

    }

    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno;
    int estado;
    int tam;

    retorno = -1;

    tam = ll_len(this);

    if(this != NULL && index >= 0 && index < tam)
    {
    	estado = addNode(this, index, pElement);

    	if(estado == 0)
    	{
    	   retorno = 0;
    	}

    }

    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno;
    int tam;

    retorno = NULL;

    tam = ll_len(this);

    if(this != NULL && index >= 0 && index < tam)
    {
    	retorno = ll_get(this, index);
    	ll_remove(this, index);

    }

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno;
    int i;
    int tam;
    Node* nodo;

    retorno = -1;
    nodo = NULL;

    if(this != NULL)
    {
    	retorno = 0;

    	tam = ll_len(this);

    	for(i = 0; i<tam; i++)
    	{
    		nodo = getNode(this, i);

    		if(nodo->pElement == pElement)
    		{
    			retorno = 1;
    			break;
    		}

    		retorno = 0;
    	}

    }

    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno;
    int i;
    int tam;
    Node* nodo;
    Node* nodoSegundo;

    retorno = -1;
    nodo = NULL;
    nodoSegundo = NULL;

    if(this != NULL && this2 != NULL)
    {
    	if(this->size == this2->size)
    	{
    		tam = ll_len(this);

    		for(i = 0; i<tam; i++)
    		{
    			nodo = getNode(this, i);
    			nodoSegundo = getNode(this2, i);

    			if(nodo->pElement != nodoSegundo->pElement)
    			{
    				retorno = 0;
    				break;
    			}

    			retorno = 1;
    		}

    	}

    	else
    	{
    		retorno = 0;
    	}

    }

    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray;
    void* elemento;
    int i;
    int tam;

    cloneArray = NULL;
    elemento = NULL;

    tam = ll_len(this);

    if(this != NULL && from >= 0 && from < tam && to >= 0 && to < tam)
    {
    	cloneArray = ll_newLinkedList();

    	for(i = from; i<to; i++)
    	{
    		elemento = ll_get(this, i);
    		ll_add(cloneArray, elemento);
    	}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray;
    int i;
    int tam;
    void* elemento;

    cloneArray = NULL;
    elemento = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
        tam = ll_len(this);

    	for(i = 0; i<tam; i++)
    	{
    		elemento = ll_get(this, i);
    		ll_add(cloneArray, elemento);
    	}

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno;
    int i;
    int j;
    int tam;
    void* pAux;

    retorno = -1;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
    	tam = ll_len(this);

    	for(i = 0; i<tam-1; i++)
    	{
    		for(j = i+1; j<tam; j++)
    		{
    			if(order == 1 && pFunc(ll_get(this, i), ll_get(this, j)) > 0)
    			{
    				pAux = ll_get(this, i);
    				ll_set(this, i, ll_get(this, j));
    				ll_set(this, j, pAux);

    			}

    			else
    			{
    				if(order == 0 && pFunc(ll_get(this, i), ll_get(this, j)) < 0)
    				{
    					pAux = ll_get(this, i);
    					ll_set(this, i, ll_get(this, j));
    					ll_set(this, j, pAux);

    				}
    			}

    		}

    	}

    	retorno = 0;

    }

    return retorno;
}
