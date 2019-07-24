#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{

    char bufferId[4096];
    char bufferFechaVenta[4096];
    char bufferTipoFoto[4096];
    char bufferCantidad[4096];
    char bufferPrecioUnitario[4096];
    char bufferCuitCliente[4096];
    Venta *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                  bufferFechaVenta,
                                                  bufferTipoFoto,
                                                  bufferCantidad,
                                                  bufferPrecioUnitario,
                                                  bufferCuitCliente);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                                  bufferFechaVenta,
                                                                  bufferTipoFoto,
                                                                  bufferCantidad,
                                                                  bufferPrecioUnitario,
                                                                  bufferCuitCliente);

            pEmpleado = venta_newParametros( bufferId,
                                                bufferFechaVenta,
                                                bufferTipoFoto,
                                                bufferCantidad,
                                                bufferPrecioUnitario,
                                                bufferCuitCliente);



            if(pEmpleado != NULL)
            {
                if(ll_add(pArrayListVenta,pEmpleado))
                {


                }
            }

        }
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromBinary(FILE* pFile , LinkedList* pArrayListVenta)
{
        int ret = -1;

    Venta* pEmpl;

    if(pFile != NULL && pArrayListVenta != NULL)
    {
        do{
            //generar espacio en memoria
            pEmpl = venta_new();

            // guardarlo en el archivo
            if(fread(pEmpl, sizeof(Venta), 1, pFile) == 1)
            {
                // agregarlo a la linkedlist
//                ll_add(pArrayListVenta, pEmpl);
            }
            else
            {
                venta_delete(pEmpl);
            }

        }while(!feof(pFile));
    }


    return ret;
}
