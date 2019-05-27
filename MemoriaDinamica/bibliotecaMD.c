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
       aux = (int*) realloc(pNumero,sizeof(int)*(tam+5));

       if(aux!=NULL)
       {
           pNumero = aux;

            for(i=0;i<tam+5;i++)
             {
                printf("\n Ingrese un numero: ");
                scanf("%d",pNumero[i]);
            }
            for(i=0;i<tam+5;i++)
            {
                printf("\n %d", *(pNumero+i));
            }

            pNumero = (int*) realloc(pNumero,sizeof(int)*4);///Achicamos

            for(i=0;i<tam+5;i++)
            {
                printf("\n %d", *(pNumero+i));
            }
       }else
       {
           printf(" No hay espacio suficiente");
       }

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

