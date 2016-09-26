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
	int i, j, Vertice, Peso;
	for (i = 0; i < this->tamanho; i++)
	{
		std::cout << "Adjacentes ao vertice " << i << ":" << std::endl;
		for (j = 0; j < this->tamanho; j++)
		{
			if (this->lista[i].vazia())
			{
				break;
			}
			if (this->lista[i].busca(j))
			{
				Vertice = this->lista[i].retornaVertice(j);
				Peso = this->lista[i].retornaPeso(j);
				std::cout << "| " << Vertice << "/" << Peso << " |   ";
			}
				
			
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

int Grafo::num_vertices()
{
	return this->tamanho;
}

int Grafo::num_arestas()
{
	int i, j, num_arestas = 0;
	for (i = 0; i < this->tamanho; i++)
	{
		for (j = 0; j < this->tamanho; j++)
		{
			if (!this->lista[i].vazia() && this->lista[i].busca(j))
			{
				num_arestas++;
			}

		}
	}
	return num_arestas;
}

int Grafo::maior_grau_saida()
{
	return 0;
}

int Grafo::maior_grau_entrada()
{
	return 0;
}

Lista * Grafo::depth_search(int X, int Y)
{
	return nullptr;
}

Lista * Grafo::width_search(int X, int Y)
{
	return nullptr;
}

Lista * Grafo::vertices_distantes(int distancia)
{
	return nullptr;
}
