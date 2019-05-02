#include <string.h>
#include "Empleado.h"


void cargarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    int j;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);

        printf("Elija sector: ");
        for(j=0; j<ts; j++)
        {
            printf("\n%d.%s\n",sectores[j].idSector,sectores[j].descripcion);
        }
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
        if(unEmpleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }

    printf("%4d %10s %c %4f %4f   %s\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto,descripcionSector);






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

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]= {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char sexo[]= {'M','F','M','M','M','M'};
    float sueldosBruto[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,2,3,1,2,2};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}

void modificar(eEmpleado lista[], int tam, int legajo)
{
    int i;
    int loEncontro = 0;
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo == lista[i].legajo)
        {
            printf("Ingrese un nuevo sueldo bruto: ");
            scanf("%f", &lista[i].sueldoBruto);

            lista[i].sueldoNeto = lista[i].sueldoBruto*0.85;


            loEncontro = 1;
            break;//modifcar
        }
    }

    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}

void borrarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int i;
    int loEncontro = 0;
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo == lista[i].legajo)
        {
            lista[i].estado = LIBRE;
            loEncontro = 1;
            break;//modifcar
        }
    }

    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
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

void mostrarEmpleadosPorSector(eSector sectores[], int ts, eEmpleado empleados[], int te)
{
   int i,j;

   for(i=0; i<ts; i++)
   {
       printf("%s: \n\n", sectores[i].descripcion);
       for(j=0; j<te; j++)
       {
           if(sectores[i].idSector==empleados[j].idSector)
           {
               mostrarEmpleado(empleados[j],sectores,ts);
           }
       }
   }

}

void mostrarSectorConMasEmpleados(eSector sectores[], int ts, eEmpleado empleados[], int te)
{
    eAuxiliar auxiliar[3];
    int i,j;
    int maximo=0;
    int flag=0;

    for(i=0; i<ts; i++)
    {
        auxiliar[i].idSector = sectores[i].idSector;
        strcpy(auxiliar[i].descripcion, sectores[i].descripcion);
        auxiliar[i].contadorEmpleados = 0;
    }

    for(i=0; i<ts; i++)
    {
       for(j=0; j<te; j++)
       {
           if(auxiliar[i].idSector==empleados[j].idSector)
           {
               auxiliar[i].contadorEmpleados++;
           }
       }
    }

    for(i=0; i<ts; i++)
    {
       if(flag=0 || auxiliar[i].contadorEmpleados>maximo)
       {
           maximo = auxiliar[i].contadorEmpleados;
           flag = 1;
       }
    }

    for(i=0; i<ts; i++)
    {
      if(auxiliar[i].contadorEmpleados == maximo)
      {
          printf("%s\n", auxiliar[i].descripcion);
      }
    }

   /*for(i=0;i<ts; i++)
   {
       printf("\n%d--%d\n\n",auxiliar[i].idSector, auxiliar[i].contadorEmpleados);
   }*/
}

/*void promedioDeSueldos(eEmpleado lista[], int te)
{
    int i;
    float contadorSueldo;

    for(i=0; i<te; i++)
    {
      if(lista[i].estado==OCUPADO)
      {
          lista[i].sueldoBruto = contadorSueldo;
          break;
      }
    }

}*/
