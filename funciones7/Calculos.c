#include <stdio.h>
#include <stdlib.h>

 void mayor(int a, int b)
{
    if(a==b)
    {
      printf("Son iguales\n\n");
    }else{
        if(a>b)
        {
          printf("El valor de a es mayor que el de b\n\n");
        }else{
              printf("El valor de b es mayor que el de a\n\n");
             }
        }
}

int suma(int a, int b)
{
  int total;

  total= a + b;
  printf(" El resultado de A+B es: %d\n",total);

  return total;
}

int resta(int a, int b)
{
    int total;

    total = a - b;
    printf(" El resultado de A-B es: %d\n",total);

    return total;
}

float division(int a, int b)
{
    int total;

    if(b==0)
    {
      printf(" No es posible dividir por cero\n");
    }else{
         total = a / b;
         printf(" La division es: %d\n", total);
         }

    return total;
}

int multiplicacion(int a,int b)
{
    int total;

    total = a * b;
    printf(" El resultado de A*B: %d\n", total);

    return total;
}

int factorial(int a)
{
    int total;

    if(a<0)
    {
      printf(" No es posible sacar fatorial de un numero negativo\n");
    }else if(a == 0 || a == 1)
          {
             total = 1;
             printf(" \n El factorial de A es: %d\n", total);
          }else{
                  total = a * factorial(a - 1);
                  printf(" El factorial de A es: %d\n", total);
               }

    return total;
}

void primo(int a)
{

    int i, primo=1;

    for(i=2; i<a; i++)
    {
       if(a%i==0)
       {
             primo=0;
             printf("%d NO es primo\n\n\n", a);
             return 0;
       }else{
             primo=1;
            }

     if(primo!=0)
     {
        printf("%d es primo\n\n\n", a);
     }
   }
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

