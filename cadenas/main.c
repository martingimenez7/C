#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char palabra[77] = "lala";
  char palabra1[77] = "hola";
  int comp;
  int len;

  printf(" ingrese nombre y apellido:\n\n ");
  //gets(palabra);
  //scanf("%s", palabra);
  //scanf("%[^\n]", palabra);
  //fgets(palabra,177,stdin);

  comp = strcmp(palabra,"lala");//compara
  //comp = stricmp(palabra,"Lala");// " y diferencia mayusculas
  printf(" %d\n\n", comp);

  strupr(palabra);
  printf(" %s\n\n",palabra);

  strcpy(palabra/*,"hola"*/,palabra1);//copia que se puede desbordar

  strncpy(palabra,palabra1,4);//copia segura

  len = strlen(palabra);//cuenta caracteres

  strcat(palabra1,palabra);
  printf(" %s\n\n", palabra1);

  printf("\n la palabra es %s\n cantidad de caracteres es %d\n",palabra,len);

  return 7;
}
