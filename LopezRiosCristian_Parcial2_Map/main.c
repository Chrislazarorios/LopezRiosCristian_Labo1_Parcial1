#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "envio.h"
#include "utn.h"

int main()
{
    LinkedList* listaenvios = ll_newLinkedList();

    int option;
    char ArchivoText[128];
//    char ArchivoBinary[128];
//    int numProblem;
////
//    FILE* pFile;
//    FILE* pFile = fopen("DATA_final1.csv","w+");
//    FILE* pFile2=fopen("test.csv","w+");
//    fprintf(pFile,"********************\n");
//    fprintf(pFile,"Informe de ventas\n");
//    fprintf(pFile,"********************");
//    printf("flag del main");
//    controller_loadFromText("data_final2.csv",listaenvios);//cargo archivo
//    controller_Listenvio(listaenvios);//printeo datos del archivo
//    fclose(pFile);





    do{

        utn_getUnsignedInt("\n\n1) Cargar datos en modo texto\n2) Listar datos \n3) Generar Archivo de costos\n4) Salir\n","\nError",1,sizeof(int),1,11,1,&option);

        switch(option)
        {
            case 1:
                utn_getTexto("\nIngrese nombre de archivo a abrir en modo texto:","\nError ",1,30,3,ArchivoText);
                controller_loadFromText(ArchivoText,listaenvios);
//                controller_loadFromText("data1.csv",listaenvios);
                break;

            case 2:
//                utn_getTexto("\nIngrese nombre de archivo a abrir en modo binario:","\nError ",1,30,3,ArchivoBinary);
//                controller_loadFromBinary(ArchivoBinary,listaenvios);
                controller_Listenvio(listaenvios);
                break;

            case 3:

                allForOne("data3.csv", listaenvios);

//                controller_saveAsText(ArchivoText,listaenvios);

//                controller_addenvio(listaenvios);
                break;

            case 4://salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }while(option != 4);
//    ll_deleteLinkedList(listaenvios);


//    fclose(pFile);
    return 0;
}
