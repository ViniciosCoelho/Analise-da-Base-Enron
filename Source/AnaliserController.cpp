#include "AnaliserController.h"

std::vector<std::string> AnaliserController::findUniqueEmails(std::list<LineAdjEmails> &adjEmails)
{
	return emailF.findUniqueEmails(adjEmails);
}

AnaliserController::AnaliserController()
{
}

AnaliserController &AnaliserController::createController()
{
	static AnaliserController instance;
	return instance;
}

AnaliserController::~AnaliserController()
{
}

bool AnaliserController::findEmailsPaths(std::string directory)
{
	Filter filter(PathFinder::findPossiblePaths(directory));
	if (!(emailPaths = filter.findCorrectPaths(directory)).empty())
		return true;
	else
		return false;
}

std::list<LineAdjEmails> AnaliserController::findAdjEmails()
{
	return emailF.findAdjEmails(this->emailPaths);
}

int AnaliserController::createGraf(std::list<LineAdjEmails> adjEmails)
{
	std::vector<std::string> uniqueEmails;
	int From, To;

	uniqueEmails = findUniqueEmails(adjEmails);
	this->graf = new Grafo(uniqueEmails.size());
	FileWriter::fileWrite(adjEmails); // Just for debuging purposes
	for (int i = 0; i < (signed)uniqueEmails.size(); i++)
		this->graf->seta_informacao(i, uniqueEmails[i]);
	for (std::list<LineAdjEmails>::iterator it = adjEmails.begin(); it != adjEmails.end(); it++)
	{
		From = std::find(uniqueEmails.begin(), uniqueEmails.end(), it->from) - uniqueEmails.begin();
		To = std::find(uniqueEmails.begin(), uniqueEmails.end(), it->to) - uniqueEmails.begin();
		this->graf->cria_adjacencia(From, To, it->weight);
	}
	graf->createWarshell();
	return uniqueEmails.size();
	
}

void AnaliserController::criaAdjacencia(int i, int j, int P)
{
	graf->cria_adjacencia(i, j, P);
}

void AnaliserController::removeAdjacencia(int i, int j)
{
	graf->remove_adjacencia(i, j);
}

void AnaliserController::imprimeAdjacencias()
{
	graf->imprime_adjacencias();
}



void AnaliserController::setaInformacao(int i, std::string rotulo)
{
	graf->seta_informacao(i, rotulo);
}

int AnaliserController::numero_adjacentes(int i)
{
	return graf->numero_adjacentes(i);
}

int AnaliserController::numberVert()
{
	return graf->num_vertices();
}

int AnaliserController::numberArest()
{
	return graf->num_arestas();
}

std::vector<std::pair<int, int>> AnaliserController::mostExitGrade()
{
	return graf->maior_grau_saida();
}

std::vector<std::pair<int, int>> AnaliserController::mostEnterGrade()
{
	return graf->maior_grau_entrada();
}

std::vector<int> AnaliserController::findNodesAtDistance(int vert, int dist)
{
	std::vector<int> aux;
	graf->vertices_distantes(vert, dist, aux);
	return aux;
}

std::vector<int> AnaliserController::depth_search(int vert, int dest)
{
	std::vector<int> aux;
	int count = 0;
	graf->depth_search(vert, dest, count, aux);
	return aux;
}

std::queue<int> AnaliserController::width_search(int vert, int dest)
{
	std::queue<int> aux;
	aux.push(vert);
	graf->breadth_search_iterative(dest, std::vector<int>(), aux);
	return aux;
}

std::stack<int> AnaliserController::bestPath(int vert, int dest)
{
	return graf->dijkstra(vert, dest);
}
