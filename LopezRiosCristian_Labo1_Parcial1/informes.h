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

int inf_a(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamMusico, int tamOrquesta);
int cantMusicoMismoTipo(Musico arrayMusico[], int tamArray, int idOrqActual);

//***************************************************************

int inf_b(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int tamMusico, int tamOrquesta, int tamInstrumento);
//***************************************************************

int inf_c(Orquesta arrayOrquesta[], int tamArray);
//***************************************************************

int inf_d(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int tamMusico, int tamOrquesta, int tamInstrumento);

//***************************************************************

int inf_e(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],  int tamMus, int tamOrq, int tamInst);
//***************************************************************

int inf_f(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamMusico, int tamOrquesta);
//***************************************************************

int inf_g(Musico arrayMusico[], Instrumento arrayInstrumento[], Orquesta arrayOrquesta[], int tamMus, int tamOrq, int tamInst);
//***************************************************************

void inf_h(Musico arrayMusico[], Orquesta arrayOrquesta[], int tamOrq, int tamMus);


//***************************************************************
int informe_totalMusicos(Musico arrayMusico[], int tamArray);



//***************************************************************
int informe_totalInstrumentos(Instrumento arrayInstrumento[], int tamArray);
