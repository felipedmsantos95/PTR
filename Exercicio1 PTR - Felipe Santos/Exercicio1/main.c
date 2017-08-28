#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diferenca.h"
#include "soma.h"


int main(int argc, char *argv[])
{
            
    if(argc == 3)
    {
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        if(num1 != 0 && num2 != 0)
        {
            printf("A soma dos numeros passados eh: %d\n", soma(num1,num2));
            printf("A diferenca dos numeros passados eh: %d\n", diferenca(num1,num2));
        }
        else
        {
            printf("Argumentos invalidos\n");
        }    
    }
    else
    {
        printf("Para usar, dois parametros precisa passar\n");
    }

    return 0;
}
