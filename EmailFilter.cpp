#include "EmailFilter.h"

bool EmailFilter::alreadyExist(std::list<LineAdjEmails> list, LineAdjEmails *lineObjective)
{
	for (std::list<LineAdjEmails>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (it->from == lineObjective->from && it->to == lineObjective->to)
			return true;
	}
	return false;
}

std::list<LineAdjEmails>::iterator EmailFilter::getExistingPosition(std::list<LineAdjEmails> list, LineAdjEmails * lineObjective)
{
	std::list<LineAdjEmails>::iterator it;

	for (it = list.begin(); it != list.end(); it++)
	{
		if (it->from == lineObjective->from && it->to == lineObjective->to)
			return it;
	}
	return it;
}

EmailFilter::EmailFilter()
{
}

EmailFilter::~EmailFilter()
{
}

std::list<LineAdjEmails> EmailFilter::findAdjEmails(std::list<std::string> emailPaths)
{
	std::list<LineAdjEmails> adjEmails;
	std::list<std::string> textFile;
	std::list<std::string>::iterator itTextFile;

	for (std::list<std::string>::iterator it = emailPaths.begin(); it != emailPaths.end(); it++)
	{
		textFile = FileReader::fileRead(*it);
		if (!textFile.empty())
		{
			itTextFile = std::find(textFile.begin(), textFile.end(), "From:");

			if (itTextFile != textFile.end())
			{
				LineAdjEmails lineAux;

				it++;
				lineAux.from = *(it++);
				lineAux.to = *(++it);
				if (alreadyExist(adjEmails, &lineAux))
				{
					(getExistingPosition(adjEmails, &lineAux))->weight;
				}
			}
		}
	}
	return adjEmails;
}
