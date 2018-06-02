#include <stdio.h>
#include "funciones.h"

int menu(){

    int opcion;
    printf("\nMenu:\n");
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

ePelicula* newArrayPeliculas(int tam){

    ePelicula* array;

    if(tam > 0)
    {
        array = (ePelicula*) malloc(tam * sizeof(ePelicula));

        if(array != NULL)
        {
            inicializarPeliculas(array, tam);
        }
    }
    return array;
}

void inicializarPeliculas(ePelicula* peliculas, int tam){

    if(peliculas != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            (peliculas+i)->estado = 0;
        }
    }
}

int buscarLibre(ePelicula* peliculas, int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if((peliculas+i)->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void guardarPeliculas(ePelicula* peliculas, int tam, char* path)
{

    FILE* f;

    f = fopen(path, "wb");

    if(f != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if( (peliculas + i)->estado)
            {
                fwrite( (peliculas+i), sizeof(ePelicula), 1, f);
            }
        }
        fclose(f);
    }
}

void cargarPelicula(ePelicula* peliculas,int tamanio,int* contador)
{
    int i;
    FILE* pelicula;
    pelicula=fopen("peliculas.bin","rb");
    if(pelicula!=NULL)
    {
        fread(contador,sizeof(int),1,pelicula);
        for(i=0;i<*(contador);i++)
        {
           fread((peliculas+i),sizeof(ePelicula),1,pelicula);
        }
        printf("Archivos cargados con exito!!\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("\nNo pudo cargarse el archivo\n");
        system("pause");
        system("cls");
    }
}

/*int cargarPeliculas(ePelicula* peliculas, int tam, char* path)
{

    FILE* f;
    int indice;
    ePelicula peliculaAuxiliar;
    int cant;
    int total = 0;

    f = fopen(path, "rb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
    }

    while(!feof(f))
    {
        indice = buscarLibre(peliculas, tam);
        if(indice == -1)
        {
            printf("No hay mas lugar\n");
            break;
        }
        else
        {
            cant = fread(&peliculaAuxiliar, sizeof(ePelicula), 1, f);

            if(cant != 1)
            {
                if(feof(f))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro\n");
                    break;
                }
            }

            *(peliculas+indice) = peliculaAuxiliar;
            total++;
        }
    }
    fclose(f);
    return total;
}
*/
void mostrarPelicula(ePelicula* pelicula)
{
    if(pelicula != NULL)
    {
        printf("%s \t%s \t%d \t%s \t%d \t%s \n", pelicula->titulo, pelicula->genero, pelicula->duracion, pelicula->descripcion, pelicula->puntaje, pelicula->linkImagen);
    }
}

void mostrarPeliculas(ePelicula* peliculas, int tam)
{

    printf("\n\tTitulo\tGenero\tDuracion\tDescripcion\tPuntaje\tImagen");

    if(peliculas != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {

            if((peliculas+ i)->estado==1)
            {
                mostrarPelicula(peliculas+i);
            }
        }
    }
    else
    {
        printf("\nNo se pueden mostrar los Peliculas\n");
    }

}

//ALTA, BAJA, MODIFICACION

int buscarPelicula(ePelicula* peliculas,int tam,char* nombre){
    int indice=-1;
    int i;
    for(i=0; i<tam; i++){
        if((peliculas+i)->estado == 1 && strcmp((peliculas+i)->titulo, nombre)==0){
            indice=i;
            break;
        }
    }
    return indice;
}

void altaPelicula(ePelicula* peliculas,int tam){
    ePelicula* nuevaPelicula;
    int indice;
    int esta;
    char nombre[50];
    char confirma;

    system("cls");
    printf("Alta de Pelicula\n\n");

    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(nombre);

    while(strlen(nombre)>49){
        printf("Reingrese genero: ");
        fflush(stdin);
        gets(nombre);
    }

    nuevaPelicula = (ePelicula*)malloc(sizeof(ePelicula));


    if(nuevaPelicula !=NULL){

    indice = buscarLibre(peliculas, tam);

    if(indice == -1){
        printf("\nEl sistema esta completo. No se puede dar de alta a peliculas nuevas.\n\n");
    }
    else

        esta = buscarPelicula(peliculas, tam, nombre);

        if(esta != -1)
        {
            printf("\nLa pelicula %s ya esta dada de alta en el sistema.\n", nombre);
            system("pause");

        }
        else{
                   nuevaPelicula->estado = 1;
                   strcpy(nuevaPelicula->titulo, nombre);

                   printf("Ingrese genero: ");
                   fflush(stdin);
                   gets(nuevaPelicula->genero);

                   while(strlen(nuevaPelicula->genero)>29){
                           printf("Reingrese genero: ");
                           fflush(stdin);
                           gets(nuevaPelicula->genero);
                   }

                   nuevaPelicula->duracion = getInt("Ingrese la duracion: ");
                   while(nuevaPelicula->duracion>500){
                        nuevaPelicula->duracion = getInt("Reingrese la duracion: ");
                    }

                   printf("Ingrese descripcion: ");
                   fflush(stdin);
                   gets(nuevaPelicula->descripcion);

                   while(strlen(nuevaPelicula->descripcion)>299){
                           printf("Reingrese descripcion: ");
                           fflush(stdin);
                           gets(nuevaPelicula->descripcion);
                   }

                    nuevaPelicula->puntaje = getInt("Ingrese el puntaje: ");

                   while((nuevaPelicula->puntaje)<0 && (nuevaPelicula->puntaje)>100){
                        nuevaPelicula->puntaje = getInt("Reingrese puntaje: ");
                   }

                   printf("Ingrese link de imagen: ");
                   fflush(stdin);
                   gets(nuevaPelicula->linkImagen);

                   while(strlen(nuevaPelicula->linkImagen)>299){
                           printf("Reingrese link: ");
                           fflush(stdin);
                           gets(nuevaPelicula->linkImagen);
                   }

                   *(peliculas+indice) = *nuevaPelicula;

                   do{
                        printf("\nConfirma el alta de Pelicula? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = tolower(confirma);
                    }while(confirma != 's' && confirma != 'n');

                    if(confirma == 's'){
                        system("cls");
                        printf("\nAlta realizada.\n\n");
                        guardarPeliculas(peliculas, tam, "peliculas.bin");
                    }
                    else{
                        system("cls");
                        printf("\nAlta no realizada.\n\n");
                    }
           }
   }
  else{
        printf("No hay espacio en memoria.\n");
    }
  }


void bajaPelicula(ePelicula* peliculas, int tam){

    char nombre[50];
    int esta;
    char confirma;

    system("cls");
    printf("Baja de la pelicula\n\n");

        printf("Ingrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(nombre);

        while(strlen(nombre)>49){
        printf("Reingrese genero: ");
        fflush(stdin);
        gets(nombre);
    }

        esta = buscarPelicula(peliculas, tam, nombre);

        if(esta == -1)
        {
            printf("\nLa pelicula %s no se encuentra en el sistema\n\n", nombre);
        }
        else{
            mostrarPelicula((peliculas+esta));

        do{
            printf("\nConfirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            (peliculas+esta)->estado=0;
            printf("\nBaja realizada.\n\n");
            guardarPeliculas(peliculas, tam, "peliculas.bin");
        }
        else{
            printf("\nBaja cancelada.\n\n");
        }

        }
}

void modificaPelicula(ePelicula* peliculas, int tam){
    char nombre[50];
    int esta;
    char confirma;
    ePelicula* modPelicula;

    system("cls");
    printf("Modificar Pelicula\n\n");

    mostrarPeliculas(peliculas,tam);

    printf("Ingrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(nombre);

    while(strlen(nombre)>49){
        printf("Reingrese genero: ");
        fflush(stdin);
        gets(nombre);
    }

    modPelicula = (ePelicula*)malloc(sizeof(ePelicula));

        esta = buscarPelicula(peliculas, tam, nombre);

        if(esta == -1)
        {
            printf("\nLa pelicula %s no se encuentra en el sistema\n\n", nombre);

        }
        else{

                mostrarPelicula(peliculas+esta);

              switch(submenuMod()){

                case 1:
                    printf("Ingrese nombre de la pelicula: ");
                   fflush(stdin);
                   gets(modPelicula->titulo);

                   while(strlen(modPelicula->titulo)>49){
                           printf("Reingrese nombre: ");
                           fflush(stdin);
                           gets(modPelicula->titulo);
                   }
                   strcpy((peliculas+esta)->titulo,modPelicula->titulo);
                    break;
                case 2:
                    printf("Ingrese genero: ");
                   fflush(stdin);
                   gets(modPelicula->genero);

                   while(strlen(modPelicula->genero)>29){
                           printf("Reingrese genero: ");
                           fflush(stdin);
                           gets(modPelicula->genero);
                   }
                   strcpy((peliculas+esta)->genero,modPelicula->genero);
                    break;
                case 3:
                    modPelicula->duracion = getInt("Ingrese la duracion: ");
                   while(modPelicula->duracion>500){
                        modPelicula->duracion = getInt("Reingrese la duracion: ");
                    }
                    (peliculas+esta)->duracion = modPelicula->duracion;
                    break;

                case 4:
                    printf("Ingrese descripcion: ");
                   fflush(stdin);
                   gets(modPelicula->descripcion);

                   while(strlen(modPelicula->descripcion)>299){
                           printf("Reingrese descripcion: ");
                           fflush(stdin);
                           gets(modPelicula->descripcion);
                   }
                   strcpy((peliculas+esta)->descripcion,modPelicula->descripcion);
                    break;
                case 5:
                    modPelicula->puntaje = getInt("Ingrese el puntaje: ");

                   while(modPelicula->puntaje<=0 || modPelicula->puntaje>101){
                        modPelicula->puntaje = getInt("Reingrese puntaje: ");
                   }
                   (peliculas+esta)->puntaje = modPelicula->puntaje;
                   break;
                case 6:
                    printf("Ingrese link de imagen: ");
                   fflush(stdin);
                   gets(modPelicula->linkImagen);

                   while(strlen(modPelicula->linkImagen)>299){
                           printf("Reingrese link: ");
                           fflush(stdin);
                           gets(modPelicula->linkImagen);
                   }
                   strcpy((peliculas+esta)->linkImagen,modPelicula->linkImagen);
                    break;
                default:
                    printf("\nOpcion no valida.\n");
                    system("pause");
                    system("cls");
                    break;
                }
        do{
            printf("\nConfirma modificacion? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            printf("\nModificacion realizada.\n\n");
            guardarPeliculas(peliculas, tam, "peliculas.bin");
        }
        else{
            printf("\nModificacion cancelada.\n\n");
        }

        }
}

int submenuMod(){
    int opcion;
    system("cls");
    printf("Menu modificar Pelicula: \n");
    printf("1) Titulo\n");
    printf("2) Genero\n");
    printf("3) Duracion\n");
    printf("4) Descripcion\n");
    printf("5) Puntaje\n");
    printf("6) Link de imagen\n");

    opcion = getInt("Seleccione una opcion: ");

    return opcion;
}

void guardarpeliculas(ePelicula* peliculas, int tam, char* path)
{

    FILE* f;

    f = fopen(path, "wb");

    if(f != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if( (peliculas + i)->estado)
            {
                fwrite( (peliculas+i), sizeof(ePelicula), 1, f);
            }
        }
        fclose(f);
    }
}

int cargarpeliculas(ePelicula* peliculas, int tam, char* path)
{

    FILE* f;
    int indice;
    ePelicula peliculaAuxiliar;
    int cant;
    int total = 0;

    f = fopen(path, "rb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }



    while(!feof(f))
    {
        indice = buscarLibre(peliculas, tam);
        if(indice == -1)
        {
            printf("No hay mas lugar\n");
            break;
        }
        else
        {
            cant = fread(&peliculaAuxiliar, sizeof(ePelicula), 1, f);

            if(cant != 1)
            {
                if(feof(f))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro\n");
                    break;
                }
            }

            *(peliculas+indice) = peliculaAuxiliar;
            total++;
        }
    }
    fclose(f);
    return total;
}

void generarPagina(ePelicula* peliculas, int tam, char* path)
{
    int i;
    int cantPeliculas=0;

    for(i=0; i<tam; i++)
    {
        if((peliculas+i)->estado==1)
        {
            cantPeliculas++;
            break;
        }
    }

    if(cantPeliculas!=0)
    {
        FILE* pagina;
        pagina=fopen(path,"w");
        if(pagina!=NULL)
        {
            fprintf(pagina,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>peliculas peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");

            for(i=0; i<tam; i++)
            {
                if((peliculas+i)->estado==1)
                {
                    fprintf(pagina,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %d</li><li>Duracion: %d</li></ul><p>%s</p></article>",(peliculas+i)->linkImagen,(peliculas+i)->titulo,(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion,(peliculas+i)->descripcion);
                }
            }
            fprintf(pagina,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
            printf("\nYa puedes ver la pagina web!\n");
        }
        fclose(pagina);
    }
    else
    {
        printf("\nNo hay ninguna pelicula ingresada.\n");
    }
}

int getInt(char mensaje[]){
    int aux;
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}
