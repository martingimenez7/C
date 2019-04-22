#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[30];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
}eEmpleado;

typedef struct
{
    char sector[50];
    char descp[70];
}eSector;

void cargarEmpleado(eEmpleado[],eSector[], int);
void mostrarEmpleado(eEmpleado,eSector);
void mostrarListaEmpleados(eEmpleado[], eSector[], int);

int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[], eSector[], int);

int modificar(eEmpleado[], eSector[],int,int);
int buscarMayor(eEmpleado[],int)
int informar(eEmpleado[],eSector[], int);
int mayorSueldo(eEmpleado[],int);
//int borrar(eEmpleado[],int);
