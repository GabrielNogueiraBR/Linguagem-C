#include <stdio.h>
#include <stdlib.h>

int soma(int num);

main(){
	
	int num, res = 0;
	
	do{
		printf("\nDigite um numero para exibir a soma de seus N primeiros numeros inteiros: ");
		scanf("%i", &num);	
	}while(num < 0);
	
	res = soma(num);
	printf("\nO resultado da soma deu: %i", res);
	
}

int soma(int num){
	
	if(num == 1){
		return 1;
	}
	else{
		return (num + soma(num-1));
	}
}
