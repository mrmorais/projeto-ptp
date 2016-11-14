#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "funcionario.h"
#include "consumidor.h"

/*
 * Project: Bodega do IMD. Grupo 13
 * File: main.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: Main function 14/11/2016
 * Issues: NO
 */

/* Quando eu escrevi isso, só Deus e eu sabíamos o que eu estava fazendo
 * Agora só Deus sabe */

int main() {
  int ch;
  while(1) {
    system("clear");
    printf("BODEGA DO IMD\n");
    printf("Por favor, selecione uma opção:\n");
    printf("1 - Funcionário\n");
    printf("2 - Consumidor\n");
    printf("0 - Sair\n\n");
    scanf("%d", &ch);

    if(ch == 0) {
      break;
    }

    switch (ch) {
      case 1:
        ch = 0;
        funcionario_menu();
        break;
      case 2:
        ch = 0;
        consumidor_menu();
        break;
    }

  }
}
