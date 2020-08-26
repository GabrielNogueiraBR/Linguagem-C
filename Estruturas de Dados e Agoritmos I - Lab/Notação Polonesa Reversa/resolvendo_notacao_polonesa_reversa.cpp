#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#define LIMITE 100

typedef struct 
{
	float items[LIMITE];
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

void push(float e, stack *s)
{
	s->top += 1;
	s->items[s->top] = e;
}

float pop(stack *s)
{
	float e;
	e = s->items[s->top];
	s->top -= 1;
	return(e);
}

float stacktop(stack *s)
{
	float e;
	e = s->items[s->top];
	return(e);
}

//funcao que retorna o valor final da notacao
float calculaExpressao(char *p, int tam);

int main(void)
{
	//string que recebe a expressao em notacao polonesa reversa
	char notacao[100];
	
	//variavel que vai armazenar o resultado da notacao
	float valorFinal;
	
	//recebendo a expressao do usuario
	printf("\nDigite a expressao desejada em notacao polonesa reversa (numeros com 1 algarismo): ");
	gets(notacao);
	fflush(stdin);
	
	valorFinal = calculaExpressao(notacao, strlen(notacao));
	
	printf("\nA notacao eh: ");
	puts(notacao);
	printf("O resultado da notacao eh igual a: %.2f", valorFinal);	
	
}

float calculaExpressao(char *p, int tam){
	
	//declarando a nossa pilha de float
	stack *pilha;
	//inicializando o top como -1 para dizer que está vazia
	pilha->top = -1;
	
	int i;
	float aux1, aux2, resultado;
	
	for(i = 0 ; i < tam; i++){
		
		if( *(p+i) >= '0' && *(p+i) <= '9' ){
			//transformando char em float
			aux1 = (float) *(p+i) - '0';
			
			//armazenando o float na pilha
			push(aux1,pilha);
		}
		
		else if( *(p+i) == '+'){
			
			aux2 = pop(pilha);
			aux1 = pop(pilha);
			
			resultado = aux1 + aux2;
			push(resultado,pilha);
		}//operacao de soma
		
		else if( *(p+i) == '-'){
			aux2 = pop(pilha);
			aux1 = pop(pilha);
			
			resultado = aux1 - aux2;
			push(resultado,pilha);
			
		}//operacao de subtracao
		
		else if( *(p+i) == '*'){
			aux2 = pop(pilha);
			aux1 = pop(pilha);
			
			resultado = aux1 * aux2;
			push(resultado,pilha);
			
		}//operacao de multiplicacao
		
		else if( *(p+i) == '/'){
			aux2 = pop(pilha);
			aux1 = pop(pilha);
			
			resultado = aux1 / aux2;
			push(resultado,pilha);
			
		}//operacao de divisao
		
		else if( *(p+i) == '^'){
			aux2 = pop(pilha);
			aux1 = pop(pilha);
			
			resultado = pow(aux1,aux2);
			push(resultado,pilha);
			
		}//operacao de potenciacao
		
		
		
		
	}//for para varrer toda nossa notacao
	
	return pop(pilha);
	
}
