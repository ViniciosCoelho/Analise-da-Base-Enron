#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <exception>
#include "Lista.h"
# define INFINITO 9999999

struct linhaGrau
{
	int vert;
	int adjs;
};

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
private:
	bool **geraMatrizBinaria();
	template<typename type>type **geraMatrizTam(type elemento);
	int **matrizCaminhosPossiveis(int dist);
public:
	Grafo(int numVert);
	~Grafo();

	void cria_adjacencia(int i, int j, int P);  // cria uma adjacência entre i e j com custo P no grafo G;
	void remove_adjacencia(int i, int j);  // remove a adjacência entre i e j no grafo G;
	void imprime_adjacencias();  // imprime a matriz de adjacências do grafo G
	void seta_informacao(int i, std::string V);  // atualiza a informação do nó i com o valor V (que deve ser uma string) no grafo G
	int numero_adjacentes(int i);
	int *adjacentes(int i);

	//Funções auxiliares
	bool Grafo::existe_vertice_visitados(std::vector<int> vetor_vertices, int vert);

	//funções do Trabalho
	int num_vertices();		// 2) a.
	int num_arestas();		// 2) b.
	std::vector<std::pair<int, int>> maior_grau_saida(); // 2) c.
	std::vector<std::pair<int, int>> maior_grau_entrada(); // 2) d.
	bool Grafo::depth_search(int X, int Y, int &count, std::vector<int> & Visitados); // 3)
	bool Grafo::breadth_search_iterative(int Y, std::vector<int>& Visitados, std::queue<int> Q); // 4)
	std::vector<int> vertices_distantes(int vertice, int distancia); // 5)
};