#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#define PATH "./data/produto.txt"
#define MAX_LIN 26 //Máxima quantidade de linhas no arquivo
#define MAX_COL 255 //Máxima quantidade de colunas por linha



void getProducts(char produto[MAX_LIN]) {
  FILE *arquivo;
  arquivo = fopen(PATH, "r");
  char ch;
  char linha[MAX_LIN][MAX_COL];
  int lin = 0, col = 0;
  while((ch=fgetc(arquivo)) != EOF) {
    linha[lin][col++] = ch;
    if(ch == '\n') {
      lin++;
      col=0;
    }
  }
  fclose(arquivo);

}

void readFile(char tupla[MAX_LIN][MAX_COL]) {
  FILE *arquivo;
  arquivo = fopen(PATH, "r");
  char ch;
  int lin = 0, col = 0;
  while((ch=fgetc(arquivo)) != EOF) {
    tupla[lin][col++] = ch;
    if(ch == '\n') {
      lin++;
      col=0;
    }
  }
  fclose(arquivo);
}

int main() {
  //char tupla[MAX_LIN];
  //readProdutos(tupla);
  //printf("%s\n", tupla[0]);
}
