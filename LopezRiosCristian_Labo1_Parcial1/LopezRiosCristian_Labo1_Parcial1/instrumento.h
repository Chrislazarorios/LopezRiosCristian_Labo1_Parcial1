#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#define TEXT_SIZE 20


typedef struct
{
    int idInstrumento;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
    char tipoStr[TEXT_SIZE];

}Instrumento;


#endif // INSTRUMENTO_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int tam);                                    //cambiar instrumento
int instrumento_buscarEmpty(Instrumento array[], int tam, int* posicion);                    //cambiar instrumento
int instrumento_buscarID(Instrumento array[], int tam, int valorBuscado, int* posicion);                    //cambiar instrumento
int instrumento_buscarInt(Instrumento array[], int tam, int valorBuscado, int* posicion);                    //cambiar instrumento
int instrumento_buscarString(Instrumento array[], int tam, char* valorBuscado, int* indice);                    //cambiar instrumento
int instrumento_alta(Instrumento array[], int tam, int* contadorID);                          //cambiar instrumento
int instrumento_baja(Instrumento array[], int tamArray);                                      //cambiar instrumento
int instrumento_bajaValorRepetidoInt(Instrumento array[], int tamArray, int valorBuscado);
int instrumento_modificar(Instrumento array[], int tamArray);                                //cambiar instrumento
int instrumento_ordenarPorString(Instrumento array[],int tam);                              //cambiar instrumento
int instrumento_listar(Instrumento array[], int tam);                      //cambiar instrumento


