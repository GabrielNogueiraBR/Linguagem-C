#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#define LIMITE 100

typedef struct 
{
	char items[LIMITE];
	int top;
}stack;

bool isfull(stack *s)
{
	bool aux;
	aux = (s->top == (LIMITE - 1)) ? true : false;
	return(aux);
}


bool empty(stack *s)
{
	bool aux;
	aux = (s-> top == -1) ? true: false;
	return(aux);
}

void push(char e, stack *s)
{
	s->top += 1;
	s->items[s->top] = e;
}

char pop(stack *s)
{
	char e;
	e = s->items[s->top];
	s->top -= 1;
	return(e);
}

char stacktop(stack *s)
{
	char e;
	e = s->items[s->top];
	return(e);
}

int main(void)
{
	// definindo as variáveis
	char frase[100];
	int tam, i, j;
	stack S1, S2;
	bool p = true; // palindromo é verdadeiro
	
	// definindo o topo da pilha
	S1.top = -1;
	S2.top = -1;
	
	// recebendo o palindromo
	printf("\nDigite uma frase: ");
	gets(frase);
	fflush(stdin);
	tam = strlen(frase);
	
	// empilhando a frase na primeira pilha
	for( i = 0; i < tam ; i++){
		if(frase[i] != ' '){
			push(frase[i], &S1);
			//printf("\nPilha 1: %c\n", frase[i]);
			//system("pause");
		}
	}
	
	// empilhando a frase na segunda pilha
	for( j = tam -1 ; j > -1 ; j--){
		if(frase[j] != ' ')
			push(frase[j], &S2);
			//printf("\nPilha 2: %c\n", frase[j]);
			//system("pause");
		}	
	
	// verificando se e palindromo
	while(S1.top != -1 && p == true){
		if( pop(&S1) != pop(&S2)){
			p = false; // palindromo é falso
		}
	}
	
	if( p == true)
		printf("\nA palavra e palindromo");
		
	else
		printf("\nA palavra nao e palindromo");
	
	
	


}