#ifndef _PRODUTO_H_
#define _PRODUTO_H_

/** @brief Estrutura que indica localização de um produto */
struct Localizacao {
	int corredor; //!< Corredor em que o produto se localiza
	int prateleira; //!< Prateleira em que o produto se localiza
};

/** @brief Estrutura simples de data gregoriana */
struct Data {
	int dia; //!< Dia do mês [1-31]
	int mes; //!< Mês do ano [1-12]
	int ano; //!< Ano do calendário gregoriano
};

/** @brief Estrutura de classe Produto
 */
typedef struct Produto {
	int id; //!< Código de identificação do produto
	enum categoria{ LIMPEZA=1, //!< Produtos de Limpeza
				 PERECIVEL, //!< Alimentos perecíveis (com validade)
				 N_PERECIVEL, //!< Alimentos não perecíveis
				 ELETRONICO //!< Equipamentos eletrônicos
			 } categoria; //!< Categoria do produto
	int codigo; //!< Código de referência do produto
	double preco; //!< Preço do produto
	char descricao[255]; //!< Nome do produto
	char fornecedor[255]; //!< Fornecedor do produto
	/** @brief Validade (produtos perecíveis)
	*
	* Somente os produtos com Produto::categoria N_PERECIVEL recebem uma data de
	* validade. Os restantes possuem a atribuição
	* @code
	* p.validade.dia = 0;
	* p.validade.mes = 0;
	* p.validade.ano = 0;
	* @endcode
	*/
	struct Data validade;
	struct Localizacao localizacao; //!< Localização do produto
	int quantidade; //!< Número de produtos em estoque
} Produto;

int produto_newProduct(Produto *p);
void produto_getProductById(int id, Produto* p);
void produto_updateProduct(int id, Produto *p);
void produto_printProduct(int first, Produto *p);
void produto_searchProduct(int search_type, Produto *p);

#endif
