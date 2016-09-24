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
			std::cout << "\t1 - Cria Adjac�ncia" << std::endl << "\t2 - Remove Adjac�ncia" << std::endl << "\t3 - Imprime Adjac�ncias" << std::endl << "\t4 - Seta Informa��o" << std::endl << "\t5 - N�mero de Adjac�ntes" << std::endl << "\t6 - Sair" << std::endl << "Escolha uma op��o:" << std::endl;
			std::cin >> option;
			switch (option)
			{
			case '1':
				std::cout << "Entre quais N�s deve ser criado a adjac�ncia? Escreva dessa forma: N�-ENTER-N�:" << std::endl;
				std::cin >> i >> j;
				while ((i < 0 || i >= grafSize) || (j < 0 || j >= grafSize))
				{
					std::cout << "Op��o incorreta. Escolha outra:" << std::endl;
					std::cin >> i >> j;
				}
				std::cout << "Qual � custo da adjac�ncia:" << std::endl;
				std::cin >> P;
				controller.criaAdjacencia(i, j, P);
				break;

			case '2':
				std::cout << "Entre quais N�s deve ser deletado a adjac�ncia? Escreva dessa forma: N�-ENTER-N�:" << std::endl;
				std::cin >> i >> j;
				while ((i < 0 || i >= grafSize) || (j < 0 || j >= grafSize))
				{
					std::cout << "Op��o incorreta. Escolha outra:" << std::endl;
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

			case '5':
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

			case '6':
				std::cout << "At� logo !" << std::endl;
				break;

			default:
				std::cout << "Op��o incorreta !" << std::endl;
				break;
			}
		} while (option != '6');
	}
	else
		std::cout << "It was not possible to build the graf. Terminanting operation." << std::endl;
}