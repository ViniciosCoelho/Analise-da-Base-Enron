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
private:
	std::vector<std::string> findUniqueEmails(std::list<LineAdjEmails> &adjEmails);
	AnaliserController();
public:
	static AnaliserController &createController();
	~AnaliserController();

	//getters
	/*std::list<std::string> get_emailPaths();
	EmailFilter get_emailfilter();
	Grafo* get_graph();*/
	bool findEmailsPaths(std::string directory);
	std::list<LineAdjEmails> AnaliserController::findAdjEmails();
	int createGraf(std::list<LineAdjEmails> adjEmails);
	void criaAdjacencia(int i, int j, int P);
	void removeAdjacencia(int i, int j);
	void imprimeAdjacencias();
	void setaInformacao(int i, std::string rotulo);
	int numero_adjacentes(int i); // Ficar esperto com esse método aq. Passo parametros diferentes pra controller e pro grafo em si.

								  //Methods for the TDE
	int numberVert(); // 2) a.
	int numberArest(); // 2) b.
	std::vector<std::pair<int, int>> mostExitGrade(); // 2) c.
	std::vector<std::pair<int, int>> mostEnterGrade(); // 2) d.
	std::vector<int> findNodesAtDistance(int vert, int dist);
	std::vector<int> depth_search(int vert, int dest);
	std::queue<int> width_search(int vert, int dest);
};

#endif