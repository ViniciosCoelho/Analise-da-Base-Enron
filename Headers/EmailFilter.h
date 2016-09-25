#ifndef EMAIL_FILTER
#define EMAIL_FILTER

#include <list>
#include <vector>
#include <algorithm>
#include "FileReader.h"

struct LineAdjEmails
{
	std::string from;
	std::string to;
	int weight;
};

class EmailFilter
{
private:
	bool alreadyExist(std::list<LineAdjEmails> &list, LineAdjEmails &lineObjective);
	bool alreadyExist(std::vector<std::string> &list, std::string &lineObjetive);
	std::list<LineAdjEmails>::iterator getExistingPosition(std::list<LineAdjEmails> &list, LineAdjEmails &lineObjective);
public:
	EmailFilter();
	~EmailFilter();

	std::list<LineAdjEmails> findAdjEmails(std::list<std::string> emailPaths);
	std::vector<std::string> findUniqueEmails(std::list<LineAdjEmails> adjEmails);
};

#endif