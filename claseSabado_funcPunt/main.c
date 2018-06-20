#include <stdio.h>
#include <stdlib.h>

void funcionPuntero(int(*delegado)(char*));
void funcion1(char* queMuestra);

int main()
{
    funcionPuntero(funcion1);
    return 0;
}

void funcionPuntero(int(*delegado)(char*))
{
    int j = delegado("chau");
    printf("\n%d", j);
}
void funcion1(char* queMuestra)
{
    printf("%s", queMuestra);
}
