#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i,j;

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

        for(j=0; j<ts; j++)
        {
            printf(" %d.%s\n",sectores[j].idSector,sectores[j].sector);
        }
        printf(" Elija sector: ");
        scanf("%d", &lista[i].idSector);

        printf("Ingrese cantidad de horas: ");
        scanf("%d", &lista[i].cantidadHoras);

        if(lista[i].idSector==sectores[j].idSector)
        {
           lista[i].valorHora = sectores[j].valor;
        }

        lista[i].sueldoBruto = lista[i].cantidadHoras;

        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }
}

void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }
    }
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int ts)
{
    char descripcionSector[20];
    int i;

    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector == sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].sector);
            break;
        }
    }

    printf("\n%d - %s - %s - %c - %f - %f - %s\n\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto,descripcionSector);
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
    int legajos[]={ 1 , 8 , 5 , 9 , 3 };
    char nombres[][50]={"Maria","Carlos","Jose","Camila","Marcelo"};
    char apell[][50]={"Lopez","Silva","Martinez","Poli","Araujo"};
    char sexo[]={'F','M','M','F','M'};
    float sueldosBruto[]={10000,30000,20000,40000,50000};
    int sector[]={1,2,3,1,2};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apell[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}

int modificar(eEmpleado lista[],int tam, eSector sectores[])
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
           opcion = menuDeOpciones("\n 1.Nombre\n 2.Apellido\n 3.Sector\n 4.Carga horaria\n Ingrese opcion a modificar: ");
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
                   printf("\n%d.%s\n",sectores[i].idSector,sectores[i].sector);
                   scanf("%d", &lista[i].idSector);

                   loEncontro = 1;
               break;
               case 4:
                   printf("\n Ingrese nueva carga horaria: ");
                   scanf("%d", &lista[i].cantidadHoras);

                   if(lista[i].idSector==sectores[i].idSector)
                   {
                     lista[i].valorHora = sectores[i].valor;
                   }

                   lista[i].sueldoBruto = lista[i].cantidadHoras;

                   loEncontro = 1;
               break;
               default:
                      printf("\n Opcion incorrecta \n");
                      system("cls");
               break;
           }
           system("cls");
           break;//modificar
       }
   }

   if(loEncontro==0)
   {
       system("cls");
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
            printf("\n Borrado completo\n");
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
