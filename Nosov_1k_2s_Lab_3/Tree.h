/*
*	Tree.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include "Function.h"
#include <queue>

using namespace std;

//	�������� ������
template <typename T>
class Tree {
private:
	struct Node { // ����
		Node* Left; // ��������� �� ����� �������
		Node* Right; // �� ������ �������
		T* Value; // ��������� �� ������� (float || complex)
	};
	Tree<T>* RoundForMap(T* (*Fun)(T*), Node* Original, Tree<T>* Result); // ���������� ����� �������� � �������������� �� ��� ��������
	Tree<T>* RoundForWhere(bool (*Fun)(T*), Node* Original, Tree<T>* Result); 
	bool RoundForSearch(Node* tree, Node* value , bool); // ����� ��� ������ 
	bool RoundForSearchTree(Node* tree1, Node* tree2 , bool result);
	void TreePrintKPL(Node* tree); // ����� KPL
	void TreePrintLKP(Node* tree); // ����� ���
	void FreeMem(Node *tree); // ������� ������
	string ToStringKPL(Node* tree , string result);
	string ToStringLKP(Node* tree , string result);
	Node* Root; // ������ ������
	Tree<T>* RoundForCut(Node* tree, bool find, T* cutElem, Tree<T>* Result);
public:
	Node* GetRoot() { return Root; } // ������ ��� �����
	void PrintTree(Tree<T>* Root); // ����� ������
	Tree<T>(); // ����������� 
	~Tree<T>(); // �������� ������
	Node* AddNode(T* Value, Node*& New_Node)
	{
		if (New_Node == nullptr)
		{
			New_Node = new Node;
			New_Node->Right = New_Node->Left = nullptr;
			New_Node->Value = Value;
			if (Root == nullptr)
				Root = New_Node;
		}
		else if (*Value < *(New_Node->Value))
		{
			New_Node->Left = AddNode(Value, New_Node->Left);
		}
		else if (*Value >= *(New_Node->Value))
		{
			New_Node->Right = AddNode(Value, New_Node->Right);
		}
		return New_Node;
	}
	void Add(T* Value) { AddNode(Value, Root); } // ����������
	Tree<T>* Map(T* (*Fun)(T*)); // ������ �������������� �������� �� ������ ������� ������
	Tree<T>* Where(bool (*Fun)(T*)); // ������ �������� ������ ������� ������ ����������
	bool SearchItem(Node *tree,T* Value); // ����� �������� �� ���������
	bool SearchTree(Tree<T>* tree1 , Tree<T>* tree2); // ����� ��������� �� ���������
	Tree<T>* Cut(Tree<T>* tree, T* cutElem); // ����������
	string ToString(); // ��������� � ������
};

template<typename T>
void Tree<T>::TreePrintKPL(Node * tree)
{
	if (tree != nullptr)
	{
		cout << ToStrings(*(tree->Value)) << "\t";
		TreePrintKPL(tree->Right);
		TreePrintKPL(tree->Left);
	}
};

template<typename T>
void Tree<T>::TreePrintLKP(Node * tree)
{
	if (tree != nullptr)
	{
		cout << " < ";
		TreePrintLKP(tree->Left);
		cout << " > ";
		cout << " [ " <<ToStrings(*(tree->Value)) << " ] ( ";
		TreePrintLKP(tree->Right);
		cout << " ) ";
	}
	
};

template<typename T>
void Tree<T>::FreeMem(Node * tree)
{
	if (tree != NULL) {
		FreeMem(tree->left);
		FreeMem(tree->right);
		delete tree->Value;
	}
}

template<typename T>
string Tree<T>::ToStringKPL(Node * tree, string result)
{
	if (tree != nullptr) {
		result += "<" + ToStrings(*(tree->Value)) + "> ( ";
		result = ToStringKPL(tree->Right, result);
		result += ") [ ";
		result = ToStringKPL(tree->Left, result);
		result += "] ";
	}
	return result;
}

template<typename T>
string Tree<T>::ToStringLKP(Node * tree, string result)
{
	if (tree != nullptr) 
	{
		result += " ( ";
		result = ToStringLKP(tree->Left, result);
		result += " ) < " + ToStrings(*(tree->Value)) + " > [ ";
		result = ToStringLKP(tree->Right, result);
		result += " ] ";
		
	}
	return result;
}

template<typename T>
void Tree<T>::PrintTree(Tree<T>* tree)
{
	cout << tree->ToString() << endl;
};

template<typename T>
Tree<T>::~Tree<T>()
{
	FreeMem(Root);
}

template<typename T>
Tree<T>* Tree<T>::Map(T* (*Fun)(T*))
{
	Tree<T> *Result = new Tree<T>();
	Result = RoundForMap(Fun, Root, Result);
	return Result;
}

template<typename T>
Tree<T>* Tree<T>::Where(bool(*Fun)(T*))
{
	Tree<T>* Result = new Tree<T>();
	Result = RoundForWhere(Fun ,Root , Result);
	return Result;
}

template<typename T>
bool Tree<T>::SearchItem(Node* tree, T* Value) 
{
	Node* New_node = new Node;
	New_node->Value = Value;
	New_node->Left = nullptr;
	New_node->Right = nullptr;
	bool result = false;
	result =  RoundForSearch(tree, New_node , result);
	return result;
}

template<typename T>
bool Tree<T>::SearchTree(Tree<T>* tree1, Tree<T>* tree2) // �����������
{
	bool result = false;
	result = RoundForSearchTree(tree1->GetRoot(), tree2->GetRoot(), result);
	return result;
}

template<typename T>
Tree<T>* Tree<T>::Cut(Tree<T>* tree, T* cutElem)
{
	Tree<T>* result = new Tree<T>();
	bool find = false;
	result = RoundForCut(tree->GetRoot(), find, cutElem, result);
	return result;
}

template<typename T>
string Tree<T>::ToString()
{
	int choise;
	cout << "�������� ����� ��� ������ ������ � ������\n() - ����� \t<>-������ \t[] - ������:\n1. ���\n2. ���\n";
	cin >> choise;
	string result = "";
	switch (choise)
	{
	case 1:
		result = ToStringLKP(Root , result);
		return result;
		break;
	case 2:
		result = ToStringKPL(Root , result);
		return result;
		break;
	default:
		cout << "������ ������ �� ����������!";
		return 0;
		break;
	}
	
}

template<typename T>
Tree<T>* Tree<T>::RoundForCut(Node* tree, bool find, T* cutElem, Tree<T>* Result)
// find - ��� �� ������ ������� , Result - ����������� ���������
{
	if (tree != nullptr)
	{
		if (*(tree->Value) == *cutElem || find)
		{
			find = true;
			Result->Add(tree->Value);
		}
		Result = RoundForCut(tree->Left, find, cutElem, Result);
		Result = RoundForCut(tree->Right, find, cutElem, Result);
	}
	return Result;
}

template<typename T>
Tree<T>* Tree<T>::RoundForWhere(bool(*Fun)(T*), Node* Original, Tree<T>* Result)
{
	if (Original != nullptr) {
		if (Fun(Original->Value))
			Result->Add(Original->Value);
		Result = RoundForWhere(Fun, Original->Left, Result);
		Result = RoundForWhere(Fun, Original->Right, Result);
	}
	return Result;
}

template<typename T>
Tree<T>::Tree()
{
	Root = nullptr;
}

template<typename T>
Tree<T>* Tree<T>::RoundForMap(T* (*Fun)(T*), Node* Original, Tree<T>* Result)
{
	if (Original != nullptr) {
		Result->Add(Fun(Original->Value));
		Result = RoundForMap(Fun, Original->Left, Result);
		Result = RoundForMap(Fun, Original->Right, Result);
	}
	return Result;
}

template<typename T>
bool Tree<T>::RoundForSearch(Node* tree, Node* Node_value , bool Result)
{
	if (Node_value == nullptr) {
		return true;
	}
	else if ((tree == nullptr) && (Node_value != nullptr)) {
		return false;
	}
	else if (tree != nullptr) {
		if (*(tree->Value) == *(Node_value->Value)) {
			if (RoundForSearch(tree->Left, Node_value->Left, Result) && RoundForSearch(tree->Right, Node_value->Right, Result)) {
				return true;
			}
		}
		Result = RoundForSearch(tree->Left, Node_value, Result) || RoundForSearch(tree->Right, Node_value, Result);
	}
	return Result;
}

template<typename T>
bool Tree<T>::RoundForSearchTree(Node* root1, Node* root2, bool result)
{
	if (root2 == nullptr) {
		return true;
	}
	else if ((root1 == nullptr) && (root2 != nullptr)) {
		return false;
	}
	else if (root1 != nullptr) {
		if (*(root1->Value) == *(root2->Value)) {
			if (RoundForSearchTree(root1->Left, root2->Left, result) && RoundForSearchTree(root1->Right, root2->Right, result)) {
				return true;
			}
		}
		result = RoundForSearchTree(root1->Left, root2, result) || RoundForSearchTree(root1->Right, root2, result);
	}
	return result;
}

#endif