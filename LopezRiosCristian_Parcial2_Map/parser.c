#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envio.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int parser_envioFromText(FILE* pFile , LinkedList* pArrayListenvio)
{

    char bufferId[4096];
    char buffernombre_producto[4096];
    char bufferkm_recorridos[4096];
    char buffertipo_entrega[4096];
    envio *penvio;



    if(pFile != NULL)
    {
        printf("llegue aca");
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                  buffernombre_producto,
                                                  bufferkm_recorridos,
                                                  buffertipo_entrega
                                                          );
                                                          printf("llegue aca tambieen");
        while(!feof(pFile))
        {

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                      buffernombre_producto,
                                                      bufferkm_recorridos,
                                                      buffertipo_entrega
                                                          );

            penvio = envio_newParametros(   bufferId,
                                            buffernombre_producto,
                                            bufferkm_recorridos,
                                            buffertipo_entrega
                                                );



            if(penvio != NULL)
            {
                if(ll_add(pArrayListenvio,penvio))
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
 * \param pArrayListenvio LinkedList*
 * \return int
 *
 */
int parser_envioFromBinary(FILE* pFile , LinkedList* pArrayListenvio)
{
        int ret = -1;

    envio* pEmpl;

    if(pFile != NULL && pArrayListenvio != NULL)
    {
        do{
            //generar espacio en memoria
            pEmpl = envio_new();

            // guardarlo en el archivo
            if(fread(pEmpl, sizeof(envio), 1, pFile) == 1)
            {
                // agregarlo a la linkedlist
//                ll_add(pArrayListenvio, pEmpl);
            }
            else
            {
                envio_delete(pEmpl);
            }

        }while(!feof(pFile));
    }


    return ret;
}
