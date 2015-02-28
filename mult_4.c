#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mult_4.h"


char * multiplicacao(char *n1, char *n2) {
	int in_menor, in_maior, zeros, size, t, i, vai_um, prod, aux, aux2, soma;
	char *result, *maior, *menor;
	zeros = 0;
	t = strlen(n1)+strlen(n2)+1;
	char saida[t], s[t];

	/*separa o menor e o maior número*/

	if (strlen(n1) >= strlen(n2)){
		in_menor = strlen(n2);
		in_maior = strlen(n1);
		maior = n1;
		menor = n2;

	} else{
		in_menor = strlen(n1);
		in_maior = strlen(n2);
		maior = n2;
		menor = n1;
	}


	/*Multiplica uma unidade do menor numero pelo maior numero e salva o resultado na saida*/
	for (i = (in_menor - 1); i >= 0; i--){
		
		vai_um = 0;
		t = strlen(n1)+strlen(n2);
		saida[t] = '\0';
		aux = zeros;
		t--;

		/*Coloca zeros a direita dependendo da localizaçao da unidade do menor numero*/
		while(aux > 0){
			saida[t] = '0';
			aux--;
			t--;
		}

		aux2 = in_maior-1;

		/*multiplica uma unidade do menor numero por todas as unidades do maior e salva em saida*/
		while (aux2 >= 0) {
			prod = ((maior[aux2] - '0') * (menor[i] - '0')) + vai_um;
			saida[t] = '0' + prod % 10;
			vai_um = prod / 10;
			t--;
			aux2--;
		}			

		saida[t] = vai_um + '0';
		
		/*Se saida ainda estiver com espaço livre a esquerda, completa com zeros*/
		while (t > 0){
			t--;
			saida[t] = '0';
		}
		
		/*Passa 'saida' para 's'*/
		if(zeros == 0)
			strcpy(s, saida);
		
		/*Soma 'saida' com 's' e salva em 's'*/
		else{
			t = strlen(s)-1;
			vai_um = 0;

			while (t >= 0) {
				soma = ((s[t] - '0') + (saida[t] - '0')) + vai_um;
				s[t] = soma % 10 + '0';
				vai_um = soma /10;
				t--;
			}
		}
		
		zeros++;
	}		

	/*tamanho do resultado final*/
	size = strlen(s);

        /* Aloca com um a mais para o fim de string '\0' */
	result = (char*) malloc(sizeof(char) * (size+1));
	strcpy(result, s);

	return result;
}