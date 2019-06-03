#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleados.h"

int main()
{
    eEmpleado* miEmpleado;
    miEmpleado = constructorFantasma(miEmpleado);

    if(set_legajo(miEmpleado,1001))
    {
        strcpy(miEmpleado->nombre,"Pedro");
        miEmpleado->sueldo = 1000;

        printf("\n %d-%s-%f \n", get_legajo(miEmpleado),miEmpleado->nombre,miEmpleado->sueldo);
    }else
    {
        printf(" Legajo incorrecto");
    }

    return 7;
}


eEmpleado* new_Empleado(int legajo, char* nombre, float sueldo)
{
    eEmpleado* empleadoRetorno;

    empleadoRetorno = (eEmpleado*) malloc(sizeof (eEmpleado));

    if(empleadoRetorno!=NULL)
    {
        empleadoRetorno->legajo = legajo;
        strcpy(empleadoRetorno->nombre,nombre);
        empleadoRetorno->sueldo = sueldo;
    }
}
