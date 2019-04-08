#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#define T 5

int main()
{
    int valores[10]={1,4,2,3,5,6,8,7,9,10};
    int numeros[T];
    int maximo;
    int indice;

    pedirVector(numeros , T);

    //mostrarVector(numeros, T);

    maximo = numeroMax(numeros, T);
    printf("el numero max es: %d", maximo);

    printf("\ningrese el numero a buscar: ");
    scanf("%d", &indice);

    indice = valor(numeros, T, indice);
    if(indice>=0){
       printf("el indice del valor es: %d", indice);
    }else{
       printf("el valor ingresado no se encontro %d", indice);
    }

    ordenarVector(valores,10);
    mostrarVector(valores, 10);

    return 0;
}
