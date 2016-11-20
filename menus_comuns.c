#include <stdio.h>
#include "produto.h"
#include "produtoDAO.h"
#include "menus_comuns.h"

void menu_search_products() {
  system("clear");
  printf("BUSCAR PRODUTO\n");
  printf("[1. Por ID]\n");
  printf("[2. Por Nome]\n");
  printf("[3. Por Fornecedor]\n");
  printf("Critério de busca: ");
  int ch;
  scanf("%i", &ch);

  Produto p;
  switch (ch) {
    case 1:
      printf("ID: ");
      scanf("%i", &p.id);
      produto_searchProduct(1, &p);
      break;
    case 2:
      printf("Nome: ");
      scanf("%s", p.descricao);
      produto_searchProduct(2, &p);
      break;
    case 3:
      printf("Fornecedor: ");
      scanf("%s", p.fornecedor);
      produto_searchProduct(3, &p);
      break;
  }
}

void menu_list_products() {
  system("clear");
  printf("LISTAGEM DE PRODUTOS\n");

  Produto products[MAX_LIN];
  produto_getAllProducts(products);
  int i;
  for(i=0; i<MAX_LIN-3; i++) {
    if(products[i].id != 0) {
      if(i==0) {
        produto_printProduct(1, &products[i]);
      } else {
        produto_printProduct(0, &products[i]);
      }
    }
  }

  printf("Voltar ao menu [PRESS 9]: "); //Err
  char go;
  scanf("%c\n", &go);
}
