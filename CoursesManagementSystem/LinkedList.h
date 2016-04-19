#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"
using namespace std;


template<class T>
class List
{
public:
	List();
	List(T d);
	bool empty();
	void push_front(T d);
	void pop_front();
	void push_back(T d);
	void pop_back();
	int find(T d);
	void insert(T d, int index);
	void erase(int index);
	void remove(T d);
	//	string peek();
	Node<T>* begin();
	Node<T>* end();
	void print_all();
	void PrintAllRec();
	void clear();
	int size();
	~List();

private:
	Node<T>* head;
	void helper(Node<T> *n);
};

#include"LinkedList.cpp"
#endif
