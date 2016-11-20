#ifndef _CARRINHO_H_
#define _CARRINHO_H_
#define MAX_PRODUCTS 100

typedef struct Carrinho {
  Produto products[MAX_PRODUCTS];
  int next_index;
} Carrinho;

void carrinho_addProduct(Carrinho *cart, Produto *p);
void carrinho_listCart(Carrinho *cart);

#endif
