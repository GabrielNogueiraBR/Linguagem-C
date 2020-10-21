#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define espaco 5

typedef struct no{
	int info;
	no *right;
	no *left;
}no;

no* make_no(int num);
void aloca_no(no **p);
void insert_tree(no **p, int num);
bool find_number_tree(int num, no *p);
int profundidade_tree(no *p);
int soma_folhas(no *p);

void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita);
void draw_arvore_hor(no *arvore);



main(){
	
	//declarando a variavel que vai ser a cabeca da arvore
	no *tree = NULL;
	int num, op;
	bool find_number;
	
	do{
		system("cls");
		printf("\n[1] Adicionar um numero positivo na arvore");
		printf("\n[2] Buscar um numero na arvore");
		printf("\n[3] Mostar arvore");
		printf("\n[4] Profundidade da arvore");
		printf("\n[5] Total de folhas da arvore");
		printf("\n[6] Sair");
		
		printf("\nDigite a opcao desejada: ");
		scanf("%i", &op);
		
		
		switch(op){
			
			
			case 1:
				do{
					system("cls");
					printf("\nDigite um numero a ser inserido na arvore: ");
					scanf("%i", &num);
					fflush(stdin);
				}while(num < 0);
				
				if(num != -1){
					insert_tree(&tree, num);
					
					printf("\nO numero %i foi inserido com sucesso.\n", num);
					system("pause");
				}
				break;
			
			case 2:
				do{
					system("cls");
					printf("\nDigite um numero a ser buscado na arvore: ");
					scanf("%i", &num);
					fflush(stdin);
				}while(num < 0);
				
				find_number = find_number_tree(num, tree);
				
				if(find_number == true)
					printf("\nO numero %i foi encontrado na arvore.\n", num);
				
				else
					printf("\nO numero %i nao foi encontrado na arvore.\n", num);
				
				system("pause");
				break;
				
			case 3:
				system("cls");
				draw_arvore_hor(tree);
				printf("\n\n");
				system("pause");
				break;
				
			case 4:
				system("cls");
				printf("\nA profundidade da arvore e %i.\n", profundidade_tree(tree));
				system("pause");
				break;
				
			case 5:
				system("cls");
				printf("\nA quantidade de folhas da arvore e %i.\n", soma_folhas(tree));
				system("pause");
				break;
				break;	
				
			case 6:
				exit(1);
				
			default:
				break;
				
		}
		
		
		
		
		
	}while(num > -1);
	
	system("cls");
	
	
}


no* make_no(int num){
	
	no *p;
	
	aloca_no(&p);
	p->info  = num;
	p->left  = NULL;
	p->right = NULL;
	
	return (p);
	
}

void aloca_no(no **p){
	
	if( (*p = (no*) malloc(sizeof(no))) == NULL )
		exit(1);
	
}

void insert_tree(no **p, int num){
	
	if( (*p) == NULL )
		(*p) = make_no(num);
	
	else if(num > (*p)->info)
		insert_tree(&(*p)->right, num);		
	
	else
		insert_tree(&(*p)->left, num);	
	
}

bool find_number_tree(int num, no *p){
	
	if( p == NULL)
		return false;
	
	else if ( p->info == num )
		return true;
	
	else if( num > p->info )
		find_number_tree(num, p->right);
	
	else
		find_number_tree(num, p->left);
	
	
	
}

int profundidade_tree(no *p){
	
	//profundidade da esquerda
	int prof_left; 
	
	//profundidade da direita
	int prof_right; 
	
	if( p == NULL){
		return (0);
	}
	
	else{
		//calcular a profundidade da esquerda
		prof_left = profundidade_tree(p->left);
		prof_right = profundidade_tree(p->right);
		
		if(prof_left > prof_right){
			return (1 + prof_left);
		}
		else
			return (1 + prof_right);
		
	}	
	
}

int soma_folhas(no *p){
	
	int folhas_direita;
	int folhas_esquerda;
	
	if( p == NULL){
		return (0);
	}
	
	else if( p->left == NULL && p->right == NULL )
		return (1);
	
	else{
		
		folhas_direita = soma_folhas(p->right);
		folhas_esquerda = soma_folhas(p->left);
		return (folhas_direita + folhas_esquerda);
	}
		
	
	
}

//funcao montada pelo professor para exibir uma arvore
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


