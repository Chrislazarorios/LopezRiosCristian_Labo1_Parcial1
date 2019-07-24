#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "venta.h"
#include "utn.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListVenta)

{
    int ret = -1;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile == NULL)
    {
        printf("El archivo no existe");
    }
    else
    {
        if(!parser_VentaFromText(pFile , pArrayListVenta))
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
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListVenta)
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
        if(!parser_VentaFromBinary(pFile, pArrayListVenta))
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
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_addVenta(LinkedList* pArrayListVenta)
{
    Venta* pVenta;

    int ret = -1;
    int auxId;
    char auxFechaVenta[128];
    char auxTipoFoto[128];
    char auxCantidad[128];
    char auxPrecioUnitario[128];
    char auxCuitCLiente[128];

    if(pArrayListVenta != NULL)
    {
        pVenta = venta_new();

        auxId = venta_generaId();
        utn_getName("Ingrese fecha venta","Error",0,128,3,auxFechaVenta);
        utn_getTexto("\nIngrese tipo foto: ","\nError",1,50,3,auxTipoFoto);
        utn_getTexto("\nIngrese Cantidad: ","\nError",1,50,3,auxCantidad);

        if(pVenta != NULL &&
            !venta_setId(pVenta,auxId) &&
            !venta_setfechaVenta(pVenta,auxFechaVenta) &&
            !venta_setTipoFoto(pVenta,auxTipoFoto) &&
            !venta_setCantidadStr(pVenta,auxCantidad) &&
            !venta_setprecioUnitarioStr(pVenta,auxPrecioUnitario) &&
            !venta_setCuitCliente(pVenta,auxCuitCLiente))
        {
            if(!ll_add(pArrayListVenta,pVenta))
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
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
//int controller_editVenta(LinkedList* pArrayListVenta)
//{
//    int ret = -1;
////    Venta* pVenta;
//
//    int auxId;
////    char auxNombre[128];
////    int auxHorasTrabajo;
////    int auxSueldo;
//    char opcion;
//    char opcionAux;
//    int posicion;
//
//    if(pArrayListVenta != NULL)
//    {
//        controller_ListVenta(pArrayListVenta);
//        utn_getUnsignedInt("\nID de empleado a modificar: ","\nError",1,sizeof(int),1,20,3,&auxId);
//        posicion = controller_findVentaById(pArrayListVenta, auxId);
//        if(posicion == -1)
//        {
//            printf("\nNo existe este ID");
//        }
//        else
//        {
//            do
//            {
////                pVenta = ll_get(pArrayListVenta, posicion);
//
//                utn_getChar("\nQue desea modificar?: \nA: Nombre \nB: Horas trabajadas \nC: Sueldo \nS: salir\nElija una opcion(A/B/C/D/S):","\nError",'A','Z',1,&opcion);
//                opcionAux = toupper(opcion);
//                switch(opcionAux)
//                {
//                    case 'A':
////                        utn_getName("\nIngrese nuevo nombre de empleado: ","\nError",1,128,3, auxNombre);                      //mensaje + cambiar campo nombre
////                        venta_setfechaVenta(pVenta, auxNombre);
//                        break;
//                    case 'B':
////                        utn_getUnsignedInt("\nIngrese nueva cantidad de horas trabajadas: ","\nError",1,sizeof(int),0,20,3,&auxHorasTrabajo);
////                        pVenta_setHorasTrabajadas(pVenta, auxHorasTrabajo);
//                        break;
//                    case 'C':
////                        utn_getUnsignedInt("\nIngrese nuevo salario de empleado: ","\nError",1,sizeof(int),0,20,3,&auxSueldo);           //mensaje + cambiar campo varInt
////                        pVenta_setSueldo(pVenta, auxSueldo);
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
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_removeVenta(LinkedList* pArrayListVenta)
{
    int auxId;
    int ret = -1;
    int posicion;

    if(pArrayListVenta != NULL)
    {
        controller_ListVenta(pArrayListVenta);
        utn_getUnsignedInt("\nID de venta a remover: ","\nError",1,sizeof(int),1,20,3,&auxId);

        posicion = controller_findVentaById(pArrayListVenta, auxId);
        if(posicion == -1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListVenta, posicion);
            ret = 0;
        }
    }

    return ret;
}

/** \brief Listar ventas
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *><
 */
int controller_ListVenta(LinkedList* pArrayListVenta)
{
    int ret = -1;
    int i;
    Venta* pVenta;

    int auxId;
    char auxFechaVenta[128];
    char auxTipoFoto[128];
    int auxCantidad;
    int auxPrecioUnitario;
    char auxCuitCliente[128];
    int len;

    if(pArrayListVenta != NULL)
    {
        len = ll_len(pArrayListVenta);

        for(i = 0; i <= len; i++)
        {
            pVenta = ll_get(pArrayListVenta, i);
            venta_getId(pVenta, &auxId);
            venta_getfechaVenta(pVenta, auxFechaVenta);
            venta_getTipoFoto(pVenta, auxTipoFoto);
            venta_getCantidad(pVenta, &auxCantidad);
            venta_getprecioUnitario(pVenta, &auxPrecioUnitario);
            venta_getCuitCliente(pVenta,auxCuitCliente);

            if(pVenta != NULL)
            {
                printf("%d, %s, %s, %d, %d, %s\n", auxId, auxFechaVenta, auxTipoFoto, auxCantidad, auxPrecioUnitario, auxCuitCliente);
                ret = 0;
            }
        }
    }

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_sortVenta(LinkedList* pArrayListVenta)
{
    int ret = -1;
    int opcion;

    if(pArrayListVenta != NULL)
    {
        utn_getUnsignedInt("Como desea ordenar? Elija una opcion : \n0 - Ordenar de forma ascendente (A - Z)\n1 - Ordenar de forma descendente (Z - A)\n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);


        while(opcion != 0 && opcion != 1)
        {
            utn_getUnsignedInt("Error, seleccione opcion 0 o 1 : \n","\nError", 1, sizeof(int), 1, 1, 3, &opcion); // order 0 - ascendente // order 1 - descendente
        }


        switch(opcion)
        {
            case 0:
                ll_sort(pArrayListVenta, controller_comparisonString,0);
                break;
            case 1:
                ll_sort(pArrayListVenta, controller_comparisonString,1);
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
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListVenta)
{
    int ret = -1;
    int i;
    int len;
    //auxiliares para getters
    int auxId;
    char auxFechaVenta[128];
    char auxTipoFoto[128];
    int auxCantidad;
    int auxPrecioUnitario;
    char auxCuitCliente[128];

    Venta* pVenta; // creamos un puntero a empleado para guardar el resultado de ll_get


    FILE* fp = fopen(path, "w+");
    if(fp != NULL)
    {
        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListVenta); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            pVenta = ll_get(pArrayListVenta, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", pVenta->id, pVenta->nombre, pVenta->horasTrabajadas, pVenta->sueldo);//cambiamos este fprintf por una funcion

            venta_getId(pVenta, &auxId);
            venta_getfechaVenta(pVenta, auxFechaVenta);
            venta_getTipoFoto(pVenta, auxTipoFoto);
            venta_getCantidad(pVenta, &auxCantidad);
            venta_getprecioUnitario(pVenta, &auxPrecioUnitario);
            venta_getCuitCliente(pVenta,auxCuitCliente);
            fprintf(fp, "%d,%s,%s,%d,%d,%s\n", auxId, auxFechaVenta, auxTipoFoto, auxCantidad, auxPrecioUnitario, auxCuitCliente);

            ret = 0;
        }

        fclose(fp);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListVenta)
{
    int ret = -1;
    int i;
    //auxiliares para getters
//    int auxId;
//    char auxNombre[50];
//    int auxHorasTrabajo;
//    int auxSueldo;

    Venta* pVenta; // creamos un puntero a empleado para guardar el resultado de ll_get

    int len;
    FILE* fp = fopen(path, "w+b"); // en windows es w+b, en linux puede ir w+ o w+b, en linux es lo mismo
    if(fp != NULL)
    {
//        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListVenta); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            pVenta = ll_get(pArrayListVenta, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", pVenta->id, pVenta->nombre, pVenta->horasTrabajadas, pVenta->sueldo);//cambiamos este fprintf por una funcion

//            pVenta_getId(pVenta, &auxId);
//            pVenta_getNombre(pVenta, auxNombre);
//            pVenta_getHorasTrabajadas(pVenta, &auxHorasTrabajo);
//            pVenta_getSueldo(pVenta, &auxSueldo);
//            fprintf(fp, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajo, auxSueldo);

            // parametros de FWRITE
            // primer parametro recibe el puntero al array de donde quiero obtener los datos a escribir
            // segundo parametro es el tamano del tipo de dato del array de donde voy a leer para escribir
            // cantidad de elementos a escribir, en este caso 1 porque voy a escribir un empleado (un globito con todos los elementos de empleado, nombre,id,sueldo,etc)
            // puntero a FILE
            fwrite(pVenta,sizeof(Venta), 1, fp);

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

int controller_findVentaById(LinkedList* pArrayListVenta, int id)
{
    int ret = -1;
    int i;
    Venta* pVenta;
    int auxId;
    int len;

    if (pArrayListVenta != NULL && id >= 0)
    {
        len = ll_len(pArrayListVenta);

        for (i = 0;i < len;i++)
        {
            pVenta = ll_get(pArrayListVenta,i);
            venta_getId(pVenta,&auxId);
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
    int comparison = strcmp(((Venta*)this)->fechaVenta,((Venta*)that)->fechaVenta);
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






int controller_cantidadDeFotosReveladas(void* this)
{
    int ret = 0;
    Venta* pVenta;

    if (this!=NULL)
    {
        pVenta = (Venta*)this;
        if(pVenta != NULL)
        {
            ret = pVenta->cantidad;
        }
    }

    return ret;
}





int controller_cantidadDeFotosPrecio300(void* this)
{
    Venta* pVenta;
    int ret = 0;
    int auxPrecio;

    if (this!=NULL)
    {
        pVenta = (Venta*)this;
        auxPrecio = pVenta->precioUnitario*pVenta->cantidad;
        if(auxPrecio > 300)
        {
            ret = 1;
        }

    }

    return ret;
}

int controller_cantidadDeFotosPrecio150(void* this)
{
    Venta* pVenta;
    int ret = 0;
    int auxPrecio;

    if (this!=NULL)
    {
        pVenta = (Venta*)this;
        auxPrecio = pVenta->precioUnitario*pVenta->cantidad;
        if(auxPrecio > 150)
        {
            ret = 1;
        }

    }

    return ret;
}

int controller_cantidadDeFotosPolaroid(void* this)
{
    int ret = 0;
    Venta* pVenta;

    if(this!=NULL)
    {
        pVenta = (Venta*)this;
        if(strncmp(pVenta->tipoFoto,"POLAROID_11x9",sizeof(pVenta->tipoFoto))==0 || strncmp(pVenta->tipoFoto,"POLAROID_10x10",sizeof(pVenta->tipoFoto))==0)
        {
            ret = 1;
        }
    }

    return ret;
}

