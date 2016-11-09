## Produto

### Atributos
int **id** número de identificação de acordo com o cadastro

enum **categoria** valor nas opções LIMPEZA, PERECIVEL, N_PERECIVEL, ELETRONICO

char[5] **codigo** codigo de cadastramento

double **preco** valor de venda do produto

char[255] **descricao** título do produto

char[65] **fornecedor** nome do fornecedor

struct Data **validade** data de validade do produto

struct Localizacao **localizacao** do produto

#### struct Data
int **dia**

int **mes**

int **ano**

#### struct Localizacao
int **corredor**

int **prateleira**
