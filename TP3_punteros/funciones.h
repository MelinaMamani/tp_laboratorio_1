#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[50];
    char genero[30];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[300];
    int estado;
}ePelicula;


int menu();
ePelicula* newArrayPeliculas(int);
void inicializarPeliculas(ePelicula*, int);
int buscarLibre(ePelicula*, int);
void mostrarPelicula(ePelicula*);
void mostrarPeliculas(ePelicula*, int);
void altaPelicula(ePelicula*, int);
void bajaPelicula(ePelicula*, int);
void modificaPelicula(ePelicula*, int);
int buscarPelicula(ePelicula*, int, char*);
void guardarPeliculas(ePelicula*, int, char*);
void cargarPelicula(ePelicula*,int,int*);
void generarPagina(ePelicula*,int,char*);

int getInt(char*);
//int validarEntero(int*, int, int);
unsigned int verifica(void);


#endif // FUNCIONES_H_INCLUDED
