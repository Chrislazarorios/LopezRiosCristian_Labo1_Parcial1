#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "envio.h"

static int ID_envioGen = 0;

envio* envio_new()
{
    return (envio*) malloc(sizeof(envio));
}

int envio_generaId(void)
{
    return ID_envioGen++;
}

void envio_setIdInicial(int value)
{
    ID_envioGen = value;
}


envio* envio_newParametros(char* ID_envio,char* nombre_producto,char* km_recorridos,char* tipo_entrega)
{
    envio* emp = envio_new();
    if(emp != NULL)
    {
        envio_setIdStr(emp, ID_envio);
        envio_setnombre_producto(emp, nombre_producto);
        envio_setkm_recorridosStr( emp, km_recorridos);
        envio_settipo_entregaStr( emp, tipo_entrega);
    }


    return emp;
}

int envio_delete(envio* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int envio_setId(envio* this,int ID_envio)
{
    int retorno = -1;
    if(this != NULL && ID_envio >= 0)//faltan
    {
//        if(valID_envioId)
        this->ID_envio = ID_envio;
        retorno = 0;
    }
    return retorno;
}

int envio_setIdStr(envio* this,char* ID_envio)
{
    int retorno = -1;
    int ID_envioAux;
    if(this != NULL)
    {
        ID_envioAux = atoi(ID_envio);
        this->ID_envio = ID_envioAux;
        retorno = 0;
    }
    return retorno;
}

int envio_getId(envio* this,int* ID_envio)
{
    int ret = -1;

    if(this != NULL)
    {
        *ID_envio = this->ID_envio;
        ret = 0;
    }

    return ret;
}

// nombre_producto envio
int envio_setnombre_producto(envio* this,char* nombre_producto)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->nombre_producto,nombre_producto,sizeof(this->nombre_producto));
        retorno = 0;
    }
    return retorno;
}


int envio_getnombre_producto(envio* this,char* nombre_producto)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre_producto,this->nombre_producto,sizeof(this->nombre_producto));
        retorno = 0;
    }
    return retorno;
}

// km_recorridos
int envio_setkm_recorridos(envio* this,int km_recorridos)
{
    int retorno = -1;
    if(this != NULL && km_recorridos >= 0)
    {
        this->km_recorridos = km_recorridos;
        retorno = 0;
    }
    return retorno;
}

int envio_setkm_recorridosStr(envio* this,char* km_recorridos)
{
    int retorno = -1;
    int horasAux;
    if(this != NULL)
    {
        horasAux = atoi(km_recorridos);
        this->km_recorridos = horasAux;
        retorno = 0;
    }
    return retorno;
}


int envio_getkm_recorridos(envio* this,int* km_recorridos)
{
    int ret = -1;

    if(this != NULL)
    {
        *km_recorridos = this->km_recorridos;
        ret = 0;
    }

    return ret;
}

//precio unitario
int envio_settipo_entrega(envio* this,int tipo_entrega)
{
    int retorno = -1;
    if(this != NULL && tipo_entrega >= 0)
    {
        this->tipo_entrega = tipo_entrega;
        retorno = 0;
    }
    return retorno;
}

int envio_settipo_entregaStr(envio* this,char* tipo_entrega)
{
    int retorno = -1;
    int tipo_entregaAux;
    if(this != NULL)
    {
        tipo_entregaAux = atoi(tipo_entrega);
        this->tipo_entrega = tipo_entregaAux;
        retorno = 0;
    }
    return retorno;
}


int envio_gettipo_entrega(envio* this,int* tipo_entrega)
{
    int ret = -1;

    if(this != NULL)
    {
        *tipo_entrega = this->tipo_entrega;
        ret = 0;
    }

    return ret;
}
// tipo entrega Char
int envio_settipo_entregaChar(envio* this,char* tipo_entregaChar)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->tipo_entregaStr,tipo_entregaChar,sizeof(this->tipo_entregaStr));
        retorno = 0;
    }
    return retorno;
}


int envio_gettipo_entregaChar(envio* this,char* tipo_entregaChar)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(tipo_entregaChar,this->tipo_entregaStr,sizeof(this->tipo_entregaStr));
        retorno = 0;
    }
    return retorno;
}


//costo envio

int envio_setcosto_envio(envio* this,int costo_envio)
{
    int retorno = -1;
    if(this != NULL && costo_envio >= 0)
    {
        this->costo_envio = costo_envio;
        retorno = 0;
    }
    return retorno;
}

int envio_setcosto_envioStr(envio* this,char* costo_envio)
{
    int retorno = -1;
    int tipo_entregaAux;
    if(this != NULL)
    {
        tipo_entregaAux = atoi(costo_envio);
        this->costo_envio = tipo_entregaAux;
        retorno = 0;
    }
    return retorno;
}


int envio_getcosto_envio(envio* this,int* costo_envio)
{
    int ret = -1;

    if(this != NULL)
    {
        *costo_envio = this->costo_envio;
        ret = 0;
    }

    return ret;
}
