#include <stdio.h>
#include <stdlib.h>

int main()
{
   char nombre[77];
   char apellido[77];

   printf(" ingrese nombre :\n\n ");
   gets(nombre);
   printf(" ingrese apellido : \n\n ");
   gets(apellido);

   strcat(nombre,apellido);
   strupr(nombre);
   printf(" %s\n\n",nombre);

   return 7;
}
