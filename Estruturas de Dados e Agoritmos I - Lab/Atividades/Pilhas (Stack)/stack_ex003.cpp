#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define LIMITE 100
/*

	DESAFIO: como seria um programa para verificar se o uso de parênteses em ua expressão está correta.

*/

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


bool emptyStack(stack *s)
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
	
	char p[100];
	int tam, i;
	stack S1; // declarando a pilha
	bool aux = true; // variável que vai nos informar se a disposição de parênteses está correta
		
	// definindo o topo da pilha
	S1.top = -1;
	
	// recebendo a expressão
	printf("\nDigite uma expressao com parenteses: ");
	gets(p);
	fflush(stdin);
	tam = strlen(p);
	
	// empilhando a expressao na pilha
	for( i = 0; i < tam && aux == true; i++){
		
		if(p[i] != ' ' ){
			
			if(p[i] == '('){
				push(p[i], &S1); // insere um elemento na pilha
			}
			
			else if( p[i] == ')'){
				
				if( emptyStack(&S1) ){
					aux = false;
				} // caso a pilha esteja vazia
				
				else{
					pop(&S1); // retira um elemento da pilha
					
				} // caso a pilha não esteja vazia
			}
			
		}
		
	}
	
	printf("\nA espressao de parenteses esta ");
	
	if(aux)
		printf("correta.\n");
	else
		printf("falsa.\n");
	
	
	
	


}