#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idSector;
    char sector[50];
    char descp[70];
    float valor;
}eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[30];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;

    int idSector;
    eSector seccion;
}eEmpleado;

void cargarEmpleado(eEmpleado[],int);
void mostrarEmpleado(eEmpleado);
void mostrarListaEmpleados(eEmpleado[],int);

int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[],int);
int modificar(eEmpleado[],int);
int borrar(eEmpleado[],int);

float buscarSueldoMaximo(eEmpleado[],int);
void mostrarEmpleadosSueldoMaximo(eEmpleado[],int);
int contarCarlos(eEmpleado[],int);
