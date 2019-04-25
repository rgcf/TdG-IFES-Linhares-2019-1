/*
    Implementação de um grafo através de lista de adjacência 
    Professor: Carlos Jones Rebello Junior
    Disciplina: Teoria dos Grafos
    Engenharia da Controle e Automação - Ifes campus Linhares
    Última atualização: 07/03/2019
*/


//--------------------------INCLUSÃO DE BIBLIOTECAS---------------------------//
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "lista.h"
//----------------------------------------------------------------------------//

//--------------------------IMPLEMENTAÇÃO DAS FUNÇÕES-------------------------//

	
/*	
//imprime uma lista adjacente (listaA) passada como parâmetro
void imprimirGrafo(nohLista* listaA, nohLista* listaPrin)
{
  //  lista = lista->prox;numNohs
    int numElem=0;

    printf("\n");
    printf("Noh %d:",listaPrin->info);
    while(listaA) // enquanto != NULL
    {
        printf("\t%d\t", listaA->info);
    	printf("\n");
    	
        listaA = listaA->prox;
		numElem++;
    }
  //  no++;

    if(numElem==0)
    {
        printf("Lista vazia!");
    }
 //   printf("\n");
 	listaPrin = listaPrin->prox;
}
*/

