#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaMD.h"

void cargar(int* pNumero,int tam)
{
    int i;
    int* aux;

    pNumero = (int*) malloc(sizeof(int)*5);
    ///Multiplico por la cant. de elementos(5)

    if(pNumero!=NULL)///Pregunto si esta guardado en memoria
    {
       for(i=0;i<tam;i++)///Cargo valores
       {
           printf(" Ingrese un numero: ");
           scanf("%d",pNumero+i);
       }
       mostrar(pNumero,tam);
       aux = (int*)realloc(pNumero,sizeof(int)*10);
    ///Reasigna espacio en memoria
    ///Devuelve NULL si no hay espacio
    }
}

void mostrar(int* pNumero, int tam)
{
    int i;

    for(i=0;i<tam;i++)///Muestro valores
       {
           printf(" %d\n", *(pNumero+i));
       }
}

