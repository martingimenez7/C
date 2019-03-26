#include <stdio.h>
#include <stdlib.h>

int ingreseNota(int nota);
int aprobados(int cantDeAprobados, int nota);

int main()
{

    return 0;
}

int ingreseNota(int nota)
{
    int contador=0;

   do{

     printf("ingrese nota: ");
     scanf("%d", & nota);
     contador++;
   }while(contador<5);

    return nota;
}

int aprobados(int cantDeAprobados, int nota)
{
    int nota;
    int cantDeAprobados=0;

    nota = ingreseNota(int nota);

    if(nota>6){
        cantDeAprobados = cantDeAprobados+1;
    }

    return cantDeAprobados;
}


