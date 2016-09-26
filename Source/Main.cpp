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
			std::cout << "\t1 - Imprime Adjac�ncias" << std::endl
					<< "\t2 - Seta Informa��o" << std::endl 
					<< "\t3 - N�mero de Adjacentes" << std::endl 
					<< "\t4 - Sair" << std::endl 
					<< "Escolha uma op��o:" << std::endl;

			std::cin >> option;
			switch (option)
			{

			case '1':
				std::cout << std::endl;
				controller.imprimeAdjacencias();
				std::setprecision(0);
				break;

			case '2':
				std::cout << "De qual N� voc� quer mudar o r�tulo:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Op��o incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				std::cout << "Qual o r�tulo a ser colocado:" << std::endl;
				std::cin >> rotulo;
				controller.setaInformacao(i, rotulo);
				break;

			case '3':
				std::cout << "De qual N� voc� quer saber as adjac�ncias:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Op��o incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				j = controller.adjacentes(i);
				std::cout << "N�mero de Adjac�ncias = " << j << std::endl << std::endl;
				break;

			case '4':
				std::cout << "At� logo !" << std::endl;
				break;

			default:
				std::cout << "Op��o incorreta !" << std::endl;
				break;
			}
		} while (option != '4');
	}
	else
		std::cout << "It was not possible to build the graf. Terminanting operation." << std::endl;
}