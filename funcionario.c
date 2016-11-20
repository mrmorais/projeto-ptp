#include "funcionario.h"

/*
 * Project: Bodega do IMD. Grupo 13
 * File: funcionario.c
 * Programmer: Maradona Morais (mrmorais@gthb)
 * Commit Log: Funcionario function 14/11/2016
 * Issues: #1 #2
 */

void funcionario_menu() {
  int ch=1;

  do {
    system("clear");
    printf("MENU DE FUNCIONÁRIO\n");
    printf("1 - Listar produtos\n");
    printf("2 - Buscar produto\n");
    printf("3 - Cadastrar novo produto\n");
    printf("4 - Reposição de Estoque\n");
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
        funcionario_new_product();
        break;
      case 4:
        funcionario_stock_replace();
        break;
    }

  } while(ch);

}

void funcionario_new_product() {
  system("clear");
  Produto p;
  printf("CADASTRO DE NOVO PRODUTO\n");
  printf("Código: ");
  scanf("%i", &p.codigo);
  printf("Descricão: ");
  scanf("%s", p.descricao); //Issue #1
  setbuf(stdin, NULL);
  printf("Fornecedor: ");
  scanf("%s", p.fornecedor); //Issue #1
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

  //Issue #2
  produto_newProduct(&p);
}

void funcionario_stock_replace() {
  system("clear");
  int id;
  Produto p;
  printf("REPOSIÇÃO DE ESTOQUE\n");
  printf("ID do produto: ");
  scanf("%i", &id);
  produto_getProductById(id, &p);
  printf("Temos %i produto(s) %s em estoque\n", p.quantidade, p.descricao);
  printf("Insira o novo valor de quantidade: ");
  scanf("%i", &p.quantidade);
  produto_updateProduct(id, &p);
}
