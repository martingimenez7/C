#include <stdio.h>
#include <stdlib.h>

//diseña nuevo tipo de dato
typedef struct //define tipo de dato
{
   int legajo;
   char nombre[20];
   char sexo;
   float sueldoBruto;
   float sueldoNeto;
}eEmpleado;

int main()
{
    eEmpleado unEmpleado;

    puts(unEmpleado.nombre);//con el punto despues de la variable se accede a cualquier variable

    printf(" Ingrese legajo: ");
    scanf("%d", & unEmpleado.legajo);
    printf(" Ingrese nombre: ");
    fflush(stdin);
    gets(unEmpleado.nombre);
    printf(" Ingrese sexo: ");
    scanf("%c", &unEmpleado.sexo);
    printf(" Ingrese sueldo bruto: ");
    scanf("%f", &unEmpleado.sueldoBruto);
    unEmpleado.sueldoNeto = unEmpleado.sueldoBruto*0.85;

    printf("%d-%s-%c-%f-$f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);


   return 7;
}
