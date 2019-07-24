#ifndef venta_H_INCLUDED
#define venta_H_INCLUDED
typedef struct
{
    int ID_Venta;
    //
    char fechaVenta[128];
    char tipoFoto[128];
    int cantidad;
    int precioUnitario;
    char cuitCLiente[128];
}Venta;

int venta_generaId(void);
void venta_setIdInicial(int value);

Venta* venta_new();
Venta* venta_newParametrosInt(int idVenta,char* fechaVenta, char* tipoFoto,int cantidad,int precioUnitario, char* cuitCLiente);
Venta* venta_newParametros(char* idVenta,char* fechaVenta, char* tipoFoto,char* cantidad,char* precioUnitario, char* cuitCLiente);
int venta_delete(Venta* this);

int venta_setId(Venta* this,int idVenta);
int venta_setIdStr(Venta* this,char* idVenta);
int venta_getId(Venta* this,int* idVenta);

int venta_setfechaVenta(Venta* this,char* fechaVenta);
int venta_getfechaVenta(Venta* this,char* fechaVenta);

int venta_setTipoFoto(Venta* this,char* tipoFoto);
int venta_getTipoFoto(Venta* this,char* tipoFoto);

int venta_setCantidad(Venta* this,int cantidad);
int venta_setCantidadStr(Venta* this,char* cantidad);
int venta_getCantidad(Venta* this,int* cantidad);

int venta_setprecioUnitario(Venta* this,int precioUnitario);
int venta_setprecioUnitarioStr(Venta* this,char* precioUnitario);
int venta_getprecioUnitario(Venta* this,int* precioUnitario);

int venta_setCuitCliente(Venta* this,char* cuitCLiente);
int venta_getCuitCliente(Venta* this,char* cuitCLiente);

#endif // venta_H_INCLUDED
