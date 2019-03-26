#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaIngreso.h"

int main()
{
   int edad;
   int legajo;
   int peso;

   edad = pedirEntero("ingrese edad: ");
   legajo = pedirEntero("ingrese legajo: ");
   peso = pedirEntero("ingrese su peso: ");

   return 0;
}
