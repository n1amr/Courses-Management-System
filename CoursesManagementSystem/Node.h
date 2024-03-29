#ifndef Node_H
#define Node_H

template<class T>
class Node
{
public:
	Node();
	Node(T d);
	~Node();
	void SetData(T d);
	void SetNext(Node<T>* n);
	T GetData();
	Node* GetNext();
	template<class LIST_T>
	friend class List;
	T operator*();

private:
	T data;
	Node<T>* next;

};

#include"Node.cpp"
#endif
