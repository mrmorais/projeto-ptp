/**
 * @file produto.c
 * @author Maradona Morais
 * @date 26 Nov 2016
 * @brief Rotinas de interação com o Produto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtoDAO.h"
#include "produto.h"

/**
 * @brief Redireciona produto para persistência
 *
 * A rotina redireciona a referência de Produto para a produtoDAO
 * @param *p Ponteiro de Produto para redirecionamento
 * @return Retorna o ID (@c int) do produto persistido
 */
int produto_newProduct(Produto *p) {
	dao_putProduto(p);
}

/**
 * @brief Insere produtos da persistência de arquivos em um array de Produto
 *
 * Insere no @p products todos os produtos que são lidos no gerenciador de persistência
 * de produtos (produtoDAO)
 */
void produto_getAllProducts(Produto products[MAX_LIN]) {
	char buffer[MAX_LIN][MAX_COL];
	dao_readFile(buffer);
	dao_setProdutos(buffer, products);
	int i;
	for (i=0; i<MAX_LIN; i++) {
		if(products[i].id > dao_getNextId() || products[i].id < 0 || products[i].validade.mes > 12 || products[i].validade.mes < 0 || (int) products[i].preco <= 0) {
			products[i].id = 0;
		}
	}
}

/**
 * @brief Pega um produto pelo o ID
 */
void produto_getProductById(int id, Produto* p) {
	dao_getProductById(id, p);
}

/**
 * @brief Atualiza informações de um produto
 */
void produto_updateProduct(int id, Produto *p) {
	dao_updateProduct(id, p);
}

/**
 * @brief Imprime, formatadamente, as informações de um produto
 */
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

/**
 * @brief Busca produtos por tipo de pesquisa
 *
 * Faz uma leitura de produtos persistidos e seleciona os produtos com as
 * especificações dadas. Os tipos de busca, definidos em @c int @p search_type, são <br>
 *<table>
 * <tr><th>Tipo<th>Filtro em<th> Valor <th>Descrição
 * <tr><td> ID <td> p.id <td> 1 <td> Buscar produto por ID
 * <tr><td> Nome <td> p.descricao <td> 2 <td> Buscar produto por Nome
 * <tr><td> Fornecedor <td> p.fornecedor <td> 3 <td> Produtos de um fornecedor
 *</table>
 * O @b termo de busca vem determinado no parâmetro @p *p
 * @param search_type Critério de busca
 * @param *p Referência ao Produto com o termo de busca determinado
 */
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
			printf("[Enter] para voltar");
			getchar();
			getchar();
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
			printf("[Enter] para voltar");
			getchar();
			getchar();
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
