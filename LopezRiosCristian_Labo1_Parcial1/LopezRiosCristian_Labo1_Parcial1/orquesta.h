#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

#include "musico.h"

#define TEXT_SIZE 20

typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    int tipo;
    char tipoStr[TEXT_SIZE];
}Orquesta;

#endif // ORQUESTA_H_INCLUDED




int orquesta_Inicializar(Orquesta array[], int tam);                                    //cambiar orquesta
int orquesta_buscarEmpty(Orquesta array[], int tam, int* posicion);                    //cambiar orquesta
int orquesta_buscarID(Orquesta array[], int tam, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarInt(Orquesta array[], int tam, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarString(Orquesta array[], int tam, char* valorBuscado, int* indice);                    //cambiar orquesta
int orquesta_alta(Orquesta array[], int tam, int* contadorID);                          //cambiar orquesta
int orquesta_baja(Orquesta array[], Musico arrayMusico[], int tamArray);                                      //cambiar orquesta
int orquesta_bajaValorRepetidoInt(Orquesta arrayOrquesta[], int tamArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int tamArray);                                //cambiar orquesta
int orquesta_ordenarPorString(Orquesta array[],int tam);                              //cambiar orquesta
int orquesta_ordenarPorInt(Orquesta array[],int tam);                              //cambiar orquesta
int orquesta_listar(Orquesta array[], int tam);                      //cambiar orquesta

