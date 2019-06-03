
typedef struct
{
    int legajo;
    char nombre[50];
    float sueldo;
}eEmpleado;

int set_legajo(eEmpleado*,int);
int get_legajo(eEmpleado*);
void delete_Empleado(eEmpleado*);
int constructorFantasma(eEmpleado*);
