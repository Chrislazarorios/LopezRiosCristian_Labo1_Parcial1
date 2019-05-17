#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

#define TEXT_SIZE 20
#define TIPO1 sinfonica
#define TIPO2 filarmonica
#define TIPO3 camara


typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    int tipo;

}Orquesta;


#endif // ORQUESTA_H_INCLUDED

int orquesta_Inicializar(Orquesta array[], int tam);                                    //cambiar orquesta
int orquesta_buscarEmpty(Orquesta array[], int tam, int* posicion);                    //cambiar orquesta
int orquesta_buscarID(Orquesta array[], int tam, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarInt(Orquesta array[], int tam, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarString(Orquesta array[], int tam, char* valorBuscado, int* indice);                    //cambiar orquesta
int orquesta_alta(Orquesta array[], int tam, int* contadorID);                          //cambiar orquesta
int orquesta_baja(Orquesta array[], int tamArray);                                      //cambiar orquesta
int orquesta_bajaValorRepetidoInt(Orquesta array[], int tamArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int tamArray);                                //cambiar orquesta
int orquesta_ordenarPorString(Orquesta array[],int tam);                              //cambiar orquesta
int orquesta_listar(Orquesta array[], int tam);                      //cambiar orquesta

