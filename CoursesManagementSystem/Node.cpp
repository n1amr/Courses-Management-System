#ifndef _NODE_CPP_
#define _NODE_CPP_

#include"Node.h"

template<class T>
Node<T>::Node()
{
	//data = 0;
	next = nullptr;
}

template<class T>
Node<T>::Node(T d) :data(d), next(nullptr){};

template<class T>
void Node<T>::SetData(T d)
{
	data = d;
}

template<class T>
T Node<T>::GetData()
{
	return data;
}

template<class T>
Node<T>* Node<T>::GetNext()
{
	return next;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
void Node<T>::SetNext(Node<T>*n)
{
	next = n;
}

#endif
