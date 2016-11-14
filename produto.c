#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "produtoDAO.h"

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
