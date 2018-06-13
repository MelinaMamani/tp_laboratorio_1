#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    char seguir = 's';
    FILE* p;
    Employee* lista = employee_new();

    ArrayList* arrayList;

    arrayList = al_newArrayList();

    do{
            system("cls");
    switch(menu()){

        case 1:
            if(parserEmployee(p, arrayList)==0){
                    printf("Empleados cargados. \n\n");
            }
            break;

        case 2:
            employee_print(lista, arrayList);
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            seguir = 'n';
            break;
        }
        system("pause");

    }while(seguir == 's');
    return 0;
}
