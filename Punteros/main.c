#include <stdio.h>
#include <stdlib.h>


/** \brief pide un numero
 *
 * \param int* guardo numero
 * \return int desvuelve 1 si se pudo, 0 si no se pudo
 *
 */
int getInt(int*);
void mostrarVector(int*,int);
///funciones de: cargar vector, ordenar vector, buscar maximo, promedio y borrar un numero(si lo esncuentra o no). el vector no puede guardar 0

int main()
{
    /**

    int* pVector;

    int x[5]={1,2,3,4,5};

    pVector = x;

    ///printf("%d\n", pVector);///direcc de memoria
    ///printf("%d\n", *pVector);/// valor de vector
    ///printf("%d\n", *pVector+1);///le suma al primer valor del vector
    ///printf("%d\n", *(pVector+2));///muestra le segundo valor del vector

    mostrarVector(x,5);

    **/

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




