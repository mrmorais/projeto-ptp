#ifndef _CONSUMIDOR_H_
#define _CONSUMIDOR_H_
#define MAX_PRODUCTS 100
#include "produto.h"
#include "menus_comuns.h"

typedef struct Carrinho {
  Produto products[MAX_PRODUCTS];
} Carrinho;

void consumidor_menu();
#endif
