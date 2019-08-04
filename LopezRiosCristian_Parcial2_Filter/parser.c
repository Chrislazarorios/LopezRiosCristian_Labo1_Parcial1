#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "llamada.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int parser_LlamadaFromText(FILE* pFile , LinkedList* pArrayListLlamada)
{

    char bufferId[4096];
    char bufferFechaLlamada[4096];
    char bufferNumero_Cliente[4096];
    char bufferID_Problema[4096];
    char bufferSolucionado[4096];
    Llamada *pLlamada;



    if(pFile != NULL)
    {
        printf("llegue aca");
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                          bufferFechaLlamada,
                                                          bufferNumero_Cliente,
                                                          bufferID_Problema,
                                                          bufferSolucionado);
                                                          printf("llegue aca tambieen");
        while(!feof(pFile))
        {

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                          bufferFechaLlamada,
                                                          bufferNumero_Cliente,
                                                          bufferID_Problema,
                                                          bufferSolucionado);

            pLlamada = llamada_newParametros(   bufferId,
                                                bufferFechaLlamada,
                                                bufferNumero_Cliente,
                                                bufferID_Problema,
                                                bufferSolucionado);



            if(pLlamada != NULL)
            {
                if(ll_add(pArrayListLlamada,pLlamada))
                {

                    printf("hice el addd");
                }
            }

        }
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLlamada LinkedList*
 * \return int
 *
 */
int parser_LlamadaFromBinary(FILE* pFile , LinkedList* pArrayListLlamada)
{
        int ret = -1;

    Llamada* pEmpl;

    if(pFile != NULL && pArrayListLlamada != NULL)
    {
        do{
            //generar espacio en memoria
            pEmpl = llamada_new();

            // guardarlo en el archivo
            if(fread(pEmpl, sizeof(Llamada), 1, pFile) == 1)
            {
                // agregarlo a la linkedlist
//                ll_add(pArrayListLlamada, pEmpl);
            }
            else
            {
                llamada_delete(pEmpl);
            }

        }while(!feof(pFile));
    }


    return ret;
}
