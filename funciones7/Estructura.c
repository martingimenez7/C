

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[30];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int cantidadHoras;
    float valorHora;
    int estado;
    int id;
    eStructName seccion;

}eStructName;

strcmp///compara
stricmp///compara + diferencia mayasculas
strcpy///copia
strlen///lee array
strcat///concatena palabras
strupr///pasa palabra a mayuscula
strlwr///pasa palabra a minuscula
toupper///pasa caracter a minuscula

void mayor(int,int);
int suma(int,int);
int resta(int,int);
float division(int,int);
int multiplicacion(int,int);
int factorial(int);
void primo(int);
int valor(int[],int,int);
int numeroMax(int[],int);

void cargar(eStructName[],int,eStructName[],int);
void mostrarEmpleados(eStructName[],int,eStructName[],int);
void mostrar(eStructName,eStructName[],int);
int buscarLibre(eStructName[],int);
void inicializar(eStructName[],int);
void hardcodearDatos(eStructName[],int);
int modificar(eStructName[],int,eStructName[]);
int borrar(eStructName[],int);
float buscarMaximo(eStructName[],int);
void mostrarX (eStructName[],int);
int contarX(eStructName[],int);
int menuDeOpciones(char[]);
void ordenar(eStructName[],int);
void validar(char[],char[],int);
char getChar(char[]);
void getString(char[],char[]);
int getStringLetras(char[],char[]);
int getStringNumeros(char[],char[]);
int esSoloLetras(char[]);
int esNumerico(char[]);
