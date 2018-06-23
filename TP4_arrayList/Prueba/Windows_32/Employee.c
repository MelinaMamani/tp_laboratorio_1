#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#define TAM 1001

int menu(){
    int opcion;

    printf("Menu Empleados:\n");
    printf("1. Parse del archivo data.csv\n");
    printf("2. Listar Empleados\n");
    printf("3. Ordenar por nombre\n");
    printf("4. Agregar un elemento\n");
    printf("5. Elimina un elemento\n");
    printf("6. Listar Empleados (Desde/Hasta)\n");
    printf("7. Salir\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* E1 = (Employee*) pEmployeeA;
    Employee* E2 = (Employee*) pEmployeeB;

    if(strcmp(E1->name, E2->name)>0)
    {
        return 1;
    }
    if(strcmp(E1->name, E2->name)<0)
    {
        return -1;
    }

    return 0;
}


void employee_print(Employee* this, ArrayList* arrayList)
{
    int i, pause = 1;

    xlkCenterPrintf("LISTA DE EMPLEADOS",1);

    xlkSortPrintf(1,"%s,%s,%s",3,"ID EMPLEADO","NOMBRE","APELLIDO");

            for( i=0;i < arrayList->len(arrayList);i++ )
            {
                this = arrayList->get(arrayList,i);
                xlkSortPrintf(3,"%d,%s,%s",3,this->id, this->name, this->lastName);
                if( i == 125*pause)
                {
                    system("pause");
                    pause++;
                }
            }
}

Employee* employee_new(void)
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    return this;

}

void employee_delete(Employee* this)
{


}

void employee_setId(Employee* this, int id)
{
    if(id > 0)
        this->id = id;
}

int employee_getId(Employee* this)
{
    return this->id;
}

void employee_setName(Employee* this, char* name)
{
    if(strlen(name)<=51)
        strcpy(this->name, name);
}

char* employee_getName(Employee* this)
{
    return this->name;
}

void employee_setLastName(Employee* this, char* lastName)
{
    if(strlen(lastName)<=51)
        strcpy(this->lastName, lastName);
}

char* employee_getLastName(Employee* this)
{
    return this->lastName;
}

void employee_setIsEmpty(Employee* this, char* isEmpty)
{
    if(strcmp(isEmpty, "true")==0){
        this->isEmpty = 1;
    }
    else if(strcmp(isEmpty, "false")==0){
        this->isEmpty = 0;
    }
}

int employee_getIsEmpty(Employee* this)
{
    return this->isEmpty;
}

