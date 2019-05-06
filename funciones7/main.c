#include <stdio.h>
#include <stdlib.h>
#define T 5

/// asiganr nombre a las variables X , StructName y tira

void cargar(eStructName lista[], int tam, eStructName tira[], int tx)
{
    int i,j;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        lista[i].id = numeroAleatorio(+1,+999,isEmpty);

        getStringLetras("\n Ingrese name: \n", lista[i].name);

        getStringLetras(" Ingrese lastName: \n", lista[i].lastName);

        printf(" Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);

        for(j=0; j<tx; j++)
        {
            printf(" %d.%s\n",tira[j].id,tira[j].sector);
        }
        printf(" Elija sector: ");
        scanf("%d", &lista[i].id);

        printf("Ingrese cantidad de horas: ");
        scanf("%d", &lista[i].cantidadHoras);

        if(lista[i].id==tira[j].id)
        {
           lista[i].valorHora = tira[j].valor;
        }

        lista[i].sueldoBruto = lista[i].cantidadHoras;

        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }
}

void mostrarListaEmpleados(eStructName lista[], int tam, eStructName tira[], int tx)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i], tira, tx);
        }
    }
}

void mostrar(eStructName lista, eStructName tira[], int ts)
{
    char descripcionSector[20];
    int i;

    for(i=0; i<ts; i++)
    {
        if(lista.id == tira[i].id)
        {
            strcpy(descripcionSector, tira[i].sector);
            break;
        }
    }

    printf("\n%d - %s - %s - %c - %f - %f - %s\n\n", lista.legajo,lista.nombre, lista.apellido, lista.sexo, lista.sueldoBruto,lista.sueldoNeto,descripcionSector);
}

int buscarLibre(eStructName lista[], int tam)
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

void inicializar(eStructName lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatos(eStructName lista[],int tam)
{
    int i;
    int legajos[]={ 1 , 8 , 5 , 9 , 3 };
    char nombres[][50]={"Maria","Carlos","Jose","Camila","Marcelo"};
    char apell[][50]={"Lopez","Silva","Martinez","Poli","Araujo"};
    char sexo[]={'F','M','M','F','M'};
    float sueldosBruto[]={10000,30000,20000,40000,50000};
    int idX[]={1,2,3,1,2};
    char productos[][50]={"Manzana","Carne","Galletitas","Jabon","Agua"};


    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apell[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].id = idX[i];
    }
}

int modificar(eStructName lista[],int tam, eStructName tira[])
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
                   printf("\n%d.%s\n",tira[i].id ,tira[i].sector);
                   scanf("%d", &lista[i].id);

                   loEncontro = 1;
               break;
               case 4:
                   printf("\n Ingrese nueva carga horaria: ");
                   scanf("%d", &lista[i].cantidadHoras);

                   if(lista[i].id == tira[i].id)
                   {
                     lista[i].valorHora = tira[i].valor;
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

int borrar(eStructName lista[], int tam)
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

float buscarMaximo(eStructName lista[], int tam)
{
    float maximo;
    int flag = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(flag==0 || lista[i].X>maximo)
            {
                maximo = lista[i].X;
                flag = 1;
            }
        }

    }
    return maximo;
}

void mostrarX (eStructName lista[], int tam)
{
    float maximo;
    int i;

    maximo = buscarMaximo(lista, tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO && maximo == lista[i].X)
        {
            mostrarEmpleado(lista[i]);
        }
    }

}

int contarX(eStructName lista[], int tam)
{
    int contadorX = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(stricmp(lista[i].X,"X")==0 && lista[i].X > X)
            {
                contadorX++;
            }
        }
    }

    return contadorX;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}

do
    {
        opcion = menuDeOpciones("\n 1.Alta\n 2.Baja\n 3.Modificar\n 4.Mostrar\n 5.Informar\n 6.Salir\n Elija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargar(lista, T, X, 3);
                system("cls");
            break;
            case 2:
                borrar(lista, T);
            break;
            case 3:
                modificar(lista, T, X);
            break;
            case 4:
                system("cls");
                mostrar(lista, T, X, 3);
            break;
            case 5:
                system("cls");
                printf("\n La cantidad de X es: %d\n", contarX(lista,T));
            break;
            case 6:
                system("cls");
                printf("\n Saliendo...\n ");
            break;
            default:
                system("cls");
                printf("\n Opcion incorrecta\n");
            break;
        }
    }while(opcion!=);

void ordenar(eStructName lista[],int tam)
{
   int i,j;
   eStructName auxiliar;

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
            if(strcmp(lista[i].X,lista[j].X) > 0)
            {
                auxiliar = lista[j];
                lista[j] = lista[i];
                lista[i] = auxiliar;
            }
        }
    }
}

 while(apellidoNombre[i]!= '\0')
   {
       if(isspace(apellidoNombre[i])/*detecta espacio*/)
       {
           apellidoNombre[i+1] = toupper(apellidoNombre[i+1]);
       }

       i++;
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

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
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

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
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

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}



