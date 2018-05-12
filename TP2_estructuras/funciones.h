#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 20



typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char descripcion[51];
    int isEmpty;
}eSector;

typedef struct{
    int dni;
    char nombre[41];
    char sexo;
    int edad;
    float sueldo;
    eFecha fechaIngreso;
    int isEmpty;
    int idSector;
}eEmpleado;

int menu();
int getInt(char[]);
float getFloat(char[]);
char getChar(char[]);
void inicializarEmpleados(eEmpleado[], int);
void mostrarEmpleado(eEmpleado);
int buscarLibre(eEmpleado[], int);
int buscarEmpleado(eEmpleado[], int, int);
void altaEmpleado(eEmpleado[], int);
void bajaEmpleado(eEmpleado[], int);
void modificaEmpleado(eEmpleado[], int);
int submenuMod();
void ordenarPorNombre(eEmpleado[], int, eSector[]);
void contarEdades(eEmpleado[], int);
unsigned int verifica(void);
int validarEntero(int, int, int);
#endif // FUNCIONES_H_INCLUDED
