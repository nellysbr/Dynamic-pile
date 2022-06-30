#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct NO {
	int dado;
	struct NO *prox;
};

struct pilha {
	NO *topo;
};

void iniciaPilha(pilha *p){
	p->topo = NULL;
}

void empilha(int dado, pilha *p){
	NO *ptr = (NO*) malloc(sizeof(NO));
	
	if (ptr == NULL){
		printf("Erro na alocacao da Pilha. \n");
	} else {
		ptr->dado = dado;
		ptr->prox = p->topo;
		p->topo = ptr;
	}
}

int desempilha (pilha *p){
	NO* ptr = p->topo;
	int dado;
	if(ptr == NULL){
		printf("Pilha vazia. \n");
		//return;
		
	} else {
		p->topo = ptr->prox;
		ptr->prox = NULL;
		dado = ptr->dado;
		free(ptr);
		return dado;
	}
}

void imprimeDinamica(pilha *p){
	NO *ptr = p->topo;
	if(ptr == NULL){
		printf("Pilha Vazia. \n");
		return;
	}else {
		while (ptr != NULL){
			printf("%d - ", ptr->dado);
			ptr = ptr->prox;
		}
		printf("\n");
	}
}


int main(){
	
	pilha *p1 = (pilha*) malloc(sizeof(pilha));
	

	iniciaPilha(p1);
		
	empilha(1, p1);
	empilha(10, p1);
	imprimeDinamica(p1);
	
	desempilha(p1);
	imprimeDinamica(p1);
		


	
}
