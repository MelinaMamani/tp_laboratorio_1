#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 50

int main()
{
    char seguir='s';

    ePelicula* peliculas;
    peliculas = newArrayPeliculas(TAM);

    if(peliculas == NULL)
    {
        printf("No se pudo conseguir memoria en peliculas\n");
        exit(1);
    }

    int cantPeliculas=0;
    cargarPelicula(peliculas,TAM,&cantPeliculas);

    while(seguir=='s')
    {
        switch(menu())
        {
            case 1:
                altaPelicula(peliculas,TAM);
                break;
            case 2:
                bajaPelicula(peliculas,TAM);
                break;
            case 3:
                modificaPelicula(peliculas,TAM);
                break;
            case 4:
                generarPagina(peliculas,TAM,"misPeliculas.html");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
