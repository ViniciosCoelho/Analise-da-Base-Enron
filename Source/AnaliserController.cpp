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

std::list<std::string> AnaliserController::get_emailPaths()
{
	return this->emailPaths;
}

EmailFilter AnaliserController::get_emailfilter()
{
	return this->emailF;
}

Grafo* AnaliserController::get_graph()
{
	return this->graf;
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
	
	uniqueEmails = findUniqueEmails(adjEmails);
	this->graf = new Grafo(uniqueEmails.size());

	FileWriter::fileWrite(adjEmails); // Just for debuging purposes
	int From, To;

	for (int i = 0; i < (signed)uniqueEmails.size(); i++)
		this->graf->seta_informacao(i, uniqueEmails[i]);
	for (std::list<LineAdjEmails>::iterator it = adjEmails.begin(); it != adjEmails.end(); it++)
	{
		From = std::find(uniqueEmails.begin(), uniqueEmails.end(), it->from) - uniqueEmails.begin();
		To = std::find(uniqueEmails.begin(), uniqueEmails.end(), it->to) - uniqueEmails.begin();
		this->graf->cria_adjacencia(From, To, it->weight);
	}		
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

int AnaliserController::adjacentes(int i)
{
	return graf->adjacentes(i, nullptr);
}