#ifndef Node_H
#define Node_H
template<class T> class List
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
private:
	T data;
	Node<T>* next;
	friend class List<T>;
};

#include"Node.cpp"
#endif
