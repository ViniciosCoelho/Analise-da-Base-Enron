#include "FileWriter.h"

FileWriter::FileWriter()
{
}

FileWriter::~FileWriter()
{
}

void FileWriter::fileWrite(std::list<LineAdjEmails> &stringsToWrite)
{
	std::ofstream file("Adjacências.txt");

	if (file.is_open())
	{
		for (std::list<LineAdjEmails>::iterator it = stringsToWrite.begin(); it != stringsToWrite.end(); it++)
		{
			file << it->from;
			file << ' ' + it->to + ' ';
			file << it->weight;
			file << '\n';
		}
	}
	file.close();
}