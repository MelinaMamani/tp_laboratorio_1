#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    /**
    * Se inicializan cuatro variables:
    * 'seguir' para continuar ejecutando el programa
    * 'opcion' para elegir una del menu
    * 'num1' y 'num2' para luego cargar dos numeros
    **/
    char seguir='S';
    int opcion=0;
    float num1=0.00;
    float num2=0.00;

    while(seguir=='S')
    {
        menu(num1, num2);
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                printf("Ingrese un numero: \n");
                scanf("%f", &num1);
                break;
            case 2:
                printf("Ingrese otro numero: \n");
                scanf("%f", &num2);
                break;
            case 3:
                suma(num1,num2);
                break;
            case 4:
                resta(num1,num2);
                break;
            case 5:
                division(num1,num2);
                break;
            case 6:
                mult(num1,num2);
                break;
            case 7:
                factorial(num1);
                break;
            case 8:
                suma(num1,num2);
                resta(num1,num2);
                division(num1,num2);
                mult(num1,num2);
                factorial(num1);
                break;
            case 9:
                //Si verifica es = 0 se sale del programa

                if(verifica()==0)
                    seguir = 'N';
                break;
            default:
                printf("Opcion no valida.\n");
                break;
            }

    }
    return 0;
}
