#ifndef FILE_FINDER
#define FILE_FINDER

#include <list>
#include "dirent.h"
#include <iostream>
#include <string>

class PathFinder
{
public:
	static std::list<std::string> findPossiblePaths(std::string directory);
};

#endif

