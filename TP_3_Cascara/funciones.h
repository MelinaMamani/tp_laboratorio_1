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
/**
 *  Agrega una pelicula al archivo binario
 *  @param Pelicula la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(ePelicula Pelicula);

/**
 *  Borra una pelicula del archivo binario
 *  @param Pelicula la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(ePelicula Pelicula);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(ePelicula lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
