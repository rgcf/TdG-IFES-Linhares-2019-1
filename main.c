/*
    Implementa��o de um grafo atrav�s de lista de adjac�ncia 
    Professor: Carlos Jones Rebello Junior
    Disciplina: Teoria dos Grafos
    Engenharia da Controle e Automa��o - Ifes campus Linhares
*/


//--------------------------INCLUS�O DE BIBLIOTECAS---------------------------//
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//#include "grafo.h"

//----------------------------------------------------------------------------//

int main ()
{
	unsigned int i=1;
	int ehConexo=0;
	
	// inicializa a lista principal
	listaPrin = inicializarLista();
	
	listaPrinAux = listaPrin;
	 
	// l� no arquivo o tipo de grafo e o n�mero de n�s 
	lerArqNumNohs();
	
	// insere os n�s na lista principal
	while(i<=numNohs)
	{
		// insere o primeiro elemento na lista
		listaPrin = inserirNaLista(listaPrin, i, 0.0);
		i++;		
	}
	listaPrinAux = listaPrin;
	printf("Numero de elementos da lista: %d\n", numElementosLista(listaPrin));

	
	// inserindo a liga��es da listaAdj
	lerArqNumArestas();
		
	listaPrinAux = listaPrin;
		
//	imprimirGrafo(listaPrinAux, listaPrin);	
		
	for(int i=1; i<=numNohs; i++)
	{
		
		imprimirLista(listaPrinAux->adj);
		listaPrinAux=listaPrinAux->prox;
	}

	
	// 0 se n�o for conexo e 1 se for
	//	ehConexo = testarCoxidade(listaPrinAux);		
	return 0;
}  	
