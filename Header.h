#include <iostream>
#include<vector>
using namespace std;
class vertex
{
public:
	vertex *next;
	vertex* prev;
	int value;
	vector<vertex*>vertices;//multiple pointers of type vector and name is vertices  
	vertex()
	{
		next = nullptr;
		prev = nullptr;
		value = 0;
	}
	vertex(vertex* s, vertex* x, int num)
	{
		next = s;
		prev = x;
		value = num;
	}	
};
class Graph
{
public:
	vertex *chain;
	Graph()
	{
		chain = NULL;
		vector <vertex*> edges;//vector edges of type vertex pointer
	}

	void addvertex(int val)
	{

		if (chain == NULL)
		{
			//add at front
			vertex *newelement = new vertex(NULL, NULL, val);
			chain = newelement;
			return;
		}
		//add at end
		vertex *newelement = new vertex(NULL, NULL, val);
		vertex *curr = chain;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newelement;
		newelement->prev = curr;
		return;
	}
	void addEdge(int n, int edge)
	{
		vertex *e = chain;
		vertex *curr = chain;

		if (curr = NULL)
		{
			cout << "There are no elements in your graph to connect";
			return;
		}
		while (e->next != NULL || e->value != edge)
		{
			cout << "Looking";
			e = e->next;
		}
		if (e->value != edge)
		{
			cout << "Your edge node doesn't exist";
			return;
		}
		while (curr->next != NULL || curr->value != n)
		{
			cout << "Looking for main node";
			curr = curr->next;
		}
		if (curr->value != n)
		{
			cout << "Could not find the main node";
			return;
		}
		curr->vertices.push_back(e);
		cout << "Edge connected";
		return;
	}
};

