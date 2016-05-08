#ifndef BinarySearchTree_H_
#define BinarySearchTree_H_
#include"TreeNode.h"
template <class T>
class BST
{
public:
	BST();
	BST(int (*compare)(T, T));
	BST(TreeNode<T> *root);
	TreeNode<T>* Search(T d);
	bool Insert(T d);
	void Remove(T d);
	TreeNode<T>* getRoot();
	TreeNode<T>* getRightSubtree();
	TreeNode<T>* getLeftSubtree();
	bool isEmpty();
	bool isLeaf(TreeNode<T>* t);
	void PrintInorder();
	
private:
	TreeNode<T> *Root;
	void PrintInorderhelper(TreeNode<T>* ptr);
	int (*comparator)(T, T);
};

#include"BST.cpp"
#endif
