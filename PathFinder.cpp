#include "PathFinder.h"

std::list<std::string> PathFinder::findPossiblePaths(std::string directory)
{
	DIR *dir;
	struct dirent *dirEnt;
	std::list<std::string> possiblePaths;
	
	dir = opendir(directory.c_str());
	if (dir != NULL)
	{
		while ((dirEnt = readdir(dir)) != NULL)
			possiblePaths.push_back(directory + dirEnt->d_name + '\\');

		closedir(dir);
	}
	else
		std::cout << "Cannot open directory: " << directory << std::endl;

	return possiblePaths;
}