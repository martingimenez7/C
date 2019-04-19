#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarEmpleado(eEmpleado lista[],eSector sect[], int tam)
{
    int i;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf(" \n Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);

        printf(" Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);

        printf(" Ingrese apellido: ");
        fflush(stdin);
        gets(lista[i].apellido);

        printf(" Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);

        printf(" Ingrese sueldo bruto: ");
        scanf("%f", &lista[i].sueldoBruto);

        lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;

        printf(" Ingrese sector: ");
        fflush(stdin);
        gets(sect[i].sector);

        printf(" Descripcion del sector: ");
        fflush(stdin);
        gets(sect[i].descp);

        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }
}

void mostrarListaEmpleados(eEmpleado lista[],eSector list[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i],list[i]);
        }
    }
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sect)
{
    printf("\n%d - %s - %s - %c - %f - %f - %s - %s\n\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto,sect.sector,sect.descp);
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatosEmpleados(eEmpleado lista[], eSector list[], int tam)
{
    int i;
    int legajos[]={ 1 , 8 , 5 };
    char nombres[][50]={" Maria "," Martin "," Jose "};
    char apell[][50]={" Lopez "," Silva "," Martinez "};
    char sexo[]={'F','M','M'};
    float sueldosBruto[]={1000,2000,3000};
    char sect[][70]={" Recursos humanos "," Limpieza "," Gerente "};
    char descripcion[][100]={" Entrevistar a empledos "," Mantener la higiene "," Dirigir empresa "};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apell[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        strcpy(list[i].sector, sect[i]);
        strcpy(list[i].descp, descripcion[i]);
    }
}

int modificar(eEmpleado lista[], eSector list[], int tam, int legajo)
{
   int i;
   int loEncontro=0;
   int opcion;

   printf(" Ingrese legajo: ");
   scanf("%d", &legajo);

   for(i=0; i<tam; i++)
   {
       if(legajo == lista[i].legajo)
       {
           opcion = menuDeOpciones(" 1.Nombre\n 2.Apellido\n 3.Sector\n 4.Sueldo\n Ingrese opcion a modificar: ");
           switch(opcion)
           {
               case 1:
                   printf(" Ingrese nuevo nombre: ");
                   fflush(stdin);
                   gets(lista[i].nombre);

                   loEncontro = 1;
               break;
               case 2:
                   printf(" Ingrese nuevo apellido: ");
                   fflush(stdin);
                   gets(lista[i].apellido);

                   loEncontro = 1;
               break;
               case 3:
                   printf(" Ingrese nuevo sector: ");
                   fflush(stdin);
                   gets(list[i].sector);
                   printf(" Descripcion del sector: ");
                   fflush(stdin);
                   gets(list[i].descp);

                   loEncontro = 1;
               break;
               case 4:
                   printf(" Ingrese nuevo sueldo: ");
                   scanf("%f", &lista[i].sueldoBruto);
                   lista[i].sueldoNeto = lista[i].sueldoBruto*0.85;

                   loEncontro = 1;
               break;
               default:
                      printf(" Opcion incorrecta");
               break;
           }
           break;//modificar
       }
   }

   if(loEncontro==0)
   {
       printf(" El dato no existe");
   }

   return loEncontro;
}

/*int borrar(eEmpleado lista[], int tam)
{
    int i;
    int loEncontro=0;
    int legajo;
    char respuesta[5];

    printf(" Ingrese legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo == lista[i].legajo)
        {
              printf(" Desea eliminar el legajo?(si-no): ");
              fflush(stdin);
              gets(respuesta);

         switch(respuesta)
         {
             case 'si':
                   printf(" Borrado completado");

                 loEncontro=1;
             break;
             case 'no':
                 printf(" Saliendo");

                 loEncontro=1;
             break;
         }
        }
    }

    if(loEncontro==0)
   {
       printf(" El dato no existe");
   }

   return loEncontro;
}*/
