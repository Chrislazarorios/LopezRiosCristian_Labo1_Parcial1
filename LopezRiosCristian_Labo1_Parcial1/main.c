#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

#define QTY_ORQUESTA 50
#define QTY_INSTRUMENTO 20
#define QTY_MUSICO 1000



int main()
{
    int opcion;
    int contadorIdorquesta = 0;
    int contadorIdmusico = 0;                   //cambiar
    int contadorIdinstrumento = 0;                   //cambiar

    Orquesta arrayOrquesta[QTY_ORQUESTA]; //cambiar
    Musico arrayMusico[QTY_MUSICO];
    Instrumento arrayInstrumento[QTY_INSTRUMENTO];


    orquesta_Inicializar(arrayOrquesta, QTY_ORQUESTA);          //cambiar
    musico_Inicializar(arrayMusico, QTY_MUSICO);
    instrumento_Inicializar(arrayInstrumento, QTY_INSTRUMENTO);


    //***************************************************

    arrayOrquesta[0].isEmpty = 0;
    arrayOrquesta[0].idOrquesta = 10;
    strncpy(arrayOrquesta[0].nombre, "AA", sizeof(arrayOrquesta[0].nombre));
    strncpy(arrayOrquesta[0].lugar, "BB", sizeof(arrayOrquesta[0].lugar));
    arrayOrquesta[0].tipo = 3;

    arrayOrquesta[1].isEmpty = 0;
    arrayOrquesta[1].idOrquesta = 11;
    strncpy(arrayOrquesta[1].nombre, "CC", sizeof(arrayOrquesta[1].nombre));
    strncpy(arrayOrquesta[1].lugar, "DD", sizeof(arrayOrquesta[1].lugar));
    arrayOrquesta[1].tipo = 2;


    arrayOrquesta[2].isEmpty = 0;
    arrayOrquesta[2].idOrquesta = 12;
    strncpy(arrayOrquesta[2].nombre, "EE", sizeof(arrayOrquesta[2].nombre));
    strncpy(arrayOrquesta[2].lugar, "FF", sizeof(arrayOrquesta[2].lugar));
    arrayOrquesta[2].tipo = 1;



    //***************************************************

    arrayMusico[0].isEmpty = 0;
    arrayMusico[0].idMusico = 10;
    strncpy(arrayMusico[0].nombre, "TT", sizeof(arrayMusico[0].nombre));
    strncpy(arrayMusico[0].apellido, "TT", sizeof(arrayMusico[0].apellido));
    arrayMusico[0].edad = 11;
    arrayMusico[0].idOrquesta = 2;
    arrayMusico[0].idInstrumento = 2;

    arrayMusico[1].isEmpty = 0;
    arrayMusico[1].idMusico = 11;
    strncpy(arrayMusico[1].nombre, "YY", sizeof(arrayMusico[1].nombre));
    strncpy(arrayMusico[1].apellido, "YY", sizeof(arrayMusico[1].apellido));
    arrayMusico[1].edad = 22;
    arrayMusico[1].idOrquesta = 1;
    arrayMusico[1].idInstrumento = 1;

    arrayMusico[2].isEmpty = 0;
    arrayMusico[2].idMusico = 12;
    strncpy(arrayMusico[2].nombre, "UU", sizeof(arrayMusico[2].nombre));
    strncpy(arrayMusico[2].apellido, "UU", sizeof(arrayMusico[2].apellido));
    arrayMusico[2].edad = 33;
    arrayMusico[2].idOrquesta = 0;
    arrayMusico[2].idInstrumento = 0;

//    //***************************************************


    arrayInstrumento[0].isEmpty = 0;
    arrayInstrumento[0].idInstrumento = 10;
    strncpy(arrayInstrumento[0].nombre, "KK", sizeof(arrayInstrumento[0].nombre));
    strncpy(arrayInstrumento[0].tipoStr, "Cuerdas", sizeof(arrayInstrumento[0].nombre));
    arrayInstrumento[0].tipo = 4;



    arrayInstrumento[1].isEmpty = 0;
    arrayInstrumento[1].idInstrumento = 11;
    strncpy(arrayInstrumento[1].nombre, "LL", sizeof(arrayInstrumento[1].nombre));
    strncpy(arrayInstrumento[1].tipoStr, "Viento-madera", sizeof(arrayInstrumento[1].nombre));
    arrayInstrumento[1].tipo = 5;



    arrayInstrumento[2].isEmpty = 0;
    arrayInstrumento[2].idInstrumento = 12;
    strncpy(arrayInstrumento[2].nombre, "HH", sizeof(arrayInstrumento[2].nombre));
    strncpy(arrayInstrumento[2].tipoStr, "Percusion", sizeof(arrayInstrumento[2].nombre));
    arrayInstrumento[2].tipo = 6;



    do
    {
        utn_getUnsignedInt("\n\n1) Alta Orquesta\n2) Baja Orquesta\n3) Listar Orquesta\n****************************\n4) Alta Musico\n5) Modificar Musico\n6) Baja Musico\n7) Listar Musicos\n****************************\n8) Alta Instrumento\n9) Listar Instrumento\n****************************\n10) Salir\n",  //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                orquesta_alta(arrayOrquesta, QTY_ORQUESTA, &contadorIdorquesta);  //cambiar
                break;

            case 2: //Modificar
                orquesta_baja(arrayOrquesta, QTY_ORQUESTA);        //cambiar
                break;

            case 3: //Baja
                orquesta_listar(arrayOrquesta, QTY_ORQUESTA);  //cambiar
                break;

            case 4://Listar
                musico_alta(arrayMusico,QTY_MUSICO,&contadorIdmusico);
                break;

            case 5://Ordenar
                musico_modificar(arrayMusico,QTY_MUSICO);
                break;

            case 6:
                musico_baja(arrayMusico,QTY_MUSICO);
                break;
            case 7:
                musico_listar(arrayMusico,QTY_MUSICO);
                break;
            case 8:
                instrumento_alta(arrayInstrumento, QTY_INSTRUMENTO, &contadorIdinstrumento);
                break;
            case 9:
                instrumento_listar(arrayInstrumento, QTY_INSTRUMENTO);
                break;
            case 10://Salir
                //orquesta_modificar(arrayOrquesta, QTY_ORQUESTA);
                //orquesta_ordenarPorString(arrayOrquesta, QTY_ORQUESTA);
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);

    return 0;
}
