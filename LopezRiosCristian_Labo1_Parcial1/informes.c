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

//int informe_totalOrquestas(Orquesta arrayOrquesta[], int tamArray)
//{
//    int i;
//    int cont = 0;
//
//    for(i = 0; i < tamArray; i++)
//    {
//        if(arrayOrquesta[i].isEmpty == 0)
//        {
//            cont++;
////            printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
////                   arrayOrquesta[i].idOrquesta,arrayOrquesta[i].nombre,arrayOrquesta[i].lugar,arrayOrquesta[i].tipo);
//        }
//    }
//    printf("\n%d", cont);
//
//    return cont;
//}




//int informe_totalMusicos(Musico arrayMusico[], int tamArray)
//{
//
//    int i;
//    int cont = 0;
//
//    for(i = 0; i < tamArray; i++)
//    {
//        if(arrayMusico[i].isEmpty == 0)
//        {
//            cont++;
////            printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
////                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento);
//        }
//    }
//    printf("\n%d", cont);
//
//    return cont;
//}



//int informe_totalInstrumentos(Instrumento arrayInstrumento[], int tamArray)
//{
//    int i;
//    int cont = 0;
//
//    for(i = 0; i < tamArray; i++)
//    {
//        if(arrayInstrumento[i].isEmpty == 0)
//        {
//            cont++;
//        }
//    }
//
//    return cont;
//}
/** \brief prints orquesta that's repeated the most
 *
 * \param arrayOrquesta Array of orquesta
 * \param  tamArray int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

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

/** \brief returns number of times an orquesta is repeated
 *
 * \param arrayOrquesta Array of orquesta
 * \param tamArray int Array length
 * \param tipoAContar int Array tipo
 * \return int cont
 *
 */

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
// Listar las orquestas con mas de cinco musicos
/** \brief prints orquesta with more than 5 musicos
 *
 * \param array musico Array of musico
 * \param arrayOrquesta Array of orquesta
 * \param tamMusico int Array length
 * \param tamOrquesta int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int inf_a(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamMusico, int tamOrquesta)
{
    int i;
    int ret = -1;
    int posicionOrq;
    int IDmasDeCinco;
    int cantMus;
    int idOrqActual = arrayMusico[0].idOrquesta;

    musico_ordenarPorInt(arrayMusico, tamMusico);



    cantMus = cantMusicoMismoTipo(arrayMusico, tamMusico, idOrqActual);// cantidad de musicos que pertenecen a la misma orquesta en el primer idOrquesta

    if(cantMus > 5)
    {
        orquesta_buscarID(arrayOrquesta, tamOrquesta, idOrqActual, &posicionOrq);

        IDmasDeCinco = idOrqActual;
        printf("\nEl id de la orquesta con mas de 5 musicos es: %d", IDmasDeCinco);
        printf("\ncantidad de musicos en esta orquesta : %d\n", cantMus);
        printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
                   arrayOrquesta[posicionOrq].idOrquesta,arrayOrquesta[posicionOrq].nombre,arrayOrquesta[posicionOrq].lugar,arrayOrquesta[posicionOrq].tipo);
        ret = 0;
        exit(1);
    }

    for(i = 0; i < tamMusico; i++)
    {

        if(arrayMusico[i].idOrquesta != arrayMusico[i-1].idOrquesta)
        {
            idOrqActual = arrayMusico[i].idOrquesta;

            cantMus = cantMusicoMismoTipo(arrayMusico, tamMusico, idOrqActual);// cantidad de musicos en un determinado idOrquesta

            if(cantMus > 5)
            {
                orquesta_buscarID(arrayOrquesta, tamOrquesta, idOrqActual, &posicionOrq);

                IDmasDeCinco = idOrqActual;
                ret = 0;
                printf("\nEl id de la orquesta con mas de 5 musicos es: %d", IDmasDeCinco);
                printf("\ncantidad de musicos en esta orquesta : %d\n", cantMus);
                printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
                   arrayOrquesta[posicionOrq].idOrquesta,arrayOrquesta[posicionOrq].nombre,arrayOrquesta[posicionOrq].lugar,arrayOrquesta[posicionOrq].tipo);

            }
        }
    }
    return ret;
}

/** \brief returns number of musicos in a specific orquesta
 *
 * \param array musico Array of musico
 * \param tamArray int Array length
 * \param idOrqActual int idOrquesta in current position
 * \return int cont
 *
 */


