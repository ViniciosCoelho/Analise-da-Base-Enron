#include <iostream>
#include <string>
#include "Filter.h"
#include "AnaliserController.h"
#include "CorrectPath.h"

void main()
{
	AnaliserController & controller = AnaliserController::createController();

	if(controller.findEmailsPaths(MAIN_PATH))
	{	
		controller.createGraf();
		//for (std::list<std::string>::iterator it = paths.begin(); it != paths.end(); it++)
			//std::cout << *it << std::endl;
	}
}