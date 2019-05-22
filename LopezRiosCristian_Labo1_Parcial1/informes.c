#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
//#include <stdio_ext.h>
#include "musico.h"
#include "orquesta.h"
#include "utn.h"
#include "instrumento.h"
#include "informes.h"

int informe_totalOrquestas(Orquesta arrayOrquesta[], int tamArray)
{
    int i;
    int cont = 0;

    for(i = 0; i < tamArray; i++)
    {
        if(arrayOrquesta[i].isEmpty == 0)
        {
            cont++;
        }
    }

    return cont;
}



int informe_totalMusicos(Musico arrayMusico[], int tamArray)
{

    int i;
    int cont = 0;

    for(i = 0; i < tamArray; i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {
            cont++;
        }
    }

    return cont;
}



int informe_totalInstrumentos(Instrumento arrayInstrumento[], int tamArray)
{
    int i;
    int cont = 0;

    for(i = 0; i < tamArray; i++)
    {
        if(arrayInstrumento[i].isEmpty == 0)
        {
            cont++;
        }
    }

    return cont;
}

int informe_orquestaMasRepetida(Orquesta arrayOrquesta[], int tamArray) // Devuelve cuantas veces se repite el mismo tipo y que tipo se repite mas veces
{
    int i;
    int max = 0;
    int ret = -1;
    int maxTipo;
    int cantTipos;
    int tipoActual = arrayOrquesta[0].tipo;

    orquesta_ordenarPorInt(arrayOrquesta, tamArray);

    cantTipos = cantOrquestasMismoTipo(arrayOrquesta, tamArray, tipoActual);
    if(cantTipos > max)
    {
        max = cantTipos;
    }

    for(i = 0; i < tamArray; i++)
    {
        if(arrayOrquesta[i].tipo != arrayOrquesta[i-1].tipo)
        {
            tipoActual = arrayOrquesta[i].tipo;
            cantTipos = cantOrquestasMismoTipo(arrayOrquesta, tamArray, tipoActual);
            if(cantTipos > max)
            {
                fflush(stdin);
                max = cantTipos;
                maxTipo = tipoActual;
                ret = 0;
                printf("El tipo de orquesta mas repetida es %d con %d repeticiones", maxTipo, max);
            }
        }

    }


    return ret;
}


int cantOrquestasMismoTipo(Orquesta arrayOrquesta[], int tamArray, int tipoAContar)
{
    int i;
    int cont = 0;

    for(i = 0; i < tamArray; i++)
    {
        if(arrayOrquesta[i].isEmpty == 0)
        {
            if(arrayOrquesta[i].tipo == tipoAContar)
            {
                cont++;
            }
        }

    }

    return cont;
}


//***************************************************************************

// Lista todos los socios que solicitaron el prestamo de un libro determinado
//int inf_c(Socio* socios,int lenSoc, Prestamo* prestamos,int lenPrestamos,int idLibro)
//{
//    int i;
//    int idSocio;
//    for(i=0; i<lenSoc;i++)
//    {
//        idSocio = socios[i].id;
//
//        // filtro
//        if(socioTienePrestamoDeLibro(prestamos,lenPrestamos,idLibro,idSocio))
//        {
//            // PRINT
//            printf("nombre: %s",socios[i].nombre);
//        }
//    }
//}
//
//
//int socioTienePrestamoDeLibro(Prestamo* prestamos,int len,int idLibro,int idSocio)
//{
//    int i;
//    int tiene=0;
//    for(i=0; i<len;i++)
//    {
//        if(prestamos[i].isEmpty==0)
//        {
//            if( prestamos[i].idSocio == idSocio &&
//                prestamos[i].idLibro == idLibro)
//            {
//                tiene=1;
//                break;
//            }
//        }
//    }
//    return tiene;
//}

//***************************************************************************
//int musico_getIdOrquesta(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input, Orquesta arrayOrquesta[], int size);
//{
//    int retorno = -1;
//    int posOrquesta;
//    int auxInput;
//
//    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<=max && reintentos>=0 && input!=NULL) // valida los parametros de la funcion
//    {
//        do
//        {
//            if(!utn_getUnsignedInt(msg,msgError,minSize,maxSize,min,max,reintentos,&auxInput))
//            {
//                while(orquesta_buscarID(arrayOrquesta, size, auxInput, &posOrquesta) == -1)
//                {
//                    printf("ID de orquesta inexistente, intentelo otra vez");
//                    utn_getUnsignedInt(msg,msgError,minSize,maxSize,min,max,reintentos,&auxInput);
//                }
//
//                if(!orquesta_buscarID(arrayOrquesta, size, auxInput, &posOrquesta))
//                {
//                    *input = auxInput;
//                    printf("ID de libro existente, respuesta aceptada");
//                    retorno = 0;
//                    break;
//                }
//
//            }
//        }
//        while(reintentos>=0);
//    }
//
//    return retorno;
//}

//int informe_getIdInstrumento(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input, int valorBuscado, Instrumento arrayInstrumento[], int size)
//{
//    int retorno = -1;
//    int posLibro;
//
//    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<=max && reintentos>=0 && input!=NULL) // valida los parametros de la funcion
//    {
//        do
//        {
//            if(!utn_getUnsignedInt(msg,msgError,minSize,maxSize,min,max,reintentos,input))
//            {
//                while(orquesta_buscarID(arrayLibros, size, valorBuscado, &posLibro) == -1)
//                {
//                    printf("codigo de libro inexistente, intentelo otra vez");
//                    utn_getUnsignedInt(msg,msgError,minSize,maxSize,min,max,reintentos,input);
//                }
//
//                if(!orquesta_buscarID(arrayLibros, size,arrayPrestamos[posicion].codLibro, &posLibro))
//                {
//                    printf("codigo de libro existe, respuesta aceptada");
//                    retorno = 0;
//                }
//
//            }
//        }
//        while(reintentos>=0);
//
//    return retorno;
//}
