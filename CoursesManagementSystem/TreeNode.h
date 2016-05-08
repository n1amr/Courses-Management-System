#ifndef TreeNode_H_
#define TreeNode_H_
template <class T>
class TreeNode
{
public:
	TreeNode(T x =0, TreeNode<T> *left = nullptr, TreeNode<T> *right = nullptr);
    T GetData();
	TreeNode<T>* GetLeft();
	TreeNode<T>* GetRight();
	void SetData(T d);
	void SetLeft(TreeNode<T>* left);
	void SetRight(TreeNode<T>* right);
private:
	TreeNode<T> *Left;
	TreeNode<T> *Right;
	T Data;
	template <class BST_T> 
	friend class BST;
};

#include"TreeNode.cpp"
#endif