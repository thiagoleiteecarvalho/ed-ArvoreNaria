/*
 * main.c
 * Classe principal de execução da Árvore N-ária.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void) {

	int opcao;
	char valor;
	char pai;
	char elemento;

	do {

		printf("\n");
		printf("ÁRVORE N-ÁRIA\n");
		printf("Escolha a opcao\n");
		printf("0. Sair\n");
		printf("1. ROOT\n");
		printf("2. INSERT\n");
		printf("3. SEARCH\n");
		printf("4. UPDATE\n");
		printf("5. Exibir Pós-Ordem\n");
		printf("Digite uma opção:");
		scanf("%d", &opcao);

		switch (opcao) {
		case 0:
			exit(1);
			break;

		case 1:
			printf("Digite um valor para a raiz da árvore:");
			scanf(" %c", &valor);
			criar_raiz(valor);
			break;

		case 2:
			printf("Digite um valor a ser inserido:");
			scanf(" %c", &valor);
			printf("Digite o pai do valor a ser inserido:");
			scanf(" %c", &pai);
			insert(getRaiz(), valor, pai);
			break;

		case 3:
			printf("Digite um elemento a ser pesquisado:");
			scanf(" %c", &valor);

			No *no_search = NULL;
			no_search = search(getRaiz(), valor);
			if (no_search != NULL) {
				printf("Elemento %c pertence a árvore.", no_search->valor);
			} else {
				printf("Elemento não %c pertence a árvore.", valor);
			}
			break;

		case 4:
			printf("Digite o elemento a ser atualizado:");
			scanf(" %c", &elemento);
			printf("Digite o novo valor:");
			scanf(" %c", &valor);
			update(getRaiz(), elemento, valor);
			break;
		case 5:
			if (getRaiz() != NULL) {
				exibir_pos_ordem(getRaiz());
			} else {
				printf("Raiz nula. Árvore inexistente.");
			}
			break;

		default:
			printf("Comando invalido\n\n");
			break;
		}

	} while (opcao);

	free(getRaiz());
	return 0;
}
