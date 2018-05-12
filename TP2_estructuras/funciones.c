#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu(){

    int opcion;
    printf("1) Alta\n");
    printf("2) Baja\n");
    printf("3) Modificar\n");
    printf("4) Ordenar por nombres\n");
    printf("5) Mostrar grafico de edades\n");
    printf("6) Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void hardCode(eSector sectores[]){
    eSector nuevoSector;

    nuevoSector.id = 1;
    strcpy(nuevoSector.descripcion, "RRHH");
    nuevoSector.isEmpty = 0;
    sectores[0] = nuevoSector;


    nuevoSector.id = 2;
    strcpy(nuevoSector.descripcion, "Sistemas");
    nuevoSector.isEmpty = 0;
    sectores[1] = nuevoSector;

    sectores[2].id = 3;
    strcpy(sectores[2].descripcion, "Administracion");
    sectores[2].isEmpty = 0;

    sectores[3].id = 4;
    strcpy(sectores[3].descripcion, "Compras");
    sectores[3].isEmpty = 0;

    sectores[4].id = 5;
    strcpy(sectores[4].descripcion, "Deposito");
    sectores[4].isEmpty = 0;
}

void inicializarEmpleados(eEmpleado vec[],int tam){
    int i;
    for(i=0;i<tam;i++){
        vec[i].isEmpty=1;
    }
}

