#ifndef ANALISER_CONTROLLER
#define ANALISER_CONTROLLER

#include "Filter.h"
#include "EmailFilter.h"

class AnaliserController
{
private:
	std::list<std::string> emailPaths;
	std::list<LineAdjEmails> adjEmails;

	AnaliserController();
	void findAdjEmails();
public:
	~AnaliserController();

	static AnaliserController &createController();
	bool findEmailsPaths(std::string directory);
	void createGraf();
};

#endif