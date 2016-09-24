#include "Lista.h"

No::No(int elemento)
{
	this->dado = elemento;
	this->proximo = NULL;
}

No::No(int elemento, int valor)
{
	dado = elemento;
	this->valor = valor;
	proximo = NULL;
}

No::~No()
{
}

int No::retorna_dado()
{
	return this->dado;
}

int No::retorna_valor()
{
	return this->valor;
}

No * No::retorna_proximo()
{
	return this->proximo;
}

void No::insere_proximo(No * proximo)
{
	this->proximo = proximo;
}

No *No::insere_depois(int elemento)
{
	No * p = new No(elemento);

	this->proximo = p;

	return p;
}

 No *No::insere_depois(int elemento, int valor)
{
	No * p = new No(elemento, valor);

	this->proximo=p;

	return p;
}
  
 void No::mostra_nos()
 {
	 No * p = this;

	 while (p != NULL)
	 {
		 cout << " " << p->dado;
		 p = p->proximo;
	 }

	 cout << endl;
 }

 int No::retira_depois()
 {
	 int aux;

	 if (this->proximo == NULL)
	 {
		 cout << "Não há nó para ser retirado. Retorno setado em 0" << endl;
		 return 0;
	 }
	 else
	 {
		 aux = this->proximo->dado;
		 this->proximo = this->proximo->proximo;

		 return aux;
	 }
 }

 No * No::retira_primeiro_no()
 {
	 No * p;

	 p = this->proximo;

	 return p;
 }

 No *No::retira_ultimo_no()
 {
	 No * p, * q;

	 p = this;

	 while (p->proximo!=NULL)
	 {
		 q = p;
		 p = p->proximo;
	 }

	 q = p->proximo;

	 return q;
 }

 void No::insere_ordenado_no(int elemento, int valor)
 {
	 No *p, *q;
		
	 p = this;
	 q = this;
	 p = p->proximo;

	 while(elemento > p->dado)
	 {
		 q = p;
		 p = p->proximo;
	 }
	 
	 q->proximo = q->insere_depois(elemento, valor);
	 q->proximo->proximo=p;
}

 Lista::Lista()
 {
	 this->primeiro = this->ultimo = NULL;
 }

 Lista::~Lista()
 {
 }

 bool Lista::vazia()
{
	if (this->primeiro == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

 bool Lista::busca(int elemento)
 {
	 No *p = this->primeiro;

	 while (elemento != p->retorna_dado())
	 {
		 if (p->retorna_dado() > elemento || p == this->ultimo)
			 return false;

		 p = p->retorna_proximo();
	 }

	 return true;
 }

int Lista::ultimo_elemento()
{
	return this->ultimo->retorna_dado();
}

void Lista::insere_primeiro(int elemento, int valor)
{
	No *aux = new No(elemento, valor);

	if (this->vazia() == true)
	{
		this->primeiro = aux;
		this->ultimo = this->primeiro;
	}
	else
	{
		aux->insere_proximo(this->primeiro);
		this->primeiro = aux;
	}
}

void Lista::insere_ultimo(int elemento, int valor)
{
	if (this->vazia() == true)
	{
		this->insere_primeiro(elemento, valor);
	}
	else
	{
		this->ultimo = this->ultimo->insere_depois(elemento, valor);
	}
}

void Lista::mostra_lista()
{
	if (this->vazia() == true)
	{
		cout << "Lista vazia." << endl;
	}
	else
	{
		this->primeiro->mostra_nos();
	}
}

int Lista::retira_ultimo()
{
	int aux;

	if (this->vazia() == true)
	{
		cout << "Lista Vazia !!! Retorno setado como 0" << endl;
		return 0;
	}
	else
	{
		aux = this->ultimo_elemento();

		if (this->primeiro == this->ultimo)
		{
			this->primeiro = this->ultimo = NULL;
		}
		else
		{
			this->ultimo = this->primeiro->retira_ultimo_no();
		}

		return aux;
	}
}


int Lista::retira_primeiro()
{
	if (this->vazia() == true)
	{
		//cout << "Lista Vazia !!! Retorno setado como 0" << endl;
		return 0;
	}
	else
	{
		if (this->primeiro == this->ultimo)
		{
			return this->retira_ultimo();
		}
		else
		{
			this->primeiro = this->primeiro->retira_primeiro_no();
		}
	}
}

void Lista::insere_ordenado(int elemento, int valor)
{
	if (this->vazia() == true)
	{
		this->insere_primeiro(elemento, valor);
	}
	else if (elemento < this->primeiro->retorna_dado())
	{
		this->insere_primeiro(elemento, valor);
	}
	else if (elemento >= this->ultimo->retorna_dado())
	{
		this->insere_ultimo(elemento, valor);
	}
	else
	{
		this->primeiro->insere_ordenado_no(elemento, valor);
	}
}

bool Lista::retiraEscolha(int elemento)
{
	if (this->vazia() == true)
	{
		return false;
	}
	else
	{
		No *p = this->primeiro, *q = NULL;

		while (elemento != p->retorna_dado())
		{
			if (p->retorna_dado() > elemento || p == this->ultimo)
				return false;

			q = p;
			p = p->retorna_proximo();
		}

		if (p == this->primeiro)
		{
			this->retira_primeiro();
		}
		else if (p == this->ultimo)
		{
			this->retira_ultimo();
		}
		else
		{
			q->insere_proximo(p->retorna_proximo());
			delete p;
		}

		return true;
	}
}

int Lista::retornaValorElemento(int elemento)
{
	No *p = this->primeiro;

	while (elemento != p->retorna_dado())
	{
		p = p->retorna_proximo();
	}

	return p->retorna_valor();
}
