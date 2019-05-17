#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20


typedef struct
{
    int idMusico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;
}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int tam);                                    //cambiar musico
int musico_buscarEmpty(Musico array[], int tam, int* posicion);                    //cambiar musico
int musico_buscarID(Musico array[], int tam, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarInt(Musico array[], int tam, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarString(Musico array[], int tam, char* valorBuscado, int* indice);                    //cambiar musico
int musico_alta(Musico array[], int tam, int* contadorID);                          //cambiar musico
int musico_baja(Musico array[], int tamArray);                                      //cambiar musico
int musico_bajaValorRepetidoInt(Musico array[], int tamArray, int valorBuscado);
int musico_modificar(Musico array[], int tamArray);                                //cambiar musico
int musico_ordenarPorString(Musico array[],int tam);                              //cambiar musico
int musico_listar(Musico array[], int tam);                      //cambiar musico


