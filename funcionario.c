#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "funcionario.h"

/*
 * Project: Bodega do IMD. Grupo 13
 * File: funcionario.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: Funcionario function 14/11/2016
 * Issues: NO
 */

void funcionario_menu() {
  int ch;
  while(1) {
    system("clear");
    printf("MENU DE FUNCIONÁRIO\n");
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

        scanf("%i\n", &ch); //Retirar isso
        break;
      case 3:
        ch = 0;
        funcionario_new_product();
        //scanf("%i", &ch); //Retirar isso
        break;
    }


  }


}

void funcionario_new_product() {
  Produto p;
  system("clear");
  printf("CADASTRO DE NOVO PRODUTO\n");
  printf("Código: ");
  scanf("%i", &p.codigo);
  printf("Descricão: ");
  scanf("%s", p.descricao);
  setbuf(stdin, NULL);
  printf("Fornecedor: ");
  scanf("%s", p.fornecedor);
  setbuf(stdin, NULL);
  int tmp_category;
  char confirm;
  printf("[1. Limpeza]\n[2. Alimento perecível]\n[3. Alimento não perecível]\n[4. Equipamento eletrônico]\nCategoria: ");
  scanf("%i", &tmp_category);
  switch (tmp_category) {
    case 1:
      p.categoria = LIMPEZA;
      break;
    case 2:
      p.categoria = PERECIVEL;
      break;
    case 3:
      p.categoria = N_PERECIVEL;
      break;
    case 4:
      p.categoria = ELETRONICO;
      break;
    default:
      p.categoria = ELETRONICO;
      break;
  }
  if(tmp_category==PERECIVEL) {
    printf("[DD-mm-yyyy] Dia de Validade: ");
    scanf("%i", &p.validade.dia);
    printf("[dd-MM-yyyy] Mês de Validade: ");
    scanf("%i", &p.validade.mes);
    printf("[dd-mm-YYYY] Ano de Validade: ");
    scanf("%i", &p.validade.ano);
  } else {
    p.validade.dia = 0;
    p.validade.mes = 0;
    p.validade.ano = 0;
  }
  printf("Quantidade: ");
  scanf("%i", &p.quantidade);
  printf("Preço: ");
  scanf("%lf", &p.preco);
  printf("Localização [corredor]: ");
  scanf("%i", &p.localizacao.corredor);
  printf("Localização [prateleira]: ");
  scanf("%i", &p.localizacao.prateleira);

  produto_newProduct(&p);
  // printf("Confirmar cadastramento? [Y/n]: ");
  // scanf("%c", &confirm);
  // if(confirm != 'n') {
  //   produto_newProduct(&p);
  // }
}
