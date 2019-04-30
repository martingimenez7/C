#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "empleados.h"

#define T 5

int menuDeOpciones(char[]);

int main()
{
    int opcion;
    eEmpleado lista[T];
    inicializarEmpleados(lista,T);
    hardcodearDatosEmpleados(lista, 5);
    eSector sectores[3] = {{1,"Contabilidad",100},{2,"Sistemas",200},{3, "RRHH", 150}};

    do
    {
        opcion = menuDeOpciones("\n 1.Alta\n 2.Baja\n 3.Modificar\n 4.Mostrar\n 5.Informar\n 6.Salir\n Elija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarEmpleado(lista, T, sectores, 3);
                system("cls");
            break;
            case 2:
                borrar(lista,T);
            break;
            case 3:
                modificar(lista,T,sectores);
            break;
            case 4:
                system("cls");
                mostrarListaEmpleados(lista, T, sectores, 3);
            break;
            case 5:
                system("cls");
                //mostrarEmpleadosSueldoMaximo(lista,T);
                //printf("\n La cantidad de carlos es: %d\n", contarCarlos(lista,T));
                printf(" Empleados por sector:\n");
                mostrarEmpleadosPorSector(sectores,3,lista,T);
                printf(" Sector con mas empleados: \n");
                mostrarSectorConMasEmpleados(sectores,3,lista,T);

            break;
            case 6:
                system("cls");
                printf("\n Saliendo...\n ");
            break;
            default:
                system("cls");
                printf("\n Opcion incorrecta\n");
            break;
        }
    }while(opcion!=6);

    return 7;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
