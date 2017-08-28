#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "sistema.h"


char *nomeArquivo()
{
    char * nome = (char *) calloc (20, sizeof (char));
    char ext[5];//Extensão do arquivo

    printf("Digite o nome do arquivo: ");
    fgets(nome, 20, stdin);
    fflush(stdin);
    printf("Digite a extensao do arquivo (Exemplo '.txt', '.doc'): ");
    fgets(ext, 5, stdin);
    fflush(stdin);

    strcat(nome, ext);

    return nome;

}

FILE *abreArquivo()
{
    char * nome = (char *) calloc (20, sizeof (char));
    nome = nomeArquivo();         
    FILE *arq = (FILE *) malloc(sizeof(FILE));//Alocando espaco na memória para o ponteiro do arquivo
    
    arq = fopen(nome, "wt");
    if(arq == NULL)
    {
        printf("Nao foi possivel criar o arquivo.\n");
        return NULL;
    }
    return (arq);
    

}

void simulacao()
{   
    //Variaveis relacionadas ao sistema
    int t;
    double *u = (double *) calloc (2, sizeof (double)); //Entrada
    double *y = (double *) calloc (3, sizeof (double)); //Saida
    double v; //Parametro velocidade linear dentro da entrada u
    double w; //Parametro velocidade angular dentro da entrada u
    
    //Variaveis relacionadas ao arquivo
    FILE *arq = abreArquivo();
    int escritaArquivo;    
    
    //Inicio da escrita
    escritaArquivo = fprintf(arq, "t\t\tv\t\t\tw\t\t\txc\t\t\tyc\t\ttheta\n");

    for(t = 0; t <= 20; t++)
    {
        u = ut(t);//Entrada em funcao do tempo
        v = u[0];
        w = u[1];
        y = yt(v, w);
        escritaArquivo = fprintf(arq, "%d\t%lf\t%lf\t%lf\t\%lf\t%lf\n", t, v, w, y[0], y[1],y[2]);
        if(escritaArquivo == EOF)
            printf("Ocorreu um erro enquanto a escrita era realizada.\n");        
        
    }

    fclose(arq);
    free(u);
    free(y);

}




