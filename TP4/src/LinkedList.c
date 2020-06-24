#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this = NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	this->size = 0;
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {
		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *pNode;
	pNode = NULL;
	int lenght = ll_len(this);

	if (this != NULL && nodeIndex > -1 && nodeIndex < lenght && lenght > 0) {
		pNode = this->pFirstNode;
		while (nodeIndex > 0) {
			pNode = pNode->pNextNode;
			nodeIndex--;
		}
	}
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
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
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;
	int lenght = ll_len(this);
	Node *newNode = NULL;
	Node *auxNode = NULL;
	Node *lastNode = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= lenght) {
		newNode = (Node*) malloc(sizeof(Node));
		if (newNode != NULL) {
			newNode->pElement = pElement;
			newNode->pNextNode = NULL;
			if (nodeIndex == 0) {
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
				returnAux = 0;
			} else {
				if (nodeIndex > 0 && nodeIndex < lenght) {
					auxNode = getNode(this, nodeIndex);
					lastNode = getNode(this, (nodeIndex - 1));
					lastNode->pNextNode = newNode;
					newNode->pNextNode = auxNode;
					returnAux = 0;
				} else {
					lastNode = getNode(this, (nodeIndex - 1));
					lastNode->pNextNode = newNode;
					returnAux = 0;
				}
			}
		}
		if (returnAux == 0) {
			this->size = lenght + 1;
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int len = ll_len(this);
	if (this != NULL) {
		if (addNode(this, len, pElement) == 0) {
			returnAux = 0;
		}
		if (returnAux == 0) {
			this->size = len + 1;
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *pNode = NULL;
	int lenght = ll_len(this);
	if (this != NULL && index >= 0 && index < lenght) {
		pNode = getNode(this, index);
		returnAux = pNode->pElement;
	}
	return returnAux;
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
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	int len = ll_len(this);
	if (this != NULL && index >= 0 && index < len) {
		if (addNode(this, index, pElement) == 0) {
			returnAux = 0;
		}
		if (returnAux == 0) {
			this->size = len + 1;
		}
	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	Node *pNode = NULL;
	Node *pNextNodeAux = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this)
			&& (getNode(this, index) != NULL)) {
		if (index == 0) {
			pNode = getNode(this, index + 1);
			this->pFirstNode = pNode;
			returnAux = 0;
		} else {
			if (index > 0 && index < ll_len(this)) {
				pNextNodeAux = getNode(this, index + 1);
				pNode = getNode(this, index - 1);
				pNode->pNextNode = pNextNodeAux;
				returnAux = 0;
			} else {
				pNode = getNode(this, (index - 1));
				pNode->pNextNode = NULL;
				returnAux = 0;
			}
		}
		if (returnAux == 0) {
			this->size = ll_len(this) - 1;
		}
	}
	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;
	int i = 0;
	Node *pNode = NULL;
	Node *pNextNodeAux = NULL;
	for (i = 0; i < ll_len(this); i++) {
		if (this != NULL && i >= 0 && i < ll_len(this)
				&& (getNode(this, i) != NULL)) {
			if (i == 0) {
				pNode = getNode(this, i + 1);
				this->pFirstNode = pNode;
				returnAux = 0;
			} else {
				if (i > 0 && i < ll_len(this)) {
					pNextNodeAux = getNode(this, i + 1);
					pNode = getNode(this, i - 1);
					pNode->pNextNode = pNextNodeAux;
					returnAux = 0;
				} else {
					pNode = getNode(this, (i - 1));
					pNode->pNextNode = NULL;
					returnAux = 0;
				}
			}
			if (returnAux == 0) {
				this->size = ll_len(this) - 1;
			}
		}
	}
	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;
	if (ll_clear(this) == 0) {
		this = NULL;
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int i;
	Node *pNode = NULL;
	if (this != NULL) {
		for (i = 0; i < ll_len(this); i++) {
			pNode = getNode(this, i);
			if (pNode->pElement == pElement) {
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;
	int i, j = 0;
	if (this != NULL) {
		for (i = 0; i < ll_len(this); i++) {
			if (this->pFirstNode != NULL) {
				j++;
			}
		}
		if (j == 0) {
			returnAux = 1;
		} else {
			if (j > 0) {
				returnAux = 0;
			}
		}
	}
	return returnAux;
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
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	int lenght = ll_len(this);
	Node *newNode = NULL;
	Node *auxNode = NULL;
	Node *lastNode = NULL;

	if (this != NULL && index >= 0 && index <= lenght) {
		newNode = (Node*) malloc(sizeof(Node));
		if (newNode != NULL) {
			newNode->pElement = pElement;
			newNode->pNextNode = NULL;
			if (index == 0) {
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
				returnAux = 0;
			} else {
				if (index > 0 && index < lenght) {
					auxNode = getNode(this, index);
					lastNode = getNode(this, (index - 1));
					lastNode->pNextNode = newNode;
					newNode->pNextNode = auxNode;
					returnAux = 0;
				} else {
					lastNode = getNode(this, (index - 1));
					lastNode->pNextNode = newNode;
					returnAux = 0;
				}
			}
		}
		if (returnAux == 0) {
			this->size = lenght + 1;
		}
	}
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		returnAux = ll_get(this, index);
		if (returnAux != NULL) {
			if (ll_remove(this, index) == 0) {
				return returnAux;
			}
		}
	}
	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int i, j = 0;
	void *auxElement = NULL;
	if (this != NULL) {
		for (i = 0; i < ll_len(this); i++) {
			auxElement = ll_get(this, i);
			if (auxElement == pElement) {
				j++;
			}
		}
		if (j > 0) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}
	return returnAux;
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
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	int i, j, k = 0;
	void *auxElement1 = NULL;
	void *auxElement2 = NULL;
	if (this != NULL && this2 != NULL) {
		if (ll_len(this) != ll_len(this2)) {
			returnAux = 0;
		} else {
			for (i = 0; i < ll_len(this); i++) {
				auxElement1 = ll_get(this, i);
				for (j = 0; j < ll_len(this2); j++) {
					auxElement2 = ll_get(this, j);
					if (auxElement1 == auxElement2) {
						k++;
					}
				}
			}
			if (k == ll_len(this)) {
				returnAux = 1;
			}
		}
	}
	return returnAux;
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
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int i;
	Node *pNode = NULL;
	if (this != NULL && from >= 0 && to >= 0 && from <= ll_len(this)
			&& to <= ll_len(this)) {
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			for (i = 0; i < ll_len(this); i++) {
				pNode = getNode(this, i);
				if (pNode != NULL) {
					addNode(cloneArray, i, pNode->pElement);
				}
			}
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
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;
	if (this != NULL) {
		cloneArray = ll_subList(this, 0, ll_len(this));
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
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	void *elementAux;
	int i, j;
	int len = ll_len(this);
	if (this != NULL && pFunc != NULL) {
		if (order == 1 || order == 0) {
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {
					if ((pFunc(ll_get(this, i), ll_get(this, j)) > 0
							&& order == 1)
							|| (pFunc(ll_get(this, i), ll_get(this, j)) < 0
									&& order == 0)) {
						elementAux = ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, elementAux);
						returnAux = 0;
					}
				}
			}
		}
	}
	return returnAux;

}

