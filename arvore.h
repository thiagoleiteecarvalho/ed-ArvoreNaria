/*
 * arvore.h
 * Header de definição da ED Árvore N-ária.
 * Author: Thiago Leite
 */

#pragma once

typedef struct no {
	char valor;
	struct no *pai;
	struct no *primogenito;
	struct no *irmao;
} No;

void setRaiz(No *no);
No* getRaiz();
No* criar_no(char elemento);
void criar_raiz(char elemento);
void insert(No *raiz, char elemento, char pai);
No* search(No *no, char elemento);
void update(No *raiz, char elemento, char novo_valor);
void exibir_pos_ordem(No *no);
