#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"

static int ID_VentaGen = 0;

Venta* venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}

int venta_generaId(void)
{
    return ID_VentaGen++;
}

void venta_setIdInicial(int value)
{
    ID_VentaGen = value;
}


Venta* venta_newParametros(char* ID_VentaVenta,char* fechaVenta, char* tipoFoto,char* cantidad,char* precioUnitario, char* cuitCLiente)
{
    Venta* emp = venta_new();
    if(emp != NULL)
    {
        venta_setIdStr(emp, ID_VentaVenta);
        venta_setfechaVenta(emp, fechaVenta);
        venta_setTipoFoto( emp, tipoFoto);
        venta_setCantidadStr( emp, cantidad);
        venta_setprecioUnitarioStr( emp, precioUnitario);
        venta_setCuitCliente( emp, cuitCLiente);
    }


    return emp;
}

int venta_delete(Venta* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int venta_setId(Venta* this,int ID_Venta)
{
    int retorno = -1;
    if(this != NULL && ID_Venta >= 0)//faltan
    {
//        if(valID_VentaId)
        this->ID_Venta = ID_Venta;
        retorno = 0;
    }
    return retorno;
}

int venta_setIdStr(Venta* this,char* ID_Venta)
{
    int retorno = -1;
    int ID_VentaAux;
    if(this != NULL)
    {
        ID_VentaAux = atoi(ID_Venta);
        this->ID_Venta = ID_VentaAux;
        retorno = 0;
    }
    return retorno;
}

int venta_getId(Venta* this,int* ID_Venta)
{
    int ret = -1;

    if(this != NULL)
    {
        *ID_Venta = this->ID_Venta;
        ret = 0;
    }

    return ret;
}

// fecha venta
int venta_setfechaVenta(Venta* this,char* fechaVenta)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->fechaVenta,fechaVenta,sizeof(this->fechaVenta));
        retorno = 0;
    }
    return retorno;
}


int venta_getfechaVenta(Venta* this,char* fechaVenta)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(fechaVenta,this->fechaVenta,sizeof(this->fechaVenta));
        retorno = 0;
    }
    return retorno;
}
// Tipo foto
int venta_setTipoFoto(Venta* this,char* tipoFoto)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->tipoFoto,tipoFoto,sizeof(this->tipoFoto));
        retorno = 0;
    }
    return retorno;
}
int venta_getTipoFoto(Venta* this,char* tipoFoto)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(tipoFoto,this->tipoFoto,sizeof(this->tipoFoto));
        retorno = 0;
    }
    return retorno;
}
// cantidad
int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_setCantidadStr(Venta* this,char* cantidad)
{
    int retorno = -1;
    int horasAux;
    if(this != NULL)
    {
        horasAux = atoi(cantidad);
        this->cantidad = horasAux;
        retorno = 0;
    }
    return retorno;
}


int venta_getCantidad(Venta* this,int* cantidad)
{
    int ret = -1;

    if(this != NULL)
    {
        *cantidad = this->cantidad;
        ret = 0;
    }

    return ret;
}

//precio unitario
int venta_setprecioUnitario(Venta* this,int precioUnitario)
{
    int retorno = -1;
    if(this != NULL && precioUnitario >= 0)
    {
        this->precioUnitario = precioUnitario;
        retorno = 0;
    }
    return retorno;
}

int venta_setprecioUnitarioStr(Venta* this,char* precioUnitario)
{
    int retorno = -1;
    int precioUnitarioAux;
    if(this != NULL)
    {
        precioUnitarioAux = atoi(precioUnitario);
        this->precioUnitario = precioUnitarioAux;
        retorno = 0;
    }
    return retorno;
}


int venta_getprecioUnitario(Venta* this,int* precioUnitario)
{
    int ret = -1;

    if(this != NULL)
    {
        *precioUnitario = this->precioUnitario;
        ret = 0;
    }

    return ret;
}
//cuit cliente
int venta_setCuitCliente(Venta* this,char* cuitCLiente)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->cuitCLiente,cuitCLiente,sizeof(this->cuitCLiente));
        retorno = 0;
    }
    return retorno;
}
int venta_getCuitCliente(Venta* this,char* cuitCLiente)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(cuitCLiente,this->cuitCLiente,sizeof(this->cuitCLiente));
        retorno = 0;
    }
    return retorno;
}
