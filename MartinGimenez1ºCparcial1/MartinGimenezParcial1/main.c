#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#define T 20

int main()
{
    int opcion;
    ePeliculas lista[T];
    inicializar(lista,T);
    hardcodearDatos(lista,T);
    eGenero generos[5] = { {1,"Accion"},{2,"Comedia"},{3,"Drama"},{4,"Romance"},{5,"Terror"} };
    eActores actores[10]= { {1,"Scarlett Johansson","Argentina"},{2,"Robert Downey Jr","EEUU"},{3,"Mark Ruffalo","Canada"},{4,"Chris Evans","EEUU"},{5,"Chris Hemsworth","Argentina"},{6,"Samuel Jackson","EEUU"},{7,"Gwyneth Paltrow","Canada"},{8,"Paul Rudd","Argentina"},{9,"Bradley Cooper","EEUU"},{10,"Josh Brolin","Canada"} };

    do
    {
        opcion = menuDeOpciones("\n 1.Alta\n 2.Modificar\n 3.Baja\n 4.Listar\n 5.Salir\n Elija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargar(lista,T,generos,5);
                system("cls");
            break;
            case 2:
                modificar(lista,T);
            break;
            case 3:
                borrar(lista,T);
            break;
            case 4:
                system("cls");
                mostrarActoresPorPais(actores,10);
            break;
            case 5:
                system("cls");
                printf("\n Saliendo...\n ");
            break;
            default:
                system("cls");
                printf("\n Opcion incorrecta\n");
            break;
        }
    }while(opcion!=5);

    return 7;
}

