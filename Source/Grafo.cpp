<<<<<<< HEAD
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



bool Grafo::depth_search(int X, int Y, int & count, std::vector<int> & Visitados)
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
		if (!(Grafo::existe_vertice_visitados(Visitados, X)))
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
		throw std::exception("destino não existe !!");
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

Lista * Grafo::vertices_distantes(int distancia)
{
	return nullptr;
}
=======
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

	if ((numAdj = numero_adjacentes(i))!= 0)
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

bool Grafo::depth_search(int X, int Y, int &count, std::vector<int> & Visitados)
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
		if (!(Grafo::existe_vertice_visitados(Visitados, X)))
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

std::vector<int> Grafo::vertices_distantes(int vertice, int distancia)
{

	return std::vector<int>();


}
>>>>>>> refs/remotes/ViniciosCoelho/master
