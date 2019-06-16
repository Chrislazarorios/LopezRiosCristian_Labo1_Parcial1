#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h" //cambiar por nombre entidad

// magic numbers
// 11 function names (Fantasma)
// 48 struct array names (fantasma)
// 12 idUnico
// 24 varInts
// 26 varString
// 22 varLongString


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param tam int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int fantasma_Inicializar(Fantasma array[], int tam)                                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma array[], int tam, int* posicion)                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma array[], int tam, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
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
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarInt(Fantasma array[], int tam, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
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
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarString(Fantasma array[], int tam, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
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
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int fantasma_alta(Fantasma array[], int tam, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && tam>0 && contadorID!=NULL)
    {
        if(fantasma_buscarEmpty(array,tam,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
            utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("getName\n: ","\nError",1,TEXT_SIZE,3,array[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getTexto("getTexto\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                   posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(Fantasma array[], int tamArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && tamArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,tamArray,1,&id);          //cambiar si no se busca por ID
        if(fantasma_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].varInt=0;                                                               //cambiar campo varInt
            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_bajaValorRepetidoInt(Fantasma array[], int tamArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int fantasma_modificar(Fantasma array[], int tamArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && tamArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,tamArray,1,&id);         //cambiar si no se busca por ID
        if(fantasma_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
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
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int fantasma_ordenarPorString(Fantasma array[],int tam)                              //cambiar fantasma
{
    int retorno=-1;
    int i, j;
    int opcion;

    Fantasma fantasmaAux;
//    char auxNombre[56],auxApellido[56], auxTelefono[56], auxEmail[56], auxSexo;
//    int auxDia, auxMes, auxAnio;

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
                        if(strcmp(array[i].varString, array[j].varString) == 1) // Ordena de forma ascendente por nombre
                        {
//                            strcpy(auxNombre,array[i].nombre);
//                            strcpy(array[i].nombre, array[j].nombre);
//                            strcpy(array[j].nombre,auxNombre);
//
//                            strcpy(auxApellido,array[i].apellido);
//                            strcpy(array[i].apellido, array[j].apellido);
//                            strcpy(array[j].apellido,auxApellido);
//
//                            auxSexo = array[i].sexo;
//                            array[i].sexo = array[j].sexo;
//                            array[j].sexo = auxSexo;
//
//                            strcpy(auxTelefono,array[i].telefono);
//                            strcpy(array[i].telefono, array[j].telefono);
//                            strcpy(array[j].telefono,auxTelefono);
//
//                            strcpy(auxEmail,array[i].eMail);
//                            strcpy(array[i].eMail, array[j].eMail);
//                            strcpy(array[j].eMail,auxEmail);
//
//                            auxDia = array[i].dia;
//                            array[i].dia = array[j].dia;
//                            array[j].dia = auxDia;
//
//                            auxMes = array[i].mes;
//                            array[i].mes = array[j].mes;
//                            array[j].mes = auxMes;
//
//                            auxAnio = array[i].anio;
//                            array[i].anio = array[j].anio;
//                            array[j].anio = auxAnio;

                            fantasmaAux = array[i];
                            array[i] = array[j];
                            array[j] = fantasmaAux;

                        }
                        else if(strcmp(array[i].varString, array[j].varString) == 0)
                        {
                            if(strcmp(array[i].varLongString, array[j].varLongString) == 1) // Ordena de forma ascendente por apellido
                            {
//                                strcpy(auxNombre,array[i].nombre);
//                                strcpy(array[i].nombre, array[j].nombre);
//                                strcpy(array[j].nombre,auxNombre);
//
//                                strcpy(auxApellido,array[i].apellido);
//                                strcpy(array[i].apellido, array[j].apellido);
//                                strcpy(array[j].apellido,auxApellido);
//
//                                auxSexo = array[i].sexo;
//                                array[i].sexo = array[j].sexo;
//                                array[j].sexo = auxSexo;
//
//                                strcpy(auxTelefono,array[i].telefono);
//                                strcpy(array[i].telefono, array[j].telefono);
//                                strcpy(array[j].telefono,auxTelefono);
//
//                                strcpy(auxEmail,array[i].eMail);
//                                strcpy(array[i].eMail, array[j].eMail);
//                                strcpy(array[j].eMail,auxEmail);
//
//                                auxDia = array[i].dia;
//                                array[i].dia = array[j].dia;
//                                array[j].dia = auxDia;
//
//                                auxMes = array[i].mes;
//                                array[i].mes = array[j].mes;
//                                array[j].mes = auxMes;
//
//                                auxAnio = array[i].anio;
//                                array[i].anio = array[j].anio;
//                                array[j].anio = auxAnio;

                                fantasmaAux = array[i];
                                array[i] = array[j];
                                array[j] = fantasmaAux;

                            }
                        }
                    }
                }
                fantasma_listar(array, tam);
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
                        if(strcmp(array[i].varString, array[j].varString) == -1) // Ordena de forma descendente por nombre
                        {
//                            strcpy(auxNombre,array[i].nombre);
//                            strcpy(array[i].nombre, array[j].nombre);
//                            strcpy(array[j].nombre,auxNombre);
//
//                            strcpy(auxApellido,array[i].apellido);
//                            strcpy(array[i].apellido, array[j].apellido);
//                            strcpy(array[j].apellido,auxApellido);
//
//                            auxSexo = array[i].sexo;
//                            array[i].sexo = array[j].sexo;
//                            array[j].sexo = auxSexo;
//
//                            strcpy(auxTelefono,array[i].telefono);
//                            strcpy(array[i].telefono, array[j].telefono);
//                            strcpy(array[j].telefono,auxTelefono);
//
//                            strcpy(auxEmail,array[i].eMail);
//                            strcpy(array[i].eMail, array[j].eMail);
//                            strcpy(array[j].eMail,auxEmail);
//
//                            auxDia = array[i].dia;
//                            array[i].dia = array[j].dia;
//                            array[j].dia = auxDia;
//
//                            auxMes = array[i].mes;
//                            array[i].mes = array[j].mes;
//                            array[j].mes = auxMes;
//
//                            auxAnio = array[i].anio;
//                            array[i].anio = array[j].anio;
//                            array[j].anio = auxAnio;

                            fantasmaAux = array[i];
                            array[i] = array[j];
                            array[j] = fantasmaAux;

                        }
                        else if(strcmp(array[i].varString, array[j].varString) == 0)
                        {
                            if(strcmp(array[i].varLongString, array[j].varLongString) == -1)// Ordena de forma descendente por apellido
                            {
//                                strcpy(auxNombre,array[i].nombre);
//                                strcpy(array[i].nombre, array[j].nombre);
//                                strcpy(array[j].nombre,auxNombre);
//
//                                strcpy(auxApellido,array[i].apellido);
//                                strcpy(array[i].apellido, array[j].apellido);
//                                strcpy(array[j].apellido,auxApellido);
//
//                                auxSexo = array[i].sexo;
//                                array[i].sexo = array[j].sexo;
//                                array[j].sexo = auxSexo;
//
//                                strcpy(auxTelefono,array[i].telefono);
//                                strcpy(array[i].telefono, array[j].telefono);
//                                strcpy(array[j].telefono,auxTelefono);
//
//                                strcpy(auxEmail,array[i].eMail);
//                                strcpy(array[i].eMail, array[j].eMail);
//                                strcpy(array[j].eMail,auxEmail);
//
//                                auxDia = array[i].dia;
//                                array[i].dia = array[j].dia;
//                                array[j].dia = auxDia;
//
//                                auxMes = array[i].mes;
//                                array[i].mes = array[j].mes;
//                                array[j].mes = auxMes;
//
//                                auxAnio = array[i].anio;
//                                array[i].anio = array[j].anio;
//                                array[j].anio = auxAnio;

                                fantasmaAux = array[i];
                                array[i] = array[j];
                                array[j] = fantasmaAux;
                            }
                        }
                    }
                }
                fantasma_listar(array, tam);
                break;
        }



        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma array[], int tam)                      //cambiar fantasma
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
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


