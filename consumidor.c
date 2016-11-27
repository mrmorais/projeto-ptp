/**
 * @file consumidor.c
 * @author Maradona Morais
 * @date 27 Nov 2016
 * @brief Menu para consumidor
 */

#include <stdio.h>
#include "consumidor.h"
#include "carrinho.h"

Carrinho cart; //!< variável de escopo global do consumidor

/**
 * @brief Menu principal do consumidor
 */
void consumidor_menu() {
  int ch = 1;
  do {
    system("clear");
    printf("MENU DE CONSUMIDOR\n");
    printf("1 - Listar produtos\n");
    printf("2 - Buscar produto\n");
    printf("3 - Adicionar ao carrinho\n");
    printf("4 - Ver carrinho\n");
    printf("5 - Limpar carrinho\n");
    printf("6 - Finalizar compra\n");
    printf("0 - Voltar\n\n");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        menu_list_products();
        break;
      case 2:
        menu_search_products();
        break;
      case 3:
        consumidor_add_to_cart();
        break;
      case 4:
        consumidor_list_cart();
        break;
      case 5:
        consumidor_clear_cart();
        break;
      case 6:
        consumidor_finish_shopping();
        break;
    }
  } while(ch);
}

/**
 * @brief Adiciona ao carrinho um produto pelo ID
 */
void consumidor_add_to_cart() {
  system("clear");
  Produto p;
  printf("ADICIONAR AO CARRINHO\n");
  printf("ID do Produto: ");
  scanf("%i", &p.id);
  printf("Quantidade: ");
  scanf("%i", &p.quantidade);

  carrinho_addProduct(&cart, &p);

  getchar();
  getchar();
}

/**
 * @brief Lista todos os produtos da compra
 */
void consumidor_list_cart() {
  system("clear");
  printf("VER CARRINHO\n");
  carrinho_listCart(&cart);

  printf("[Enter] para voltar");
  getchar();
  getchar();
}

/**
 * @brief Limpa todos os produtos do carrinho
 */
void consumidor_clear_cart() {
  system("clear");
  carrinho_clearCart(&cart);
  printf("CARRINHO LIMPO\n");

  printf("[Enter] para voltar");
  getchar();
  getchar();
}

/**
 * @brief Finaliza uma compra
 */
void consumidor_finish_shopping() {
  system("clear");
  printf("COMPRA FINALIZADA\n");
  printf("TOTAL À PAGAR: R$ %.2f\n", carrinho_totalPrice(&cart));
  carrinho_clearCart(&cart);

  printf("[Enter] para voltar");
  getchar();
  getchar();
}
