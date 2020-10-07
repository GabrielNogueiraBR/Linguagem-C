#include <stdio.h>
#include <stdlib.h>

int mult_impares(int num);

main(){
	
	int num, res = 0;
	
	do{
		printf("\nDigite um numero para exibir a multiplicacao dos N primeiros numeros inteiros impares: ");
		scanf("%i", &num);	
	}while(num < 0);
	
	res = mult_impares(num);
	printf("\nO resultado da multiplicacao deu: %i", res);
	
}

int mult_impares(int num){
	
	if(num == 1){
		return 1;
	}
	else{
		return ((2*num-1) * mult_impares(num-1));
	}
}
