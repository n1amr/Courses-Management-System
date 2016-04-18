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
	head = new Node(d);
}

template<class T>
bool List<T>::IsEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

template<class T>
void List<T>::AddFront(T d)
{
	Node *nw = new Node(d);
	nw->next = head;
	head = nw;
}

template<class T>
void List<T>::RemoveFront()
{
	if (IsEmpty()) return;
	Node *temp = head;
	head = temp->next;
	delete temp;
}

template<class T>
void List<T>::AddEnd(T d)
{
	if (IsEmpty())
	{
		AddFront(d);
		return;
	}
	Node *temp = head; //initialization
	while (temp->next != nullptr) //itteration till finding the end of list
		temp = temp->next;
	Node *nw = new Node(d);
	temp->next = nw;
}
template<class T>
void List<T>::RemoveEnd()
{
	if (IsEmpty()) return;
	if (head->next == nullptr)
	{
		RemoveFront();
		return;
	}
	Node *prev = head;
	Node *last = prev->next;
	while (last->next != nullptr)
	{
		last = last->next;
		prev = prev->next;
	}
	prev->next = nullptr;
	delete last;
}



template<class T>
int List<T>::Find(T d)
{
if (IsEmpty()) return -1;
Node *tmp = head;
int index = 0;
while (tmp!=nullptr)
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
void List<T>::Add(T d, int index)
{
	if (index < 0)
		return;
	if (index == 0)
	{
		AddFront(d);
		return;
	}
	if (index> size() - 1)
	{
		printf("you exceed the limit of list.. you can add index till index %d \n", size() - 1);
		return;
	}
	Node* temp = head;
	while (--index != 0)
		temp = temp->next;
	Node* temp2 = temp->next;
	Node* nw = new Node(d);
	temp->next = nw;
	nw->next = temp2;
}

template<class T>
void List<T>::Remove(int index)
{
	if (IsEmpty()) return;
	if (index < 0) return;
	if (index == 0)
	{
		RemoveFront();
		return;
	}
	Node* prev = head;
	Node* tmp = prev->next;
	while (--index != 0)
	{
		tmp = tmp->next;
		prev = prev->next;
	}
	prev->next = tmp->next;
	delete tmp;
}

template<class T>
void List<T>::Removedata(T d)
{
int i;
i= Find(d);
Remove(i);
}

template<class T>
void List<T>::PrintAll()
{
	Node* temp = head;
	while (temp != nullptr)
	{

		printf("%d \n", temp->data);
		temp = temp->next;
	}
}

template<class T>
 Node* List<T>::peek()
{
	return head;
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
	while (!IsEmpty())
		RemoveFront();
}

template<class T>
int List<T>::size()
{
	int size = 0;
	Node *tmp = head;
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

