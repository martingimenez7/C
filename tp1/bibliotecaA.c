#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaA.h"

int suma(int a, int b)
{
  int total;

  total= a + b;

  return total;
}

int resta(int a, int b)
{
    int total;

    total = a - b;

    return total;
}

float division(int a, int b)
{
    int total;

    total = a / b;

    return total;
}

int multiplicacion(int a,int b)
{
    int total;

    total = a * b;

    return total;
}

int factorial(int a)
{
    int total;

    if(a == 0 || a == 1){
        total = 1;
    }else{
           total = a * factorial(a - 1);
         }

    return total;
}

