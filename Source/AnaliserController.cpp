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

	uniqueEmails = findUniqueEmails(adjEmails);
	graf = &Grafo::Grafo(uniqueEmails.size());

	FileWriter::fileWrite(adjEmails); // Just for debuging purposes
	for (int i = 0; i < (signed)uniqueEmails.size(); i++)
		graf->seta_informacao(i, uniqueEmails[i]);
	for (std::list<LineAdjEmails>::iterator it = adjEmails.begin(); it != adjEmails.end(); it++)
		graf->cria_adjacencia(std::find(uniqueEmails.begin(), uniqueEmails.end(), it->from)-uniqueEmails.begin(), std::find(uniqueEmails.begin(), uniqueEmails.end(), it->to) - uniqueEmails.begin(), it->weight);
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