int buscarLibre(eEmpleado vec[] ,int tam){
    int indice=-1;
    int i;
    for(i=0;i<tam;i++){
        if(vec[i].isEmpty==1){
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[]){
    int i, j;
    printf("\nDNI   \tNombre\tEdad\tSexo\tSueldo  \tF. de Ingr.\tSector\n");
    for(i=0; i< tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            for(j=0; j<5; j++){
                if(vec[i].idSector==sec[j].id){
                    printf("%4d  \t%s \t%d \t%c \t$%8.2f \t%02d/%02d/%4d \t%s\n", vec[i].dni, vec[i].nombre, vec[i].edad, vec[i].sexo, vec[i].sueldo, vec[i].fechaIngreso.dia, vec[i].fechaIngreso.mes, vec[i].fechaIngreso.anio, sec[j].descripcion);
                }
            }
        }
    }
    printf("\n");
}

void mostrarEmpleado(eEmpleado emp){
    printf("%4d     %s      %d     %c     $%10.2f    %02d/%02d/%4d     Num. Sector: %d\n", emp.dni, emp.nombre, emp.edad, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, emp.idSector);
}

int buscarEmpleado(eEmpleado vec[],int tam,int dni){
    int indice=-1;
    int i;
    for(i=0;i<tam;i++){
        if(vec[i].isEmpty == 0 && vec[i].dni==dni){
            indice=i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[],int tam){
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int dni;
    char confirma;
    char aux[41];

    system("cls");
    printf("Alta de empleado\n\n");

    dni = getInt("Ingrese el dni: ");

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }
    else

        esta = buscarEmpleado(vec, tam, dni);

        if(esta != -1)
        {
            printf("\nEl dni %d ya esta dado de alta en el sistema.\n", dni);
                   mostrarEmpleado(vec[esta]);
        }
        else{
                   nuevoEmpleado.isEmpty = 0;
                   nuevoEmpleado.dni = dni;

                   printf("Ingrese nombre: ");
                   fflush(stdin);
                   gets(nuevoEmpleado.nombre);

                   nuevoEmpleado.edad = getInt("Ingrese su edad: ");

                   nuevoEmpleado.edad = validarEdad(nuevoEmpleado.edad, 0, 100);

                   nuevoEmpleado.sexo = getChar("Ingrese el sexo: ");

                   nuevoEmpleado.sueldo = getFloat("Ingrese el sueldo: ");

                   printf("Ingrese fecha de ingreso d / m / a\n");
                   nuevoEmpleado.fechaIngreso.dia = getInt("Dia: ");
                   nuevoEmpleado.fechaIngreso.mes = getInt("Mes: ");
                   nuevoEmpleado.fechaIngreso.anio = getInt("Anio: ");

                   printf("\n1) RRHH");
                   printf("\n2) Sistemas");
                   printf("\n3) Administracion");
                   printf("\n4) Compras");
                   printf("\n5) Deposito");
                   nuevoEmpleado.idSector = getInt("\nIngrese un sector: ");

                   vec[indice] = nuevoEmpleado;

                   do{
                        printf("\nConfirma el alta de empleado? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = tolower(confirma);
                    }while(confirma != 's' && confirma != 'n');

                    if(confirma == 's'){
                        system("cls");
                        printf("\nAlta realizada.\n\n");
                    }
                    else{
                        system("cls");
                        printf("\nAlta no realizada.\n\n");
                    }
           }
  }

void bajaEmpleado(eEmpleado vec[], int tam){
    int dni;
    int esta;
    char confirma;

    system("cls");
    printf("Baja del Empleado\n\n");

        dni = getInt("Ingrese el dni: ");

        esta = buscarEmpleado(vec, tam, dni);

        if(esta == -1)
        {
            printf("\nEl dni %d no se encuentra en el sistema\n\n", dni);

        }
        else{
            mostrarEmpleado(vec[esta]);

        do{
            printf("\nConfirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            vec[esta].isEmpty = 1;
            printf("\nBaja realizada.\n\n");
        }
        else{
            printf("\nBaja cancelada.\n\n");
        }

        }
}

void modificaEmpleado(eEmpleado vec[], int tam){
    int dni;
    int esta;
    char confirma;
    eEmpleado modEmpleado;

    system("cls");
    printf("Modificar Empleado\n\n");

        dni = getInt("Ingrese el dni: ");

        esta = buscarEmpleado(vec, tam, dni);

        if(esta == -1)
        {
            printf("\nEl dni %d no se encuentra en el sistema\n\n", dni);

        }
        else{

                mostrarEmpleado(vec[esta]);

              switch(submenuMod()){

                case 1:
                    modEmpleado.dni = getInt("Ingrese nuevo dni: ");
                    vec[esta].dni = modEmpleado.dni;
                    break;
                case 2:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(modEmpleado.nombre);
                    strcpy(vec[esta].nombre, modEmpleado.nombre);
                    break;
                case 3:
                    modEmpleado.edad = getInt("Ingrese nueva edad: ");
                    vec[esta].edad = modEmpleado.edad;
                    break;
                case 4:
                    modEmpleado.sexo = getChar("Ingrese nuevo sexo: ");
                    vec[esta].sexo = modEmpleado.sexo;
                    break;
                case 5:
                    modEmpleado.sueldo = getFloat("Ingrese nuevo sueldo: ");
                    vec[esta].sueldo = modEmpleado.sueldo;
                    break;
                case 6:
                    printf("Ingrese nueva fecha de ingreso d / m / a: ");
                    modEmpleado.fechaIngreso.dia = getInt("Dia: ");
                    modEmpleado.fechaIngreso.mes = getInt("Mes: ");
                    modEmpleado.fechaIngreso.anio = getInt("Anio: ");

                    vec[esta].fechaIngreso.dia = modEmpleado.fechaIngreso.dia;
                    vec[esta].fechaIngreso.mes = modEmpleado.fechaIngreso.mes;
                    vec[esta].fechaIngreso.anio = modEmpleado.fechaIngreso.anio;
                    break;
                case 7:
                    printf("\n1) RRHH");
                    printf("\n2) Sistemas");
                    printf("\n3) Administracion");
                    printf("\n4) Compras");
                    printf("\n5) Deposito");
                    modEmpleado.idSector = getInt("Ingrese nuevo sector: ");
                    vec[esta].idSector = modEmpleado.idSector;
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
        }
        else{
            printf("\nModificacion cancelada.\n\n");
        }

        }
}

int submenuMod(){
    int opcion;
    system("cls");
    printf("Menu modificar empleado: \n");
    printf("1) DNI\n");
    printf("2) Nombre\n");
    printf("3) Edad\n");
    printf("4) Sexo\n");
    printf("5) Sueldo\n");
    printf("6) Fecha de ingreso\n");
    printf("7) Sector\n");

    opcion = getInt("Seleccione una opcion: ");

    return opcion;
}

void ordenarPorNombre(eEmpleado vec[], int tam, eSector sec[]){
    int i, j;
    eEmpleado auxiliar;

    system("cls");
    printf("Lista ordenada por nombres: \n");

    for(i=0; i< tam; i++){
        for(j=i+1; j<tam; j++){
                if(stricmp(vec[i].nombre,vec[j].nombre)>0){
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }
            }
    }
    printf("\nNombre\tDNI   \tEdad\tSexo\tSueldo\tF. de Ingr.\tSector\n");
    for(i=0; i< tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            for(j=0; j<5; j++){
                if(vec[i].idSector==sec[j].id){
                    printf("%s\t%4d\t%d\t%c\t$%8.2f\t%02d/%02d/%4d\t%s\n", vec[i].nombre, vec[i].dni, vec[i].edad, vec[i].sexo, vec[i].sueldo, vec[i].fechaIngreso.dia, vec[i].fechaIngreso.mes, vec[i].fechaIngreso.anio, sec[j].descripcion);
                }
            }
        }
    }
}

void contarEdades(eEmpleado vec[], int tam){
    int a = 0, b = 0, c = 0, mayor, i, flag=0;

    for(i=0; i<tam; i++){
        if(vec[i].isEmpty==0){
           if(vec[i].edad>0 && vec[i].edad<=18){
                    a++;
                }
            else if(vec[i].edad>18 && vec[i].edad<35){
                    b++;
                }
            else if(vec[i].edad>35){
                    c++;
                }
           }
        }

    if(a >= b && a >= c){
        mayor = a;
    }else{
        if(b >= a && b >= c)
        {
            mayor = b;
        }
        else{
        mayor = c;
        }
    }

    system("cls");
    printf("Grafico de edades\n\n");

    for(i=mayor; i>0; i--){
        if(i<= a){
            printf("*");
        }
        if(i<= b){
            flag=1;
            printf("\t*");
        }
        if(i<= c){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("<18\t19-35\t>35\n\n");

}

/**
* \brief Verifica el ingreso de caracteres. Chequea para que
solo sean admitidas las letras S o N.
* Se ingresa void y devuelve un entero sin signo
0 si se ingreso la N
1 si se ingreso la S
*/
unsigned int verifica(void)
{
        char letra;
        printf("\nDesea continuar? (S/N)\n");
        letra=toupper(getche());
        while(!((letra=='S')||(letra=='N')))
        {
        printf("\nHa ingresado opci¢n no valida... Reintente el ingreso(S/N)...\n");
        letra=toupper(getche());
        }
        return (letra=='S');
}

int getInt(char mensaje[]){
    int aux;
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}

float getFloat(char mensaje[]){
    float aux;
    printf("%s", mensaje);
    scanf("%f", &aux);
    return aux;
}

char getChar(char mensaje[]){
    char aux;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    return aux;
}
int validarEntero(int num, int limMin, int limMax){
    while(num<=limMin || num>=limMax){
        num = getInt("Error. Reingrese el dato: ");
    }
    return num;
}
