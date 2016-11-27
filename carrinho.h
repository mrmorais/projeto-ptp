#ifndef _CARRINHO_H_
#define _CARRINHO_H_
#define MAX_PRODUCTS 100

/** @brief Estrutura de compra */
typedef struct Carrinho {
  Produto products[MAX_PRODUCTS]; //!< Array de estruturas do tipo Produto
  int next_index; //!< Valor correspondente ao próximo index do @p products
} Carrinho;

void carrinho_addProduct(Carrinho *cart, Produto *p);
double carrinho_totalPrice(Carrinho *cart);
void carrinho_listCart(Carrinho *cart);
void carrinho_clearCart(Carrinho *cart);

#endif
