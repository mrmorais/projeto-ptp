#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtoDAO.h"
#include "produto.h"

/*
 * Project: Bodega do IMD. Grupo 13
 * File: produto.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: Produto function 14/11/2016
 * DOC Url: https://github.com/mrmorais/projeto-ptp/blob/master/docs/class/produto.md
 * Issues: NO
 */

int produto_newProduct(Produto *p) {
	dao_putProduto(p);
}

void produto_getAllProducts(Produto products[MAX_LIN]) {
	char buffer[MAX_LIN][MAX_COL];
	dao_readFile(buffer);
	dao_setProdutos(buffer, products);
	int i;
	for (i=0; i<MAX_LIN; i++) {
		if(products[i].id < dao_getNextId() && products[i].id > 0) {
			products[i].id = 0;
		}
	}
}

void produto_getProductById(int id, Produto* p) {
	dao_getProductById(id, p);
}

void produto_updateProduct(int id, Produto *p) {
	dao_updateProduct(id, p);
}

void produto_printProduct(int first, Produto *p) {
	if(first) {
		printf("------------------------------------------------------------------\n");
	}
	printf("ID:  %i  ", (*p).id);
	printf("Descricao:  %s  \n", (*p).descricao);
	printf("Preço:  R$ %.2f ", (*p).preco);
	printf("Fornecedor:  %s  ", (*p).fornecedor);
	printf("Quantidade:  %i  \n", (*p).quantidade);
	printf("Data de Validade:  %i/%i/%i  ", (*p).validade.dia, (*p).validade.mes, (*p).validade.ano);
	printf("Corredor:  %i  ", (*p).localizacao.corredor);
	printf("Prateleira:  %i \n", (*p).localizacao.prateleira);
	printf("------------------------------------------------------------------\n");
}

void produto_searchProduct(int search_type, Produto *p) {
	Produto tmp_p;

	Produto products[MAX_LIN];
  produto_getAllProducts(products);

	int i, first = 1, wait;

	switch (search_type) {
		case 1: //ID
			dao_getProductById((*p).id, &tmp_p);
			if(tmp_p.id == 0) {
				printf("Não foi possível encontrar um produto com este ID\n");
			} else {
				produto_printProduct(1, &tmp_p);
			}
			printf("Voltar ao menu [PRESS 9]: "); //Err
			scanf("%i", &wait);
			break;
		case 2: //Nome
			for(i = 0; i<MAX_LIN; i++) {
				if(strcmp(products[i].descricao,(*p).descricao)==0) {
					produto_printProduct(first, &products[i]);
					if(first) {
						first=0;
					}
				}
			}
			printf("Voltar ao menu [PRESS 9]: "); //Err
			scanf("%i", &wait);
			break;
		case 3: //Fornecedor
			for(i = 0; i<MAX_LIN; i++) {
				if(strcmp(products[i].fornecedor,(*p).fornecedor)==0) {
					produto_printProduct(first, &products[i]);
					if(first) {
						first=0;
					}
				}
			}
			printf("Voltar ao menu [PRESS 9]: "); //Err
			scanf("%i", &wait);
			break;
	}
}
