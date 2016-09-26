#pragma once

#include <iostream>
#include <iomanip>
#include "Lista.h"
# define INFINITO 9999999

class Vertice 
{
private:
	std::string nome;
public:
	Vertice();
	~Vertice();

	std::string retornaNome();
	void recebeNome(std::string V);
};

class Grafo
{
private:
	int tamanho;
	Lista *lista;
	Vertice *vertices;

public:
	Grafo(int numVert);
	~Grafo();

	void cria_adjacencia(int i, int j, int P);  // cria uma adjacência entre i e j com custo P no grafo G;
	void remove_adjacencia(int i, int j);  // remove a adjacência entre i e j no grafo G;
	void imprime_adjacencias();  // imprime a matriz de adjacências do grafo G
	void seta_informacao(int i, std::string V);  // atualiza a informação do nó i com o valor V (que deve ser uma string) no grafo G
	int adjacentes(int i,  int *adj);  // retorna o número de adjacentes ao vértice i no grafo G e os armazena no vetor adj

	//funções do Trabalho
	int num_vertices();		// 2) a.
	int num_arestas();		// 2) b.
	int maior_grau_saida();		// 2) c.
	int maior_grau_entrada();	// 2) d.
	Lista* depth_search(int X /* individuo origem */, int Y /* individuo destino */); // 3)
	Lista* width_search(int X /* individuo origem */, int Y /* individuo destino */); // 4)
	Lista* vertices_distantes(int distancia); // 5)


};