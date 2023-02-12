/*
 * arvore.c
 * Classe de implemantação da ED Árvore Clássica.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *raiz = NULL;

void setRaiz(No *no) {
	raiz = no;
}

No* getRaiz() {
	return raiz;
}

No* criar_no(char elemento) {

	No *no = malloc(sizeof(No));
	no->valor = elemento;
	no->primogenito = NULL;
	no->irmao = NULL;

	return no;
}

void criar_raiz(char elemento) { /*I*/

	if (raiz == NULL) {
		raiz = criar_no(elemento); /*II*/
	} else {
		printf("Raiz já foi criada\n");
	}
}

void insert(No *raiz, char elemento, char pai) { /*I*/

	No *no_pai = search(raiz, pai);

	if (no_pai != NULL) {

		if (no_pai->primogenito == NULL) {

			no_pai->primogenito = criar_no(elemento);
			no_pai->primogenito->pai = no_pai;
			printf("Primogênito %c de %c inserido.\n", elemento, pai);
		} else {

			No *filho = no_pai->primogenito;

			while (filho->irmao != NULL) {
				filho = filho->irmao;
			}

			filho->irmao = criar_no(elemento);
			printf("Filho %c de %c e irmão de %c inserido.\n", elemento, pai,
					filho->valor);
		}
	} else {
		printf("Pai não encontrado. INSERT não realizado.\n");
	}
}

No* search(No *no, char elemento) {

	if (no != NULL) {

		if (no->valor == elemento) {

			return no;
		} else {

			No *filho = no->primogenito;

			while (filho != NULL) {

				No *no_pesquisa = search(filho, elemento);

				if (no_pesquisa != NULL) {
					return no_pesquisa;
				}

				filho = filho->irmao;
			}
		}
	}

	return NULL;
}

void update(No *raiz, char elemento, char novo_valor) {

	No *no = search(raiz, elemento);

	if (no != NULL) {
		no->valor = novo_valor;
	} else {
		printf("Nó não encontrado. Impossível realizar UPDATE.");
	}
}

void exibir_pos_ordem(No *no) {

	if (no != NULL) {

		No *no_auxiliar = no->primogenito;

		while (no_auxiliar != NULL) {

			exibir_pos_ordem(no_auxiliar);
			no_auxiliar = no_auxiliar->irmao;
		}
		printf("%c ", no->valor);
	}
}

