#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "venta.h"
#include "utn.h"

int main()
{
    LinkedList* listaVentas = ll_newLinkedList();
    int cantVentas;
    int ventasMayor300;
    int ventasMayor150;
    int cantPolaroid;
    int option;
    char ArchivoText[128];
    char ArchivoBinary[128];

    FILE* pFile=fopen("resultados.csv","w+");
    fprintf(pFile,"********************\n");
    fprintf(pFile,"Informe de ventas\n");
    fprintf(pFile,"********************");
    controller_loadFromText("data.csv",listaVentas);//cargo archivo

//    lenLista=ll_len(listaVentas);//tamaño del archivo
//    fprintf(pFile,"\nCantidad de Total de ventas: %d",ll_len(listaVentas));
//    fprintf(pFile, "%d, %s, %s, %d, %d, %s\n", ll_add(), auxFechaVenta, auxTipoFoto, auxCantidad, auxPrecioUnitario, auxCuitCliente);

    cantVentas = ll_count(listaVentas, controller_cantidadDeFotosReveladas);
    fprintf(pFile,"\nCantidad total de ventas : %d\n", cantVentas);

    ventasMayor150 = ll_count(listaVentas, controller_cantidadDeFotosPrecio150);
    fprintf(pFile,"\nCantidad de fotos con precio mayor a 150 : %d\n",ventasMayor150);

    ventasMayor300 = ll_count(listaVentas, controller_cantidadDeFotosPrecio300);
    fprintf(pFile,"\nCantidad de fotos con precio mayor a 300 : %d\n",ventasMayor300);

    cantPolaroid = ll_count(listaVentas, controller_cantidadDeFotosPolaroid);
    fprintf(pFile,"\nCantidad de fotos polaroid : %d\n",cantPolaroid);

//    controller_ListVenta(listaVentas);//printeo datos del archivo
    fprintf(pFile,"********************");


    do{

        utn_getUnsignedInt("\n\n1) Cargar datos en modo texto\n2) Cargar datos en modo binario\n3) Alta empleado\n4) Modificar empleado\n5) Baja empleado\n6) Listar empleado\n7) Ordenar empleado\n8) Guardar datos en modo texto\n9) Guardar datos en modo binario\n10) Salir\n","\nError",1,sizeof(int),1,11,1,&option);

        switch(option)
        {
            case 1:
                utn_getTexto("\nIngrese nombre de archivo a abrir en modo texto:","\nError ",1,30,3,ArchivoText);
                controller_loadFromText(ArchivoText,listaVentas);
                break;

            case 2:
                utn_getTexto("\nIngrese nombre de archivo a abrir en modo binario:","\nError ",1,30,3,ArchivoBinary);
                controller_loadFromBinary(ArchivoBinary,listaVentas);
                break;

            case 3:
                controller_addVenta(listaVentas);
                break;

            case 4:
//                controller_editVenta(listaVentas);
                break;

            case 5:
                controller_removeVenta(listaVentas);
                break;

            case 6:
                controller_ListVenta(listaVentas);
                break;

            case 7:
                controller_sortVenta(listaVentas);
                break;

            case 8:
                utn_getTexto("\nIngrese nombre de archivo a guardar en modo texto: ","\nError ",1,30,3,ArchivoText);
                controller_saveAsText(ArchivoText,listaVentas);
                break;

            case 9:
                utn_getTexto("\nIngrese nombre de archivo a guardar en modo binario: ","\nError ",1,30,3,ArchivoBinary);
                controller_saveAsBinary(ArchivoBinary,listaVentas);
                break;

            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }while(option != 10);
    ll_deleteLinkedList(listaVentas);


    fclose(pFile);
    return 0;
}
