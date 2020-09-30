#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
	int info;
	struct no *prox;
}no;


void aloca_no(no **p);
void mostrar_lista(no **p);
int  remover_no(no *p);
void novo_no(no **p, int valor);

void operacao_inserir(no **p, int valor);
void operacao_remover(no **p);
void operacao_exibir(no *p);

no *busca_topo(no *p);
no *busca_antecessor(no *lista, no *p);

bool pilha_vazia(no *p);

main(){
	
	no *stack = NULL;
	
	int op, valor;
	
	do{
		system("cls");
		printf("\n======================================================================");
		printf("\n[1] - Inserir");
		printf("\n[2] - Remover");
		printf("\n[3] - Exibir pilha");
		printf("\n[0] - Sair");
		printf("\n\nDigite a opcao desejada: ");
		scanf("%i", &op);
		fflush(stdin);
		
		switch(op){
			
			case 0:
				exit(1);
				break;
			case 1:
				printf("\nDigite o numero a ser inserido: ");
				scanf("%i", &valor);
				fflush(stdin);
				operacao_inserir(&stack, valor);
				break;
			case 2:
				if(!pilha_vazia(stack)){
					operacao_remover(&stack);
				}//caso nao esteja vazia
				else{
					printf("\nErro! Lista vazia.\n");
					system("pause");					
				}
				break;
			case 3:
				if(!pilha_vazia(stack)){
					operacao_exibir(stack);
				}//caso nao esteja vazia
				else{
					printf("\nErro! Lista vazia.\n");
					system("pause");					
				}
				break;
			default:
				break;
		}
	}while(op =! 0);
}

void aloca_no(no **p){

	if( (*p = (no*) malloc(sizeof(no))  ) == NULL )
		exit(1);
	
}

no *busca_topo(no *p){
	
	no *q;
	
	q = p;
	
	while(q->prox != NULL){
		q = q->prox;
	}
	
	return (q);
	
}

no *busca_antecessor(no *lista, no *p){
	no *q = lista;
	
	if(q == p){
		return NULL; // quer dizer que possui apenas um elemento na pilha
	} // antecessor e o proprio numero buscado
	
	while(q->prox != p){
		q = q->prox;
	}
	
	
	return (q);
}

bool pilha_vazia(no *p){
	
	if( p == NULL)
		return true;
	
	return false;
}

void novo_no(no **p, int valor){
	
	if(pilha_vazia(*p)){
		aloca_no(p);
		(*p)->info = valor;
		(*p)->prox = NULL;
	}//caso esteja vazio
	
	else{
		no *q;
		q = busca_topo(*p);
		
		aloca_no(&q->prox);  //q->prox recebe o novo endereço
		
		q = q->prox; //q avanca para nova posicao criada
		q->info = valor;
		q->prox = NULL;
	}
}

int remover_no(no *p){
	
	int aux;
	no *q, *ant;
	
	q = busca_topo(p);
	ant = busca_antecessor(p,q);
	
	if(ant != NULL){
		aux = q->info;
		free(ant->prox);
		ant->prox = NULL;
	}
	else
		free(q);
		
	return aux;
}

void operacao_inserir(no **p, int valor){
	
	novo_no(p, valor);
	printf("\nO valor [%i] foi inserido com sucesso.\n", valor);
	system("pause");
	
}

void operacao_remover(no **p){
	
	int valor;
	
	valor = remover_no(*p);
	
	printf("\nO valor [%i] foi removido com sucesso.\n", valor);
	system("pause");
	
}

void operacao_exibir(no *p){
	no *q = p;
	bool fim = false;
	
	while(!fim){
		
		printf("\t[%i]", q->info);
		
		if(q->prox != NULL)
			q = q->prox;
		else
			fim = true;
	}
	
	printf("\n\n");
	system("pause");
}
