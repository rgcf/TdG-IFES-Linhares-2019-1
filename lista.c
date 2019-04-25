/*
    Implementa��o de um grafo atrav�s de lista de adjac�ncia 
    Professor: Carlos Jones Rebello Junior
    Disciplina: Teoria dos Grafos
    Engenharia da Controle e Automa��o - Ifes campus Linhares
    �ltima atualiza��o: 07/03/2019
*/


//--------------------------INCLUS�O DE BIBLIOTECAS---------------------------//
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//#include "grafo.h"
//----------------------------------------------------------------------------//

//--------------------------IMPLEMENTA��O DAS FUN��ES-------------------------//

// fun��o de inicializa��o: retorna uma lista vazia
nohLista* inicializarLista(void)
{
	//printf("lista inicializada!!!\n");
   return NULL;
}


// insere um novo elemento na lista
nohLista* inserirNaLista(nohLista* l, int info, float custo)
{
    nohLista *novo = (nohLista*) malloc(sizeof(nohLista));
    novo->info = info ;   
    novo->custo = custo;
    novo->prox = l;

    return novo;   
} 


//retorna o numero de elementos da lista
int numElementosLista(nohLista *l)
{
	int num=0;
	while(l) // enquanto n�o for NULL
	{
		num++;
		l = l->prox;
	}
	return num;
} 


// fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia 
int vazia (nohLista* l)
{
	if (l == NULL)
	{
		return 1;
	}	
	else
	{
		return 0;
	}
	
	//pode ser escrita de forma enxuta como abaixo
	//return (l == NULL);
}
	
	
// fun��o busca: busca um elemento na lista 
nohLista* busca (nohLista* l, int dado)
{
	nohLista *p;
	for (p=l; p!=NULL; p=p->prox)
	{
		if (p->info == dado)
		{	
			return p;
		}
	}
	return NULL; //n�o achou o elemento
}	
	
	
//imprime uma lista passada por par�metro
void imprimirLista(nohLista* lista)
{
    int numElem=0;

    printf("\n");

    while(lista) // enquanto != NULL
    {
        printf("\t%d\t", lista->info);
    	printf("\n");
    	
        lista = lista->prox;
		numElem++;
    }

    if(numElem==0)
    {
        printf("Lista vazia!");
    }
}


// fun��o retira um elemento da lista
nohLista* retirarDaLista(nohLista* l, int dado) 
{
	nohLista* ant = NULL; // ponteiro para o elemento anterior
	nohLista* p = l; //ponteiro que percorre a lista

	// procura elemento na lista, guardando anterior 
	while (p != NULL && p->info != dado) 
	{
		ant = p;
		p = p->prox;
	}
	
	// verifica se achou elemento 
	if (p == NULL)
	{
		printf("p==NULL\n");
		return l; // n�o achou: retorna lista original
	}
	
	// retira o primeiro elemento da lista, se ant � NULL, ent�o o ponteiro n�o andou na lista
	if (ant == NULL) 
	{
		// retira elemento do inicio
		l = p->prox;
	}
	
	// caso o ponteiro tenha andado e n�o estamos mais no primeiro elemento da lista...
	else 
	{
		// retira elemento do meio da lista
		ant->prox = p->prox;
	}

	free(p);

	return l;
}



// fun��o libera a lista 
void liberarLista (nohLista *l)  // l � o cabe�alho da lista
{
    nohLista *p = l, *t;
    
	while (p != NULL) 
	{
		t = p->prox; // guarda refer�ncia para o pr�ximo elemento
		printf("liberando noh: %d\n", p->info);
		free(p);
		// libera a mem�ria apontada por p
		p = t;
		// faz p apontar para o pr�ximo
	}
}


void lerArqNumNohs()
{
  //  FILE *fp; //cria um ponteiro para o arquivo de dados 

    fp=fopen("grafo2.dat","rt");// abre o arquivo para leitura
    
    
    if (!fp)
    {
        printf("Erro!!! Arquivo nao encontrado!");
    }
    
    else
    {
    	 	
    	//l� no arquivo o tipo de grafo
       	fscanf(fp,"%d",&tipoGrafo);
    	printf("tipo de grafo: %d\n", tipoGrafo);
    	
    	//l� no arquivo o num de nohs do grafo
    	fscanf(fp,"%d",&numNohs);
    	printf("numNohs: %d\n",numNohs);
	}
    
    
//	fclose(fp);  // fecha o arquivo ap�s o t�rmino do seu uso
}   

