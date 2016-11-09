#ifndef _PRODUTO_H_
#define _PRODUTO_H_

struct Localizacao {
	int corredor;
	int prateleira;
};

struct Data {
	int dia;
	int mes;
	int ano;
};

typedef struct Produto {
	enum { LIMPEZA, PERECIVEL, N_PERECIVEL, ELETRONICO } categoria;
	int codigo;
	double preco;
	char descricao[255];
	char fornecedor[255];
	struct Data validade;
	struct Localizacao localizacao;
} Produto;

int newProduct(Produto *p);
Produto getProduct(int id);

#endif
