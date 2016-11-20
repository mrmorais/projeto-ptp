#include <stdio.h>
#include "consumidor.h"
#include "carrinho.h"
/*
 * Project: Bodega do IMD. Grupo 13
 * File: consumidor.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: Consumidor function 13/11/2016
 * Issues: NO
 */

Carrinho cart;

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
    }
  } while(ch);
}

void consumidor_add_to_cart() {
  system("clear");
  Produto p;
  printf("ADICIONAR AO CARRINHO\n");
  printf("ID do Produto: ");
  scanf("%i", &p.id);
  printf("Quantidade: ");
  scanf("%i", &p.quantidade);

  carrinho_addProduct(&cart, &p);

  int wait;
  printf("Voltar ao menu [PRESS 9]: "); //Err
  scanf("%i", &wait);
}

void consumidor_list_cart() {
  system("clear");
  printf("VER CARRINHO\n");
  carrinho_listCart(&cart);

  int wait;
  printf("Voltar ao menu [PRESS 9]: "); //Err
  scanf("%i", &wait);
}
