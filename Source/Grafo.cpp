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

int Grafo::numero_adjacentes(int i)
{
	int numAdj = 0;

	if (!this->lista[i].vazia())
	{
		for (int j = 0; j < this->tamanho; j++)
		{
			if (this->lista[i].busca(j))
				numAdj++;
		}
	}
	return numAdj;
}

int *Grafo::adjacentes(int i)
{
	int numAdj;

	if ((numAdj = numero_adjacentes(i)) != 0)
	{
		int k = 0, *adj = nullptr;
		adj = new int[numAdj];

		for (int j = 0; j < this->tamanho; j++)
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

int Grafo::num_vertices()
{
	return this->tamanho;
}

int Grafo::num_arestas()
{
	int numArest = 0;
	for (int i = 0; i < this->tamanho; i++)
		numArest += numero_adjacentes(i);
	return numArest;
}

std::vector<std::pair<int, int>> Grafo::maior_grau_saida()
{
	std::vector<std::pair<int, int>> maioresGrausSaida;
	for (int i = 0; i < 20; i++)
		maioresGrausSaida.push_back(std::pair<int, int>(-1, -1));
	for (int vert = 0; vert < this->tamanho; vert++)
	{
		int numAdj;
		numAdj = numero_adjacentes(vert);
		for (std::vector<std::pair<int, int>>::iterator it = maioresGrausSaida.begin(); it != maioresGrausSaida.end(); it++)
		{
			if (numAdj > it->second)
			{
				maioresGrausSaida.insert(it, std::pair<int, int>(vert, numAdj));
				maioresGrausSaida.erase(maioresGrausSaida.begin() + 20);
				break;
			}
		}
	}
	return maioresGrausSaida;
}

std::vector<std::pair<int, int>> Grafo::maior_grau_entrada()
{
	std::vector<std::pair<int, int>> maioresGrausEnt;
	for (int i = 0; i < 20; i++)
		maioresGrausEnt.push_back(std::pair<int, int>(-1, -1));
	for (int vert = 0; vert < this->tamanho; vert++)
	{
		int numEnt = 0;
		for (int i = 0; i < this->tamanho; i++)
		{
			if (!lista[i].vazia())
			{
				if (lista[i].busca(vert))
					numEnt++;
			}
		}
		for (std::vector<std::pair<int, int>>::iterator it = maioresGrausEnt.begin(); it != maioresGrausEnt.end(); it++)
		{
			if (numEnt > it->second)
			{
				maioresGrausEnt.insert(it, std::pair<int, int>(vert, numEnt));
				maioresGrausEnt.erase(maioresGrausEnt.begin() + 20);
				break;
			}
		}
	}
	return maioresGrausEnt;
}

bool Grafo::existe_vertice_visitados(std::vector<int> vetor_vertices, int vert)
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

int Grafo::depth_search(int X, int Y, int &count, std::vector<int> & Visitados)
{
	int* adj = nullptr;
	int num_adj;

	count--;
	if (count == -1)
	{
		Visitados.clear();
		return 0;
	}
	if (X == Y)
	{
		Visitados.push_back(X);
		return X;
	}
	else
	{
		if (!(Grafo::existe_vertice_visitados(Visitados, X)))
		{
			Visitados.push_back(X);
			num_adj = this->numero_adjacentes(X);
			adj = this->adjacentes(X);
			for (int i = 0; i < num_adj; i++)
			{
				int x;
				if ((x = depth_search(adj[i], Y, count, Visitados)) != 0)
				{
					return x;
				}
			}
		}
		return 0;
	}
}

bool Grafo::breadth_search_iterative(int Y, std::vector<int>& Visitados, std::queue<int> Q)
{
	int num_adj;
	int x;
	bool* visit = new bool[this->num_vertices()];
	int* adj = nullptr;

	for (int i = 0; i < this->tamanho; i++)
	{
		visit[i] = false;
	}
	if (Q.empty())
	{
		throw std::exception("Destino não existe !! ");
		return false;
	}
	else
	{
		x = Q.front();
		visit[x] = true;
	}
	if (x == Y)
	{
		Visitados.push_back(x);
		return true;
	}
	else
	{
		while (!Q.empty())
		{
			Visitados.push_back(x);
			if (x == Y)
			{
				return true;
			}
			adj = this->adjacentes(x);
			num_adj = this->numero_adjacentes(x);
			for (int i = 0; i < num_adj; i++)
			{
				if (!visit[adj[i]])
				{
					visit[adj[i]] = true;
					Q.push(adj[i]);
				}
			}
			Q.pop();
			x = Q.front();
		}
	}
}

std::vector<int> Grafo::pointer_int_to_vector(int * v, int tam)
{
	std::vector<int> V;
	for (int i = 0; i < tam; i++)
	{
		V.push_back(v[i]);
	}
	return V;
}

int Grafo::vertices_distantes(int vertice, int distancia, std::vector<int>& distantes)
{
	int num_adj, x;
	std::vector<int> adj;
	num_adj = Grafo::numero_adjacentes(vertice);
	adj = Grafo::pointer_int_to_vector(Grafo::adjacentes(vertice), num_adj);

	if (distancia == 0)
	{
		distantes.push_back(vertice);
		return vertice;
	}
	
	while (!adj.empty())
	{
		for (int i = 0; i < num_adj; i++)
		{
			x = adj.back();
			Grafo::vertices_distantes(x, distancia - 1, distantes);
			adj.pop_back();
		}
	}

	return vertice;
}

bool Grafo::warshellPosition(int ini, int dest)
{
	if (matrizBin[ini][dest] == true)
		return true;
	else
		return false;
}

void Grafo::createWarshell()
{
	matrizBin = new bool*[tamanho];
	for (int i = 0; i < tamanho; i++)
	{
		matrizBin[i] = new bool[tamanho];
		if (lista[i].vazia())
		{
			for (int j = 0; j < tamanho; j++)
				matrizBin[i][j] = false;
		}
		else
		{
			for (int j = 0; j < tamanho; j++)
			{
				if (!lista[i].busca(j))
					matrizBin[i][j] = false;
				else
					matrizBin[i][j] = true;
			}
		}
	}
	for (int k = 0; k < tamanho; k++)
	{
		for (int i = 0; i < tamanho; i++)
		{
			if (matrizBin[i][k] == 1)
			{
				for (int j = 0; j < tamanho; j++)
					matrizBin[i][j] = matrizBin[i][j] | matrizBin[k][j];
			}
		}
	}
}

std::stack<int> Grafo::dijkstra(int inicio, int destino)
{
	std::stack<int> melhorCaminho;
	if (warshellPosition(inicio, destino))
	{
		int atual = inicio, i;
		float *distancia = new float[tamanho];
		float distAtual;
		int *caminho = new int[tamanho];
		bool *membro = new bool[tamanho];

		for (i = 0; i < tamanho; i++)
		{
			if (i == inicio)
			{
				membro[i] = true;
				distancia[i] = 0;
				caminho[i] = NONE;
			}
			else
			{
				membro[i] = false;
				distancia[i] = INFINITO;
			}
		}
		while (atual != destino)
		{
			if (!lista[atual].vazia())
			{
				for (i = 0; i < tamanho; i++)
				{
					if (lista[atual].busca(i))
					{
						if (1.0 / (lista[atual].retornaPeso(i) + distancia[atual]) < 1.0 / distancia[i])
						{
							distancia[i] = lista[atual].retornaPeso(i) + distancia[atual];
							caminho[i] = atual;
						}
					}
				}
			}
			distAtual = INFINITO;
			for (i = 0; i < tamanho; i++)
			{
				//if (distancia[i] >= 1.0)
				{
					if (membro[i] == false && distancia[i] > distAtual /*&& i != inicio*/)
					{
						atual = i;
						distAtual = distancia[i];
					}
				}
			}
			membro[atual] = true;
		}
		int aux = atual;
		melhorCaminho.push(destino);
		do
		{
			melhorCaminho.push(caminho[atual]);
		} while ((atual = caminho[atual]) != inicio);
		melhorCaminho.push(distancia[aux]);
	}
	return melhorCaminho;
}