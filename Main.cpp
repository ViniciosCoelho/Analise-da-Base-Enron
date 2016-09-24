#include <iostream>
#include <string>
#include "Filter.h"
#include "AnaliserController.h"
#include "CorrectPath.h"

void main()
{
	AnaliserController & controller = AnaliserController::createController(); // It's a singleton.

	if (controller.findEmailsPaths(MAIN_PATH))
	{
		std::list<LineAdjEmails> adjEmails;
		int grafSize;
		char option;

		std::cout << "Processing emails. Please wait..." << std::endl;
		adjEmails = controller.findAdjEmails();
		std::cout << "Creating graf. Please wait..." << std::endl;
		grafSize = controller.createGraf(adjEmails);
		std::cout << "Graf is now usable!" << std::endl;
		do
		{
			int i, j, P;
			std::string rotulo;
			std::cout << "\t1 - Cria Adjacência" << std::endl << "\t2 - Remove Adjacência" << std::endl << "\t3 - Imprime Adjacências" << std::endl << "\t4 - Seta Informação" << std::endl << "\t5 - Número de Adjacêntes" << std::endl << "\t6 - Sair" << std::endl << "Escolha uma opção:" << std::endl;
			std::cin >> option;
			switch (option)
			{
			case '1':
				std::cout << "Entre quais Nós deve ser criado a adjacência? Escreva dessa forma: NÓ-ENTER-NÓ:" << std::endl;
				std::cin >> i >> j;
				while ((i < 0 || i >= grafSize) || (j < 0 || j >= grafSize))
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i >> j;
				}
				std::cout << "Qual é custo da adjacência:" << std::endl;
				std::cin >> P;
				controller.criaAdjacencia(i, j, P);
				break;

			case '2':
				std::cout << "Entre quais Nós deve ser deletado a adjacência? Escreva dessa forma: NÓ-ENTER-NÓ:" << std::endl;
				std::cin >> i >> j;
				while ((i < 0 || i >= grafSize) || (j < 0 || j >= grafSize))
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i >> j;
				}
				controller.removeAdjacencia(i, j);
				break;

			case '3':
				std::cout << std::endl;
				controller.imprimeAdjacencias();
				std::setprecision(0);
				break;

			case '4':
				std::cout << "De qual Nó você quer mudar o rótulo:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				std::cout << "Qual o rótulo a ser colocado:" << std::endl;
				std::cin >> rotulo;
				controller.setaInformacao(i, rotulo);
				break;

			case '5':
				std::cout << "De qual Nó você quer saber as adjacências:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				j = controller.adjacentes(i);
				std::cout << "Número de Adjacências = " << j << std::endl << std::endl;
				break;

			case '6':
				std::cout << "Até logo !" << std::endl;
				break;

			default:
				std::cout << "Opção incorreta !" << std::endl;
				break;
			}
		} while (option != '6');
	}
	else
		std::cout << "It was not possible to build the graf. Terminanting operation." << std::endl;
}