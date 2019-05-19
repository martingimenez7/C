#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void pedirVector(int numeros[], int T)
{
    int i;

    for(i=0; i<T; i++)
    {
        printf("ingrese un numero: ");
        scanf ("%d", & numeros[i]);
    }
}

void mostrarVector(int numeros[], int T)
{
    int i;

    for(i=0; i<T; i++)
    {
        printf(" %d\n",  numeros[i]);

    }
}

int numeroMax(int numeros[],int tam)
{
    int i;
    int maximo;
    int flag=0;


    for(i=0; i<tam; i++)
    {

        if(flag==0 || numeros[i]>maximo){

            maximo = numeros[i];
            flag=1;
        }
    }

    return maximo;
}

int valor(int numeros[],int tam,int indice)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(numeros[i]==indice){
            indice=i;
            break;
        }
    }

    return indice;
}

void ordenarVector(int numeros[],int tam)
{
    int i,j,aux;

    for(i=0;i<tam-1;i++)
    {
      for(j=i+1;j<tam;j++)
      {
        printf("para i = %d, con j = %d\n", numeros[i],numeros[j]);
        if(numeros[i]>numeros[j])//criterio
        {
          aux = numeros[i];
          numeros[i] = numeros[j];
          numeros[j] = aux;
        }//if
      }//for j
    }//for i

}
