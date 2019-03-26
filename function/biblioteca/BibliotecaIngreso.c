#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaIngreso.h"

int pedirEntero(char texto[])
{
    int unEntero;

    printf("%s", texto);
    scanf("%d", &unEntero);

    return unEntero;
}
