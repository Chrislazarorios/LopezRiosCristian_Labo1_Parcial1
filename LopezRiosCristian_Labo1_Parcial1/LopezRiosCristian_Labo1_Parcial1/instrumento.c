#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "instrumento.h" //cambiar por nombre entidad
#include "informes.h"



/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param tam int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int tam)                                    //cambiar instrumento
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
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int tam, int* posicion)                    //cambiar instrumento
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
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int tam, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumento==valorBuscado)                                                   //cambiar campo ID
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
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento array[], int tam, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)                                                   //cambiar campo tipo
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
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int tam, char* valorBuscado, int* indice)                    //cambiar instrumento
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
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int tam, int* contadorID)                          //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int* auxTipoStr;
    if(array!=NULL && tam>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,tam,&posicion)==-1)                          //cambiar instrumento
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idInstrumento=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre de instrumento: ","\nError",1,TEXT_SIZE,3,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getUnsignedInt("\nIngrese tipo de instrumento(4:Cuerdas/5:Viento-madera/6:Percusion): ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);           //mensaje + cambiar campo tipo
            auxTipoStr = &array[posicion].tipo;
            switch(*auxTipoStr)
            {
                case 4:
                    strcpy(array[posicion].tipoStr,"Cuerdas");
                    break;
                case 5:
                    strcpy(array[posicion].tipoStr,"Viento-madera");
                    break;
                case 6:
                    strcpy(array[posicion].tipoStr,"Percusion");
                    break;
            }

            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n tipo: %s\n",
                   posicion, array[posicion].idInstrumento,array[posicion].nombre,array[posicion].tipoStr);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int tamArray)                                      //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && tamArray>0)
    {
        instrumento_listar(array, tamArray);
        utn_getUnsignedInt("\nID de instrumento a cancelar: ","\nError",1,sizeof(int),1,tamArray,1,&id);          //cambiar si no se busca por ID
        if(instrumento_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idInstrumento=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo tipo
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int tamArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(array[i].idInstrumento==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idInstrumento=0;                                                                   //cambiar campo id
                array[i].tipo=0;                                                               //cambiar campo tipo
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int instrumento_modificar(Instrumento array[], int tamArray)                                //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    char opcionAux;

    if(array!=NULL && tamArray>0)
    {
        instrumento_listar(array, tamArray);
        utn_getUnsignedInt("\nID de instrumento a modificar: ","\nError",1,sizeof(int),1,tamArray,1,&id);         //cambiar si no se busca por ID
        if(instrumento_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n tipo: %d\n",
                   posicion, array[posicion].idInstrumento,array[posicion].nombre,array[posicion].tipo);
                utn_getChar("\nModificar: \nA: nombre \nB: tipo \nS: salir\nElija una opcion(A/B/S):","\nError",'A','Z',1,&opcion);
                opcionAux = toupper(opcion);
                switch(opcionAux)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre de instrumento: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nIngrese nuevo tipo de instrumento: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);           //mensaje + cambiar campo tipo
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcionAux!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int instrumento_ordenarPorString(Instrumento array[],int tam)                              //cambiar instrumento
{
    int retorno=-1;
    int i, j;
    int opcion;

    Instrumento instrumentoAux;
//    char auxNombre[56];
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
//
//
//                            auxTipo = array[i].tipo;
//                            array[i].tipo = array[j].tipo;
//                            array[j].tipo = auxTipo;


                            instrumentoAux = array[i];
                            array[i] = array[j];
                            array[j] = instrumentoAux;

                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(array[i].tipo > array[j].tipo) // Ordena de forma ascendente por apellido
                            {
//                                strcpy(auxNombre,array[i].nombre);
//                                strcpy(array[i].nombre, array[j].nombre);
//                                strcpy(array[j].nombre,auxNombre);
//
//
//                                auxTipo = array[i].tipo;
//                                array[i].tipo = array[j].tipo;
//                                array[j].tipo = auxTipo;


                                instrumentoAux = array[i];
                                array[i] = array[j];
                                array[j] = instrumentoAux;

                            }
                        }
                    }
                }
                instrumento_listar(array, tam);
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
//
//
//                            auxTipo = array[i].tipo;
//                            array[i].tipo = array[j].tipo;
//                            array[j].tipo = auxTipo;


                            instrumentoAux = array[i];
                            array[i] = array[j];
                            array[j] = instrumentoAux;

                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(array[i].tipo < array[j].tipo)// Ordena de forma descendente por apellido
                            {
//                                strcpy(auxNombre,array[i].nombre);
//                                strcpy(array[i].nombre, array[j].nombre);
//                                strcpy(array[j].nombre,auxNombre);
//
//
//                                auxTipo = array[i].tipo;
//                                array[i].tipo = array[j].tipo;
//                                array[j].tipo = auxTipo;


                                instrumentoAux = array[i];
                                array[i] = array[j];
                                array[j] = instrumentoAux;
                            }
                        }
                    }
                }
                instrumento_listar(array, tam);
                break;
        }



        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int tam)                      //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!=NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
            {
                    continue;
            }

            else
            {
                printf("\n ID: %d\n nombre: %s\n tipo: %s\n",
                   array[i].idInstrumento,array[i].nombre,array[i].tipoStr);

            }

        }
        retorno=0;
    }
    return retorno;
}

