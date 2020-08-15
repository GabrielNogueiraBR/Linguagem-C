#include <stdio.h>
#include <stdlib.h>

main(){
	
	int vet[100], vet_copy[100], vetor_quantidade = 0, i;
	char op;
	
	do{
		
		printf("\nDigite um numero: ");
		scanf("%i", &vet[vetor_quantidade]);
		fflush(stdin);
		vetor_quantidade++;
		
		printf("\nDeseja continuar? (S/N) : ");
		scanf("%c", &op);
		fflush(stdin);
	}while((op == 'S' || op == 's' )&& vetor_quantidade< 100);
	
	
	for(i = 0; i < vetor_quantidade; i++){
		
		printf("\n\nvet[%i] 		= %i", i, vet[i]);
		
	}
	
	
}


