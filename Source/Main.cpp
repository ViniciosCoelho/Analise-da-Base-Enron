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
		grafSize = controller.createGraf(adjEmails);
		std::cout << "Graph is now usable!" << std::endl;
		do
		{
			int i, j, P;
			std::string rotulo;
			std::vector<std::pair<int, int>> vecPrinter;
			std::vector<int> vecNodePrinter;
			std::queue<int> auxPrinter;
			std::cout << "\t1 - Imprime Adjacências" << std::endl
				<< "\t2 - Número de Adjacentes" << std::endl
				<< "\t3 - Número de Vértices" << std::endl
				<< "\t4 - Número de Arestas" << std::endl
				<< "\t5 - Maior Grau de Saída" << std::endl
				<< "\t6 - Maior Grau de Entrada" << std::endl
				<< "\t7 - Busca em Profundidade" << std::endl
				<< "\t8 - Busca em Largura" << std::endl
				<< "\t9 - Nós a uma distância de N arestas de um determinado Nó" << std::endl
				<< "\t0 - Sair" << std::endl
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
				std::cout << "De qual Nó você quer saber as adjacências:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				j = controller.numero_adjacentes(i);
				std::cout << "Número de Adjacências = " << j << std::endl << std::endl;
				break;

			case '3':
				std::cout << "Número de vértices no grafo vale: " << controller.numberVert() << std::endl << std::endl;
				break;

			case '4':
				std::cout << "Número de arestas no grafo vale: " << controller.numberArest() << std::endl << std::endl;
				break;

			case '5':
				std::cout << "Os 20 emails que mais enviaram mensagens foram:" << std::endl;
				vecPrinter = controller.mostExitGrade();
				for (int i = 0; i < 20; i++)
					std::cout << i + 1 << "º) Email: " << vecPrinter[i].first << " Envios: " << vecPrinter[i].second << std::endl;
				std::cout << std::endl;
				break;

			case '6':
				std::cout << "Os 20 emails que mais receberam mensagens foram:" << std::endl;
				vecPrinter = controller.mostEnterGrade();
				for (int i = 0; i < 20; i++)
					std::cout << i + 1 << "º) Email: " << vecPrinter[i].first << " Recebidos: " << vecPrinter[i].second << std::endl;
				std::cout << std::endl;
				break;

			case '7':
				std::cout << "Qual o Nó origem:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				std::cout << "Qual o Nó destino:" << std::endl;
				std::cin >> j;
				while (j < 0 || j >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> j;
				}
				vecNodePrinter = controller.depth_search(i, j);
				if (!vecNodePrinter.empty())
				{
					for (i = 0; i < vecNodePrinter.size(); i++)
						std::cout << vecNodePrinter[i] << " ";
					std::cout << std::endl;
				}
				else
					std::cout << "Não existe caminho..." << std::endl;
				break;

			case '8':
				std::cout << "Qual o Nó origem:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				std::cout << "Qual o Nó destino:" << std::endl;
				std::cin >> j;
				while (j < 0 || j >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> j;
				}
				auxPrinter = controller.width_search(i, j);
				if (!auxPrinter.empty())
				{
					while (!auxPrinter.empty())
					{
						std::cout << auxPrinter.front() << " ";
						auxPrinter.pop();
					}
				}
				else
					std::cout << "Não existe adjacência!" << std::endl;
				break;

			case '9':
				std::cout << "De qual Nó você quer saber as adjacências:" << std::endl;
				std::cin >> i;
				while (i < 0 || i >= grafSize)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> i;
				}
				std::cout << "A quantas arestas de distância elas devem estar:" << std::endl;
				std::cin >> j;
				while (j <= 0)
				{
					std::cout << "Opção incorreta. Escolha outra:" << std::endl;
					std::cin >> j;
				}
				vecNodePrinter = controller.findNodesAtDistance(i, j);
				std::cout << "Os Nós adjacêntes ao Nó origem a uma distância de " << j << " Arestas são:" << std::endl;
				if (!vecNodePrinter.empty())
				{
					for (int i = 0; i < vecNodePrinter.size(); i++)
						std::cout << i + 1 << "º) " << vecNodePrinter[i] << std::endl;
				}
				else
					std::cout << "Nenhum" << std::endl;
				std::cout << std::endl;
				break;

			case 'a':

				break;

			case '0':
				std::cout << "Até logo !" << std::endl;
				break;

			default:
				std::cout << "Opção incorreta !" << std::endl;
				break;
			}
		} while (option != '0');
	}
	else
		std::cout << "It was not possible to build the graf. Terminanting operation." << std::endl;
}