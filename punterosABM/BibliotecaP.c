#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaP.h"

int mostrarTodoElVector(eDato* pVector, int tam)
{
    int i;
    int estado=1;

    if(pVector!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
           if(pVector[i].numero!=0)
           {
             mostrarVector(pVector+i);
             //printf("\n %d - %c\n", (*(pDato+i)).numero , (*(pDato+i)).letra);///parentesis doble para que sume direccion y despues acceda al dato
             //printf("\n %d - %c\n", (pVector+i)->numero, (pVector+i)->letra);///con flecha
           }
       }
       estado=0;
    }

    return estado;
}

void mostrarVector(eDato* pVector)
{
    //printf("\n %d - %c\n", (*(pDato+i)).numero , (*(pDato+i)).letra);///parentesis doble para que sume direccion y despues acceda al dato
    printf("\n %d - %c\n", pVector->numero, pVector->letra);
}

int ordenarVector(eDato* pVector,int tam)
{
    int i,j;
    int aux;
    int esNull = 1;

    if(pVector!=NULL && tam>0)
    {
        for(i=0;i<tam-1;i++)
        {
          for(j=i+1;j<tam;j++)
          {
            if(  (pVector+i)->letra > (pVector+j)->letra )//criterio
            {
             aux = *(pVector+i);
             *(pVector+i) = *(pVector+j);
             *(pVector+j) = aux;
            }//if
          }//for j
        }//for int i,j,aux;
        esNull=0;
    }

    return esNull;
}
