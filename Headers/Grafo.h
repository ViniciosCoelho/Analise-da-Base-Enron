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

	void cria_adjacencia(int i, int j, int P);  // cria uma adjac�ncia entre i e j com custo P no grafo G;
	void remove_adjacencia(int i, int j);  // remove a adjac�ncia entre i e j no grafo G;
	void imprime_adjacencias();  // imprime a matriz de adjac�ncias do grafo G
	void seta_informacao(int i, std::string V);  // atualiza a informa��o do n� i com o valor V (que deve ser uma string) no grafo G
	int adjacentes(int i,  int *adj);  // retorna o n�mero de adjacentes ao v�rtice i no grafo G e os armazena no vetor adj
};