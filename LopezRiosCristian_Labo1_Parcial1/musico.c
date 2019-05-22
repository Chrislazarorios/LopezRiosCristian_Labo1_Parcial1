#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "informes.h"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param tam int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int tam)                                    //cambiar musico
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
* \param array musico Array de musico
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int tam, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int tam, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)                                                   //cambiar campo ID
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
* \param array musico Array de musico
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int tam, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)                                                   //cambiar campo varInt
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
* \param array musico Array de musico
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int tam, char* valorBuscado, int* indice)                    //cambiar musico
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
* \param array musico Array de musico
* \param tam int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico arrayMusico[], int tam, int* contadorID)                         //cambiar musico
{
    int retorno=-1;
    int posicion;
    if(arrayMusico!=NULL && tam>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(arrayMusico,tam,&posicion)==-1)                          //cambiar musico
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            arrayMusico[posicion].idMusico=*contadorID;                                                       //campo ID
            arrayMusico[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre de musico: ","\nError",1,TEXT_SIZE,3,arrayMusico[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getName("\nIngrese apellido de musico: ","\nError",1,TEXT_SIZE,3,arrayMusico[posicion].apellido);                      //mensaje + cambiar campo nombre
            utn_getUnsignedInt("\nIngrese edad de musico: ","\nError",1,sizeof(int),1,1,1,&arrayMusico[posicion].edad);           //mensaje + cambiar campo varInt
            //utn_getEdad("\nIngrese edad de musico: ","\nError",0,110,3,&arrayMusico[posicion].edad);
            utn_getUnsignedInt("\nIngrese idOrquesta de musico: ","\nError",0,sizeof(int),0,110,3,&arrayMusico[posicion].idOrquesta);           //mensaje + cambiar campo varInt
            //informe_getIdOrquesta("\nIngrese idOrquesta de musico: ","\nError", 0, sizeof(int), 1, 1, 3, &arrayMusico[posicion].idOrquesta, arrayOrquesta, tam);
            utn_getUnsignedInt("\nIngrese idInstrumento de musico: ","\nError",1,sizeof(int),1,1,3,&arrayMusico[posicion].idInstrumento);           //mensaje + cambiar campo varInt
            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
                   posicion, arrayMusico[posicion].idMusico,arrayMusico[posicion].nombre,arrayMusico[posicion].apellido,arrayMusico[posicion].edad,arrayMusico[posicion].idOrquesta,arrayMusico[posicion].idInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int tamArray)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && tamArray>0)
    {
        musico_listar(array, tamArray);
        utn_getUnsignedInt("\nID de musico a cancelar: ","\nError",1,sizeof(int),1,tamArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idMusico=0;                                                                   //cambiar campo id
            array[posicion].edad=0;                                                               //cambiar campo varInt
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");
            array[posicion].idOrquesta=0;                                                               //cambiar campo varInt
            array[posicion].idInstrumento=0;
            printf("Musico eliminado exitosamente!!");                                                             //cambiar campo varInt

            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param tam int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int tamArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(array[i].idMusico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idMusico=0;                                                                   //cambiar campo id
                array[i].edad=0;                                                               //cambiar campo varInt                                                  //cambiar campo varInt
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");
                array[i].idOrquesta=0;                                                               //cambiar campo varInt
                array[i].idInstrumento=0;                                                //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int tamArray)                                //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    char opcionAux;

    if(array!=NULL && tamArray>0)
    {
        musico_listar(array, tamArray);
        utn_getUnsignedInt("\nID de musico a modificar: ","\nError",1,sizeof(int),1,tamArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
                   posicion, array[posicion].idMusico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);
                utn_getChar("\nModificar: \nA: nombre \nB: apellido \nC: edad \nD: idOrquesta \nE: idInstrumento \nS: salir\nElija una opcion(A/B/C/D/E/S):","\nError",'A','Z',1,&opcion);
                opcionAux = toupper(opcion);
                switch(opcionAux)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre de musico: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'B':
                        utn_getName("\nIngrese nuevo apellido de musico: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);                      //mensaje + cambiar campo nombre
                        break;
                    case 'C':
                        utn_getUnsignedInt("\nIngrese nueva edad de musico: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edad);           //mensaje + cambiar campo varInt
                        break;
                    case 'D':
                        utn_getUnsignedInt("\nIngrese nueva idOrquesta de musico: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idOrquesta);           //mensaje + cambiar campo varInt
                        break;
                    case 'E':
                        utn_getUnsignedInt("\nIngrese nueva idInstrumento de musico: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idInstrumento);           //mensaje + cambiar campo varInt
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
* \param array musico Array de musico
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorString(Musico array[],int tam)                              //cambiar musico
{
    int retorno=-1;
    int i, j;
    int opcion;

    Musico musicoAux;
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
                        if(strcmp(array[i].nombre, array[j].nombre) == 1) // Ordena de forma ascendente por nombre
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

                            musicoAux = array[i];
                            array[i] = array[j];
                            array[j] = musicoAux;

                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(strcmp(array[i].apellido, array[j].apellido) == 1) // Ordena de forma ascendente por apellido
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

                                musicoAux = array[i];
                                array[i] = array[j];
                                array[j] = musicoAux;

                            }
                        }
                    }
                }
                musico_listar(array, tam);
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

                            musicoAux = array[i];
                            array[i] = array[j];
                            array[j] = musicoAux;

                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(strcmp(array[i].apellido, array[j].apellido) == -1)// Ordena de forma descendente por apellido
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

                                musicoAux = array[i];
                                array[i] = array[j];
                                array[j] = musicoAux;
                            }
                        }
                    }
                }
                musico_listar(array, tam);
                break;
        }



        retorno=0;
    }
    return retorno;
}

//*****************************************

int musico_ordenarPorInt(Musico array[],int tam)
{
    int retorno = -1;
    int i, j;
    int opcion;

    Musico musicoAux;

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
                        if(array[i].idOrquesta > array[j].idOrquesta) // Ordena de forma ascendente por nombre
                        {

                            musicoAux = array[i];
                            array[i] = array[j];
                            array[j] = musicoAux;

                        }
                    }
                }
                musico_listar(array, tam);
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
                        if(array[i].idOrquesta < array[j].idOrquesta) // Ordena de forma descendente por nombre
                        {

                            musicoAux = array[i];
                            array[i] = array[j];
                            array[j] = musicoAux;

                        }

                    }
                }
                musico_listar(array, tam);
                break;
        }



        retorno=0;
    }
    return retorno;
}


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int tam)                      //cambiar musico
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
            {
                printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
                   array[i].idMusico,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
            }

        }

        retorno=0;
    }
    return retorno;
}

