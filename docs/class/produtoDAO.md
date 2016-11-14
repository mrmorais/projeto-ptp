## ProdutoDAO.c
Rotinas para manipulações de arquivos **./data/produto.txt** e **./data/count_id.txt**

### Rotinas

#### void dao_readFile(char tupla[MAX_LIN][MAX_COL]);
Recebe:
* matriz vazia de _char_ **tupla[MAX_LIN][MAX_COL]**

Esta rotina lê o diretamente o arquivo **produto.txt** e insere as informações na **tupla**. Aqui não é feita a estruturação das dados como produto, somente é feita a leitura do arquivo. O primeiro índice até **MAX_LIN** indica a quantidade máxima de linhas a serem lidas, atualmente definida em **26**. O segundo índice até **MAX_COL** indica a quantidade máxima de caracteres a serem lidos, setado em **255**.

A leitura do arquivo é passada para a matriz **tupla** de forma que cada **tupla[i]** é uma linha do arquivo **produto.txt**.

#### void dao_setProdutos(char tupla[MAX_LIN][MAX_COL], Produto produto[MAX_LIN]);
Recebe:

* a matriz **tupla[MAX_LIN][MAX_COL]**, que já foi preenchida na rotina **dao_readFile** com os dados do arquivo **produto.txt**.
* o vetor vazio de _Produto_ **produto[MAX_LIN]**

Esta rotina faz a leitura de cada linha de **tupla** e faz a estruturação de tais linhas como _Produto_. Para isso é feita a leitura observando as ocorrências do delimitador **:**, como explicado em **data_storage.md** desta DOC.

#### int dao_putProduto(Produto \*p);
Recebe:
* o ponteiro **\*p** para um _Produto_

Esta rotina escreve no final do arquivo **produto.txt** as informações de um novo produto, obedecendo a estrutura de dados de Produto (ver **data_storage.md** desta DOC).

#### int dao_getNextId();

Faz a leitura do arquivo **id_count.txt** e retorna o ID do útimo produto cadastrado. Além disso incrementa o valor no arquivo citado. Para entender a utilidade deste mecanismo ver **data_storage.md**
