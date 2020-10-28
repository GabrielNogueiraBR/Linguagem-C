#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no{
	int info;
	no *left;
	no *right;	
}no;


void bubble_sort(int vet[], int tam);
void exibe_vetor(int *p, int tam);
void aloca_no(no **p);
void inicializa_arvore(no **p, int info);
void cria_arvore(no **p, int vet[], int inicio, int fim);
int busca_binaria(int vet[], int inicio, int fim);

//FUNCOES FORNECIDAS PELO PROFESSOR
#define espaco 5
void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita);
void draw_arvore_hor(no *arvore);

main(){
	
	int qtd = 10;
	int vet[10];
	no *tree = NULL; //Cabeca da arvore
	
	//Recebendo 10 numeros em um vetor
	for(int i = 0; i< qtd; i++){
		printf("\nDigite um numero inteiro: ");
		scanf("%i", (vet)+i);
	}
	
	//Exibindo o vetor original
	printf("\nVetor Original: ");
	exibe_vetor(vet, qtd);
	
	//Metodo de ordenacao bublle sort
	bubble_sort(vet, qtd);
	
	//Exibindo o vetor ordenado
	printf("\nVetor Ordenado: ");
	exibe_vetor(vet, qtd);
	
	//Criando uma arvore binaria a partir do vetor ordenado
	cria_arvore(&tree, vet, 0, qtd -1);
	
	//Exibindo a arvore
	printf("\n\n\n\nExibindo a arvore: \n");
	draw_arvore_hor(tree);
	
	printf("\n\n\n\n");
	system("pause");
	
}

void cria_arvore(no **p, int vet[], int inicio, int fim){
	
	
	
	if(inicio > fim )
		return;
		
	else if(inicio == fim){
		int valor; // valor que vai ir no nodo da arvore
		int indice = inicio;
		
		valor = vet[indice];
		
		aloca_no(p);
		inicializa_arvore(p,valor);
		
	}
	else{
		
		int valor; // valor que vai ir no nodo da arvore
		int indice = (inicio+fim)/2;
		
		valor = vet[indice];
		
		aloca_no(p);
		inicializa_arvore(p,valor);
		
		
		cria_arvore(&((*p)->left),vet,inicio,indice-1); //cria arvore a esquerda
		cria_arvore(&((*p)->right),vet,indice+1,fim); //cria arvore a direita
		
		return;
	}
	
}

void inicializa_arvore(no **p, int info){
	(*p)->info = info;
	(*p)->left = NULL;
	(*p)->right = NULL;
}


void bubble_sort(int vet[], int tam){
	
		
	bool troca; //variavel de controle para o metodo de ordenacao
	int aux; //variavel auxiliar para armazenar o valor durante a ordenacao (troca)
	troca = true;
	
	
	while(troca == true){
		troca = false; // por padrao definimos a cada iteracao o valor da troca como false
		for(int i = 0; i < tam -1; i++){
			
			if( vet[i] > vet[i+1]){
				troca = true;
				
				aux = vet[i+1];
				vet[i+1] = vet[i];
				vet[i] = aux;
			}
		}
	}
	
	
}

void exibe_vetor(int *p, int tam){
	
	for(int i = 0; i< tam; i++){
		printf("\t[%i]", *(p+i));
	}
}


void aloca_no(no **p){
	
	if( (*p = (no*) malloc(sizeof(no))) == NULL )
		exit(1);
	
}



//FUNCOES FORNECIDAS PELO PROFESSOR
void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita)
{
	if (arvore== NULL)
		return;
	depth++;
	desenha_arvore_horiz(arvore->right, depth, path, 1);
	path[depth-2] = 0;
	if(direita)
		path[depth-2] = 1;
		if(arvore->left)
			path[depth-1] = 1;
		printf("\n");
		for(int i=0; i<depth-1; i++)
		{
			if(i == depth-2)
				printf("+");
			else if(path[i])
				printf("|");
			else
				printf(" ");
			
			for(int j=1; j< espaco; j++)
				if(i < depth-2)
					printf(" ");
				else
					printf("-");
		}
		printf("%d\n", arvore->info);
		for(int i=0; i<depth; i++)
		{
			if(path[i])
				printf("|");
			else
				printf(" ");
				for(int j=1; j< espaco; j++)
					printf(" ");
		}
		desenha_arvore_horiz(arvore->left, depth, path, 0);
		
}
void draw_arvore_hor(no *arvore)
{
	char path[255] = {};
	desenha_arvore_horiz(arvore, 0, path, 0);
	
}
