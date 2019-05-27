#include <stdio.h>
#include <stdlib.h>

FILE* miArchivo;
///1º se abre, 2º se utiliza, 3º se cierra

int main()
{
    //char nombre[20]="Martin";

    miArchivo = fopen("D://MisDatos.txt","W");
    /**
    - Permite abrir el archivo
    - Path = archivo que se recibe
    - W(texto),WB(binario) = modo en el que se abre el archivo
    **/

    fprintf(miArchivo,"Martin");
    /**
    - Hace lo mismo que el printf
    - Recibe el archivo
    - Devuelve texto que quiero escribir
    **/

    fclose(miArchivo);
    /**
    - Cierra el archivo
    **/

    char nombre[20];

    miArchivo = fopen("D:\MisDatos.txt","r");

    fgets(nombre,30,miArchivo);

    fclose(miArchivo);

    printf("%s",nombre);

    return 7;
}
