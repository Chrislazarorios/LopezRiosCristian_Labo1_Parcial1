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

int musico_getIdOrquesta(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input, Orquesta arrayOrquesta[], int size);

int informe_getIdInstrumento(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input, Instrumento arrayInstrumento[], int size);


//***************************************************************
int informe_totalOrquestas(Orquesta arrayOrquesta[], int tamArray);
int informe_orquestaMasRepetida(Orquesta arrayOrquesta[], int tamArray);
int cantOrquestasMismoTipo(Orquesta arrayOrquesta[], int tamArray, int tipoAContar);



//***************************************************************
int informe_totalMusicos(Musico arrayMusico[], int tamArray);



//***************************************************************
int informe_totalInstrumentos(Instrumento arrayInstrumento[], int tamArray);
