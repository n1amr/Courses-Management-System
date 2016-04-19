#ifndef _List_CPP_
#define _List_CPP_

#include"LinkedList.h"
#include<stdio.h>

template<class T>
List<T>::List()
{
	head = nullptr;
}
template<class T>
List<T>::List(T d)
{
	head = new Node<T>(d);
}

template<class T>
bool List<T>::empty()
{
	if (head == nullptr)
		return true;
	return false;
}

template<class T>
void List<T>::push_front(T d)
{
	Node<T> *nw = new Node<T>(d);
	nw->next = head;
	head = nw;
}

template<class T>
void List<T>::pop_front()
{
	if (empty()) return;
	Node<T> *temp = head;
	head = temp->next;
	delete temp;
}

template<class T>
void List<T>::push_back(T d)
{
	if (empty())
	{
		push_front(d);
		return;
	}
	Node<T> *temp = head; //initialization
	while (temp->next != nullptr) //itteration till finding the end of List
		temp = temp->next;
	Node<T> *nw = new Node<T>(d);
	temp->next = nw;
}
template<class T>
void List<T>::pop_back()
{
	if (empty()) return;
	if (head->next == nullptr)
	{
		pop_front();
		return;
	}
	Node<T> *prev = head;
	Node<T> *last = prev->next;
	while (last->next != nullptr)
	{
		last = last->next;
		prev = prev->next;
	}
	prev->next = nullptr;
	delete last;
}



template<class T>
int List<T>::find(T d)
{
	if (empty()) return -1;
	Node<T> *tmp = head;
	int index = 0;
	while (tmp != nullptr)
	{

		if (tmp->data == d)
		{
			return index;
			index++;

		}
		tmp = tmp->next;
		index++;
	}
	return -1;
}

template<class T>
void List<T>::insert(T d, int index)
{
	if (index < 0)
		return;
	if (index == 0)
	{
		push_front(d);
		return;
	}
	if (index> size() - 1)
	{
		printf("you exceed the limit of List.. you can add index till index %d \n", size() - 1);
		return;
	}
	Node<T>* temp = head;
	while (--index != 0)
		temp = temp->next;
	Node<T>* temp2 = temp->next;
	Node<T>* nw = new Node<T>(d);
	temp->next = nw;
	nw->next = temp2;
}

template<class T>
void List<T>::erase(int index)
{
	if (empty()) return;
	if (index < 0) return;
	if (index == 0)
	{
		pop_front();
		return;
	}
	Node<T>* prev = head;
	Node<T>* tmp = prev->next;
	while (--index != 0)
	{
		tmp = tmp->next;
		prev = prev->next;
	}
	prev->next = tmp->next;
	delete tmp;
}

template<class T>
void List<T>::remove(T d)
{
	int i;
	i = Find(d);
	erase(i);
}

template<class T>
void List<T>::print_all()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		printf("%d \n", temp->data);
		temp = temp->next;
	}
}

template<class T>
Node<T>* List<T>::begin()
{
	return head;
}

template<class T>
Node<T>* List<T>::end()
{
	if(empty())
		return nullptr;

	Node<T>* tmp = head;
	while(tmp->GetNext() != nullptr)
		tmp = tmp->GetNext();
	return tmp;
}

template<class T>
void List<T>::helper(Node<T> *n)
{
	if (n != nullptr)
	{
		printf("%d \n", n->data);
		helper(n->next);
	}
}

template<class T>
void List<T>::PrintAllRec()
{
	helper(head);
}

template<class T>
void List<T>::clear()
{
	while (!empty())
		pop_front();
}

template<class T>
int List<T>::size()
{
	int size = 0;
	Node<T> *tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		size++;
	}
	return size;
}

template<class T>
List<T>::~List()
{
	clear();
}

#endif
