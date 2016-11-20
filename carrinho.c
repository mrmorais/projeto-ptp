#include "produto.h"
#include "carrinho.h"
#include <stdio.h>

void carrinho_addProduct(Carrinho *cart, Produto *p) {
  Produto tmp_p;
  produto_getProductById((*p).id, &tmp_p);
  if(tmp_p.id == 0) {
    printf("Não existe um produto com este ID\n");
  } else {
    if(tmp_p.quantidade >= (*p).quantidade) {
      tmp_p.quantidade -= (*p).quantidade;
      produto_updateProduct(tmp_p.id, &tmp_p);
      tmp_p.quantidade = (*p).quantidade;
      (*cart).products[(*cart).next_index++] = tmp_p;
      printf("%i x %s Adicionado(s) com sucesso\n", tmp_p.quantidade, tmp_p.descricao);
    } else {
      printf("A quantidade desejada é maior que a existente\n");
    }
  }
}

void carrinho_listCart(Carrinho *cart) {
  int i, first=1;
  double total_price = 0;
  for(i=0; i<(*cart).next_index; i++) {
    produto_printProduct(first, &(*cart).products[i]);
    total_price += (*cart).products[i].preco * (*cart).products[i].quantidade;
  }
  printf("TOTAL À PAGAR: R$ %.2f \n", total_price);
}
