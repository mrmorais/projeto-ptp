#include <stdio.h>

/*
 * Project: Bodega do IMD. Grupo 13
 * File: consumidor.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: Consumidor function 13/11/2016
 * Issues: NO
 */

void consumidor_menu() {
  int ch;
  while(1) {
    system("clear");
    printf("MENU DE CONSUMIDOR\n");
    printf("1 - Listar produtos\n");
    printf("2 - Buscar produto\n");
    printf("3 - Cadastrar novo produto\n");
    printf("4 - Reposição de Estoque\n");
    printf("0 - Voltar\n\n");
    scanf("%d", &ch);

    if(ch == 0) {
      break;
    }

    switch (ch) {
      case 1:
        ch = 0;
        system("clear");
        printf("Listando os produtos...\n");

        scanf("%i\n", &ch);
        break;
    }


  }


}
