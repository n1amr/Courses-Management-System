#ifndef TreeNode_cpp_
#define TreeNode_cpp_
#include"TreeNode.h"

template <class T>
TreeNode<T>::TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : Data(x), Left(left), Right(right) {
}

template <class T>
T TreeNode<T>::GetData() {
	return Data;
}

template <class T>
TreeNode<T>* TreeNode<T>::GetLeft() {
	return Left;
}

template <class T>
TreeNode<T>* TreeNode<T>::GetRight() {
	return Right;
}

template <class T>
void TreeNode<T>::SetData(T d) {
	Data = d;
}

template <class T>
void TreeNode<T>::SetLeft(TreeNode<T>* left) {
	Left = left;
}

template <class T>
void TreeNode<T>::SetRight(TreeNode<T>* right) {
	Right = right;
}

#endif