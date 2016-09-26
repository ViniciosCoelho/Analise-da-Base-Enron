#ifndef FILTER
#define FILTER

#include "PathFinder.h"

class Filter
{
private:
	std::list<std::string> paths;
	
	void addPaths(std::list<std::string> aux);
public:
	Filter(std::list<std::string> initialPaths);
	~Filter();

	std::list<std::string> findCorrectPaths(std::string directory);
};

#endif