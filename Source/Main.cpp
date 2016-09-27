#include <iostream>
#include <string>
#include <locale.h>
#include "Filter.h"
#include "AnaliserController.h"
#include "CorrectPath.h"

void main()
{
	AnaliserController & controller = AnaliserController::createController(); // It's a singleton.

	setlocale(LC_ALL, "");


	if (controller.findEmailsPaths(MAIN_PATH))
	{
		std::list<LineAdjEmails> adjEmails;
		int grafSize;
		char option;

		std::cout << "Processing emails. Please wait..." << std::endl;
		adjEmails = controller.findAdjEmails();
		std::cout << "Creating graph. Please wait..." << std::endl;
		grafSize = controller.createGraf(adjEmails);	// 1)
		std::cout << "Graph is now usable!" << std::endl;
		do
		{
			int i, j, P;
			std::string rotulo;
			std::cout << "\t1 - Imprime Adjacências" << std::endl
					<< "\t2 - Número de Adjacentes" << std::endl 
					<< "\t3 - Sair" << std::endl 
					<< "Escolha uma opção:" << std::endl;
			std::cin >> option;
			switch (option)
			{

			case '1':
				std::cout << std::endl;
				controller.imprimeAdjacencias();
				std::setprecision(0);
				break;

			case '2':
				
				break;

			case '3':
				std::cout << "Até logo !" << std::endl;
				break;

			default:
				std::cout << "Opção incorreta !" << std::endl;
				break;
			}
		} while (option != '3');
	}
	else
		std::cout << "It was not possible to build the graf. Terminanting operation." << std::endl;

	
}