#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "produtoDAO.h"

/*
 * Project: Bodega do IMD. Grupo 13
 * File: produtoDAO.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: ProdutoDAO function 14/11/2016
 * DOC Url: https://github.com/mrmorais/projeto-ptp/blob/master/docs/class/produtoDAO.md
 * Issues: NO
 */

void dao_readFile(char tupla[MAX_LIN][MAX_COL]) {
  /* Isto é mágica. Não toque aqui. */
  FILE *arquivo;
  arquivo = fopen(PRODUTO_TXT, "r");
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

void dao_setProdutos(char tupla[MAX_LIN][MAX_COL], Produto produto[MAX_LIN]) {
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
          case 11: //Quantidade
            p.quantidade = atoi(info);
            break;
        }
        //reset info - rever como fazer isso usando o strcpy
        int l;
        for (l=0; l<65; l++) {
          info[l] = 0;
        }
        posicao++;
      } else {
        info[k++] = tupla[i][j];
      }
    }
  }
}

int dao_putProduto(Produto *p) {
  FILE *arquivo;
  arquivo = fopen(PRODUTO_TXT, "a+");
  (*p).id = dao_getNextId();
  fprintf(arquivo, "%i:%i:%i:%.2f:%s:%s:%i:%i:%i:%i:%i:%i:\n",
          (*p).id,
          (*p).categoria,
          (*p).codigo,
          (*p).preco,
          (*p).descricao,
          (*p).fornecedor,
          (*p).validade.dia,
          (*p).validade.mes,
          (*p).validade.ano,
          (*p).localizacao.corredor,
          (*p).localizacao.prateleira,
          (*p).quantidade);

  fclose(arquivo);
  return (*p).id;
}

int dao_getNextId() {
  FILE *arquivo;
  arquivo = fopen(ID_COUNT_TXT, "r");
  char last_id_str[11];
  int i = 0, last_id = 0;
  char ch;
  while((ch=fgetc(arquivo)) != EOF) {
    last_id_str[i] = ch;
    i++;
  }
  last_id = atoi(last_id_str);

  fclose(arquivo);
  arquivo = fopen(ID_COUNT_TXT, "w");

  int next_id = last_id+1;

  fprintf(arquivo, "%d\n", next_id);

  fclose(arquivo);

  return next_id;
}
