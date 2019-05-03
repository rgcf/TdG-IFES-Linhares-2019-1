#ifndef LISTA
#define LISTA

/* define o tipo nó do grafo, que é o próprio grafo*/
typedef struct no 
{	
	int info;
	int nohLigado;
	float custo;
	int numLig;
	struct no *prox; //ponteiro para o próximo nó da lista 
	struct no *adj; //lista de nós adjacentes  
}nohLista;

FILE *fp; //cria um ponteiro para o arquivo de dados 

nohLista *listaAdj;//, *noh;
nohLista *listaPrin, *listaPrinAux;

int tipoGrafo, numNohs, nohOrig, nohDest, no;

// função de inicialização: retorna uma lista vazia
nohLista* inicializarLista(void);

// insere um novo elemento na lista
nohLista* inserirNaLista(nohLista* l, int info, float custo);

//retorna o numero de elementos da lista
int numElementosLista(nohLista *l);

// testa se a lista está vazia
int vazia (nohLista* l);

//busca um elemento na lista
nohLista* busca (nohLista* l, int dado);

//imprime uma lista passada por parâmetro
void imprimirLista(nohLista* lista);

// função retira: retira elemento v passado como parâmetro da lista
nohLista* retirarDaLista(nohLista* l, int dado); 

// libera a memória alocada
void liberarLista (nohLista* l); 

// imprime o vetor de listas (grafo)
void imprimirVetLista(nohLista vet[5]);

// faz a leitura das nós do arquivo de entrada
void lerArqNumNohs();

// faz a leitura das arestas do arquivo de entrada
void lerArqNumArestas();


int verificaVetor(int *vetor, int noh);
// funções para grafos

// testar se existe caminho entre quaisquer dois vértices de G
int testarConexidade(nohLista* l);
// 0 se o grau do vértice é par e 1 se o grau for ímpar
int testarGrauVertice(nohLista *li, int vertice);
#endif
