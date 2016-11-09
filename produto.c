#include <stdio.h>

struct Localizacao {
	int corredor;
	int prateleira;
};

struct Produto {
	enum { LIMPEZA, PERECIVEL, N_PERECIVEL, ELETRONICO } categoria;
	int codigo;
	double preco;
	char[255] descricao;
	char[65] fornecedor;
	
};