int cantMusicoMismoTipo(Musico arrayMusico[], int tamArray, int idOrqActual)
{
    int i;
    int cont = 0;

    for(i = 0; i < tamArray; i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {
            if(arrayMusico[i].idOrquesta == idOrqActual)
            {
                cont++;
            }
        }
    }

    return cont;
}

//***************************************************************************
/** \brief
 *
 * \param array musico Array of musico
 * \param arrayOrquesta Array of orquesta
 * \param array Instrumento Array of Instrumentos
 * \param tamMusico int Array length
 * \param tamOrquesta int Array length
 * \param tamInstrumento int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int inf_b(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int tamMusico, int tamOrquesta, int tamInstrumento)
{
    int i;
    int ret = -1;
    int valorBuscadoOrq; // ID orquesta del musico mayor de 30
    int valorBuscadoIns; // ID instrumento del musico mayor de 30
    int posOrq; // posicion de la orquesta donde el musico es mayor de 30
    int posIns; // posicion del instrumento donde el musico es mayor de 30

    for(i = 0;i<tamMusico; i++)
    {
        if(arrayMusico[i].edad > 30)
        {
            ret = 0;
            valorBuscadoOrq = arrayMusico[i].idOrquesta;
            valorBuscadoIns = arrayMusico[i].idInstrumento;

            orquesta_buscarID(arrayOrquesta, tamOrquesta, valorBuscadoOrq, &posOrq);
            instrumento_buscarID(arrayInstrumento, tamInstrumento, valorBuscadoIns, &posIns);

            printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n Nombre del instrumento que toca : %s\n Nombre de la orquesta a la que pertenece : %s\n",
                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento, arrayInstrumento[posIns].nombre, arrayOrquesta[posOrq].nombre);
            break;
        }
    }
    return ret;
}

//***************************************************************************


int inf_c(Orquesta arrayOrquesta[], int tamArray)
{
    int ret = -1;
    int i;
    char auxLugar[50];
    char auxLugar2[50];

    utn_getTexto("\nIngrese lugar de orquesta: ","\nError",1,TEXT_SIZE,1, auxLugar);
    strncpy(auxLugar2, auxLugar, sizeof(auxLugar2));
    auxLugar2[0] = toupper(auxLugar[0]);


    for(i = 0; i< tamArray; i++)
    {
        if(arrayOrquesta[i].isEmpty == 0)
        {
            if(strcmp(auxLugar2, arrayOrquesta[i].lugar)==0)
            {
                 printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %s\n",
                   arrayOrquesta[i].idOrquesta,arrayOrquesta[i].nombre,arrayOrquesta[i].lugar,arrayOrquesta[i].tipoStr);
                ret = 0;
            }
        }

    }

    return ret;
}

//***************************************************************************
int inf_d(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int tamMusico, int tamOrquesta, int tamInstrumento)
{
    int i;
    int j = 0;
    int ret = -1;

    int idOrqActual;
    int idInst;
    int posInst;
    int posOrq;

    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;

    musico_ordenarPorInt(arrayMusico, tamMusico);

    idOrqActual = arrayOrquesta[j].idOrquesta;// recorro los id del array orquesta uno por uno, empezando por la posicion 0


    for(i = 0; i < tamMusico; i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {
            if(idOrqActual == arrayMusico[i].idOrquesta) // si el primer idOrquesta de arrayOrquesta y el idOrquesta de arrayMusico coinciden (ese musico en particular pertenece a esa orquesta)
            {
                idInst = arrayMusico[i].idInstrumento;// recorro los id instrumento del array musico uno por uno
                instrumento_buscarID(arrayInstrumento, tamInstrumento, idInst, &posInst);//obtengo la posicion del instrumento que posee ese musico
                if(arrayInstrumento[posInst].tipo == 1)
                {
                    cont1++;
                }
                else if(arrayInstrumento[posInst].tipo == 2)
                {
                    cont2++;
                }
                else if(arrayInstrumento[posInst].tipo == 3)
                {
                    cont3++;
                }
            }
            else if(arrayMusico[i].idOrquesta != arrayMusico[i-1].idOrquesta) // si el idOrquesta del arrayMusico cambia
            {
                idOrqActual = arrayOrquesta[j+1].idOrquesta;// el nuevo idOrquesta de arrayMusico es el idOrqActual

                if(idOrqActual == arrayMusico[i].idOrquesta)
                {
                    idInst = arrayMusico[i].idInstrumento;// recorro los id instrumento del array musico uno por uno
                    instrumento_buscarID(arrayInstrumento, tamInstrumento, idInst, &posInst);//obtengo la posicion del instrumento que posee ese musico
                    if(arrayInstrumento[posInst].tipo == 1)
                    {
                        cont1++;
                    }
                    else if(arrayInstrumento[posInst].tipo == 2)
                    {
                        cont2++;
                    }
                    else if(arrayInstrumento[posInst].tipo == 3)
                    {
                        cont3++;
                    }

                }
                j++;
            }
            if(cont1 == 5 && cont2 == 3 && cont3 == 2)
            {
                orquesta_buscarID(arrayOrquesta, tamOrquesta, idOrqActual, &posOrq);
                ret = 0;
                printf("\n*************************");
                printf("\nOrquesta completa!!");
                printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
                   arrayOrquesta[posOrq].idOrquesta,arrayOrquesta[posOrq].nombre,arrayOrquesta[posOrq].lugar,arrayOrquesta[posOrq].tipo);
                printf("\n*************************");

                printf("\ncontador 1 : %d", cont1);
                printf("\ncontador 2 : %d", cont2);
                printf("\ncontador 3 : %d", cont3);
            }
        }
    }





    return ret;
}




//***************************************************************************
int inf_e(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],  int tamMus, int tamOrq, int tamInst)
{
    int ret = -1;
    int i;
    int auxOrq;
//    char auxOrqStr[20];
//    char auxOrqStr2[20];
    int posInst;
//    int posOrq;

    utn_getUnsignedInt("\nIngrese idOrquesta de musico: ","\nError",0,sizeof(int),0,110,3,&auxOrq);           //mensaje + cambiar campo varInt
//    utn_getTexto("\nIngrese nombre de orquesta: ","\nError", 0, 20, 3, auxOrqStr);
//    strncpy(auxOrqStr2, auxOrqStr, sizeof(auxOrqStr2));
//    auxOrqStr2[0] = toupper(auxOrqStr[0]);


    for(i = 0; i< tamMus; i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {
            if(auxOrq == arrayMusico[i].idOrquesta)
            {
                instrumento_buscarID(arrayInstrumento, tamInst, arrayMusico[i].idInstrumento, &posInst);
                 printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n Nombre de instrumento: %s\n",
                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento, arrayInstrumento[posInst].nombre);
                ret = 0;
            }


//            if(!orquesta_buscarString(arrayOrquesta, tamOrq, auxOrqStr2, &posOrq))
//            {
//                if(strcmp(auxOrqStr2, arrayOrquesta[posOrq].nombre)==0)
//                {
//                    if(arrayOrquesta[posOrq].idOrquesta == arrayMusico[i].idOrquesta)
//                    {
//                        instrumento_buscarID(arrayInstrumento, tamInst, arrayMusico[i].idInstrumento, &posInst);
//                         printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n Nombre de instrumento: %s\n",
//                           arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento, arrayInstrumento[posInst].nombre);
//                        ret = 0;
//                    }
//
//                }
//            }

        }

    }
    return ret;
}

//***************************************************************

int inf_f(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamMusico, int tamOrquesta)
{
    int i;
    int ret = -1;
    int posicionOrq;
    int IDmasDeCinco;
    int cantMus;
    int max = 0;
    int idOrqActual = arrayMusico[0].idOrquesta;

    musico_ordenarPorInt(arrayMusico, tamMusico);


    cantMus = cantMusicoMismoTipo(arrayMusico, tamMusico, idOrqActual);// cantidad de musicos que pertenecen a la misma orquesta en el primer idOrquesta


    for(i = 0; i < tamMusico; i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {
            if(idOrqActual == arrayMusico[i].idOrquesta)
            {
                if(cantMus > max)
                {
                    max = cantMus;
                    orquesta_buscarID(arrayOrquesta, tamOrquesta, idOrqActual, &posicionOrq);

                    IDmasDeCinco = idOrqActual;
                    printf("\nEl id de la orquesta con mas musicos es: %d", IDmasDeCinco);
                    printf("\ncantidad de musicos en esta orquesta : %d\n", max);
                    printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %s\n",
                               arrayOrquesta[posicionOrq].idOrquesta,arrayOrquesta[posicionOrq].nombre,arrayOrquesta[posicionOrq].lugar,arrayOrquesta[posicionOrq].tipoStr);
                    ret = 0;
                }
            }

            else if(arrayMusico[i].idOrquesta != arrayMusico[i-1].idOrquesta)
            {
                idOrqActual = arrayMusico[i].idOrquesta;

                cantMus = cantMusicoMismoTipo(arrayMusico, tamMusico, idOrqActual);// cantidad de musicos en un determinado idOrquesta

                if(cantMus >= max)
                {
                    max = cantMus;
                    orquesta_buscarID(arrayOrquesta, tamOrquesta, idOrqActual, &posicionOrq);

                    IDmasDeCinco = idOrqActual;
                    ret = 0;
                    printf("\nEl id de la orquesta con mas musicos es: %d", IDmasDeCinco);
                    printf("\ncantidad de musicos en esta orquesta : %d\n", max);
                    printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %s\n",
                       arrayOrquesta[posicionOrq].idOrquesta,arrayOrquesta[posicionOrq].nombre,arrayOrquesta[posicionOrq].lugar,arrayOrquesta[posicionOrq].tipoStr);

                }
            }
        }
    }

    return ret;
}
//***************************************************************

int inf_g(Musico arrayMusico[], Instrumento arrayInstrumento[], Orquesta arrayOrquesta[], int tamMus, int tamOrq, int tamInst)
{
    int ret = -1;
    int i;
    int tipoBuscado = 1; // instrumento tipo 1 = cuerdas
    int posInst;
    int posOrq;

    for(i = 0; i< tamMus; i++)
    {
        if(arrayMusico[i].isEmpty == 0 )
        {
            instrumento_buscarInt(arrayInstrumento, tamInst, tipoBuscado, &posInst);
            if(arrayInstrumento[posInst].idInstrumento == arrayMusico[i].idInstrumento)
            {
                orquesta_buscarID(arrayOrquesta, tamOrq, arrayMusico[i].idOrquesta, &posOrq);
                 printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n Nombre de Orquesta: %s\n Nombre de Instrumento : %s\n",
                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento, arrayOrquesta[posOrq].nombre, arrayInstrumento[posInst].nombre);
                ret = 0;
            }
        }

    }
    return ret;

}
//***************************************************************************

void inf_h(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamOrq, int tamMus)
{

    float prom;

    int i;
    float contOrq = 0;
    float contMus = 0;

    for(i = 0; i < tamOrq; i++)
    {
        if(arrayOrquesta[i].isEmpty == 0)
        {
            contOrq++;
//            printf("\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %d\n",
//                   arrayOrquesta[i].idOrquesta,arrayOrquesta[i].nombre,arrayOrquesta[i].lugar,arrayOrquesta[i].tipo);
        }
    }
    printf("\nOrquestas : %.2f", contOrq);



    for(i = 0; i < tamMus; i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {
            contMus++;
//            printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idOrquesta: %d\n idInstrumento: %d\n",
//                   arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayMusico[i].idOrquesta,arrayMusico[i].idInstrumento);
        }
    }
    printf("\nMusicos: %.2f", contMus);


    prom = contMus/contOrq;

    printf("\nEl promedio de musicos por orquesta es de %.2f\n", prom);
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
