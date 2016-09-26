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
		{
			if (dirEnt->d_type == DT_DIR)
				possiblePaths.push_back(directory + dirEnt->d_name + '\\');
			else
				possiblePaths.push_back(directory + dirEnt->d_name);
		}

		closedir(dir);
	}
	else
		std::cout << "Cannot open directory: " << directory << std::endl;

	return possiblePaths;
}