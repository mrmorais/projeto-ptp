#include <stdio.h>
#include "consumidor.h"
/*
 * Project: Bodega do IMD. Grupo 13
 * File: consumidor.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: Consumidor function 13/11/2016
 * Issues: NO
 */

void consumidor_menu() {
  int ch = 1;
  do {
    system("clear");
    printf("MENU DE CONSUMIDOR\n");
    printf("1 - Listar produtos\n");
    printf("2 - Buscar produto\n");
    printf("3 - Ver carrinho\n");
    printf("4 - Limpar carrinho\n");
    printf("5 - Finalizar compra\n");
    printf("0 - Voltar\n\n");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        menu_list_products();
        break;
      case 2:
        menu_search_products();
        break;
    }
  } while(ch);
}
