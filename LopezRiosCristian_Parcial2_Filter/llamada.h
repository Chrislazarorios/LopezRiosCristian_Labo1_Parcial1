#ifndef llamada_H_INCLUDED
#define llamada_H_INCLUDED
typedef struct
{
    int ID_Llamada;
    //
    char fecha[128];
    int Numero_Cliente;
    int ID_Problema;
    char Solucionado[128];
}Llamada;

int llamada_generaId(void);
void llamada_setIdInicial(int value);

Llamada* llamada_new();
Llamada* llamada_newParametrosInt(int idLlamada,char* fecha,int Numero_Cliente,int ID_Problema, char* Solucionado);
Llamada* llamada_newParametros(char* idLlamada,char* fecha,char* Numero_Cliente,char* ID_Problema, char* Solucionado);
int llamada_delete(Llamada* this);

int llamada_setId(Llamada* this,int idLlamada);
int llamada_setIdStr(Llamada* this,char* idLlamada);
int llamada_getId(Llamada* this,int* idLlamada);

int llamada_setfecha(Llamada* this,char* fecha);
int llamada_getfecha(Llamada* this,char* fecha);

int llamada_setTipoFoto(Llamada* this,char* tipoFoto);
int llamada_getTipoFoto(Llamada* this,char* tipoFoto);

int llamada_setNumero_Cliente(Llamada* this,int Numero_Cliente);
int llamada_setNumero_ClienteStr(Llamada* this,char* Numero_Cliente);
int llamada_getNumero_Cliente(Llamada* this,int* Numero_Cliente);

int llamada_setID_Problema(Llamada* this,int ID_Problema);
int llamada_setID_ProblemaStr(Llamada* this,char* ID_Problema);
int llamada_getID_Problema(Llamada* this,int* ID_Problema);

int llamada_setSolucionado(Llamada* this,char* Solucionado);
int llamada_getSolucionado(Llamada* this,char* Solucionado);

#endif // llamada_H_INCLUDED

