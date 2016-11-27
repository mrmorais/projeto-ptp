/**
 * @file carrinho.c
 * @author Maradona Morais
 * @date 26 Nov 2016
 * @brief Rotinas de interação com o Carrinho
 */

#include "produto.h"
#include "carrinho.h"
#include <stdio.h>

/**
 * @brief Adiciona produto ao Carrinho
 *
 * Esta função adiciona no Carrinho cart a referência para o Produto p. <br>
 * Este produto é inserido na posição @p next_index (que é posteriormente incrementada
 * em uma unidade) do @p products[] na Struct Carrinho.
 *
 * @param *cart Ponteiro para o carrinho de produtos, no qual o produto deve ser inserido.
 * @param *p Ponteiro para o produto que deve ser anexado ao final do array de produtos do @p *cart
 */
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

/**
  * @brief Calcula o valor total da compra
  *
  * Retorna a soma da quantidade de todos os produtos multiplicado por seus respectivos
  * preços.
  *
  * @param *cart Referência do carrinho que deve ter total de compra calculado.
  */
double carrinho_totalPrice(Carrinho *cart) {
  double total_price = 0; int i;
  for (i = 0; i < (*cart).next_index; i++) {
    total_price += (*cart).products[i].preco * (*cart).products[i].quantidade;
  }
  return total_price;
}

/**
 * @brief Imprime todos os produtos e o total à pagar
 *
 * Esta rotina @c void imprime, na saída padrão, as informações de cada produto
 * adicionado ao carrinho. E, por fim, imprime o preço total a ser pago, calculado por
 * carrinho_totalPrice(Carrinho *cart).
 *
 * @param *cart Referência do carrinho que deve ter os produtos impressos.
 */
void carrinho_listCart(Carrinho *cart) {
  int i, first=1;
  double total_price = 0;
  for(i=0; i<(*cart).next_index; i++) {
    produto_printProduct(first, &(*cart).products[i]);
    total_price += (*cart).products[i].preco * (*cart).products[i].quantidade;
  }
  printf("TOTAL À PAGAR: R$ %.2f \n", carrinho_totalPrice(cart));
}

/**
 * @brief Limpa todos os produtos do carrinho.
 *
 * Rotina limpa todos os produtos já cadastrados e reseta o atributo @p next_index do @p cart.
 *
 * @param *cart Referência ao carrinho que deve ter todos os produtos apagados.
 */
void carrinho_clearCart(Carrinho *cart) {
  int i;
  Produto empty;
  for (i = 0; i<MAX_PRODUCTS; i++) {
    (*cart).products[i] = empty;
  }
  (*cart).next_index = 0;
}
