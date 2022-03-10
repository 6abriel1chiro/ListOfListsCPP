#pragma once
#include "Header.h"
#define TAM 100
template <class T>
class ListOfLists
{
private:
	Header<T> vec[TAM];
	int first;
	int last;
public:
	ListOfLists();
	~ListOfLists();
	void insertFirst(T criterio,T elem);
	void mostrar();
	List<T>* buscar(T criterio);

	void Delete(T criterio, T elem);
};
template <class T>
ListOfLists<T>::ListOfLists()
{
	first = -1;
	last = -1;
}
template <class T>
ListOfLists<T>::~ListOfLists()
{

}
template <class T>
void ListOfLists<T>::insertFirst(T criterio, T elem)
{
	bool result = false;
	if (first == -1 and last == -1)
	{
		first = TAM / 2;
		last = TAM / 2;
		vec[first].setCriterio(criterio);
		vec[first].getList()->InsertFirst(elem);
	}
	else
	{
		int aux = first;
		while (criterio != vec[aux].getCriterio() && aux != last)
		{
			if (aux == TAM - 1)
			{
				aux = 0;
			}
			else
			{
				aux ++;
			}
		}
		if (criterio == vec[aux].getCriterio())
		{
			vec[aux].getList()->InsertFirst(elem);
		}
		else
		{
			if (first == 0)
			{
				if (last == TAM - 1)
				{
					first = TAM - 1;
					result = true;
				}
			}
			else
			{
				if (last != first - 1)
				{
					first = first - 1;
					result = true;
				}
			}
		}

	}
	if (result == true)
	{
		vec[first].setCriterio(criterio);
		vec[first].getList()->InsertFirst(elem);
	}
}
template <class T>
void ListOfLists<T>::mostrar()
{
	int aux = first;
	if (first == -1 and last == -1)
	{
		cout<<"lista vacia";
	}
	else
	{
		while(aux!=last)
		{
			cout << "*"<<vec[aux].getCriterio()<<"*" << endl;
			vec[aux].getList()->showList();
			if (aux == TAM - 1)
			{
				aux = 0;
			}
			else
			{
				aux++;
			}
		}
		cout << vec[aux].getCriterio() << endl;
		vec[aux].getList()->showList();
	}
}
template <class T>
List<T>* ListOfLists<T>::buscar(T criterio)
{
	List<T>* dato = NULL;
	if (first == -1 && last == -1)
	{
		cout<<"lista vacia";
	}
	else
	{
		int pos = first;
		while (pos != last)
		{
			if (pos != TAM - 1)
			{
				if (criterio == vec[pos].getCriterio())
				{
					dato= vec[pos].getList();
				}
				pos++;
			}
			else
			{
				if (criterio == vec[pos].getCriterio())
				{
					dato = vec[pos].getList();
				}
				pos = 0;
			}
		}
		if (pos == last)
		{
			if (criterio == vec[pos].getCriterio())
			{
				dato = vec[pos].getList();
			}
		}
	}
	return dato;
}
template <class T>
void ListOfLists<T>::Delete(T criterio, T elem)
{
	bool deleted;
	if (first == -1 && last == -1)
	{
		deleted = false;
		cout<<"lista vacia";
	}
	else
	{
		int pos = first;
		while (pos != last)
		{
			if (pos != TAM - 1)
			{
				if (criterio == vec[pos].getCriterio())
				{
					deleted = vec[pos].getList()->DeleteElem(elem);
				}
				pos++;
			}
			else
			{
				if (criterio == vec[pos].getCriterio())
				{
					deleted = vec[pos].getList()->DeleteElem(elem);
				}
				pos = 0;
			}
		}
		if (pos == last)
		{
			if (criterio == vec[pos].getCriterio())
			{
				deleted = vec[pos].getList()->DeleteElem(elem);
			}
		}
	}

}


