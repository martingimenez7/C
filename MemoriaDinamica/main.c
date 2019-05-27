#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaMD.h"
#define T 5


int main()
{
    int* pNumero;

    pNumero = (int*) malloc(sizeof(int)*5);
    ///Multiplico por la cant. de elementos(5)

    cargar(pNumero,T);

    pNumero = (int*)realloc(pNumero,sizeof(int)*10);
    ///Reasigna espacio en memoria
    ///Devuelve NULL si no hay espacio


    //pNumero = (int*) malloc(sizeof(int));
    ///Devuelve un puntero de cualquier tipo. Si no encuentra espacio, devuelve NULL
    ///La direcc de memoria se muestra con sizeof()
    ///Busca espacio en memoria

    //*pNumero = 77;

    //pNumero = (int*) calloc(sizeof(int),1);
    ///Inicializa los elemnetos en 0
    ///Pide: tamaño que se quiere reservar y cantidad de elementos



    /*printf("\n pNumero HEAP: %d\n", pNumero);
    printf(" pNumero STACK: %d\n", &pNumero);

    if(pNumero!=NULL)
    {

        printf(" pNumero VALOR: %d\n", *pNumero);

        printf("\n Luego de hacer un free: \n");
        free(pNumero);

        printf("\n pNumero HEAP: %d\n", pNumero);
        printf(" pNumero STACK: %d\n", &pNumero);
        printf(" pNumero VALOR: %d\n", *pNumero);

    }*/


    return 7;
}
