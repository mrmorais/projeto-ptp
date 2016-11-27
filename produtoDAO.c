/**
 * @file produtoDAO.c
 * @author Maradona Morais
 * @date 26 Nov 2016
 * @brief Manipulador de arquivos para persistência de Produto
 */

#include "produtoDAO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void dao_readFile(char buffer[MAX_LIN][MAX_COL]) {
  /* Isto é mágica. Não toque aqui. */
  FILE *arquivo;
  arquivo = fopen(PRODUTO_TXT, "r");
  char ch;
  int lin = 0, col = 0;
  while((ch=fgetc(arquivo)) != EOF) {
    buffer[lin][col++] = ch;
    if(ch == '\n') {
      lin++;
      col=0;
    }
  }
  fclose(arquivo);
}

void dao_writeFile(Produto products[MAX_LIN]) {
  FILE *arquivo;
  arquivo = fopen(PRODUTO_TXT, "w");
  int i;
  for(i=0; i<MAX_LIN; i++) {
    if(products[i].id != 0 && products[i].id < dao_getNextId()) {
      fprintf(arquivo, "%i:%i:%i:%.2f:%s:%s:%i:%i:%i:%i:%i:%i:\n",
              products[i].id,
              products[i].categoria,
              products[i].codigo,
              products[i].preco,
              products[i].descricao,
              products[i].fornecedor,
              products[i].validade.dia,
              products[i].validade.mes,
              products[i].validade.ano,
              products[i].localizacao.corredor,
              products[i].localizacao.prateleira,
              products[i].quantidade);
    }
  }
  fclose(arquivo);
}

void dao_setProdutos(char tupla[MAX_LIN][MAX_COL], Produto produto[MAX_LIN]) {
  int i, j;
  for(i=0; i < MAX_LIN; i++) {
    int posicao = 0, k = 0;
    char info[65] = "";
    for(j=0; j < strlen(tupla[i]); j++) {
      if(tupla[i][j] == ':') { // ":" é o delimitador no arquivo produto.txt
        k = 0;
        switch (posicao) {
          case 0: //ID
            produto[i].id = atoi(info);
            break;
          case 1: //Categoria
            produto[i].categoria = atoi(info);
            break;
          case 2: //Código
            produto[i].codigo = atoi(info);
            break;
          case 3: //Preço
            produto[i].preco = atof(info);
            break;
          case 4: //Descricao
            strcpy(produto[i].descricao, info);
            break;
          case 5: //Fornecedor
            strcpy(produto[i].fornecedor, info);
            break;
          case 6: //Dia validade
            produto[i].validade.dia = atoi(info);
            break;
          case 7: //Mes validade
            produto[i].validade.mes = atoi(info);
            break;
          case 8: //Ano validade
            produto[i].validade.ano = atoi(info);
            break;
          case 9: //Corredor
            produto[i].localizacao.corredor = atoi(info);
            break;
          case 10: //Prateleira
            produto[i].localizacao.prateleira = atoi(info);
            break;
          case 11: //Quantidade
            produto[i].quantidade = atoi(info);
            break;
        }

        // info[0] = '\0';
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

void dao_updateProduct(int id, Produto* p) {
  Produto products[MAX_LIN];
  produto_getAllProducts(products);

  int i;
  for(i=0; i<MAX_LIN; i++) {
    if(products[i].id == id) {
      products[i] = *p;
      break;
    }
  }

  dao_writeFile(products);
}

void dao_getProductById(int id, Produto *p) {
  (*p).id = 0;

  Produto products[MAX_LIN];
  produto_getAllProducts(products);

  int i;
  for(i=0; i<MAX_LIN; i++) {
    if(products[i].id == id) {
      *p = products[i];
      break;
    }
  }
}
