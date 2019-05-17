#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "fantasma.h"
#include "autor.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"



/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array socios Array of socios
* \param tam int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socios_Inicializar(Socios array[], int tam)                                    //cambiar socios
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
* \param array socios Array de socios
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socios_buscarEmpty(Socios array[], int tam, int* posicion)                    //cambiar socios
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
* \param array socios Array de socios
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarID(Socios array[], int tam, int valorBuscado, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idSocios==valorBuscado)                                                   //cambiar campo ID
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
* \param array socios Array de socios
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarInt(Socios array[], int tam, int valorBuscado, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].isEmpty==1)
                continue;
//            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
//            {
//                retorno=0;
//                *posicion=i;
//                break;
//            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array socios Array de socios
* \param tam int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarString(Socios array[], int tam, char* valorBuscado, int* indice)                    //cambiar socios
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
* \param array socios Array de socios
* \param tam int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socios_alta(Socios array[], int tam, int* contadorID)                          //cambiar socios
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && tam>0 && contadorID!=NULL)
    {
        if(socios_buscarEmpty(array,tam,&posicion)==-1)                          //cambiar socios
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idSocios=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;

            utn_getName("\nIngrese nombre de socio : \n","\nError",1,TEXT_SIZE,3,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getName("\nIngrese apellido de socio: \n","\nError",1,TEXT_SIZE,3,array[posicion].apellido);                 //mensaje + cambiar campo apellido
            utn_getChar("\nIngrese sexo del socio(M/F): \n", "\nError",'A','Z',3,&array[posicion].sexo);
            utn_getTelefono("\nIngrese Telefono de socio: \n","\nError",1,TEXT_SIZE,8,12,3,array[posicion].telefono);                 //mensaje + cambiar campo apellido
            utn_getEmail("\nIngrese eMail\n","\nError",1,TEXT_SIZE,3,array[posicion].eMail);

            utn_getDate("\nIngrese dia de asociado: \n", "\nError, dia fuera de limite", 0,31,3,&array[posicion].dia);
            utn_getDate("\nIngrese mes de asociado: \n", "\nError, dia fuera de limite", 0,12,3,&array[posicion].mes);
            utn_getDate("\nIngrese anio de asociado: \n", "\nError, dia fuera de limite", 1800,2100,3,&array[posicion].anio);

//            utn_getUnsignedInt("\nIngrese dia de asociado: \n","\nError",1,sizeof(int),1,1,1,&array[posicion].dia);           //mensaje + cambiar campo varInt
//            utn_getUnsignedInt("\nIngrese mes de asociado: \n","\nError",1,sizeof(int),1,1,1,&array[posicion].mes);           //mensaje + cambiar campo varInt
//            utn_getUnsignedInt("\nIngrese anio de asociado: \n","\nError",2,20,4,20,3,&array[posicion].anio);           //mensaje + cambiar campo varInt

            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sexo: %c\n Telefono: %s\n eMail: %s\n Dia: %d\n Mes: %d\n Anio: %d\n",
                   posicion, array[posicion].idSocios,array[posicion].nombre,array[posicion].apellido, array[posicion].sexo, array[posicion].telefono, array[posicion].eMail, array[posicion].dia,array[posicion].mes, array[posicion].anio);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socios Array de socios
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_baja(Socios array[], int tamArray)                                      //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && tamArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,tamArray,1,&id);          //cambiar si no se busca por ID
        if(socios_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idSocios=0;                                                                   //cambiar campo id
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            array[posicion].sexo = ' ';
            strcpy(array[posicion].telefono,"");
            strcpy(array[posicion].eMail,"");
            array[posicion].dia=0;                                                                //cambiar campo varInt
            array[posicion].mes=0;                                                               //cambiar campo varInt
            array[posicion].anio=0;                                                               //cambiar campo varInt
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socios Array de socios
* \param tam int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_bajaValorRepetidoInt(Socios array[], int tamArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(array[i].idSocios==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idSocios=0;                                                                   //cambiar campo id
//                array[i].varInt=0;                                                               //cambiar campo varInt
//                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socios Array de socios
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int socios_modificar(Socios array[], int tamArray)                                //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && tamArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,tamArray,1,&id);         //cambiar si no se busca por ID
        if(socios_buscarID(array,tamArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
//                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n nombre: %s\n apellido: %s",
//                       posicion, array[posicion].idSocios,array[posicion].varInt,array[posicion].varFloat,array[posicion].nombre,array[posicion].apellido);
                utn_getChar("\nModificar: \nA: Nombre \nB: Apellido \nC: Sexo \nD: Telefono \nE: eMail \nF: Dia \nG: Mes \nH: Anio \nS: salir","\nError",'A','Z',3,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre de socio: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'B':
                        utn_getName("\nIngrese nuevo apellido de socio: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
                        break;
                    case 'C':
                        utn_getChar("\nIngrese nuevo sexo de socio (M/F): ","\nError",'A','Z',3,&array[posicion].sexo);
                        break;
                    case 'D':
                        utn_getTelefono("\nIngrese nuevo telefono de socio: ","\nError",8,TEXT_SIZE,8,12,3,array[posicion].telefono);
                        break;
                    case 'E':
                        utn_getEmail("\nIngrese nuevo eMail de socio: ", "\nError", TEXT_SIZE, 1024, 3, array[posicion].eMail);
                        break;
                    case 'F':
                        utn_getUnsignedInt("\nIngrese nuevo dia de socio: ","\nError",1,sizeof(int),1,1,1,&array[posicion].dia);           //mensaje + cambiar campo varInt
                        break;
                    case 'G':
                        utn_getUnsignedInt("\nIngrese nuevo mes de socio: ","\nError",1,sizeof(int),1,1,1,&array[posicion].mes);
                        break;
                    case 'H':
                        utn_getUnsignedInt("\nIngrese nuevo anio de socio: ","\nError",1,sizeof(int),1,1,1,&array[posicion].anio);
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
* \param array socios Array de socios
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socios_ordenarPorString(Socios array[],int tam)                              //cambiar socios
{
    int retorno=-1;
    int i, j;
    int opcion;

    //Socios socioAux;
    char auxNombre[56],auxApellido[56], auxTelefono[56], auxEmail[56], auxSexo;
    int auxDia, auxMes, auxAnio;

//    char bufferString[TEXT_SIZE];                               //cambiar campo nombre
//    int bufferId;
//    int bufferIsEmpty;

//    int bufferInt;                                              //cambiar buffer int
//    float bufferFloat;                                          //cambiar buffer varFloat
//    char bufferLongString[TEXT_SIZE];                           //cambiar campo apellido

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
                            strcpy(auxNombre,array[i].nombre);
                            strcpy(array[i].nombre, array[j].nombre);
                            strcpy(array[j].nombre,auxNombre);

                            strcpy(auxApellido,array[i].apellido);
                            strcpy(array[i].apellido, array[j].apellido);
                            strcpy(array[j].apellido,auxApellido);

                            auxSexo = array[i].sexo;
                            array[i].sexo = array[j].sexo;
                            array[j].sexo = auxSexo;

                            strcpy(auxTelefono,array[i].telefono);
                            strcpy(array[i].telefono, array[j].telefono);
                            strcpy(array[j].telefono,auxTelefono);

                            strcpy(auxEmail,array[i].eMail);
                            strcpy(array[i].eMail, array[j].eMail);
                            strcpy(array[j].eMail,auxEmail);

                            auxDia = array[i].dia;
                            array[i].dia = array[j].dia;
                            array[j].dia = auxDia;

                            auxMes = array[i].mes;
                            array[i].mes = array[j].mes;
                            array[j].mes = auxMes;

                            auxAnio = array[i].anio;
                            array[i].anio = array[j].anio;
                            array[j].anio = auxAnio;


//                            socioAux = array[i];
//                            array[i] = array[j];
//                            array[j] = socioAux;
                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(strcmp(array[i].apellido, array[j].apellido) == 1) // Ordena de forma ascendente por apellido
                            {
                                strcpy(auxNombre,array[i].nombre);
                                strcpy(array[i].nombre, array[j].nombre);
                                strcpy(array[j].nombre,auxNombre);

                                strcpy(auxApellido,array[i].apellido);
                                strcpy(array[i].apellido, array[j].apellido);
                                strcpy(array[j].apellido,auxApellido);

                                auxSexo = array[i].sexo;
                                array[i].sexo = array[j].sexo;
                                array[j].sexo = auxSexo;

                                strcpy(auxTelefono,array[i].telefono);
                                strcpy(array[i].telefono, array[j].telefono);
                                strcpy(array[j].telefono,auxTelefono);

                                strcpy(auxEmail,array[i].eMail);
                                strcpy(array[i].eMail, array[j].eMail);
                                strcpy(array[j].eMail,auxEmail);

                                auxDia = array[i].dia;
                                array[i].dia = array[j].dia;
                                array[j].dia = auxDia;

                                auxMes = array[i].mes;
                                array[i].mes = array[j].mes;
                                array[j].mes = auxMes;

                                auxAnio = array[i].anio;
                                array[i].anio = array[j].anio;
                                array[j].anio = auxAnio;

//                                socioAux = array[i];
//                                array[i] = array[j];
//                                array[j] = socioAux;
                            }
                        }
                    }
                }
                socios_listar(array, tam);
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
                            strcpy(auxNombre,array[i].nombre);
                            strcpy(array[i].nombre, array[j].nombre);
                            strcpy(array[j].nombre,auxNombre);

                            strcpy(auxApellido,array[i].apellido);
                            strcpy(array[i].apellido, array[j].apellido);
                            strcpy(array[j].apellido,auxApellido);

                            auxSexo = array[i].sexo;
                            array[i].sexo = array[j].sexo;
                            array[j].sexo = auxSexo;

                            strcpy(auxTelefono,array[i].telefono);
                            strcpy(array[i].telefono, array[j].telefono);
                            strcpy(array[j].telefono,auxTelefono);

                            strcpy(auxEmail,array[i].eMail);
                            strcpy(array[i].eMail, array[j].eMail);
                            strcpy(array[j].eMail,auxEmail);

                            auxDia = array[i].dia;
                            array[i].dia = array[j].dia;
                            array[j].dia = auxDia;

                            auxMes = array[i].mes;
                            array[i].mes = array[j].mes;
                            array[j].mes = auxMes;

                            auxAnio = array[i].anio;
                            array[i].anio = array[j].anio;
                            array[j].anio = auxAnio;

//                            socioAux = array[i];
//                            array[i] = array[j];
//                            array[j] = socioAux;
                        }
                        else if(strcmp(array[i].nombre, array[j].nombre) == 0)
                        {
                            if(strcmp(array[i].apellido, array[j].apellido) == -1)// Ordena de forma descendente por apellido
                            {
                                strcpy(auxNombre,array[i].nombre);
                                strcpy(array[i].nombre, array[j].nombre);
                                strcpy(array[j].nombre,auxNombre);

                                strcpy(auxApellido,array[i].apellido);
                                strcpy(array[i].apellido, array[j].apellido);
                                strcpy(array[j].apellido,auxApellido);

                                auxSexo = array[i].sexo;
                                array[i].sexo = array[j].sexo;
                                array[j].sexo = auxSexo;

                                strcpy(auxTelefono,array[i].telefono);
                                strcpy(array[i].telefono, array[j].telefono);
                                strcpy(array[j].telefono,auxTelefono);

                                strcpy(auxEmail,array[i].eMail);
                                strcpy(array[i].eMail, array[j].eMail);
                                strcpy(array[j].eMail,auxEmail);

                                auxDia = array[i].dia;
                                array[i].dia = array[j].dia;
                                array[j].dia = auxDia;

                                auxMes = array[i].mes;
                                array[i].mes = array[j].mes;
                                array[j].mes = auxMes;

                                auxAnio = array[i].anio;
                                array[i].anio = array[j].anio;
                                array[j].anio = auxAnio;

//                                socioAux = array[i];
//                                array[i] = array[j];
//                                array[j] = socioAux;
                            }
                        }
                    }
                }
                socios_listar(array, tam);
                break;
        }

        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array socios Array de socios
* \param tam int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socios_listar(Socios array[], int tam)                      //cambiar socios
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
            printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Sexo: %c\n Telefono: %s\n eMail: %s\n Dia: %d\n Mes: %d\n Anio: %d\n",
                       array[i].idSocios,array[i].nombre,array[i].apellido,array[i].sexo,array[i].telefono, array[i].eMail, array[i].dia, array[i].mes, array[i].anio);      //cambiar todos
            }

        }
        retorno=0;
    }
    return retorno;
}

