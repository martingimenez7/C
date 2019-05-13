#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Biblioteca.h"

void cargar(ePeliculas lista[], int tam, eGenero tira[], int tg)
{
    int i,j;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        lista[i].id = numeroAleatorio(1000,2000,LIBRE);

        getStringLetras("\n Ingrese titulo: ", lista[i].titulo);

        getStringLetras("\n Ingrese nombre de actor: ", lista[i].actor.nombre);

        printf(" Ingrese fecha de estreno \n");
        printf(" Dia: ");
        scanf("%d", & lista[i].fechaEstreno.dia);
        printf(" Mes: ");
        scanf("%d",& lista[i].fechaEstreno.mes);
        printf(" a%co: ", 164);
        scanf("%d", &lista[i].fechaEstreno.anio);

        for(j=0; j<tg; j++)
        {
            printf(" %d.%s\n",tira[j].id,tira[j].descripcion);
        }
        printf(" Elija genero: ");
        scanf("%d", &lista[i].id);

        lista[i].estado = OCUPADO;
    }
    else
    {
        printf("No hay espacio");
    }
}

int buscarLibre(ePeliculas lista[], int tam)
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

void inicializar(ePeliculas lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

char numeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int modificar(ePeliculas lista[],int tam)
{
   int i;
   int loEncontro=0;
   int opcion;
   int id;

   printf("\n Ingrese id: ");
   scanf("%d", &id);

   for(i=0; i<tam; i++)
   {
       if(id == lista[i].id)
       {
           opcion = menuDeOpciones("\n 1.Titulo\n 2.Actor\n 3.Fecha de estreno\n Ingrese opcion a modificar: ");
           switch(opcion)
           {
               case 1:
                   getStringLetras("\n Ingrese nuevo titulo: ", lista[i].titulo);

                   loEncontro = 1;
               break;
               case 2:
                  getStringLetras("\n Ingrese nuevo actor: ", lista[i].actor.nombre);

                   loEncontro = 1;
               break;
               case 3:
                   printf(" Ingrese fecha de estreno \n");
                   printf(" Dia: ");
                   scanf("%d", & lista[i].fechaEstreno.dia);
                   printf(" Mes: ");
                   scanf("%d",& lista[i].fechaEstreno.mes);
                   printf(" a%co: ", 164);
                   scanf("%d", &lista[i].fechaEstreno.anio);

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

int borrar(ePeliculas lista[], int tam)
{
    int i;
    int loEncontro=0;
    int id;

    printf("\n Ingrese id: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id)
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

void hardcodearDatos(ePeliculas lista[],int tam)
{
    int i;
    int id []={ 1000 ,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020 };
    char titulo[][50]={"Avengers EndGame","Thor","Cellular","Men in black 4","IronMan","13 going on 30","Lucy","Nace una estrella","Dime cuantos?","Guardianes de la galaxia","A perfect murder","La isla","Que paso ayer","Home alone 3","Deadpool","Sherlock Holmes","Men in black 3","Avengers infinity war","Grandes esperanzas","SWAT","XxX"};
    int dia[]={ 20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11 };
    int mes []= { 4,6,5,7,9,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5 };
    int anio [] ={ 2019,2013,2004,2019,1012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992 };
    int idActor[]={ 2,5,4,5,2,31,9,4,9,7,1,9,1,10,2,10,10,7,6,6 };
    int genero []={ 1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1 };

    for(i=0; i<tam; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].titulo, titulo[i]);
        lista[i].fechaEstreno.dia = dia[i];
        lista[i].fechaEstreno.mes = mes[i];
        lista[i].fechaEstreno.anio = anio[i];
        lista[i].idActor = idActor[i];
        lista[i].idGenero = genero[i];
        lista[i].estado = OCUPADO;
    }
}

void mostrarLista(ePeliculas lista[], int tam, eGenero tira[], int tg, eActores actores[], int ta)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            ordenar(lista,tam);
            mostrar(lista[i],tira,tg,actores,ta);
        }
    }
}

void mostrar(ePeliculas lista, eGenero tira[], int ts, eActores actores[], int ta)
{
    char descripcionGenero[20];
    char descripcionActor[20];
    char descripcionPais[20];
    int i,j;

    for(i=0; i<ts; i++)
    {
        if(lista.idGenero == tira[i].id)
        {
            strcpy(descripcionGenero, tira[i].descripcion);
            break;
        }

    }
    for(j=0; j<ta; j++)
    {
        if(lista.idActor == actores[j].id)
        {
            strcpy(descripcionActor, actores[j].nombre);
            strcpy(descripcionPais, actores[j].pais);
            break;
        }
    }

    printf("\n%d - %s - %s - %s - %d - %s\n\n", lista.id,lista.titulo,descripcionActor,descripcionPais,lista.fechaEstreno.anio,descripcionGenero);
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}

void ordenar(ePeliculas lista[],int tam)
{
   int i,j;
   ePeliculas auxiliar;

    for(i=0; i < tam - 1; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            continue;
        }
        for(j=i+1; j < tam; j++)
        {
            if(lista[j].estado == LIBRE)
            {
                continue;
            }
            if(strcmp(lista[i].actor.pais ,lista[j].actor.pais ) > 0)
            {
                auxiliar = lista[j];
                lista[j] = lista[i];
                lista[i] = auxiliar;
            }
        }
    }
}









