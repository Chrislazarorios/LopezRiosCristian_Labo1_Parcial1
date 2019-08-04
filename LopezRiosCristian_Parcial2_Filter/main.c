#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "llamada.h"
#include "utn.h"

int main()
{
    LinkedList* listaLlamadas = ll_newLinkedList();

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
//    controller_loadFromText("DATA_final1.csv",listaLlamadas);//cargo archivo
//    controller_ListLlamada(listaLlamadas);//printeo datos del archivo
//    fclose(pFile);





    do{

        utn_getUnsignedInt("\n\n1) Cargar datos en modo texto\n2) Listar datos \n3) Filtrar problema\n4) Salir\n","\nError",1,sizeof(int),1,11,1,&option);

        switch(option)
        {
            case 1:
                utn_getTexto("\nIngrese nombre de archivo a abrir en modo texto:","\nError ",1,30,3,ArchivoText);
//                    controller_loadFromText("DATA_final1.csv",listaLlamadas);//cargo archivo
                controller_loadFromText(ArchivoText,listaLlamadas);
//                controller_loadFromText("data1.csv",listaLlamadas);
                break;

            case 2:
//                utn_getTexto("\nIngrese nombre de archivo a abrir en modo binario:","\nError ",1,30,3,ArchivoBinary);
//                controller_loadFromBinary(ArchivoBinary,listaLlamadas);
                controller_ListLlamada(listaLlamadas);
                break;

            case 3:

//                utn_getUnsignedInt("\nIngrese numero de problema a filtrar: ","\nError ",1,sizeof(int),1,30,3,&numProblem);
//                controller_saveAsText3("data2.csv" , listaLlamadas, numProblem);




//                ll_filter(listaLlamadas, controller_saveAsText2);
                allForOne("data3.csv", listaLlamadas);


//                controller_saveAsText(ArchivoText,listaLlamadas);

//                controller_addLlamada(listaLlamadas);
                break;

            case 4://salir
//                controller_editLlamada(listaLlamadas);
                break;



            default:
                printf("\nOpcion no valida");
        }
    }while(option != 4);
//    ll_deleteLinkedList(listaLlamadas);


//    fclose(pFile);
    return 0;
}
