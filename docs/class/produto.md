## Produto

### Atributos

| Type     | Name     | Desc |
| :------------- | :------------- |:-------------|
|int|id|número de identificação de acordo com o cadastro|
|enum|categoria|valor nas opções LIMPEZA, PERECIVEL, N_PERECIVEL, ELETRONICO|
|int|codigo|código de cadastramento|
|double|preco|valor de venda do produto|
|char[255]|descricao|título do produto|
|char[65]|fornecedor|nome do fornecedor|
|struct Data|validade|data de validade do produto|
|struct Localizacao|localizacao|localizaçao do produto|
|int |quantidade|quantidade de produtos|


#### struct Data
| Type     | Name
| :------------- | :------------- |
|int|dia|
|int|mes|
|int|ano|

#### struct Localizacao
| Type     | Name
| :------------- | :------------- |
|int|corredor|
|int|prateleira|

### Rotinas
#### int produto_newProduct(Produto \*p);
Recebe:
* ponteiro **p** para um _Produto_

Repassa para o **produtoDAO.c** a referência de um produto para que seja grava em **produto.txt**.
