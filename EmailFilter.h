#ifndef  EMAIL_FILTER
#define EMAIL_FILTER

#include <list>
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
	bool alreadyExist(std::list<LineAdjEmails> list, LineAdjEmails *lineObjective);
	std::list<LineAdjEmails>::iterator getExistingPosition(std::list<LineAdjEmails> list, LineAdjEmails *lineObjective);
public:
	EmailFilter();
	~EmailFilter();

	std::list<LineAdjEmails> findAdjEmails(std::list<std::string> emailPaths);
};

#endif