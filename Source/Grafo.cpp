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
		if (!this->lista[i].vazia())
		{
			std::cout << std::endl;
			std::cout << "Adjacentes ao vertice " << i << ":" << std::endl;
		}
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
		if (!this->lista[i].vazia())
		{
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << "Vertices sem adjacência: " << std::endl;
	for (i = 0; i < this->tamanho; i++)
	{
		if (this->lista[i].vazia())
		{
			std::cout << i << "  ";
		}

	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void Grafo::seta_informacao(int i, std::string V)
{
	this->vertices[i].recebeNome(V);
}

int* Grafo::adjacentes(int i)
{
	int numAdj = 0, j, k = 0;

	if (!this->lista[i].vazia())
	{
		for (j = 0; j < this->tamanho; j++)
		{
			if (this->lista[i].busca(j))
				numAdj++;
		}

		int* adj = new int[numAdj];

		for (j = 0; j < this->tamanho; j++)
		{
			if (this->lista[i].busca(j))
			{
				adj[k] = j;
				k++;
			}
		}

		return adj;
	}
	else
	{
		return nullptr;
	}
}

int Grafo::numero_adjacentes(int i)
{
	int numAdj = 0, j, k = 0;

	if (!this->lista[i].vazia())
	{
		for (j = 0; j < this->tamanho; j++)
		{
			if (this->lista[i].busca(j))
				numAdj++;
		}
		return numAdj++;
	}
	else
	{

		return 0;
	}
}

void Grafo::imprime_adjacencias(int numAdj, int* adj)
{
	std::cout << "Adjacências: ";
	for (int j = 0; j < numAdj; j++)
		std::cout << adj[j] << " ";
	std::cout << std::endl;
}

bool Grafo::existe_vertice(std::vector<int> vetor_vertices, int vert)
{
	for (int i = 0; i < vetor_vertices.size(); i++)
	{
		if (vetor_vertices[i] == vert)
		{
			return true;
		}
	}
	return false;
}

int Grafo::num_vertices()
{
	return this->tamanho;
}



int Grafo::maior_grau_saida()
{
	return 0;
}

int Grafo::maior_grau_entrada()
{
	return 0;
}



bool Grafo::depth_search(int X, int Y, int count, std::vector<int> & Visitados)
{
	
	int* adj = nullptr;
	int num_adj;
	count++;
	if (count > 50)
	{
		Visitados.clear();
		return false;
	}
	if (X == Y)
	{
		Visitados.push_back(X);
		return true;
	}
	else
	{
		if (!(Grafo::existe_vertice(Visitados, X)))
		{
			Visitados.push_back(X);
			num_adj = this->numero_adjacentes(X);
			adj = this->adjacentes(X);
			for (int i = 0; i < num_adj; i++)
			{
				if (bool x = depth_search(adj[i], Y, count, Visitados))
				{
					return true;
				}
			}
		}
		return false;
	}
	
}

bool Grafo::width_search(int Y, std::vector<int>& Visitados, std::queue<int> Q)
{
	int x;
	if (Q.empty)
	{
		throw std::exception("destino não existe !!");
		return false;
	}
	else
	{
		x = Q.pop;
		//visite(x);
	}

	if (x == Y)
	{
		return true;
	}
	else
	{

	}
	return false;
}

Lista * Grafo::vertices_distantes(int distancia)
{
	return nullptr;
}
