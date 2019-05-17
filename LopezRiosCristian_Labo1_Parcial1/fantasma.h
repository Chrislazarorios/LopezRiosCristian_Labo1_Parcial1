#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 20

// magic numbers
//FANTASMA = 3
//Fantasma = 12
//fantasma = 21

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    float varFloat;
    char varChar;
    char varLongString[TEXT_SIZE];

}Fantasma;


#endif // FANTASMA_H_INCLUDED

int fantasma_Inicializar(Fantasma array[], int tam);                                    //cambiar fantasma
int fantasma_buscarEmpty(Fantasma array[], int tam, int* posicion);                    //cambiar fantasma
int fantasma_buscarID(Fantasma array[], int tam, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarInt(Fantasma array[], int tam, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarString(Fantasma array[], int tam, char* valorBuscado, int* indice);                    //cambiar fantasma
int fantasma_alta(Fantasma array[], int tam, int* contadorID);                          //cambiar fantasma
int fantasma_baja(Fantasma array[], int tamArray);                                      //cambiar fantasma
int fantasma_bajaValorRepetidoInt(Fantasma array[], int tamArray, int valorBuscado);
int fantasma_modificar(Fantasma array[], int tamArray);                                //cambiar fantasma
int fantasma_ordenarPorString(Fantasma array[],int tam);                              //cambiar fantasma
int fantasma_listar(Fantasma array[], int tam);                      //cambiar fantasma

