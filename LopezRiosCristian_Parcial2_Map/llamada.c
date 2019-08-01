#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"

static int ID_LlamadaGen = 0;

Llamada* llamada_new()
{
    return (Llamada*) malloc(sizeof(Llamada));
}

int llamada_generaId(void)
{
    return ID_LlamadaGen++;
}

void llamada_setIdInicial(int value)
{
    ID_LlamadaGen = value;
}


Llamada* llamada_newParametros(char* ID_Llamada,char* fecha,char* Numero_Cliente,char* ID_Problema, char* Solucionado)
{
    Llamada* emp = llamada_new();
    if(emp != NULL)
    {
        llamada_setIdStr(emp, ID_Llamada);
        llamada_setfecha(emp, fecha);
        llamada_setNumero_ClienteStr( emp, Numero_Cliente);
        llamada_setID_ProblemaStr( emp, ID_Problema);
        llamada_setSolucionado( emp, Solucionado);
    }


    return emp;
}

int llamada_delete(Llamada* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int llamada_setId(Llamada* this,int ID_Llamada)
{
    int retorno = -1;
    if(this != NULL && ID_Llamada >= 0)//faltan
    {
//        if(valID_LlamadaId)
        this->ID_Llamada = ID_Llamada;
        retorno = 0;
    }
    return retorno;
}

int llamada_setIdStr(Llamada* this,char* ID_Llamada)
{
    int retorno = -1;
    int ID_LlamadaAux;
    if(this != NULL)
    {
        ID_LlamadaAux = atoi(ID_Llamada);
        this->ID_Llamada = ID_LlamadaAux;
        retorno = 0;
    }
    return retorno;
}

int llamada_getId(Llamada* this,int* ID_Llamada)
{
    int ret = -1;

    if(this != NULL)
    {
        *ID_Llamada = this->ID_Llamada;
        ret = 0;
    }

    return ret;
}

// fecha llamada
int llamada_setfecha(Llamada* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}


int llamada_getfecha(Llamada* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(fecha,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

// Numero_Cliente
int llamada_setNumero_Cliente(Llamada* this,int Numero_Cliente)
{
    int retorno = -1;
    if(this != NULL && Numero_Cliente >= 0)
    {
        this->Numero_Cliente = Numero_Cliente;
        retorno = 0;
    }
    return retorno;
}

int llamada_setNumero_ClienteStr(Llamada* this,char* Numero_Cliente)
{
    int retorno = -1;
    int horasAux;
    if(this != NULL)
    {
        horasAux = atoi(Numero_Cliente);
        this->Numero_Cliente = horasAux;
        retorno = 0;
    }
    return retorno;
}


int llamada_getNumero_Cliente(Llamada* this,int* Numero_Cliente)
{
    int ret = -1;

    if(this != NULL)
    {
        *Numero_Cliente = this->Numero_Cliente;
        ret = 0;
    }

    return ret;
}

//precio unitario
int llamada_setID_Problema(Llamada* this,int ID_Problema)
{
    int retorno = -1;
    if(this != NULL && ID_Problema >= 0)
    {
        this->ID_Problema = ID_Problema;
        retorno = 0;
    }
    return retorno;
}

int llamada_setID_ProblemaStr(Llamada* this,char* ID_Problema)
{
    int retorno = -1;
    int ID_ProblemaAux;
    if(this != NULL)
    {
        ID_ProblemaAux = atoi(ID_Problema);
        this->ID_Problema = ID_ProblemaAux;
        retorno = 0;
    }
    return retorno;
}


int llamada_getID_Problema(Llamada* this,int* ID_Problema)
{
    int ret = -1;

    if(this != NULL)
    {
        *ID_Problema = this->ID_Problema;
        ret = 0;
    }

    return ret;
}
//cuit cliente
int llamada_setSolucionado(Llamada* this,char* Solucionado)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->Solucionado,Solucionado,sizeof(this->Solucionado));
        retorno = 0;
    }
    return retorno;
}
int llamada_getSolucionado(Llamada* this,char* Solucionado)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(Solucionado,this->Solucionado,sizeof(this->Solucionado));
        retorno = 0;
    }
    return retorno;
}

