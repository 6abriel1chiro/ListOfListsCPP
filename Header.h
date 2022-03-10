#pragma once
#include "List.h"
template <class T>
class Header
{
private:
	List<T>* lista;
	T criterio;
public:
	Header();
	void setCriterio(T c);
	T getCriterio();
	List<T>* getList();
};
template <class T>
Header<T>::Header()
{
	lista = new List<T>();
}
template <class T>
void Header<T>::setCriterio(T c)
{
	this->criterio = c;
}
template <class T>
T Header<T>::getCriterio()
{
	return criterio;
}
template <class T>
List<T>* Header<T>::getList()
{
	return lista;
}
