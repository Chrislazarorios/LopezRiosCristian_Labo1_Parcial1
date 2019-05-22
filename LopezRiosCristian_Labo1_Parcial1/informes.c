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

    for(i = 0; i <= tamArray; i++)
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

int inf_a(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamArray)
{
    int i;
    int ret = -1;
    //int auxIdOrquesta;
    int IDmasDeCinco;
    int cantMus;
    int idOrqActual = arrayMusico[0].idOrquesta;



    musico_ordenarPorInt(arrayMusico, tamArray);

    cantMus = cantMusicoMismoTipo(arrayOrquesta, tamArray, idOrqActual);// cantidad de musicos en un mismo idOrquesta

    if(cantMus > 5)
    {
        printf("Nombre de orquesta con mas de 5 musicos : %s", arrayOrquesta[0].nombre);
    }

    for(i = 0; i < tamArray; i++)
    {

        if(arrayMusico[i].idOrquesta != arrayMusico[i-1].idOrquesta)
        {
            idOrqActual = arrayMusico[i].idOrquesta;


                cantMus = cantMusicoMismoTipo(arrayOrquesta, tamArray, idOrqActual);
                if(cantMus > 5)
                {

                        IDmasDeCinco = idOrqActual;
                        ret = 0;
                        printf("El id orquesta con mas de 5 musicos es %d", IDmasDeCinco);
                        //printf("Nombre de orquesta con mas de 5 musicos : %s", arrayMusico[auxIdOrquesta].nombre);



                }
        }

    }
    return ret;
}

int cantMusicoMismoTipo(Orquesta arrayOrquesta[], int tamArray, int idOrqActual)
{
    int i;
    int cont = 0;

    for(i = 0; i < tamArray; i++)
    {
        if(arrayOrquesta[i].isEmpty == 0)
        {
            if(arrayOrquesta[i].idOrquesta == idOrqActual)
            {
                cont++;
            }
        }

    }

    return cont;
}

//int orquestaTieneMusicos(Musico arrayMusico[],int len,int auxIdOrquesta)
//{
//    int i;
//    int tiene=-1;
//    for(i=0; i<len;i++)
//    {
//        if(arrayMusico[i].isEmpty==0)
//        {
//            if( arrayMusico[i].idOrquesta == auxIdOrquesta)
//            {
//                tiene=0;
//                break;
//            }
//        }
//    }
//    return tiene;
//}
//***************************************************************************
int inf_b(Musico arrayMusico[], int tamArray)
{
    int i;

    for(i = 0;i<tamArray; i++)
    {
        if(arrayMusico[i].edad > 30)
        {
            printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento);
        }
    }
 return 0;
}

//***************************************************************************

int inf_c(Orquesta arrayOrquesta[], int tamArray)
{
    int ret = -1;
    int i;
    char auxLugar[50];

    utn_getTexto("\nIngrese lugar de orquesta: ","\nError",1,TEXT_SIZE,1, auxLugar);


    for(i = 0; i< tamArray; i++)
    {
        if(arrayOrquesta[i].isEmpty == 0)
        {
            if(strcmp(auxLugar, arrayOrquesta[i].lugar)==0)
            {
                 printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
                   arrayOrquesta[i].idOrquesta,arrayOrquesta[i].nombre,arrayOrquesta[i].lugar,arrayOrquesta[i].tipo);
                ret = 0;
            }
        }

    }

    return ret;
}

//***************************************************************************



int inf_e(Musico arrayMusico[], int tamArray)
{
    int ret = -1;
    int i;
    int auxOrq;

    utn_getUnsignedInt("\nIngrese idOrquesta de musico: ","\nError",0,sizeof(int),0,110,3,&auxOrq);           //mensaje + cambiar campo varInt


    for(i = 0; i< tamArray; i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {
            if(auxOrq == arrayMusico[i].idOrquesta)
            {
                 printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento);
                ret = 0;
            }
        }

    }
    return ret;
}

//***************************************************************

//int inf_f(Musico arrayMusico[], int tamArray)
//{
//    return 0;
//}
//***************************************************************

//int inf_g(Musico arrayMusico[], Instrumento arrayInstrumento[], int tamArray)
//{
//    int ret = -1;
//    int i;
//    int auxOrq;
//
//    utn_getUnsignedInt("\nIngrese idOrquesta de musico: ","\nError",0,sizeof(int),0,110,3,&auxOrq);           //mensaje + cambiar campo varInt
//
//
//    for(i = 0; i< tamArray; i++)
//    {
//        if(arrayMusico[i].isEmpty == 0)
//        {
//            if(strcmp(auxLugar, arrayOrquesta[i].lugar)==0)
//            {
//                 printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
//                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento);
//                ret = 0;
//            }
//        }
//
//    }
//    return ret;
//
//}
//***************************************************************************

void inf_h(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamArray)
{
    int auxTotalOrq;
    int auxTotalMus;
    int prom;

    auxTotalOrq = informe_totalOrquestas(arrayOrquesta, tamArray);
    auxTotalMus = informe_totalMusicos(arrayMusico, tamArray);

    prom = auxTotalMus/auxTotalOrq;

    printf("\nEl promedio de musicos por orquesta es de %d\n", prom);
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
