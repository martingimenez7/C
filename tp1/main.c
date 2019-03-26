#include <stdio.h>
#include <stdlib.h>

int suma(int, int);
int resta(int, int);
float division(int, int);
int multiplicacion(int, int);
int factorial(int);

void main(void)
{
  int a,b,s,r,d,m,f;

  printf("ingrese numero : ");
  scanf("%d",&a);

  printf("ingrese otro numero : ");
  scanf("%d",&b);

  s = suma(a,b);
  printf("el resultado de a+b es %d",s);

  r = resta(a,b);
  printf("\nel resultado de a-b es %d",r);

  d = division(a,b);
  printf("\nel resultado de a/b %d", d);

  m = multiplicacion(a,b);
  printf("\nel resultado de a*b %d", m);

  f = factorial(a);
  printf("\nel factorial de a es %d", f);
}
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
