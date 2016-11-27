## Armazenamento de dados
O sistema deve armazenar os produtos cadastrados para alterações e consultas futuras, fazendo a persistência de dados dos produtos.

Foi definida uma estruturação dos dados dos produtos, armazenados no caminho **./data/produto.txt**. A manipulação dos arquivos de dados é feito pelas rotinas de **produtoDAO.c**.

### produto.txt
Armazena, de forma estruturada, as informações dos produtos cadastrados. A estrutura de armazenamento segue o seguinte padrão:
```
  id:categoria:codigo:preco:descricao:fornecedor:d_vencimento:m_vencimento:a_vencimento:corredor:prateleira:quantidade:
```
Cada linha do arquivo possui dados de apenas **um** produto. O delimitador **:** indica a separação entre informações e final da linha.

### id_count.txt
O arquivo **id_count.txt** armazena o valor de _id_ do último próduto cadastrado. A criação desta persistência economiza processamento, visto que não se torna necessária uma leitura completa do arquivo **produto.txt** para identificar o último id utilizado. Além idsso, é convencional a definição de um método rápido como o tal para obtenção desta informação.
