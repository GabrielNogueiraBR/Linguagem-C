#include <stdio.h>
#include <stdlib.h>

main(){
	
	int vet[100], vet_copy[100], vetor_quantidade = 0, i, j;
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
	
	for(i = vetor_quantidade -1 , j = 0; i >= 0; i--){
		
		vet_copy[i] = vet[j];
		j++;
		
	}
	
	
	
	for(i = 0; i < vetor_quantidade; i++){
		
		printf("\n\nvet[%i] 		= %i", i, vet[i]);
		printf("\nvet_copy[%i] 	= %i", i, vet_copy[i]);
		
	}
	
	
}


