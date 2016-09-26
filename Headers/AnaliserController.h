#ifndef ANALISER_CONTROLLER
#define ANALISER_CONTROLLER

#include "Filter.h"
#include "EmailFilter.h"
#include "FileWriter.h"
#include "Grafo.h"

class AnaliserController
{
private:
	std::list<std::string> emailPaths;
	EmailFilter emailF;
	Grafo *graf;

	std::vector<std::string> findUniqueEmails(std::list<LineAdjEmails> &adjEmails);
	AnaliserController();
public:
	static AnaliserController &createController();
	~AnaliserController();

	//getters
	std::list<std::string> get_emailPaths();
	EmailFilter get_emailfilter();
	Grafo* get_graph();
	
	bool findEmailsPaths(std::string directory);
	std::list<LineAdjEmails> AnaliserController::findAdjEmails();
	int createGraf(std::list<LineAdjEmails> adjEmails);
	void criaAdjacencia(int i, int j, int P);
	void removeAdjacencia(int i, int j);
	void imprimeAdjacencias();
	void setaInformacao(int i, std::string rotulo);
	int* adjacentes(int i); // Ficar esperto com esse método aq. Passo parametros diferentes pra controller e pro grafo em si.
	/*
	Agora é só ir colocando as funções do grafo aq, que dai essa classe delega pro grafo fazer.
	*/
};

#endif