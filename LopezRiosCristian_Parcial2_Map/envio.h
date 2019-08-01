#ifndef envio_H_INCLUDED
#define envio_H_INCLUDED
typedef struct
{
    int ID_envio;
    //
    char nombre_producto[128];
    int km_recorridos;
    int tipo_entrega;
    char tipo_entregaStr[128];
    int costo_envio;
}envio;

int envio_generaId(void);
void envio_setIdInicial(int value);

envio* envio_new();
envio* envio_newParametrosInt(int idenvio,char* nombre_producto,int km_recorridos,int tipo_entrega);
envio* envio_newParametros(char* idenvio,char* nombre_producto,char* km_recorridos,char* tipo_entrega);
int envio_delete(envio* this);

int envio_setId(envio* this,int idenvio);
int envio_setIdStr(envio* this,char* idenvio);
int envio_getId(envio* this,int* idenvio);

int envio_setnombre_producto(envio* this,char* nombre_producto);
int envio_getnombre_producto(envio* this,char* nombre_producto);

int envio_setkm_recorridos(envio* this,int km_recorridos);
int envio_setkm_recorridosStr(envio* this,char* km_recorridos);
int envio_getkm_recorridos(envio* this,int* km_recorridos);

int envio_settipo_entrega(envio* this,int tipo_entrega);
int envio_settipo_entregaStr(envio* this,char* tipo_entrega);
int envio_gettipo_entrega(envio* this,int* tipo_entrega);

int envio_settipo_entregaChar(envio* this,char* nombre_producto);
int envio_gettipo_entregaChar(envio* this,char* nombre_producto);

int envio_setcosto_envio(envio* this,int tipo_entrega);
int envio_setcosto_envioStr(envio* this,char* tipo_entrega);
int envio_getcosto_envio(envio* this,int* tipo_entrega);

#endif // envio_H_INCLUDED
