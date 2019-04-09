#include <stdio.h>
#include <stdlib.h>
#include <string.h>//libreria str'sd
#include <ctype.h>//libreria de toupper

void pedirCadena(char[], char[], int);
void validarTamCadena(char[], char[], int);

int main()
{
   char nombre[20];
   char apellido[20];
   char apellidoNombre[41];//="";
   int i=0;


   pedirCadena(" Nombre :", nombre, 20);
   pedirCadena(" Apellido :", apellido, 20);

   strcpy(apellidoNombre,apellido);

   strcat(apellidoNombre, ", ");
   strcat(apellidoNombre, nombre);

   strlwr(apellidoNombre);

   apellidoNombre[0] = toupper(apellidoNombre[0]);//mayuscula a 1 caracter

   while(apellidoNombre[i]!= '\0')
   {
       if(isspace(apellidoNombre[i])/*detecta espacio*/)
       {
           apellidoNombre[i+1] = toupper(apellidoNombre[i+1]);
       }

       i++;
   }

   puts(apellidoNombre);

   return 7;
}

void pedirCadena(char mensaje[],char cadena[], int tam)
{
    printf("Ingrese %s", mensaje);
    fflush(stdin);//lee cadena
    scanf("%[^\n]", cadena);

    validarTamCadena(mensaje, cadena, tam);
}

void validarTamCadena(char mensajeError[], char cadena[], int tam)
{
    while(strlen(cadena)>tam)
    {
        printf(" Reingrese %s", mensajeError);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }

}
