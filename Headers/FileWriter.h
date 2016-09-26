#ifndef FILE_WRITER
#define FILE_WRITER

#include <string>
#include <list>
#include <fstream>
#include "EmailFilter.h"

class FileWriter
{
public:
	FileWriter();
	~FileWriter();

	static void fileWrite(std::list<LineAdjEmails> &stringsToWrite);
};

#endif