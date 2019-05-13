
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char nombre[60];
    char pais[20];
}eActores;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char descripcion[50];

}eGenero;

typedef struct
{
    int id;
    char titulo[30];
    int estado;
    int idActor;
    int idGenero;
    eGenero genero;
    eActores actor;
    eFecha fechaEstreno;
}ePeliculas;

void cargar(ePeliculas[],int,eGenero[],int);
int buscarLibre(ePeliculas[],int);
void inicializar(ePeliculas[],int);
char numeroAleatorio(int,int,int);
void getString(char [],char[]);
int getStringLetras(char mensaje[],char[]);
int esSoloLetras(char[]);
int modificar(ePeliculas[],int);
int borrar(ePeliculas[],int);
void hardcodearDatos(ePeliculas[],int);
void mostrarLista(ePeliculas[],int,eGenero[],int,eActores[],int);
void mostrar(ePeliculas,eGenero[],int,eActores[],int);
int menuDeOpciones(char[]);
void ordenar(ePeliculas[],int);


