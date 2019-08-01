#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
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
    int returnAux = -1;
    if(this != NULL)
    {
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
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    Node* pNode = NULL;

    if(this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex < this->size)
        {
            pNode = (this->pFirstNode);

            for(i = 0; i < nodeIndex; i++)
            {
                pNode = pNode->pNextNode;
            }
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* previousNode = NULL;
    Node* pNode = NULL;
    pNode = (Node*)malloc(sizeof(Node));
//    int len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= this->size && pNode != NULL)
    {
        if(nodeIndex == 0) //si es el primer nodo
        {
            pNode->pElement = pElement; // elemento del nodo actual
            pNode->pNextNode = this->pFirstNode; // direccion del siguiente nodo es el indice+1

            this->pFirstNode = pNode;

            this->size++;
        }
        if(nodeIndex > 0)// si esta entre dos nodos
        {
            previousNode = getNode(this, nodeIndex-1); // obtengo el nodo anterior
            previousNode->pNextNode = pNode; // direccion del siguiente nodo es el nodo actual

            pNode->pElement = pElement; // elemento del nodo actual
            pNode->pNextNode = previousNode->pNextNode; // direccion del siguiente nodo es el indice+1

            this->size++;

        }
        if(nodeIndex == this->size)//si es el ultimo nodo
        {
            previousNode = getNode(this, nodeIndex-1);
            previousNode->pNextNode = pNode;

            pNode->pElement = pElement;
            pNode->pNextNode = NULL;

            this->size++;
        }

        returnAux = 0;
    }
    else
    {
        free(pNode);
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
    int returnAux = -1;

    int len = ll_len(this);

    returnAux = addNode(this, len, pElement); // addNode retorna 0 si funciono correctamente


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
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;
    pNode = getNode(this, index);

    if(this != NULL && index >= 0 && index <= this->size && pNode != NULL)
    {
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    pNode = getNode(this, index);
    if(this != NULL && index >= 0 && index < this->size)
    {
        pNode->pElement = pElement;

        if(pNode != NULL)
        {
            returnAux = 0;
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
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* previousNode;
    pNode = getNode(this, index);

    if(this != NULL && index >= 0 && index < this->size)
    {
        if(index == 0) //si es el primer nodo
        {
            pNode->pNextNode = this->pFirstNode; // direccion del siguiente nodo es el indice+1

            this->pFirstNode = pNode;
        }
        if(index > 0)// si esta entre dos nodos o al final
        {
            previousNode = getNode(this, index-1); // obtengo el nodo anterior

            previousNode->pNextNode = pNode->pNextNode; // direccion del siguiente nodo es el indice+1
        }
//        if(index == this->size)//si es el ultimo nodo, no hace falta
//        {
//
//        }

        this->size--;
        returnAux = 0;
    }
    free(pNode);
    return returnAux;
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
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
        for(i = 0; i< this->size; i++)
        {
            if(ll_remove(this, i) == 0)
            {
                returnAux = 0;
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
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        this = NULL;
        free(this);
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
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int i;

    if(this != NULL)
    {
        pNode = this->pFirstNode;
        for(i = 0; i < this->size; i++)
        {
            if(pNode->pElement == pElement)
            {
                returnAux = i;
                break;
            }
            pNode->pNextNode = pNode;
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
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->size != 0)
        {
            returnAux = 0;
        }
        else if(this->size == 0)
        {
            returnAux = 1;
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(addNode(this, index, pElement) == 0)
        {
            returnAux = 0;
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
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode;
//    Node* pAuxNode;

//    if(this != NULL && index >= 0 && index < this->size)
//    {
//        pAuxNode = getNode(this, index);
//        if(pAuxNode != NULL)
//        {
//            if(index == 0)//si es el primer nodo
//            {
//                pNode = this->pFirstNode;
////                this->pFirstNode = pNode;
//                returnAux = pNode->pElement; //retorno el elemento del nodo a borrar, para no perderlo despues de borrarlo
//                free(pNode); //borro el nodo a borrar
//                this->size--; //disminuyo el tamanio en un nodo menos
//            }
//            else// si esta entre medio de nodos o al final
//            {
//                pAuxNode = getNode(this, index-1); // el auxiliar es el anterior al nodo a borrar
//                pNode = pAuxNode->pNextNode; // el nodo a borrar es el siguiente al auxiliar
//                pAuxNode->pNextNode = pNode->pNextNode; // el siguiente del auxiliar es el siguiente del nodo a borrar, ya que el nodo a borrar ya no existira
//                returnAux = pNode->pElement; // retorno el elemento del nodo a borrar, para no perderlo despues de borrarlo
//                free(pNode); //borro el nodo a borrar
//                this->size--; //disminuyo el tamanio en un nodo menos
//            }
//        }

    if(this != NULL && index >= 0 && index < this->size)
    {
        pNode = getNode(this, index);
        if(pNode!=NULL)
        {
            returnAux = pNode->pElement;
            ll_remove(this, index);
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
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int flagContains = 0;
    int i;

    if(this != NULL)
    {
        for(i = 0; i < ll_len(this); i++)
        {
            pNode = getNode(this, i);
            if(pNode->pElement == pElement)
            {
                returnAux=1;
                flagContains = 1;
                break;
            }
        }
        if(flagContains == 0)
        {
            returnAux=0;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    int i;
    int j;
    Node* lista1;
    Node* lista2;

    if(this2!=NULL && this!=NULL)
    {
        for(i=0;i<=ll_len(this);i++)
        {
            lista1=ll_get(this,i);
           for(j=0;j<=ll_len(this2);j++)
           {
               lista1=ll_get(this,i);
               lista2=ll_get(this2,j);
               if(ll_len(this)==ll_len(this2))
               {
                   if(lista2==lista1)
                   {
                       returnAux=1;
                   }
               }
               else
               {
                   returnAux=0;
               }
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int lenLista=ll_len(this);
    Node *pAuxNode;
    if (this!=NULL && from>=0 && from<lenLista && to>from && to<=lenLista)
    {
        cloneArray=ll_newLinkedList();
        if (cloneArray!=NULL)
        {
            pAuxNode=this->pFirstNode;
            for(i=0;i<to;i++)
            {
                if (i>=from)
                {
                    addNode(cloneArray,i,pAuxNode->pElement);
                }
                pAuxNode=pAuxNode->pNextNode;
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
LinkedList* ll_clone(LinkedList* this)
{
//    LinkedList* cloneArray = NULL;
    return ll_subList(this,0,ll_len(this));

//    return cloneArray;
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
    int returnAux =-1;
    int i;
    int flagNoEstaOrdenado=1;
    int lenLista=ll_len(this);
    Node *pNodeA;
    Node *pNodeB;
    void *pAuxElement;
    if (this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
        if(lenLista>=2)
        {
            while(flagNoEstaOrdenado==1)
            {
                flagNoEstaOrdenado=0;
                pNodeA=this->pFirstNode->pNextNode;
                pNodeB=this->pFirstNode;
                for(i=1;i<lenLista;i++)
                {
                    if (order==0 && pFunc(pNodeA->pElement,pNodeB->pElement)>0)
                    {
                        pAuxElement=pNodeA->pElement;
                        pNodeA->pElement=pNodeB->pElement;
                        pNodeB->pElement=pAuxElement;
                        flagNoEstaOrdenado=1;
                    }
                    if(order==1 && pFunc(pNodeA->pElement,pNodeB->pElement)<0)
                    {
                        pAuxElement=pNodeA->pElement;
                        pNodeA->pElement=pNodeB->pElement;
                        pNodeB->pElement=pAuxElement;
                        flagNoEstaOrdenado=1;
                    }
                    pNodeA=pNodeA->pNextNode;
                    pNodeB=pNodeB->pNextNode;
                }
            }
            returnAux=0;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

//  pFunc return 1 en true y 0 en false

/** \brief Map recorre la lista y pasa elemento a elemento a la funcion pasada por parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param  pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de la funcion estan contenidos en la lista (this)
                        ( 0) si los elementos de la funcion NO estan contenidos en la lista (this)
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux = -1;
    void* element;
    int i;

    if(this != NULL)
    {
        for(i=0; i<this->size;i++)
        {
            element = ll_get(this, i);
            if(pFunc(element) != -1) // si la funcion parametro retorna true
            {
                returnAux = 1;
            }
            else
            {
                return 0;
            }
        }
    }

    return returnAux;
}

/** \brief reduce lo mismp pero si la funcion retorna true se borra
 *
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de la funcion estan contenidos en la lista (this)
                        ( 0) si los elementos de la funcion NO estan contenidos en la lista (this)
 */

 int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux = -1;
    void* element;
    int i;

    if(this != NULL)
    {
        for(i=0; i<this->size;i++)
        {
            element = ll_get(this, i);
            if(pFunc(element) == 1)
            {
                ll_remove(this, i);
                returnAux = 1;
            }
            else
            {
                returnAux = 0;
            }
        }

    }

    return returnAux;
}


/** \brief filter creas una lsita nueva recorres la lista vieja ocn la funcion parametro si da true haces un add a la lista nueva de ese elemento

 *
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de la funcion estan contenidos en la lista (this)
                        ( 0) si los elementos de la funcion NO estan contenidos en la lista (this)
 */

 LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* returnAux = NULL;
    void* pVoid;
    LinkedList* auxList = NULL;
    int i;

    if(this != NULL && (*pFunc)!=NULL)
    {
        auxList=ll_newLinkedList();
        returnAux=ll_newLinkedList();
        for(i=0; i<ll_len(this);i++)
        {
            pVoid=ll_get(this,i);
            if(pFunc(pVoid)==1)
            {
                ll_add(auxList,pVoid);
            }
//            else
//            {
//                returnAux = 0;
//            }
        }
        if(returnAux != NULL)
        {
            returnAux=auxList;
        }

    }

    return returnAux;
}



int ll_count(LinkedList* this, int(*fn)(void* elements))
{
    int i;
    int returnAux = -1;

    if(this != NULL && (*fn)!=NULL)
    {
        returnAux = 0;
        for(i=0; i<ll_len(this);i++)
        {
            returnAux += fn(ll_get(this, i));
        }
    }

    return returnAux;
}



