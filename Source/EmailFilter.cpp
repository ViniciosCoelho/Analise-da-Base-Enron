#include "EmailFilter.h"

bool EmailFilter::alreadyExist(std::list<LineAdjEmails> &list, LineAdjEmails &lineObjective)
{
	for (std::list<LineAdjEmails>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (it->from == lineObjective.from && it->to == lineObjective.to)
			return true;
	}
	return false;
}

bool EmailFilter::alreadyExist(std::vector<std::string> &list, std::string &lineObjetive)
{
	for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (*it == lineObjetive)
			return true;
	}
	return false;
}

std::list<LineAdjEmails>::iterator EmailFilter::getExistingPosition(std::list<LineAdjEmails> &list, LineAdjEmails &lineObjective)
{
	std::list<LineAdjEmails>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if (it->from == lineObjective.from && it->to == lineObjective.to)
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
			if ((itTextFile = std::find(textFile.begin(), textFile.end(), "From:")) != textFile.end())
			{
				std::string fromEmail;
				std::vector<LineAdjEmails> vecLineAdjEmails;

				if (++itTextFile != textFile.end())
				{
					if (*itTextFile != "To:" && *itTextFile != "Subject:")
					{
						fromEmail = *itTextFile;
						do
						{
							itTextFile++;
						} while (*itTextFile != "To:" && *itTextFile != "Subject:");
					}
				}
				if (*itTextFile == "To:")
					itTextFile++;
				while (itTextFile != textFile.end())
				{
					if (*itTextFile != "Subject:" && !fromEmail.empty())
					{
						LineAdjEmails lineAux;

						lineAux.from = fromEmail;
						itTextFile->erase(std::remove(itTextFile->begin(), itTextFile->end(), ','));
						lineAux.to = *itTextFile;
						vecLineAdjEmails.push_back(lineAux);
					}
					else
						break;
					itTextFile++;
				}
				for (int i = 0; i < (signed)vecLineAdjEmails.size(); i++)
				{
					if (alreadyExist(adjEmails, vecLineAdjEmails[i]))
						(getExistingPosition(adjEmails, vecLineAdjEmails[i]))->weight++;
					else
					{
						vecLineAdjEmails[i].weight = 1;
						adjEmails.push_back(vecLineAdjEmails[i]);
					}
				}
			}
		}
	}
	return adjEmails;
}

std::vector<std::string> EmailFilter::findUniqueEmails(std::list<LineAdjEmails> adjEmails)
{
	std::vector<std::string> uniqueEmails;
	for (std::list<LineAdjEmails>::iterator it = adjEmails.begin(); it != adjEmails.end(); it++)
	{
		if (!alreadyExist(uniqueEmails, it->from))
			uniqueEmails.push_back(it->from);
		if (!alreadyExist(uniqueEmails, it->to))
			uniqueEmails.push_back(it->to);
	}
	return uniqueEmails;
}