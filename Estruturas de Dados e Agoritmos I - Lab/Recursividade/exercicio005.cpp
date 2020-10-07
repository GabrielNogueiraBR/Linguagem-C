#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int valor_proc, int indice_esq, int indice_dir, int *vetor);
void aloca_int(int **vetor, int tam);

main(){
	
	int valor, op, qtd, *vetor, indice_encontrado;
	vetor = NULL;
	qtd = 0;
	
	do{
		system("cls");
		printf("\n\tMenu:\n");
		printf("\n[1] Adicionar numero");
		printf("\n[2] Listar");
		printf("\n[3] Procurar numero");
		printf("\n[4] Sair");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%i", &op);
		
		
		switch(op){
			
			case 1:
				system("cls");
				printf("\nDigite o numero a ser inserido: ");
				scanf("%i", &valor);
				qtd++;
				aloca_int(&vetor, qtd);
				*(vetor+qtd-1) = valor;
				break;
			case 2:
				system("cls");
				printf("\n\n");
				for(int i = 0; i < qtd; i++){
					printf("\t[%i]", *(vetor+i));
				}
				printf("\n\n");
				system("pause");
				break;
			case 3:
				system("cls");
				printf("\nDigite o numero a ser procurado: ");
				scanf("%i", &valor);
				
				indice_encontrado = busca_binaria(valor,0,qtd-1,vetor);
				
				if(indice_encontrado == -1){
					printf("\n\nErro, o numero nao foi encontrado.\n");
					system("pause");
				}
				else{
					printf("\nO numero foi encontrado.\n");
					printf("\nValor: %i\nIndice no vetor: %i\n", *(vetor+indice_encontrado),indice_encontrado);
					system("pause");
				}
				
				break;
			case 4:
				exit(1);
		}
		
		
	}while(op != 3);
}

void aloca_int(int **vetor, int tam){
	
	if( (*vetor = (int*) realloc(*vetor, tam*sizeof(int)) ) == NULL)
		exit(1);
}

int busca_binaria(int valor_proc, int indice_esq, int indice_dir, int *vetor){
	
	int meio = indice_esq + indice_dir;
	meio = meio/2;
	
	if( *(vetor+meio) == valor_proc ){
		return meio;
	}
	else{
		
		if( *(vetor+meio) > valor_proc){
			return busca_binaria(valor_proc,indice_esq,meio-1,vetor);
		}
		else{
			return busca_binaria(valor_proc,meio+1,indice_dir,vetor);
		}
		
	}
}

