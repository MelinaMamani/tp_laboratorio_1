/**
* \brief Muestra al usuario un menú con nueve opciones
* \param a Se carga el primer numero iniciado en 0
* \param b Se carga el segundo numero iniciado en 0
*/
void menu(float a, float b){
        printf("\n1) Ingresar 1er operando (A= %.1f)\n", a);
        printf("2) Ingresar 2do operando (B= %.1f)\n", b);
        printf("3) Calcular la suma (A+B)\n");
        printf("4) Calcular la resta (A-B)\n");
        printf("5) Calcular la division (A/B)\n");
        printf("6) Calcular la multiplicacion (A*B)\n");
        printf("7) Calcular el factorial (A!)\n");
        printf("8) Calcular todas las operaciones\n");
        printf("9) Salir\n");
}

/**
* \brief Muestra la suma de dos numeros
* \param a Se carga el primer numero
* \param b Se carga el segundo numero
*/
void suma(float a, float b){
        float resultado;
        resultado = a + b;
        printf("Suma = %.2f\n", resultado);
}

/**
* \brief Muestra la resta de dos numeros
* \param a Se carga el primer numero
* \param b Se carga el segundo numero
*/
void resta(float a, float b){
        float resultado;
        resultado = a - b;
        printf("Resta = %.2f\n", resultado);
}

/**
* \brief Muestra la division entre dos numeros
y verifica si el divisor es igual a cero
* \param a Se carga el primer numero
* \param b Se carga el segundo numero
*/
void division(float a, float b){
        float resultado;
        if(b==0){
                printf("No se puede divir por 0. Ingrese otro numero en la opcion 2.\n");
                }
        else{
                resultado = a / b;
                printf("Division = %.2f\n", resultado);
        }
}

/**
* \brief Muestra la multiplicacion entre dos numeros
* \param a Se carga el primer numero
* \param b Se carga el segundo numero
*/
void mult(float a, float b){
        float resultado;
        resultado = a * b;
        printf("Multiplicacion = %.2f\n", resultado);
}

/**
* \brief Muestra el factorial del primer numero ingresado
y verifica su es negativo o mayor a veinte
* \param n Se carga el primer numero
*/
void factorial(float n)
{
    int i;
    int numFac;
    unsigned long long factor=1;
    numFac = ceil(n);

    for(i=1;i<=numFac;i++)
    {
        factor=factor*i;
    }
    if(n<0){
            printf("No se puede factorear numeros negativos.\n");
            }
    else if(n>20){
            printf("Error. Numero demasiado alto.\n");
            }
    else{
            printf("El factorial de %d es %llu\n",numFac,factor);
            }
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
        printf("Desea continuar...S/N?\n");
        letra=toupper(getche());
        while(!((letra=='S')||(letra=='N')))
        {
        printf("\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)...\n");
        letra=toupper(getche());
        }
        return (letra=='S');
}

