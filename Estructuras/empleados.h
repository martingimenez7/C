#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idSector;
    char sector[50];
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
    int cantidadHoras;
    int estado;
    float valorHora;
    int idSector;
    eSector seccion;
}eEmpleado;

void cargarEmpleado(eEmpleado[],int,eSector[],int);
void mostrarEmpleado(eEmpleado,eSector[], int );
void mostrarListaEmpleados(eEmpleado[],int,eSector[], int);

int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[],int);
int modificar(eEmpleado[],int,eSector[]);
int borrar(eEmpleado[],int);

float buscarSueldoMaximo(eEmpleado[],int);
void mostrarEmpleadosSueldoMaximo(eEmpleado[],int);
int contarCarlos(eEmpleado[],int);
