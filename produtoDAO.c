#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#define PATH "./data/produto.txt"
#define MAX_LIN 26 //Máxima quantidade de linhas no arquivo
#define MAX_COL 255 //Máxima quantidade de colunas por linha

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

void setProdutos(char tupla[MAX_LIN][MAX_COL], Produto produto[MAX_LIN]) {
  int i, j;
  for(i=0; i < MAX_LIN; i++) {
    Produto p;
    int posicao = 0, k = 0;
    char info[65] = "";
    for(j=0; j < strlen(tupla[i]); j++) {
      if(tupla[i][j] == ':') { // ":" é o delimitador no arquivo produto.txt
        k = 0;
        switch (posicao) {
          case 0: //ID
            p.id = atoi(info);
            break;
          case 1: //Categoria
            p.categoria = atoi(info);
            break;
          case 2: //Código
            p.codigo = atoi(info);
            break;
          case 3: //Preço
            p.preco = atof(info);
            break;
          case 4: //Descricao
            strcpy(p.descricao, info);
            break;
          case 5: //Fornecedor
            strcpy(p.fornecedor, info);
            break;
          case 6: //Dia validade
            p.validade.dia = atoi(info);
            break;
          case 7: //Mes validade
            p.validade.mes = atoi(info);
            break;
          case 8: //Ano validade
            p.validade.ano = atoi(info);
            break;
          case 9: //Corredor
            p.localizacao.corredor = atoi(info);
            break;
          case 10: //Prateleira
            p.localizacao.prateleira = atoi(info);
            break;
        }
        //reset info - rever como fazer isso usando o strcpy
        int l;
        for (l=0; l<65; l++) {
          info[l] = 0;
        }
        printf("\n%s\n", info);
        posicao++;
      } else {
        info[k++] = tupla[i][j];
      }
    }
  }
}

int main() {
  char tupla[MAX_LIN][MAX_COL];
  readFile(tupla);

  Produto produto[MAX_LIN];
  setProdutos(tupla, produto);
}
