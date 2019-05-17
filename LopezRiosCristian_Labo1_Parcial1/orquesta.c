#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param tam int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int tam)                                    //cambiar orquesta
{
    int retorno=-1;
    if(array!= NULL && tam>0)
    {
        for(;tam>0;tam--)
        {
            array[tam-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int tam, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0 && posicion!=NULL)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int tam, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int tam, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int tam, char* valorBuscado, int* indice)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int tam, int* contadorID)                          //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && tam>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,tam,&posicion)==-1)                          //cambiar orquesta
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idOrquesta=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre de orquesta: ","\nError",1,TEXT_SIZE,3,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("\nIngrese lugar de orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);                 //mensaje + cambiar campo varLongString
            utn_getUnsignedInt("\nIngrese tipo de orquesta(1/2/3): ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);           //mensaje + cambiar campo varInt
            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
                   posicion, array[posicion].idOrquesta,array[posicion].nombre,array[posicion].lugar,array[posicion].tipo);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int tamArray)                                      //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && tamArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,tamArray,1,tamArray,1,&id);          //cambiar si no se busca por ID
        if(orquesta_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idOrquesta=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo varInt
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].lugar,"");                                               //cambiar campo varLongString
            retorno=0;
            printf("Orquesta eliminada exitosamente!!");
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int tamArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(array[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idOrquesta=0;                                                                   //cambiar campo id
                array[i].tipo=0;                                                               //cambiar campo varInt
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].lugar,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orquesta_modificar(Orquesta array[], int tamArray)                                //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && tamArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,tamArray,1,&id);         //cambiar si no se busca por ID
        if(orquesta_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
                   posicion, array[posicion].idOrquesta,array[posicion].nombre,array[posicion].lugar,array[posicion].tipo);
                utn_getChar("\nModificar: \nA: nombre \nB: lugar \nC: tipo \nS: salir\nElija una opcion(A/B/C/S):","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre de orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre

                        break;
                    case 'B':
                        utn_getTexto("\nIngrese nuevo lugar para orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
                        break;
                    case 'C':
                        utn_getUnsignedInt("\nIngrese nuevo tipo de orquesta: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);           //mensaje + cambiar campo varInt

                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenarPorString(Orquesta array[],int tam)                              //cambiar orquesta
{
    int retorno=-1;
    int i, j;
    int opcion;

    Orquesta orquestaAux;
//    char auxNombre[56],auxLugar[56];
//    int auxTipo;

    if(array!=NULL && tam>=0)
    {

        utn_getUnsignedInt("Como desea ordenar? Elija una opcion : \n1 - Ordenar de forma ascendente (A - Z)\n2 - Ordenar de forma descendente (Z - A)\n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);


        while(opcion != 1 && opcion != 2)
        {
            utn_getUnsignedInt("Error, seleccione opcion 1 o 2 : \n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);
        }


        switch(opcion)
        {
            case 1:
                for(i = 0; i < tam - 1; i++)
                {
                    if(array[i].isEmpty == 1)
                    {
                        continue;
                    }
                    for(j = i + 1; j < tam; j++)
                    {
                        if(array[j].isEmpty == 1)
                        {
                            continue;
                        }
                        if(strcmp(array[i].nombre, array[j].nombre) == 1) // Ordena de forma ascendente por nombre
                        {
//                            strcpy(auxNombre,array[i].nombre);
//                            strcpy(array[i].nombre, array[j].nombre);
//                            strcpy(array[j].nombre,auxNombre);
////
//                            strcpy(auxLugar,array[i].lugar);
//                            strcpy(array[i].lugar, array[j].lugar);
//                            strcpy(array[j].lugar,auxLugar);
//
//                            auxTipo = array[i].tipo;
//                            array[i].tipo = array[j].tipo;
//                            array[j].tipo = auxTipo;


                            orquestaAux = array[i];
                            array[i] = array[j];
                            array[j] = orquestaAux;

                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(strcmp(array[i].lugar, array[j].lugar) == 1) // Ordena de forma ascendente por lugar
                            {
//                                strcpy(auxNombre,array[i].nombre);
//                                strcpy(array[i].nombre, array[j].nombre);
//                                strcpy(array[j].nombre,auxNombre);
//    //
//                                strcpy(auxLugar,array[i].lugar);
//                                strcpy(array[i].lugar, array[j].lugar);
//                                strcpy(array[j].lugar,auxLugar);
//
//                                auxTipo = array[i].tipo;
//                                array[i].tipo = array[j].tipo;
//                                array[j].tipo = auxTipo;

                                orquestaAux = array[i];
                                array[i] = array[j];
                                array[j] = orquestaAux;

                            }
                        }
                    }
                }
                orquesta_listar(array, tam);
                break;
            case 2:
                for(i = 0; i < tam - 1; i++)
                {
                    if(array[i].isEmpty == 1)
                    {
                        continue;
                    }
                    for(j = i + 1; j < tam; j++)
                    {
                        if(array[j].isEmpty == 1)
                        {
                            continue;
                        }
                        if(strcmp(array[i].nombre, array[j].nombre) == -1) // Ordena de forma descendente por nombre
                        {
//                            strcpy(auxNombre,array[i].nombre);
//                            strcpy(array[i].nombre, array[j].nombre);
//                            strcpy(array[j].nombre,auxNombre);
////
//                            strcpy(auxLugar,array[i].lugar);
//                            strcpy(array[i].lugar, array[j].lugar);
//                            strcpy(array[j].lugar,auxLugar);
//
//                            auxTipo = array[i].tipo;
//                            array[i].tipo = array[j].tipo;
//                            array[j].tipo = auxTipo;


                            orquestaAux = array[i];
                            array[i] = array[j];
                            array[j] = orquestaAux;

                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(strcmp(array[i].lugar, array[j].lugar) == -1)// Ordena de forma descendente por lugar
                            {
//                                strcpy(auxNombre,array[i].nombre);
//                                strcpy(array[i].nombre, array[j].nombre);
//                                strcpy(array[j].nombre,auxNombre);
//    //
//                                strcpy(auxLugar,array[i].lugar);
//                                strcpy(array[i].lugar, array[j].lugar);
//                                strcpy(array[j].lugar,auxLugar);
//
//                                auxTipo = array[i].tipo;
//                                array[i].tipo = array[j].tipo;
//                                array[j].tipo = auxTipo;


                                orquestaAux = array[i];
                                array[i] = array[j];
                                array[j] = orquestaAux;
                            }
                        }
                    }
                }
                orquesta_listar(array, tam);
                break;
        }



        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int tam)                      //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
                   array[i].idOrquesta,array[i].nombre,array[i].lugar,array[i].tipo);
        }
        retorno=0;
    }
    return retorno;
}


