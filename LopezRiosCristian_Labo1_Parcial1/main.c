#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"

#define QTY_ORQUESTA 50
#define QTY_INSTRUMENTO 20
#define QTY_MUSICO 15

// tipos de orquesta
#define ORQTIPO1 sinfonica
#define ORQTIPO2 filarmonica
#define ORQTIPO3 camara

//tipos de instrumento
#define INSTIPO1 Cuerdas
#define INSTIPO2 Viento-madera
#define INSTIPO3 Percusion

int main()
{
//    int auxTotalOrq;
//    float auxFloatOrq;
//    int auxTotalMus;
//    float auxFloatMus;
//    float prom;

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
    arrayOrquesta[0].idOrquesta = 1;
    strncpy(arrayOrquesta[0].nombre, "Orquesta1", sizeof(arrayOrquesta[0].nombre));
    strncpy(arrayOrquesta[0].lugar, "Lugar1", sizeof(arrayOrquesta[0].lugar));
    arrayOrquesta[0].tipo = 1;
    strncpy(arrayOrquesta[0].tipoStr, "sinfonica", sizeof(arrayOrquesta[0].tipoStr));

    arrayOrquesta[1].isEmpty = 0;
    arrayOrquesta[1].idOrquesta = 2;
    strncpy(arrayOrquesta[1].nombre, "Orquesta2", sizeof(arrayOrquesta[1].nombre));
    strncpy(arrayOrquesta[1].lugar, "Lugar1", sizeof(arrayOrquesta[1].lugar));
    arrayOrquesta[1].tipo = 2;
    strncpy(arrayOrquesta[1].tipoStr, "filarmonica", sizeof(arrayOrquesta[1].tipoStr));


    arrayOrquesta[2].isEmpty = 0;
    arrayOrquesta[2].idOrquesta = 3;
    strncpy(arrayOrquesta[2].nombre, "Orquesta3", sizeof(arrayOrquesta[2].nombre));
    strncpy(arrayOrquesta[2].lugar, "Lugar2", sizeof(arrayOrquesta[2].lugar));
    arrayOrquesta[2].tipo = 3;
    strncpy(arrayOrquesta[2].tipoStr, "sinfonica", sizeof(arrayOrquesta[2].tipoStr));


    arrayOrquesta[3].isEmpty = 0;
    arrayOrquesta[3].idOrquesta = 4;
    strncpy(arrayOrquesta[3].nombre, "Orquesta4", sizeof(arrayOrquesta[3].nombre));
    strncpy(arrayOrquesta[3].lugar, "Lugar3", sizeof(arrayOrquesta[3].lugar));
    arrayOrquesta[3].tipo = 3;
    strncpy(arrayOrquesta[3].tipoStr, "camara", sizeof(arrayOrquesta[3].tipoStr));
    //***************************************************

    arrayMusico[0].isEmpty = 0;
    arrayMusico[0].idMusico = 1;
    strncpy(arrayMusico[0].nombre, "Mus1", sizeof(arrayMusico[0].nombre));
    strncpy(arrayMusico[0].apellido, "Amus1", sizeof(arrayMusico[0].apellido));
    arrayMusico[0].edad = 30;
    arrayMusico[0].idOrquesta = 1;
    arrayMusico[0].idInstrumento = 2;

    arrayMusico[1].isEmpty = 0;
    arrayMusico[1].idMusico = 2;
    strncpy(arrayMusico[1].nombre, "Mus2", sizeof(arrayMusico[1].nombre));
    strncpy(arrayMusico[1].apellido, "Amus2", sizeof(arrayMusico[1].apellido));
    arrayMusico[1].edad = 20;
    arrayMusico[1].idOrquesta = 2;
    arrayMusico[1].idInstrumento = 5;

    arrayMusico[2].isEmpty = 0;
    arrayMusico[2].idMusico = 3;
    strncpy(arrayMusico[2].nombre, "Mus3", sizeof(arrayMusico[2].nombre));
    strncpy(arrayMusico[2].apellido, "Amus3", sizeof(arrayMusico[2].apellido));
    arrayMusico[2].edad = 25;
    arrayMusico[2].idOrquesta = 4;
    arrayMusico[2].idInstrumento = 2;

    arrayMusico[3].isEmpty = 0;
    arrayMusico[3].idMusico = 4;
    strncpy(arrayMusico[3].nombre, "Mus4", sizeof(arrayMusico[3].nombre));
    strncpy(arrayMusico[3].apellido, "Amus4", sizeof(arrayMusico[3].apellido));
    arrayMusico[3].edad = 27;
    arrayMusico[3].idOrquesta = 4;
    arrayMusico[3].idInstrumento = 1;

    arrayMusico[4].isEmpty = 0;
    arrayMusico[4].idMusico = 5;
    strncpy(arrayMusico[4].nombre, "Mus5", sizeof(arrayMusico[4].nombre));
    strncpy(arrayMusico[4].apellido, "Amus5", sizeof(arrayMusico[4].apellido));
    arrayMusico[4].edad = 22;
    arrayMusico[4].idOrquesta = 1;
    arrayMusico[4].idInstrumento = 3;

    arrayMusico[5].isEmpty = 0;
    arrayMusico[5].idMusico = 6;
    strncpy(arrayMusico[5].nombre, "Mus6", sizeof(arrayMusico[5].nombre));
    strncpy(arrayMusico[5].apellido, "Amus6", sizeof(arrayMusico[5].apellido));
    arrayMusico[5].edad = 35;
    arrayMusico[5].idOrquesta = 3;
    arrayMusico[5].idInstrumento = 4;



//    //***************************************************


    arrayInstrumento[0].isEmpty = 0;
    arrayInstrumento[0].idInstrumento = 1;
    strncpy(arrayInstrumento[0].nombre, "Inst1", sizeof(arrayInstrumento[0].nombre));
    strncpy(arrayInstrumento[0].tipoStr, "Cuerdas", sizeof(arrayInstrumento[0].nombre));
    arrayInstrumento[0].tipo = 1;



    arrayInstrumento[1].isEmpty = 0;
    arrayInstrumento[1].idInstrumento = 2;
    strncpy(arrayInstrumento[1].nombre, "Inst2", sizeof(arrayInstrumento[1].nombre));
    strncpy(arrayInstrumento[1].tipoStr, "Viento-madera", sizeof(arrayInstrumento[1].nombre));
    arrayInstrumento[1].tipo = 2;



    arrayInstrumento[2].isEmpty = 0;
    arrayInstrumento[2].idInstrumento = 3;
    strncpy(arrayInstrumento[2].nombre, "Inst3", sizeof(arrayInstrumento[2].nombre));
    strncpy(arrayInstrumento[2].tipoStr, "Viento-madera", sizeof(arrayInstrumento[2].nombre));
    arrayInstrumento[2].tipo = 2;


    arrayInstrumento[3].isEmpty = 0;
    arrayInstrumento[3].idInstrumento = 4;
    strncpy(arrayInstrumento[3].nombre, "Inst4", sizeof(arrayInstrumento[3].nombre));
    strncpy(arrayInstrumento[3].tipoStr, "Percusion", sizeof(arrayInstrumento[3].nombre));
    arrayInstrumento[3].tipo = 3;


    arrayInstrumento[4].isEmpty = 0;
    arrayInstrumento[4].idInstrumento = 5;
    strncpy(arrayInstrumento[4].nombre, "Inst5", sizeof(arrayInstrumento[4].nombre));
    strncpy(arrayInstrumento[4].tipoStr, "Percusion", sizeof(arrayInstrumento[4].nombre));
    arrayInstrumento[4].tipo = 3;




    do
    {
        utn_getUnsignedInt("\n\n1) Alta Orquesta\n2) Baja Orquesta\n3) Listar Orquesta\n****************************\n4) Alta Musico\n5) Modificar Musico\n6) Baja Musico\n7) Listar Musicos\n****************************\n8) Alta Instrumento\n9) Listar Instrumento\n****************************\n10) informe a\n11) informe b\n12) informe c \n13) informe d \n14) informe e\n15) informe f\n16) informe g\n17) informe h\n****************************\n18) Salir\n",  //cambiar
                      "\nError",1,sizeof(int),1,20,5,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                orquesta_alta(arrayOrquesta, QTY_ORQUESTA, &contadorIdorquesta);  //cambiar
                break;

            case 2: //Modificar
                orquesta_baja(arrayOrquesta, arrayMusico, QTY_ORQUESTA);        //cambiar
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
            case 10:
                inf_a(arrayMusico, arrayOrquesta, QTY_MUSICO, QTY_ORQUESTA);
//                orquesta_modificar(arrayOrquesta, QTY_ORQUESTA);
                break;
            case 11:
                inf_b(arrayMusico, arrayOrquesta, arrayInstrumento,QTY_MUSICO, QTY_ORQUESTA, QTY_INSTRUMENTO);
                //orquesta_ordenarPorString(arrayOrquesta, QTY_ORQUESTA);
                break;
            case 12:
                inf_c(arrayOrquesta, QTY_ORQUESTA);
                //musico_ordenarPorString(arrayMusico, QTY_MUSICO);
                break;
            case 13:
                inf_d(arrayMusico, arrayOrquesta, arrayInstrumento, QTY_MUSICO, QTY_ORQUESTA, QTY_INSTRUMENTO);
                //instrumento_baja(arrayInstrumento, QTY_INSTRUMENTO);
                break;
            case 14:
                inf_e(arrayMusico, arrayOrquesta, arrayInstrumento, QTY_MUSICO, QTY_ORQUESTA, QTY_INSTRUMENTO);
                //instrumento_modificar(arrayInstrumento, QTY_INSTRUMENTO);
                break;
            case 15:
                inf_f(arrayMusico, arrayOrquesta,  QTY_MUSICO,  QTY_ORQUESTA);
//                instrumento_ordenarPorString(arrayInstrumento, QTY_INSTRUMENTO);
                //informe_orquestaMasRepetida(arrayOrquesta, QTY_ORQUESTA);
                break;
            case 16:
                inf_g(arrayMusico, arrayInstrumento, arrayOrquesta, QTY_MUSICO, QTY_ORQUESTA, QTY_INSTRUMENTO);
                //instrumento_modificar(arrayInstrumento, QTY_INSTRUMENTO);
                break;
            case 17:
                inf_h( arrayMusico, arrayOrquesta, QTY_ORQUESTA, QTY_MUSICO);
                //instrumento_modificar(arrayInstrumento, QTY_INSTRUMENTO);
                break;
            case 18://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=18);

    return 0;
}