// n�o vou ler todo o arquivo novamente porque o ponteiro j� est� posicionado corretamente no arquivo (lerArqNumNohs()), visto que, ainda n�o foi
// liberada a mem�ria
void lerArqNumArestas()
{
	// vari�vel que recebe 0 para ler a origem e 1 para ler o destino
	int trocar=0;
	// vari�vel que controla a cria��o da lista de adjac�ncia
	int criar=0;
	
	int manterLeitura=0;

	//listaAdj = inicializarLista();
	//listaPrinAux= listaPrinAux->prox;

    while(!feof(fp))
    {
    	if(manterLeitura==0)
    	{
			// armazena o n� origem
		  	if(trocar == 0)
		  	{
		  		// l� a origem e o destino do noh e armazena
		    	fscanf(fp,"%d",&nohOrig); 
		    	trocar=1;
		    	
		    	//printf("nohOrig: %d -- ",nohOrig);
		  	}
		  	// armazena o n� destino
		  	else if(trocar == 1)
		  	{
		  		// l� a origem e o destino do noh e armazena
		    	fscanf(fp,"%d",&nohDest); 
		    	trocar=2;
		    	
		    	//printf("nohDest: %d\n",nohDest);
		  	}
		}
      	
      	if(trocar == 2)
      	{

	  		 // se o n� de origem recebido for igual o ao n� atual na lista principal...
	  		 if(nohOrig == listaPrinAux->info)
	  		 {
	  		 	if(criar==0)
	  		 	{
	  		 		listaAdj = inicializarLista();
	  		 		criar++;
	  		 	}
	  		 	
	  		 	listaAdj = inserirNaLista(listaAdj, nohDest, nohOrig);
	  	     	listaPrinAux->adj = listaAdj;
				// listaPrinAux->nohLigado = 1;
				listaPrinAux->numLig++;
	  	     	trocar=0;
	  	     	manterLeitura=0;
	  	     }
	  	     // se n�o for precisamos andar na lista
	  	     else 
	  	     {
	  	        // pula para o pr�ximo n� da lista
	  	     	listaPrinAux = listaPrinAux->prox;
	  	     	criar=0;
	  	     	//printf("nao\n");
	  	     	manterLeitura++;
	  	     }
      	}

  
    }
        
    fclose(fp);  // fecha o arquivo ap�s o t�rmino do seu uso
}

//Para ligações não direcionadas easy way
int testarConexidade(nohLista* l) 
{
	if (!(l->adj))
			return 0;
	while (l)
	{
		if (!(l->adj))
			return 0;
		l = l->prox;
	}
	return 1;	
}
//Fazendo a busca em profundidade de verdade... hard game....
int testarConexidadeHard(nohLista* l) 
{
	int i, v = 0;
	int *vetVertices = (int *) malloc(numNohs * sizeof(int));
	nohLista *aux, *auxPos;
	//Se o nó inicial não possuir nenhuma ligação então ele já retorna que não é conexo
	if (!(l->adj))
			return 0;
	
	vetVertices[v] = l -> info;
	auxPos = aux = l;

	while (auxPos)
	{
		while (aux)
		{
			v++;
			for (i = 0; i < numNohs; i++)
			{
				if (vetVertices[i] == aux->info) //Verifica se o vértice já existe no vetor
					break;

				if (!(vetVertices[i])) //Caso o vetor atinja o valor nulo ele recebe o vértice e encerra o for
				{
					vetVertices[i] = aux->info;
					break;
				}
			}

			aux = aux->nohLigado;
		}
		aux = auxPos;
	}

	return 1;	

	
}

int testarGrauVertice(nohLista *li, int vertice)
{
	if (li->info != vertice) 
		li = busca(li, vertice);
	
	if (li->numLig % 2)
		return 1;
	else
		return 0;
}

