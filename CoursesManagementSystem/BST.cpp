#ifndef BinarySearchTree_CPP_
#define BinarySearchTree_CPP_
#include"BST.h"
#include<iostream>
template<class T>
BST<T>::BST()
{
	Root = nullptr;

}


template<class T>
BST<T>::BST(TreeNode<T> *root){
	this->Root = root;
}

template<class T>
TreeNode<T>* BST<T>::Search(T d){
	if (isEmpty())
		return nullptr;
	TreeNode<T>*tmp = Root;
	while (tmp!=nullptr)
	{
		if (tmp->Data == d)
			return tmp;
		else if (d > tmp->Data)
			tmp = tmp->Right;
		else
			tmp = tmp->Left;
	}
	return nullptr;
}
template<class T>
bool BST<T>::Insert(T d){
	if (isEmpty()){
		Root = new TreeNode<T>(d); return true;
	}
	TreeNode<T> *tmp = Root;
	while (tmp!=nullptr){
		if (tmp->Data == d) return false;
		else if (d > tmp->Data)
			if (tmp->Right == nullptr){
				TreeNode<T> * newnode = new TreeNode<T>(d);
				tmp->Right = newnode;
				return true;
			}
			else
				tmp = tmp->Right;
		else{
			if (tmp->Left == nullptr){
				TreeNode<T> * newnode = new TreeNode<T>(d);
				tmp->Left = newnode;
				return true;
			}
			else
				tmp = tmp->Left;
		}
	}	
  	return false;
}
template<class T>
void BST<T>::Remove(T d){
	if (isEmpty()) return ;
	if (Search(d) == nullptr)return;
	TreeNode<T>*tmp = Root;
	TreeNode<T>*parent = nullptr;
	char child;
	while (tmp != nullptr)
	{
		if (tmp->Data == d)
			break;
		else if (d > tmp->Data){
			parent = tmp;
			tmp = tmp->Right;
			child = 'R';
		}
		else{
			parent = tmp;
			tmp = tmp->Left;
			child = 'L';
		}
	}
	//if want to delete is leaf 
	if (isLeaf(tmp))
	{
		if (parent != nullptr)
			if (child == 'L')
				parent->Left = nullptr;
			else  // child is right 
				parent->Right = nullptr;
		else
			Root = nullptr;
		return;
	}
	//if has one child right  
	else if (tmp->Left==nullptr){
		if (parent != nullptr){
			if (child == 'R')
				parent->Right = tmp->Right;
			else
				parent->Left = tmp->Right;
		}
		else
			Root = tmp->Right;
	}
	//if has one child left
	else if (tmp->Right==nullptr){
		if (parent != nullptr){
			if (child == 'R')
				parent->Right = tmp->Left;
			else
				parent->Left = tmp->Left;
		}
		else
			Root = tmp->Left;

	}
	// if has 2 childs
	else{
		
        TreeNode<T> * leftChild = tmp->Left;
		if (leftChild->Right == nullptr){
			tmp->Data=leftChild->Data;
		    tmp->Left=leftChild->Left;
		}

		TreeNode<T>* parent2 = leftChild;
		
		while (leftChild->Right!=nullptr){   	
			parent2 = leftChild;
			leftChild = leftChild->Right;
		}
		tmp->Data = leftChild->Data;
		parent2->Right = nullptr;
	
	}
}
template<class T>
void BST<T>::PrintInorder()
{
	PrintInorderhelper(Root);
}
template<class T>
void BST<T>::PrintInorderhelper(TreeNode<T> *ptr){
	if (ptr != nullptr)
	{
		if (ptr->Left != nullptr)
		{
			PrintInorderhelper(ptr->Left);
		}
		std::cout << ptr->Data << " ";
		if (ptr->Right != nullptr)
		{
			PrintInorderhelper(ptr->Right);
		}
		
		
	}
	else
		std::cout << "the tree is empty\n";




}
template<class T>
TreeNode<T>* BST<T>::getRoot(){
	return Root;
}
template<class T>
TreeNode<T>* BST<T>::getRightSubtree(){
	return Root->Right;
}
template<class T>
TreeNode<T>* BST<T>::getLeftSubtree(){
	return Root->Left;
}
template<class T>
bool BST<T>::isEmpty(){
	if (Root == nullptr)
		return true;
	return false;
}
template<class T>
 bool BST<T>::isLeaf(TreeNode<T>* t){
	if (isEmpty())return false;
	if (t->Left==nullptr && t->Right == nullptr)
		return true;
	return false;
}

#endif