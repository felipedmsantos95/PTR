#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <fcntl.h>
#include <rtai_lxrt.h>
#include <math.h>
#include "sistema.h"
#include "simulacao.h"
#include "libIn.h"
#include "libOut.h"
#include "libX.h"

int main(int argc, char *argv[])
{
	int priority=0;   // Highest
	int stack_size=0; // Use default (512)
	int msg_size=0;   // Use default (256)
	
	struct sched_param mysched;
	mysched.sched_priority = sched_get_priority_max(SCHED_FIFO) - 1;
	if( sched_setscheduler( 0, SCHED_FIFO, &mysched ) == -1 ) {
		puts("ERROR IN SETTING THE SCHEDULER");
		perror("errno");
		exit(1);
	}
	task = rt_task_init( nam2num("Name"), priority, stack_size, msg_size);

	//Simulação
	double *u = (double *) calloc (2, sizeof (double)); //Entrada
	double *y = (double *) calloc (3, sizeof (double)); //Saida
	int t = 20;
    
	simulacao(t, u, y);
	//Fim da Simulação

	rt_task_delete(task);
	return 0;
}
