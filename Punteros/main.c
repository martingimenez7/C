#include <stdio.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1
#define T 5

/** \brief pide un numero
 *
 * \param int* guardo numero
 * \return int desvuelve 1 si se pudo, 0 si no se pudo
 *
 */
int getInt(int*);
void mostrarVector(int*,int);
void cargarVector(int*,int);
void ordenarVector(int*,int);
int numeroMax(int*,int);
void promedioVector(int*,int);
int borrarValor(int*,int);
///funciones de: cargar vector, ordenar vector, buscar maximo, promedio y borrar un numero(si lo esncuentra o no). el vector no puede guardar 0

int main()
{

    int* pVector;

    int x[5];//={1,2,3,4,5};

    pVector = x;

    ///printf("%d\n", pVector);///direcc de memoria
    ///printf("%d\n", *pVector);/// valor de vector
    ///printf("%d\n", *pVector+1);///le suma al primer valor del vector
    ///printf("%d\n", *(pVector+2));///muestra le segundo valor del vector

    cargarVector(x,T);

    ordenarVector(x,T);
    mostrarVector(x,T);

    numeroMax(x,T);
    printf(" El numero maximo es: %d \n", *x);

    promedioVector(x,T);
    borrarValor(x,T);
    mostrarVector(x,T);

    {
    ///-----------------------------

    /**

    int numero;
    int respuesta;

    respuesta = getInt(&numero);

    if(respuesta==0)
    {
        printf("\n No se pudo cargar el numero \n");
    }else
      {
        printf(" El numero es: %d \n", numero);

      }
    **/

     ///-----------------------------

     /**

     int p;
     int* q;
     int* r;

     p = 10;
     q = &p;///q es = a la direccion de memoria de p
     r = q;

    printf(" %p\n", q);///valor de puntero q
    printf(" %p\n", r);///valor de puntero r
    printf(" %d\n", *q);///valor dentro del puntero q
    printf(" %d\n", *r);///valor dentro del puntero r

    **/

    ///-----------------------------

    /**

    int* x = NULL;
    int v = 10;

    x = &v;

    printf("\n Valor de v: %d\n", v);///Muestra valor

    printf(" Direccion de memoria de v: %p\n", &v);///Muestro direccion de memoria

    printf(" Direccion de memoria de x: %p\n", &x);

    printf(" Valor del puntero x: %p\n", x);

    printf(" Valor dentro del puntero x: %d\n\n", *x);

    **/

    ///-----------------------------

    /**

    char letra;
    char* pLetra;/// "p" de puntero

    pLetra = &letra;

    printf(" Ingrese caracter: ");
    fflush(stdin);
    scanf("%c", pLetra);

    printf(" Valor: %d\n", letra);

    **/
    }

    return 7;
}

int getInt(int* pValor)
{


    int estado=0;

    if(pValor!=NULL)
    {
        printf("\n Ingrese numero: ");
        scanf("%d", pValor);
        estado = 1;
    }

    return estado;
}

void mostrarVector(int* pVector, int tam)
{
    int i;

    for(i=0; i<5; i++)
    {
      printf("%d\n", *(pVector+i));
    }
}

void cargarVector(int* pVector, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("ingrese un numero: ");
        scanf ("%d", &pVector[i]);
    }
}

void ordenarVector(int* pVector,int tam)
{
    int i,j,aux;

    for(i=0;i<tam-1;i++)
    {
      for(j=i+1;j<tam;j++)
      {
        if(pVector[i]>pVector[j])//criterio
        {
          aux = pVector[i];
          pVector[i] = pVector[j];
          pVector[j] = aux;
        }//if
      }//for j
    }//for i

}

int numeroMax(int* pVector,int tam)
{
    int i;
    int maximo;
    int flag=0;


   for(i=0; i<tam; i++)
    {
        if(flag==0 || pVector[i]>maximo)
        {
            maximo = pVector[i];
            flag = 1;
        }
    }

    return maximo;
}

int borrarValor(int* pVector, int tam)
{
    int i;
    int loEncontro=0;
    int numero;

    printf("\n Ingrese numero a borrar: ");
    scanf("%d", &numero);

    for(i=0; i<tam; i++)
    {
        if(numero == pVector[i])
        {
            printf("\n Borrado completo\n");
            pVector[i] = LIBRE;
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

void promedioVector(int* pVector, int tam)
{
   int i;
   float auxiliarPromedio;
   float auxiliarSueldo=0;
   for(i=0; i<tam; i++)
   {
      if(pVector[i] == LIBRE)
        {
            break;
        }
         auxiliarSueldo = auxiliarSueldo + pVector[i];
   }

   auxiliarPromedio = auxiliarSueldo / tam;
   printf(" El promedio es: %f\n",auxiliarPromedio);
}
