#include "FileReader.h"

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

std::list<std::string> FileReader::fileRead(std::string filePath)
{
	std::ifstream file(filePath);
	std::list<std::string> fileWords;

	if (file.is_open())
	{
		std::string aux;
		while (!file.eof())
		{
			file >> aux;
			fileWords.push_back(aux);
		}
		file.close();
	}
	else
		std::cout << "Error opening the file: " << filePath;
	return fileWords;
}
