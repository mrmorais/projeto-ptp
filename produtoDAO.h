#ifndef _PRODUTODAO_H_
#define _PRODUTODAO_H_
#define PRODUTO_TXT "./data/produto.txt"
#define ID_COUNT_TXT "./data/id_count.txt"
#define MAX_LIN 26 //Máxima quantidade de linhas no arquivo
#define MAX_COL 255 //Máxima quantidade de colunas por linha

void dao_readFile(char tupla[MAX_LIN][MAX_COL]);
void dao_setProdutos(char tupla[MAX_LIN][MAX_COL], Produto produto[MAX_LIN]);
int dao_putProduto(Produto *p);
int dao_getNextId();
void dao_updateProduct(int id, Produto* p);
void dao_getProductById(int id, Produto* p);

#endif
