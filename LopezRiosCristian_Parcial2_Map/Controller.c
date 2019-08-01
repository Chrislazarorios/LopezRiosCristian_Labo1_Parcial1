#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "envio.h"
#include "utn.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListenvio)

{
    int ret = -1;
    FILE* pFile;
    pFile = fopen(path,"r");
    printf("primer flag");
    if(pFile == NULL)
    {
        printf("El archivo no existe");
    }
    else
    {
        if(!parser_envioFromText(pFile , pArrayListenvio))
        {
            ret = 0;
        }
    }

    fclose(pFile);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListenvio)
{
    int ret = -1;
    FILE* pFile;
    pFile = fopen(path,"rb");

    if(pFile == NULL)
    {
        printf("El archivo no existe");
    }
    else
    {
        if(!parser_envioFromBinary(pFile, pArrayListenvio))
        {
            ret = 0;
        }
    }

    fclose(pFile);
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int controller_addenvio(LinkedList* pArrayListenvio)
{
    envio* penvio;
    int len;

    int ret = -1;
    int auxId;
    char auxnombre_productoenvio[128];
    char auxTipoFoto[128];
    char auxkm_recorridos[128];
    char auxtipo_entrega[128];

    if(pArrayListenvio != NULL)
    {
        penvio = envio_new();

//        auxId = envio_generaId();
        len = ll_len(pArrayListenvio);
        auxId = len + 1;
        utn_getName("Ingrese nombre_producto envio","Error",0,128,3,auxnombre_productoenvio);
        utn_getTexto("\nIngrese tipo foto: ","\nError",1,50,3,auxTipoFoto);
        utn_getTexto("\nIngrese km_recorridos: ","\nError",1,50,3,auxkm_recorridos);

//        utn_getUnsignedInt("\nIngrese tipo de orquesta(1:Sinfonica/2:Filarmonica/3:Camara): ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);           //mensaje + cambiar campo varInt
//            auxTipoStr = &array[posicion].tipo;
//            switch(*auxTipoStr)
//            {
//                case 1:
//                    strcpy(array[posicion].tipoStr,"Sinfonica");
//                    break;
//                case 2:
//                    strcpy(array[posicion].tipoStr,"Filarmonica");
//                    break;
//                case 3:
//                    strcpy(array[posicion].tipoStr,"Camara");
//                    break;
//            }

        if(penvio != NULL &&
            !envio_setId(penvio,auxId) &&
            !envio_setnombre_producto(penvio,auxnombre_productoenvio) &&
            !envio_setkm_recorridosStr(penvio,auxkm_recorridos) &&
            !envio_settipo_entregaStr(penvio,auxtipo_entrega))
        {
            if(!ll_add(pArrayListenvio,penvio))
            {
                ret = 0;
            }
            else
            {
                printf("Error al agregar empleado");
            }
        }
    }

    return ret;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
//int controller_editenvio(LinkedList* pArrayListenvio)
//{
//    int ret = -1;
////    envio* penvio;
//
//    int auxId;
////    char auxNombre[128];
////    int auxHorasTrabajo;
////    int auxSueldo;
//    char opcion;
//    char opcionAux;
//    int posicion;
//
//    if(pArrayListenvio != NULL)
//    {
//        controller_Listenvio(pArrayListenvio);
//        utn_getUnsignedInt("\nID de empleado a modificar: ","\nError",1,sizeof(int),1,20,3,&auxId);
//        posicion = controller_findenvioById(pArrayListenvio, auxId);
//        if(posicion == -1)
//        {
//            printf("\nNo existe este ID");
//        }
//        else
//        {
//            do
//            {
////                penvio = ll_get(pArrayListenvio, posicion);
//
//                utn_getChar("\nQue desea modificar?: \nA: Nombre \nB: Horas trabajadas \nC: Sueldo \nS: salir\nElija una opcion(A/B/C/D/S):","\nError",'A','Z',1,&opcion);
//                opcionAux = toupper(opcion);
//                switch(opcionAux)
//                {
//                    case 'A':
////                        utn_getName("\nIngrese nuevo nombre de empleado: ","\nError",1,128,3, auxNombre);                      //mensaje + cambiar campo nombre
////                        envio_setnombre_producto(penvio, auxNombre);
//                        break;
//                    case 'B':
////                        utn_getUnsignedInt("\nIngrese nueva km_recorridos de horas trabajadas: ","\nError",1,sizeof(int),0,20,3,&auxHorasTrabajo);
////                        penvio_setHorasTrabajadas(penvio, auxHorasTrabajo);
//                        break;
//                    case 'C':
////                        utn_getUnsignedInt("\nIngrese nuevo salario de empleado: ","\nError",1,sizeof(int),0,20,3,&auxSueldo);           //mensaje + cambiar campo varInt
////                        penvio_setSueldo(penvio, auxSueldo);
//                        break;
//                    case 'S':
//                        break;
//                    default:
//                        printf("\nOpcion no valida");
//                }
//            }while(opcionAux!='S');
//
//            ret = 0;
//        }
//    }
//
//    return ret;
//}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int controller_removeenvio(LinkedList* pArrayListenvio)
{
    int auxId;
    int ret = -1;
    int posicion;

    if(pArrayListenvio != NULL)
    {
        controller_Listenvio(pArrayListenvio);
        utn_getUnsignedInt("\nID de envio a remover: ","\nError",1,sizeof(int),1,20,3,&auxId);

        posicion = controller_findenvioById(pArrayListenvio, auxId);
        if(posicion == -1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListenvio, posicion);
            ret = 0;
        }
    }

    return ret;
}

/** \brief Listar envios
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *><
 */
int controller_Listenvio(LinkedList* pArrayListenvio)
{
    int ret = -1;
    int i;
    envio* penvio;


    int auxId;
    char auxnombre_productoenvio[128];
    int auxkm_recorridos;
    int auxtipo_entrega;
    int len;

    if(pArrayListenvio != NULL)
    {
        len = ll_len(pArrayListenvio);

        for(i = 0; i <= len; i++)
        {
            penvio = ll_get(pArrayListenvio, i);
            envio_getId(penvio, &auxId);
            envio_getnombre_producto(penvio, auxnombre_productoenvio);
            envio_getkm_recorridos(penvio, &auxkm_recorridos);
            envio_gettipo_entrega(penvio, &auxtipo_entrega);

            switch(auxtipo_entrega)
            {
                case 1:
                    envio_settipo_entregaChar(penvio, "normal");
                    break;
                case 2:
                    envio_settipo_entregaChar(penvio, "express");
                    break;
                case 3:
                    envio_settipo_entregaChar(penvio, "Segun disponibilidad");
                    break;
            }

            if(penvio != NULL)
            {
                printf("%d, %s, %d, %s\n", auxId, auxnombre_productoenvio, auxkm_recorridos, penvio->tipo_entregaStr);
                ret = 0;
            }
        }
    }

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int controller_sortenvio(LinkedList* pArrayListenvio)
{
    int ret = -1;
    int opcion;

    if(pArrayListenvio != NULL)
    {
        utn_getUnsignedInt("Como desea ordenar? Elija una opcion : \n0 - Ordenar de forma ascendente (A - Z)\n1 - Ordenar de forma descendente (Z - A)\n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);


        while(opcion != 0 && opcion != 1)
        {
            utn_getUnsignedInt("Error, seleccione opcion 0 o 1 : \n","\nError", 1, sizeof(int), 1, 1, 3, &opcion); // order 0 - ascendente // order 1 - descendente
        }


        switch(opcion)
        {
            case 0:
                ll_sort(pArrayListenvio, controller_comparisonString,0);
                break;
            case 1:
                ll_sort(pArrayListenvio, controller_comparisonString,1);
                break;
            default:
                printf("\nOpcion no valida");
        }
    }

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListenvio)
{
    int ret = -1;
    int i;
    int len;
    //auxiliares para getters
    int auxId;
    char auxnombre_productoenvio[128];
    int auxkm_recorridos;
    int auxtipo_entrega;

    envio* penvio; // creamos un puntero a empleado para guardar el resultado de ll_get


    FILE* fp = fopen(path, "w+");
    if(fp != NULL)
    {
        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListenvio); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            penvio = ll_get(pArrayListenvio, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", penvio->id, penvio->nombre, penvio->horasTrabajadas, penvio->sueldo);//cambiamos este fprintf por una funcion

            envio_getId(penvio, &auxId);
            envio_getnombre_producto(penvio, auxnombre_productoenvio);
            envio_getkm_recorridos(penvio, &auxkm_recorridos);
            envio_gettipo_entrega(penvio, &auxtipo_entrega);
            fprintf(fp, "%d,%s,%d,%d\n", auxId, auxnombre_productoenvio, auxkm_recorridos, auxtipo_entrega);

            ret = 0;
        }

        fclose(fp);
    }
    return ret;
}

//void allForOne(char* path, LinkedList* listaenvios)
//{
//    envio* penvio;
//    LinkedList* pListaenvios;
//    int i;
//    int len;
//    int numProblem;
//    int auxId;
//    char auxnombre_productoenvio[128];
//    int auxkm_recorridos;
//    int auxtipo_entrega;
//
//    FILE* fp = fopen(path, "w+");
//
//    utn_getUnsignedInt("\nIngrese numero de problema: ","\nError ",1,sizeof(int),1,30,3,&numProblem);
//
//    len = ll_len(listaenvios);
//
//    switch(numProblem)
//    {
//        case 1:
//            pListaenvios = ll_map(listaenvios, controller_map1);
//        break;
//        case 2:
//            pListaenvios = ll_map(listaenvios, controller_map2);
//        break;
//        case 3:
//            pListaenvios = ll_map(listaenvios, controller_map3);
//        break;
//        case 4:
//            pListaenvios = ll_map(listaenvios, controller_map4);
//        break;
//        case 5:
//            pListaenvios = ll_map(listaenvios, controller_map5);
//        break;
//    }
//    for(i = 0;i < len;i++)
//    {
//        penvio = ll_get(pListaenvios, i);
//
//        envio_getId(penvio, &auxId);
//        envio_getnombre_producto(penvio, auxnombre_productoenvio);
//        envio_getkm_recorridos(penvio, &auxkm_recorridos);
//        envio_gettipo_entrega(penvio, &auxtipo_entrega);
//        fprintf(fp, "%d,%s,%d,%d\n", auxId, auxnombre_productoenvio, auxkm_recorridos, auxtipo_entrega);
//
//    }
//
//    fclose(fp);
//}



void allForOne(char* path, LinkedList* listaenvios)
{
    envio* penvio;
    int i;
    int len;
    int auxId;
    char auxnombre_productoenvio[128];
    int auxkm_recorridos;
    int auxtipo_entrega;
    int auxcosto_envio;
    int costoFijo;

    FILE* fp = fopen(path, "w+");

    len = ll_len(listaenvios);

    fprintf(fp,"id_envio,nombre_producto,km_recorridos,tipo_entrega,costo_envio\n");


    for(i = 0;i < len;i++)
    {
        penvio = ll_get(listaenvios, i);

        envio_getId(penvio, &auxId);
        envio_getnombre_producto(penvio, auxnombre_productoenvio);
        envio_getkm_recorridos(penvio, &auxkm_recorridos);
        envio_gettipo_entrega(penvio, &auxtipo_entrega);

        if(auxtipo_entrega == 1)
        {
            costoFijo = 330;
        }
        else if(auxtipo_entrega == 2)
        {
            costoFijo = 560;
        }
        else if(auxtipo_entrega == 3)
        {
            costoFijo = 80;
        }

        envio_setcosto_envio(penvio, costoFijo);

        ll_map(listaenvios, controller_map0);

        envio_getcosto_envio(penvio, &auxcosto_envio);

        fprintf(fp, "%d,%s,%d,%d,%d\n", auxId, auxnombre_productoenvio, auxkm_recorridos, auxtipo_entrega, auxcosto_envio);

    }

    fclose(fp);
}

int controller_map0(void* this)
{
    int ret = -1;

    envio* penvio;

    penvio = (envio*)this;


    if(penvio != NULL)
    {
        if(penvio->km_recorridos < 50)
        {
            penvio->costo_envio += (67 * penvio->km_recorridos);
        }
        else
        {
            penvio->costo_envio += (80 * penvio->km_recorridos);
        }
        ret = 1;
    }

    return ret;
}

int controller_map1(void* this)
{
    int ret = -1;

    envio* penvio;

    penvio = (envio*)this;

//    len = ll_len(pArrayListenvio);

//    for(i = 0;i < len;i++)
//    {
        if(penvio->tipo_entrega == 1)
        {
            ret = 1;
        }
//    }



    return ret;
}
int controller_map2(void* this)
{
    int ret = -1;

    envio* penvio;

    penvio = (envio*)this;

    if(penvio->tipo_entrega == 2)
    {
        ret = 1;
    }

    return ret;
}
int controller_map3(void* this)
{
    int ret = -1;

    envio* penvio;

    penvio = (envio*)this;

    if(penvio->tipo_entrega == 3)
    {
        ret = 1;
    }

    return ret;
}
int controller_map4(void* this)
{
    int ret = -1;

    envio* penvio;

    penvio = (envio*)this;

    if(penvio->tipo_entrega == 4)
    {
        ret = 1;
    }

    return ret;
}
int controller_map5(void* this)
{
    int ret = -1;

    envio* penvio;

    penvio = (envio*)this;

    if(penvio->tipo_entrega == 5)
    {
        ret = 1;
    }

    return ret;
}



int controller_saveAsText3(char* path , LinkedList* pArrayListenvio, int tipoProblem)
{
    int ret = -1;
    int i;
    int len;
    //auxiliares para getters
    int auxId;
    char auxnombre_productoenvio[128];
    int auxkm_recorridos;
    int auxtipo_entrega;
//    int numProblem;

    envio* penvio; // creamos un puntero a empleado para guardar el resultado de ll_get


    FILE* fp = fopen(path, "w+");
    if(fp != NULL)
    {


        len = ll_len(pArrayListenvio); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            penvio = ll_get(pArrayListenvio, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", penvio->id, penvio->nombre, penvio->horasTrabajadas, penvio->sueldo);//cambiamos este fprintf por una funcion

            envio_getId(penvio, &auxId);
            envio_getnombre_producto(penvio, auxnombre_productoenvio);
            envio_getkm_recorridos(penvio, &auxkm_recorridos);
            envio_gettipo_entrega(penvio, &auxtipo_entrega);
            if(tipoProblem == auxtipo_entrega)
            {
                fprintf(fp, "%d,%s,%d,%d\n", auxId, auxnombre_productoenvio, auxkm_recorridos, auxtipo_entrega);
            }


            ret = 0;
        }

        fclose(fp);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListenvio)
{
    int ret = -1;
    int i;
    //auxiliares para getters
//    int auxId;
//    char auxNombre[50];
//    int auxHorasTrabajo;
//    int auxSueldo;

    envio* penvio; // creamos un puntero a empleado para guardar el resultado de ll_get

    int len;
    FILE* fp = fopen(path, "w+b"); // en windows es w+b, en linux puede ir w+ o w+b, en linux es lo mismo
    if(fp != NULL)
    {
//        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListenvio); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            penvio = ll_get(pArrayListenvio, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", penvio->id, penvio->nombre, penvio->horasTrabajadas, penvio->sueldo);//cambiamos este fprintf por una funcion

//            penvio_getId(penvio, &auxId);
//            penvio_getNombre(penvio, auxNombre);
//            penvio_getHorasTrabajadas(penvio, &auxHorasTrabajo);
//            penvio_getSueldo(penvio, &auxSueldo);
//            fprintf(fp, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajo, auxSueldo);

            // parametros de FWRITE
            // primer parametro recibe el puntero al array de donde quiero obtener los datos a escribir
            // segundo parametro es el tamano del tipo de dato del array de donde voy a leer para escribir
            // km_recorridos de elementos a escribir, en este caso 1 porque voy a escribir un empleado (un globito con todos los elementos de empleado, nombre,id,sueldo,etc)
            // puntero a FILE
            fwrite(penvio,sizeof(envio), 1, fp);

            ret = 0;
        }

        fclose(fp);
    }
    return ret;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int controller_findenvioById(LinkedList* pArrayListenvio, int id)
{
    int ret = -1;
    int i;
    envio* penvio;
    int auxId;
    int len;

    if (pArrayListenvio != NULL && id >= 0)
    {
        len = ll_len(pArrayListenvio);

        for (i = 0;i < len;i++)
        {
            penvio = ll_get(pArrayListenvio,i);
            envio_getId(penvio,&auxId);
            if (id==auxId)
            {
                ret = i;
                break;
            }
        }
    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return ret;
}

int controller_comparisonString(void *this,void *that)
{
    int ret = -1;
    int comparison = strcmp(((envio*)this)->nombre_producto,((envio*)that)->nombre_producto);
    if (comparison < 0)
    {
        ret = 1;
    }
    else if (comparison > 0)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}






//int controller_km_recorridosDeFotosReveladas(void* this)
//{
//    int ret = 0;
//    envio* penvio;
//
//    if (this!=NULL)
//    {
//        penvio = (envio*)this;
//        if(penvio != NULL)
//        {
//            ret = penvio->km_recorridos;
//        }
//    }
//
//    return ret;
//}





//int controller_km_recorridosDeFotosPrecio300(void* this)
//{
//    envio* penvio;
//    int ret = 0;
//    int auxPrecio;
//
//    if (this!=NULL)
//    {
//        penvio = (envio*)this;
//        auxPrecio = penvio->tipo_entrega*penvio->km_recorridos;
//        if(auxPrecio > 300)
//        {
//            ret = 1;
//        }
//
//    }
//
//    return ret;
//}

//int controller_km_recorridosDeFotosPrecio150(void* this)
//{
//    envio* penvio;
//    int ret = 0;
//    int auxPrecio;
//
//    if (this!=NULL)
//    {
//        penvio = (envio*)this;
//        auxPrecio = penvio->tipo_entrega*penvio->km_recorridos;
//        if(auxPrecio > 150)
//        {
//            ret = 1;
//        }
//
//    }
//
//    return ret;
//}
//
//int controller_km_recorridosDeFotosPolaroid(void* this)
//{
//    int ret = 0;
//    envio* penvio;
//
//    if(this!=NULL)
//    {
//        penvio = (envio*)this;
//        if(strncmp(penvio->tipoFoto,"POLAROID_11x9",sizeof(penvio->tipoFoto))==0 || strncmp(penvio->tipoFoto,"POLAROID_10x10",sizeof(penvio->tipoFoto))==0)
//        {
//            ret = 1;
//        }
//    }
//
//    return ret;
//}

