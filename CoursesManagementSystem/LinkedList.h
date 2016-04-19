#include "Node.h"
using namespace std;

#ifndef LinkedList_H
#define LinkedList_H


template<class T> 
class List
{
public:
	List();
	List(T d);
	bool IsEmpty();
	void AddFront(T d);
	void RemoveFront();
	void AddEnd(T d);
	void RemoveEnd();
	int Find(T d);
	void Add(T d, int index);
	void Remove(int index);
	void Removedata(T d);
	//	string peek();
	Node<T>* peek();
	void PrintAll();
	void PrintAllRec();
	void clear();
	int size();
	~List();

private:
	Node<T>* head;
	void helper(Node<T> *n);
};





//#include"LinkedList.cpp"
#endif
