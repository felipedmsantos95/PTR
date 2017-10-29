#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "sistema.h"
#include <sys/time.h>
#include <unistd.h>




char *nomeArquivo()
{
    char * nome = (char *) calloc (20, sizeof (char));
    char ext[5];//Extensão do arquivo

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);    
    //fgets(nome, 20, stdin);
    fflush(stdin);
    printf("Digite a extensao do arquivo (Exemplo '.txt', '.doc'): ");
    //fgets(ext, 5, stdin);
    scanf("%s", ext);
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


void simulacao(int t, double *u, double *y)
{   
    //Variaveis relacionadas ao sistema
    int k;
    double v; //Parametro velocidade linear dentro da entrada u
    double w; //Parametro velocidade angular dentro da entrada u
    
    //Variaveis relacionadas ao arquivo
    FILE *arq = abreArquivo();
    int escritaArquivo;

    //Variáveis relacionadas a temporização do sistema
    char buffer[30];
    struct timeval t0;
    struct timeval t1;
    long elapsed;

    //Para o cálculo do item 5 do exercício: Gráfico da amostragem
    long tkMenos1 = 0;
    long Tk;

    //Para o cálculo do item 7 do exercício: Gráfico de Jitter
    long Jk;    
    
    //Inicio da escrita
   
   
   

    for(k = 0; k <= t; k++)
    {
        if(k != 0)//Capturando o tempo decorrido da iteração anterior
            tkMenos1 = elapsed;

        gettimeofday(&t0, 0);//Inicio da contagem da iteração
        u = ut(k);//Entrada em funcao do tempo
        v = u[0];
        w = u[1];
        y = yt(u, k);
        usleep(30);
        gettimeofday(&t1, 0);//Final da contagem da iteração
        elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;//Cálculo do tempo decorrido
        
        //Esses condicoes são as formulas dos itens 5 e 7
        if(k == 0)
        {
            Tk = 0;
            Jk = 0;
        }
        else
        {
            Tk = elapsed - tkMenos1;
            Jk = Tk - 30;
        }

        escritaArquivo = fprintf(arq, "%d\t%lf\t%lf\t%lf\t\%lf\t%lf\t%ld\t%ld\t%ld\n", k, v, w, y[0], y[1],y[2], elapsed, Tk, Jk);
        if(escritaArquivo == EOF)
            printf("Ocorreu um erro enquanto a escrita era realizada.\n");        
        
    }

    fclose(arq);
    free(u);
    free(y);

}




