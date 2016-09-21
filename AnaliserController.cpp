#include "AnaliserController.h"

AnaliserController::AnaliserController()
{
}

void AnaliserController::findAdjEmails()
{
	EmailFilter emailF;

	this->adjEmails = emailF.findAdjEmails(this->emailPaths);
}

AnaliserController::~AnaliserController()
{
}

AnaliserController &AnaliserController::createController()
{
	static AnaliserController instance;
	return instance;
}

bool AnaliserController::findEmailsPaths(std::string directory)
{
	Filter filter(PathFinder::findPossiblePaths(directory));
	if (!(emailPaths = filter.findCorrectPaths(directory)).empty())
		return true;
	else
		return false;
}

void AnaliserController::createGraf()
{
	this->findAdjEmails();
}