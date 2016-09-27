#pragma once

#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class No
{
private:
	No *proximo;
	int vertice;
	int peso;

public:
	No(int elemento);
	No(int elemento, int valor);
	~No();

	int retorna_vertice();
	int retorna_peso();
	No *retorna_proximo();
	void insere_proximo(No * proximo);
	No *insere_depois(int elemento);
	No *insere_depois(int elemento, int valor);  // Insere o elemento info depois do nó No
	void mostra_nos();
	int retira_depois();	// Retira o elemento posterior ao nó No e retorna a sua informação
	No *retira_primeiro_no();
	No *retira_ultimo_no();
	void insere_ordenado_no(int elemento, int valor);
};

class Lista
{
private:
	No *primeiro;
	No *ultimo;

public:
	Lista();
	~Lista();

	bool vazia(); // Verifica se a lista L está vazia
	bool busca(int elemento);
	int ultimo_elemento(); // Retorna a informação do último elemento da Lista
	void insere_primeiro(int elemento, int valor); // Insere o elemento info como primeiro na lista L
	void insere_ultimo(int elemento, int valor);	// Insere o elemento info como último na lista L
	void mostra_lista(); // Mostra em Tela os Elementos da Lista L
	int retira_primeiro(); // Retira o primeiro elemento da Lista e retorna o valor da info do No
	int retira_ultimo(); // Retira o último elemento da Lista e retorna a informação do Nó
	void insere_ordenado(int elemento, int valor); // Insere o elemento info de maneira ordenada na lista
	bool retiraEscolha(int elemento);
	int retornaPeso(int elemento);
	int retornaVertice(int elemento);
};