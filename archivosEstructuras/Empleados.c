#include <stdio.h>
#include <stdlib.h>
#include "Empleados.h"

int get_legajo(eEmpleado* this)
{
    int legajo=0;

    if(this!=NULL)
    {
        legajo = this->legajo;
    }
    return legajo;
}

int set_legajo(eEmpleado* this, int legajo)
{
    int valido=0;

    if(this!=NULL && legajo>100)
    {
        this->legajo = legajo;
        valido = 1;
    }
    return valido;
}

void delete_Empleado(eEmpleado* miEmpleado)
{
    if(miEmpleado!=NULL)
    {
        free(miEmpleado);
        miEmpleado = NULL;
    }
}

int constructorFantasma(eEmpleado* unEmpleado)
{


    unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));


    return unEmpleado;
}
