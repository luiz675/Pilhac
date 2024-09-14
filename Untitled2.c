#define TAMANHO 10

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int fim;
    int dados[TAMANHO];
} TPilha;

TPilha pilha;
TPilha Aux;


int tamanhoDaPilha(TPilha *p) {
    return p->fim;
}

void insereNaPilha(TPilha *p, int el) {
    if (tamanhoDaPilha(p) >= TAMANHO) {
        printf("Pilha cheia!\n");
        return;
    }
    
    p->dados[p->fim] = el;
    p->fim++;
}

int removeDaPilha(TPilha *p) {
    if (tamanhoDaPilha(p) <= 0) {
        printf("Pilha vazia!\n");
        return -1;
    }

    int el = p->dados[p->fim - 1];
    p->fim--;
    return el;
}
int removeCarro(TPilha *p, int Carro){
	if (tamanhoDaPilha(p) <= 0){
		printf("Pilha vazia");
		return - 1;
		
	}
	
	int c = removeDaPilha(&pilha);
	while(c != Carro){
		insereNaPilha (&Aux, c);
		c = removeDaPilha(&pilha);
		
	}
	printf("Retirou o carro %d\n", c);
	
	while(tamanhoDaPilha(&Aux) > 0){
		c = removeDaPilha(&Aux);
		insereNaPilha(&pilha, c);
	}
}

void mostrarPilha(TPilha p) {
    int i;
    printf("\n\n");
    for (i = p.fim - 1; i >= 0; i--) {
        printf("| %d |\n", p.dados[i]);
    }
    printf("\n\n");
}


int main() {
    while (1 == 1) {
        printf("--- BEM-VINDO AO ESTACIONAMENTO 24 HORAS ---\n\n");
        printf("O que você deseja fazer hoje?\n\n");
        printf("1 - Exibir a pilha carro\n");
        printf("2 - Inserir na pilha carro \n");
        printf("3 - Remover da pilha carro \n");
        printf("0 - Sair\n\n: ");
        int opcao, add;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarPilha(pilha);
                system("pause");
                break;
            case 2:
                printf("Escolha a placa do  para adicionar: ");
                scanf("%d", &add);
                insereNaPilha(&pilha, add);
                break;
            case 3:
            	printf("Escolha a placa do  para remover: ");
                scanf("%d", &add);
                add = removeCarro(&pilha, add);
                
                system("pause");
                break;
            case 0:
                return 0;
            default:
                break;
        }

    }

    return 0;
}
