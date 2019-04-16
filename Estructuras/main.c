#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 2
#define OCUPADO 1
#define LIBRE 0

//diseña nuevo tipo de dato
typedef struct //define tipo de dato
{
   int legajo;
   char nombre[20];
   char sexo;
   float sueldoBruto;
   float sueldoNeto;
}eEmpleado;

void ingresarEmpleado(eEmpleado[],int);
void mostrarEmpleado(eEmpleado[],int);
void mostarTodosLosEmpleados(eEmpleado);

void inicializarEmpleado(eEmpleado[],int,int);
int buscarLibre(eEmpleado[],int);

int buscarUno(eEmpleado,int,int);//indice o -1
int borrarUno(eEmpleado,int,int);

int main()
{
    eEmpleado unEmpleado;
    eEmpleado lista[T];
   // int indice;

    ingresarEmpleado(lista,T);
   // inicializarEmpleado(lista,T);
    //mostrarEmpleado(unEmpleado);
    //indice = buscarLibre(lista,T);
    //lista[indice] = unEmpleado;

    mostarTodosLosEmpleados(unEmpleado);

   // puts(unEmpleado.nombre);//con el punto despues de la variable se accede a cualquier variable

   return 7;
}

void ingresarEmpleado(eEmpleado lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
      printf(" Ingrese legajo: ");
      scanf("%d", &lista[i].legajo);
      printf(" Ingrese nombre: ");
      fflush(stdin);
      gets(lista[i].nombre);
      printf(" Ingrese sexo: ");
      scanf("%c", &lista[i].sexo);
      printf(" Ingrese sueldo bruto: ");
      scanf("%f", &lista[i].sueldoBruto);
      lista[i].sueldoNeto = lista[i].sueldoBruto*0.85;
    }
}

void mostrarEmpleado(eEmpleado unEmpleado[], int tam)
{
   if(tam==0)
   {
     unEmpleado[tam];
   }
}

void mostarTodosLosEmpleados(eEmpleado unEmpleado)
{

   printf(" Legajo: %d\n Nombre: %d\n Sexo: %c\n Sueldo B: %f\n Sueldo : %f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
}

void inicializarEmpleado(eEmpleado lista[], int tam, int valor)
{
  int i;
  for(i=0; i<tam; i++)
  {
    lista[i].legajo = valor;
  }
}

