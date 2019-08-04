#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "llamada.h"
#include "utn.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLlamada)

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
        if(!parser_LlamadaFromText(pFile , pArrayListLlamada))
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
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListLlamada)
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
        if(!parser_LlamadaFromBinary(pFile, pArrayListLlamada))
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
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int controller_addLlamada(LinkedList* pArrayListLlamada)
{
    Llamada* pLlamada;
    int len;

    int ret = -1;
    int auxId;
    char auxFechaLlamada[128];
    char auxTipoFoto[128];
    char auxNumero_Cliente[128];
    char auxID_Problema[128];
    char auxCuitCLiente[128];

    if(pArrayListLlamada != NULL)
    {
        pLlamada = llamada_new();

//        auxId = llamada_generaId();
        len = ll_len(pArrayListLlamada);
        auxId = len + 1;
        utn_getName("Ingrese fecha llamada","Error",0,128,3,auxFechaLlamada);
        utn_getTexto("\nIngrese tipo foto: ","\nError",1,50,3,auxTipoFoto);
        utn_getTexto("\nIngrese Numero_Cliente: ","\nError",1,50,3,auxNumero_Cliente);

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

        if(pLlamada != NULL &&
            !llamada_setId(pLlamada,auxId) &&
            !llamada_setfecha(pLlamada,auxFechaLlamada) &&
            !llamada_setNumero_ClienteStr(pLlamada,auxNumero_Cliente) &&
            !llamada_setID_ProblemaStr(pLlamada,auxID_Problema) &&
            !llamada_setSolucionado(pLlamada,auxCuitCLiente))
        {
            if(!ll_add(pArrayListLlamada,pLlamada))
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
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
//int controller_editLlamada(LinkedList* pArrayListLlamada)
//{
//    int ret = -1;
////    Llamada* pLlamada;
//
//    int auxId;
////    char auxNombre[128];
////    int auxHorasTrabajo;
////    int auxSueldo;
//    char opcion;
//    char opcionAux;
//    int posicion;
//
//    if(pArrayListLlamada != NULL)
//    {
//        controller_ListLlamada(pArrayListLlamada);
//        utn_getUnsignedInt("\nID de empleado a modificar: ","\nError",1,sizeof(int),1,20,3,&auxId);
//        posicion = controller_findLlamadaById(pArrayListLlamada, auxId);
//        if(posicion == -1)
//        {
//            printf("\nNo existe este ID");
//        }
//        else
//        {
//            do
//            {
////                pLlamada = ll_get(pArrayListLlamada, posicion);
//
//                utn_getChar("\nQue desea modificar?: \nA: Nombre \nB: Horas trabajadas \nC: Sueldo \nS: salir\nElija una opcion(A/B/C/D/S):","\nError",'A','Z',1,&opcion);
//                opcionAux = toupper(opcion);
//                switch(opcionAux)
//                {
//                    case 'A':
////                        utn_getName("\nIngrese nuevo nombre de empleado: ","\nError",1,128,3, auxNombre);                      //mensaje + cambiar campo nombre
////                        llamada_setfecha(pLlamada, auxNombre);
//                        break;
//                    case 'B':
////                        utn_getUnsignedInt("\nIngrese nueva Numero_Cliente de horas trabajadas: ","\nError",1,sizeof(int),0,20,3,&auxHorasTrabajo);
////                        pLlamada_setHorasTrabajadas(pLlamada, auxHorasTrabajo);
//                        break;
//                    case 'C':
////                        utn_getUnsignedInt("\nIngrese nuevo salario de empleado: ","\nError",1,sizeof(int),0,20,3,&auxSueldo);           //mensaje + cambiar campo varInt
////                        pLlamada_setSueldo(pLlamada, auxSueldo);
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
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int controller_removeLlamada(LinkedList* pArrayListLlamada)
{
    int auxId;
    int ret = -1;
    int posicion;

    if(pArrayListLlamada != NULL)
    {
        controller_ListLlamada(pArrayListLlamada);
        utn_getUnsignedInt("\nID de llamada a remover: ","\nError",1,sizeof(int),1,20,3,&auxId);

        posicion = controller_findLlamadaById(pArrayListLlamada, auxId);
        if(posicion == -1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListLlamada, posicion);
            ret = 0;
        }
    }

    return ret;
}

/** \brief Listar llamadas
 *
 * \param path char*
 * \param pArrayListLlamada LinkedList*
 * \return int
 *><
 */
int controller_ListLlamada(LinkedList* pArrayListLlamada)
{
    int ret = -1;
    int i;
    Llamada* pLlamada;


    int auxId;
    char auxFechaLlamada[128];
    int auxNumero_Cliente;
    int auxID_Problema;
    char auxSolucionado[128];
    int len;

    if(pArrayListLlamada != NULL)
    {
        len = ll_len(pArrayListLlamada);

        for(i = 0; i <= len; i++)
        {
            pLlamada = ll_get(pArrayListLlamada, i);
            llamada_getId(pLlamada, &auxId);
            llamada_getfecha(pLlamada, auxFechaLlamada);
            llamada_getNumero_Cliente(pLlamada, &auxNumero_Cliente);
            llamada_getID_Problema(pLlamada, &auxID_Problema);
            llamada_getSolucionado(pLlamada,auxSolucionado);

            if(pLlamada != NULL)
            {
                printf("%d, %s, %d, %d, %s\n", auxId, auxFechaLlamada, auxNumero_Cliente, auxID_Problema, auxSolucionado);
                ret = 0;
            }
        }
    }

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int controller_sortLlamada(LinkedList* pArrayListLlamada)
{
    int ret = -1;
    int opcion;

    if(pArrayListLlamada != NULL)
    {
        utn_getUnsignedInt("Como desea ordenar? Elija una opcion : \n0 - Ordenar de forma ascendente (A - Z)\n1 - Ordenar de forma descendente (Z - A)\n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);


        while(opcion != 0 && opcion != 1)
        {
            utn_getUnsignedInt("Error, seleccione opcion 0 o 1 : \n","\nError", 1, sizeof(int), 1, 1, 3, &opcion); // order 0 - ascendente // order 1 - descendente
        }


        switch(opcion)
        {
            case 0:
                ll_sort(pArrayListLlamada, controller_comparisonString,0);
                break;
            case 1:
                ll_sort(pArrayListLlamada, controller_comparisonString,1);
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
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLlamada)
{
    int ret = -1;
    int i;
    int len;
    //auxiliares para getters
    int auxId;
    char auxFechaLlamada[128];
    int auxNumero_Cliente;
    int auxID_Problema;
    char auxSolucionado[128];

    Llamada* pLlamada; // creamos un puntero a empleado para guardar el resultado de ll_get


    FILE* fp = fopen(path, "w+");
    if(fp != NULL)
    {
        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListLlamada); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            pLlamada = ll_get(pArrayListLlamada, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", pLlamada->id, pLlamada->nombre, pLlamada->horasTrabajadas, pLlamada->sueldo);//cambiamos este fprintf por una funcion

            llamada_getId(pLlamada, &auxId);
            llamada_getfecha(pLlamada, auxFechaLlamada);
            llamada_getNumero_Cliente(pLlamada, &auxNumero_Cliente);
            llamada_getID_Problema(pLlamada, &auxID_Problema);
            llamada_getSolucionado(pLlamada,auxSolucionado);
            fprintf(fp, "%d,%s,%d,%d,%s\n", auxId, auxFechaLlamada, auxNumero_Cliente, auxID_Problema, auxSolucionado);

            ret = 0;
        }

        fclose(fp);
    }
    return ret;
}

void allForOne(char* path, LinkedList* listaLlamadas)
{
    Llamada* pLlamada;
    LinkedList* pListaLlamadas;
    int i;
    int len;
    int numProblem;
    int auxId;
    char auxFechaLlamada[128];
    int auxNumero_Cliente;
    int auxID_Problema;
    char auxSolucionado[128];

    FILE* fp = fopen(path, "w+");

    utn_getUnsignedInt("\nIngrese numero de problema: ","\nError ",1,sizeof(int),1,30,3,&numProblem);

    len = ll_len(listaLlamadas);

    switch(numProblem)
    {
        case 1:
            pListaLlamadas = ll_filter(listaLlamadas, controller_filter1);
        break;
        case 2:
            pListaLlamadas = ll_filter(listaLlamadas, controller_filter2);
        break;
        case 3:
            pListaLlamadas = ll_filter(listaLlamadas, controller_filter3);
        break;
        case 4:
            pListaLlamadas = ll_filter(listaLlamadas, controller_filter4);
        break;
        case 5:
            pListaLlamadas = ll_filter(listaLlamadas, controller_filter5);
        break;
    }
    for(i = 0;i < len;i++)
    {
        pLlamada = ll_get(pListaLlamadas, i);

        llamada_getId(pLlamada, &auxId);
        llamada_getfecha(pLlamada, auxFechaLlamada);
        llamada_getNumero_Cliente(pLlamada, &auxNumero_Cliente);
        llamada_getID_Problema(pLlamada, &auxID_Problema);
        llamada_getSolucionado(pLlamada,auxSolucionado);
        fprintf(fp, "%d,%s,%d,%d,%s\n", auxId, auxFechaLlamada, auxNumero_Cliente, auxID_Problema, auxSolucionado);

    }

    fclose(fp);
}

int controller_filter1(void* this)
{
    int ret = -1;

    Llamada* pLlamada;

    pLlamada = (Llamada*)this;

//    len = ll_len(pArrayListLlamada);

//    for(i = 0;i < len;i++)
//    {
        if(pLlamada->ID_Problema == 1)
        {
            ret = 1;
        }
//    }



    return ret;
}
int controller_filter2(void* this)
{
    int ret = -1;

    Llamada* pLlamada;

    pLlamada = (Llamada*)this;

    if(pLlamada->ID_Problema == 2)
    {
        ret = 1;
    }

    return ret;
}
int controller_filter3(void* this)
{
    int ret = -1;

    Llamada* pLlamada;

    pLlamada = (Llamada*)this;

    if(pLlamada->ID_Problema == 3)
    {
        ret = 1;
    }

    return ret;
}
int controller_filter4(void* this)
{
    int ret = -1;

    Llamada* pLlamada;

    pLlamada = (Llamada*)this;

    if(pLlamada->ID_Problema == 4)
    {
        ret = 1;
    }

    return ret;
}
int controller_filter5(void* this)
{
    int ret = -1;

    Llamada* pLlamada;

    pLlamada = (Llamada*)this;

    if(pLlamada->ID_Problema == 5)
    {
        ret = 1;
    }

    return ret;
}



int controller_saveAsText3(char* path , LinkedList* pArrayListLlamada, int tipoProblem)
{
    int ret = -1;
    int i;
    int len;
    //auxiliares para getters
    int auxId;
    char auxFechaLlamada[128];
    int auxNumero_Cliente;
    int auxID_Problema;
    char auxSolucionado[128];
//    int numProblem;

    Llamada* pLlamada; // creamos un puntero a empleado para guardar el resultado de ll_get


    FILE* fp = fopen(path, "w+");
    if(fp != NULL)
    {


        len = ll_len(pArrayListLlamada); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            pLlamada = ll_get(pArrayListLlamada, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", pLlamada->id, pLlamada->nombre, pLlamada->horasTrabajadas, pLlamada->sueldo);//cambiamos este fprintf por una funcion

            llamada_getId(pLlamada, &auxId);
            llamada_getfecha(pLlamada, auxFechaLlamada);
            llamada_getNumero_Cliente(pLlamada, &auxNumero_Cliente);
            llamada_getID_Problema(pLlamada, &auxID_Problema);
            llamada_getSolucionado(pLlamada,auxSolucionado);
            if(tipoProblem == auxID_Problema)
            {
                fprintf(fp, "%d,%s,%d,%d,%s\n", auxId, auxFechaLlamada, auxNumero_Cliente, auxID_Problema, auxSolucionado);
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
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListLlamada)
{
    int ret = -1;
    int i;
    //auxiliares para getters
//    int auxId;
//    char auxNombre[50];
//    int auxHorasTrabajo;
//    int auxSueldo;

    Llamada* pLlamada; // creamos un puntero a empleado para guardar el resultado de ll_get

    int len;
    FILE* fp = fopen(path, "w+b"); // en windows es w+b, en linux puede ir w+ o w+b, en linux es lo mismo
    if(fp != NULL)
    {
//        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListLlamada); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            pLlamada = ll_get(pArrayListLlamada, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", pLlamada->id, pLlamada->nombre, pLlamada->horasTrabajadas, pLlamada->sueldo);//cambiamos este fprintf por una funcion

//            pLlamada_getId(pLlamada, &auxId);
//            pLlamada_getNombre(pLlamada, auxNombre);
//            pLlamada_getHorasTrabajadas(pLlamada, &auxHorasTrabajo);
//            pLlamada_getSueldo(pLlamada, &auxSueldo);
//            fprintf(fp, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajo, auxSueldo);

            // parametros de FWRITE
            // primer parametro recibe el puntero al array de donde quiero obtener los datos a escribir
            // segundo parametro es el tamano del tipo de dato del array de donde voy a leer para escribir
            // Numero_Cliente de elementos a escribir, en este caso 1 porque voy a escribir un empleado (un globito con todos los elementos de empleado, nombre,id,sueldo,etc)
            // puntero a FILE
            fwrite(pLlamada,sizeof(Llamada), 1, fp);

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

int controller_findLlamadaById(LinkedList* pArrayListLlamada, int id)
{
    int ret = -1;
    int i;
    Llamada* pLlamada;
    int auxId;
    int len;

    if (pArrayListLlamada != NULL && id >= 0)
    {
        len = ll_len(pArrayListLlamada);

        for (i = 0;i < len;i++)
        {
            pLlamada = ll_get(pArrayListLlamada,i);
            llamada_getId(pLlamada,&auxId);
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
    int comparison = strcmp(((Llamada*)this)->fecha,((Llamada*)that)->fecha);
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






//int controller_Numero_ClienteDeFotosReveladas(void* this)
//{
//    int ret = 0;
//    Llamada* pLlamada;
//
//    if (this!=NULL)
//    {
//        pLlamada = (Llamada*)this;
//        if(pLlamada != NULL)
//        {
//            ret = pLlamada->Numero_Cliente;
//        }
//    }
//
//    return ret;
//}





//int controller_Numero_ClienteDeFotosPrecio300(void* this)
//{
//    Llamada* pLlamada;
//    int ret = 0;
//    int auxPrecio;
//
//    if (this!=NULL)
//    {
//        pLlamada = (Llamada*)this;
//        auxPrecio = pLlamada->ID_Problema*pLlamada->Numero_Cliente;
//        if(auxPrecio > 300)
//        {
//            ret = 1;
//        }
//
//    }
//
//    return ret;
//}

//int controller_Numero_ClienteDeFotosPrecio150(void* this)
//{
//    Llamada* pLlamada;
//    int ret = 0;
//    int auxPrecio;
//
//    if (this!=NULL)
//    {
//        pLlamada = (Llamada*)this;
//        auxPrecio = pLlamada->ID_Problema*pLlamada->Numero_Cliente;
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
//int controller_Numero_ClienteDeFotosPolaroid(void* this)
//{
//    int ret = 0;
//    Llamada* pLlamada;
//
//    if(this!=NULL)
//    {
//        pLlamada = (Llamada*)this;
//        if(strncmp(pLlamada->tipoFoto,"POLAROID_11x9",sizeof(pLlamada->tipoFoto))==0 || strncmp(pLlamada->tipoFoto,"POLAROID_10x10",sizeof(pLlamada->tipoFoto))==0)
//        {
//            ret = 1;
//        }
//    }
//
//    return ret;
//}

