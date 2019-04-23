#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarEmpleado(eEmpleado lista[], int tam)
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
        gets(lista[i].seccion.sector);

        printf(" Descripcion del sector: ");
        fflush(stdin);
        gets(lista[i].seccion.descp);

        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }
}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i]);
        }
    }
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n%d - %s - %s - %c - %f - %f - %s - %s\n\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto,unEmpleado.seccion.sector,unEmpleado.seccion.descp);
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

void hardcodearDatosEmpleados(eEmpleado lista[],int tam)
{
    int i;
    int legajos[]={ 1 , 8 , 5 };
    char nombres[][50]={"Maria","Carlos","Jose"};
    char apell[][50]={"Lopez","Silva","Martinez"};
    char sexo[]={'F','M','M'};
    float sueldosBruto[]={1000,30000,2000};
    char sect[][70]={"Recursos humanos","Limpieza","Gerente"};
    char descripcion[][100]={"Entrevistar a empledos"," Mantener la higiene","Dirigir empresa"};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apell[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        strcpy(lista[i].seccion.sector, sect[i]);
        strcpy(lista[i].seccion.descp, descripcion[i]);
    }
}

int modificar(eEmpleado lista[],int tam)
{
   int i;
   int loEncontro=0;
   int opcion;
   int legajo;

   printf("\n Ingrese legajo: ");
   scanf("%d", &legajo);

   for(i=0; i<tam; i++)
   {
       if(legajo == lista[i].legajo)
       {
           opcion = menuDeOpciones("\n 1.Nombre\n 2.Apellido\n 3.Sector\n 4.Sueldo\n Ingrese opcion a modificar: ");
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
                   gets(lista[i].seccion.sector);
                   printf(" Descripcion del sector: ");
                   fflush(stdin);
                   gets(lista[i].seccion.descp);

                   loEncontro = 1;
               break;
               case 4:
                   printf(" Ingrese nuevo sueldo: ");
                   scanf("%f", &lista[i].sueldoBruto);
                   lista[i].sueldoNeto = lista[i].sueldoBruto*0.85;

                   loEncontro = 1;
               break;
               default:
                      printf("\n Opcion incorrecta \n");
                      system("cls");
               break;
           }
           break;//modificar
       }
   }

   if(loEncontro==0)
   {
       printf("\n El dato no existe\n");
   }

   return loEncontro;
}

int borrar(eEmpleado lista[], int tam)
{
    int i;
    int loEncontro=0;
    int legajo;

    printf("\n Ingrese legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo == lista[i].legajo)
        {
            system("cls");
            printf(" Borrado completo");
            lista[i].estado = LIBRE;
            loEncontro = 1;
            break;
        }
    }

    if(loEncontro==0)
   {
       printf("\n El dato no existe\n");
   }

   return loEncontro;
}

float buscarSueldoMaximo(eEmpleado lista[], int tam)
{
    float maximo;
    int flag = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(flag==0 || lista[i].sueldoBruto>maximo)
            {
                maximo = lista[i].sueldoBruto;
                flag = 1;
            }
        }

    }



    return maximo;

}

void mostrarEmpleadosSueldoMaximo(eEmpleado lista[], int tam)
{
    float maximo;
    int i;

    maximo = buscarSueldoMaximo(lista, tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO && maximo == lista[i].sueldoBruto)
        {
            //mostrarEmpleado(lista[i]);

        }
    }

}

int contarCarlos(eEmpleado lista[], int tam)
{
    int contadorCarlos = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(stricmp(lista[i].nombre,"carlos")==0 && lista[i].sueldoBruto>20000)
            {
                contadorCarlos++;
            }
        }
    }

    return contadorCarlos;
}
