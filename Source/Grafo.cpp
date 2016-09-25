#include "Grafo.h"

Vertice::Vertice()
{
}

Vertice::~Vertice()
{
}

Grafo::Grafo(int numVert)
{
	tamanho = numVert;
	lista = new Lista[tamanho];
	vertices = new Vertice[tamanho];
}

Grafo::~Grafo()
{
}

std::string Vertice::retornaNome()
{
	return this->nome;
}

void Vertice::recebeNome(std::string V)
{
	this->nome = V;
}

void Grafo::cria_adjacencia(int i, int j, int P)
{
	this->lista[i].insere_ordenado(j, P);
}

void Grafo::remove_adjacencia(int i, int j)
{
	if (!this->lista[i].vazia())
	{
		this->lista[i].retiraEscolha(j);
	}
}

void Grafo::imprime_adjacencias()
{
	int i, j;

	for (i = 0; i < this->tamanho; i++)
	{
		for (j = 0; j < this->tamanho; j++)
		{
			if(!this->lista[i].vazia() && this->lista[i].busca(j))
				std::cout << " " << this->lista[i].retornaValorElemento(j);
			else
				std::cout << " " << INFINITO;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Grafo::seta_informacao(int i, std::string V)
{
	this->vertices[i].recebeNome(V);
}

int Grafo::adjacentes(int i, int *adj)
{
	int numAdj = 0, j, k = 0;

	if (!this->lista[i].vazia())
	{
		for (j = 0; j < this->tamanho; j++)
		{
			if (this->lista[i].busca(j))
				numAdj++;
		}

		adj = new int[numAdj];

		for (j = 0; j < this->tamanho; j++)
		{
			if (this->lista[i].busca(j))
			{
				adj[k] = j;
				k++;
			}
		}

		std::cout << "Adjacências: ";
		for (j = 0; j < numAdj; j++)
			std::cout << adj[j] << " ";
		std::cout << std::endl;

		return numAdj;
	}
	else
	{
		return 0;
	}
}