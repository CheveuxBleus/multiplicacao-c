#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "mult_4.h"

int main(int argc, char **argv){

	struct mallinfo after;
	
	printf("Resultado: %s\n", multiplicacao(argv[1], argv[2]));

	after = mallinfo();
	printf("\nMemoria total usada: %d bytes",after.uordblks);
	printf("\nMemoria requisitada mas liberada em tempo de execução: %d bytes\n",after.fordblks);

	return 0;
}