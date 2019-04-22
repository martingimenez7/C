#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "empleados.h"

#define T 10

int menuDeOpciones(char[]);

int main()
{
    int opcion;

    eEmpleado lista[T];
    eSector list[T];
    inicializarEmpleados(lista,T);
    hardcodearDatosEmpleados(lista, list, 4);

    do
    {
        opcion = menuDeOpciones("\n 1.Alta\n 2.Baja\n 3.Modificar\n 4.Mostrar\n 5.Informar\n 6.Salir\n Elija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarEmpleado(lista, list,  T);
            break;
           /* case 2:
                borrar(lista,T);
            break;*/
            case 3:
                modificar(lista, list, T,1);
            break;
            case 4:
                mostrarListaEmpleados(lista, list,  T);
            break;
            case 5:
                informar(lista,list, T);
            break;
            case 6:
                printf("\n Saliendo...\nm ");
            break;
            default:
                printf("\n Opcion incorrecta\n");
            break;
        }
    }while(opcion!=6);

    return 0;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
