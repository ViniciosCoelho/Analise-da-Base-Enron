#include "Filter.h"

void Filter::addPaths(std::list<std::string> aux)
{
	for (std::list<std::string>::iterator itAux = aux.begin(); itAux != aux.end(); itAux++)
		paths.push_back(*itAux);
}

Filter::Filter(std::list<std::string> initialPaths)
{
	paths = initialPaths;
}

Filter::~Filter()
{
}

std::list<std::string> Filter::findCorrectPaths(std::string directory)
{
	std::list<std::string> aux;
	std::list<std::string>::iterator it;
	std::list<std::string>::iterator itAux;
	int i, size, j;

	if (!paths.empty())
	{
		for (i = 0; i < 2; i++)
			paths.erase(paths.begin());
		for (itAux = it = paths.begin(), i = 0, size = paths.size(); i < size; it++, i++)
		{
			if (itAux != it)
				paths.erase(itAux++);

			if (!(aux = PathFinder::findPossiblePaths(*it + "_sent_mail\\")).empty())
			{
				for (j = 0; j < 2; j++)
					aux.erase(aux.begin());
				this->addPaths(aux);
			}
			else if (!(aux = PathFinder::findPossiblePaths(*it + "sent\\")).empty())
			{
				for (j = 0; j < 2; j++)
					aux.erase(aux.begin());
				this->addPaths(aux);
			}
		}
		paths.erase(itAux);
	}
	return paths;
}