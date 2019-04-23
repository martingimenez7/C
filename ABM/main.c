
#include <stdlib.h>
#include "Empleado.h"

#define T 6

int menuDeOpciones(char[]);

int main()
{
    int opcion;

    eEmpleado lista[T];
    inicializarEmpleados(lista,T);

    eSector sectores[3] = {{1,"Contabilidad",100},{2,"Sistemas",200},{3, "RRHH", 150}};

hardcodearDatosEmpleados(lista,6);
    do
    {
        opcion = menuDeOpciones("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Informar\n10.Salir\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarEmpleado(lista, T, sectores, 3);

            break;
            case 2:
                borrarEmpleado(lista, T, 3);
                break;
            case 3:

                modificar(lista, T, 3);
            break;

            case 4:
                mostrarListaEmpleados(lista, T, sectores, 3);
                break;
            case 5:

                mostrarEmpleadosSueldoMaximo(lista,T);
                printf("La cantidad de carlos es: %d\n", contarCarlos(lista,T));

                break;

        }
    }while(opcion!=10);

    return 0;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
