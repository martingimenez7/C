#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaA.h"

int main()
{
  int a,b,s,r,d,m,f,opcion;

  do{

       printf("1.calcular la suma \n2.calcular resta \n3.calcular division \n4.calcular multiplicacion \n5.calcular el factorial \n6.salir \nintroduzca una opcion: ");
       scanf("%d", & opcion);

     switch(opcion)
     {
       case 1:
            printf("\ningrese numero(A) : ");
            scanf("%d",&a);
            printf("ingrese otro numero(B) : ");
            scanf("%d",&b);

            s = suma(a,b);
            printf("el resultado de A+B es %d\n",s);
       break;
       case 2:
            printf("\ningrese numero(A) : ");
            scanf("%d",&a);
            printf("ingrese otro numero(B) : ");
            scanf("%d",&b);

            r = resta(a,b);
            printf("\nel resultado de A-B es %d\n",r);
       break;
       case 3:
            printf("\ningrese numero(A) : ");
            scanf("%d",&a);
            printf("ingrese otro numero(B) : ");
            scanf("%d",&b);

            d = division(a,b);
            printf("\nel resultado de A/B %d\n", d);
       break;
       case 4:
            printf("\ningrese numero(A) : ");
            scanf("%d",&a);
            printf("ingrese otro numero(B) : ");
            scanf("%d",&b);

            m = multiplicacion(a,b);
            printf("\nel resultado de A*B %d?n", m);
       break;
       case 5:
            printf("\ningrese numero(A) : ");
            scanf("%d",&a);

            f = factorial(a);
            printf(" \nel factorial de A es %d\n", f);
       break;
       case 6:
            printf("saiendo del menu...\n");
       break;

     }
   }while(opcion>=6);
    system("pause");
    system("cls");
  return 0;
}
