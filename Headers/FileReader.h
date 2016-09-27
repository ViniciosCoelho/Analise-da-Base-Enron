#ifndef FILE_READER
#define FILE_READER

#include <iostream>
#include <string>
#include <list>
#include <fstream>

class FileReader
{
public:
	FileReader();
	~FileReader();

	static std::list<std::string> fileRead(std::string filePath);
};

#endif