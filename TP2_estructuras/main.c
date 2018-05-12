#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main(){
system("title ABM formularios");
char salir='S';

eEmpleado gente[TAM];
eSector sectores[5];

inicializarEmpleados(gente,TAM);
hardCode(sectores);

do{
    switch (menu()){

    case 1 :
        altaEmpleado(gente,TAM);
        break;
    case 2 :
        bajaEmpleado(gente,TAM);
        break;
    case 3 :
        modificaEmpleado(gente,TAM);
        break;
    case 4 :
        ordenarPorNombre(gente,TAM,sectores);
        break;
    case 5:
        contarEdades(gente,TAM);
        break;
    case 6:
        if(verifica()==0)
        salir = 'N';
        break;
    default:
        printf("\nOpcion incorrecta\n");
        system("pause");
        system("cls");
    }

}while(salir=='S');

  return 0;
}
