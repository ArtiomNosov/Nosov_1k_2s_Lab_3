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
class BinaryTree {
private:
	struct Node { // ����
		Node* Left; // ��������� �� ����� �������
		Node* Right; // �� ������ �������
		T* Value; // ��������� �� ������� (float || complex)
	};
	BinaryTree<T>* RoundForMap(T* (*Fun)(T*), Node* Original, BinaryTree<T>* Result); // ���������� ����� �������� � �������������� �� ��� ��������
	BinaryTree<T>* RoundForWhere(bool (*Fun)(T*), Node* Original, BinaryTree<T>* Result); 
	bool RoundForSearch(Node* tree, Node* value , bool); // ����� ��� ������ 
	bool RoundForSearchTree(Node* tree1, Node* tree2 , bool result);
	void TreePrintKPL(Node* tree); // ����� KPL
	void TreePrintLKP(Node* tree); // ����� ���
	void FreeMem(Node *tree); // ������� ������
	string ToStringKPL(Node* tree , string result);
	string ToStringLKP(Node* tree , string result);
	Node* Root; // ������ ������
	BinaryTree<T>* RoundForCut(Node* tree, bool find, T* cutElem, BinaryTree<T>* Result);
public:
	Node* GetRoot() { return Root; } // ������ ��� �����
	void PrintTree(BinaryTree<T>* Root); // ����� ������
	BinaryTree<T>(); // ����������� 
	~BinaryTree<T>(); // �������� ������
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
	BinaryTree<T>* Map(T* (*Fun)(T*)); // ������ �������������� �������� �� ������ ������� ������
	BinaryTree<T>* Where(bool (*Fun)(T*)); // ������ �������� ������ ������� ������ ����������
	bool SearchItem(Node *tree,T* Value); // ����� �������� �� ���������
	bool SearchTree(BinaryTree<T>* tree1 , BinaryTree<T>* tree2); // ����� ��������� �� ���������
	BinaryTree<T>* Cut(BinaryTree<T>* tree, T* cutElem); // ����������
	string ToString(); // ��������� � ������
};

template<typename T>
void BinaryTree<T>::TreePrintKPL(Node * tree)
{
	if (tree != nullptr)
	{
		cout << ToStrings(*(tree->Value)) << "\t";
		TreePrintKPL(tree->Right);
		TreePrintKPL(tree->Left);
	}
};

template<typename T>
void BinaryTree<T>::TreePrintLKP(Node * tree)
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
void BinaryTree<T>::FreeMem(Node * tree)
{
	if (tree != NULL) {
		FreeMem(tree->Left);
		FreeMem(tree->Right);
		delete tree->Value;
	}
}

template<typename T>
string BinaryTree<T>::ToStringKPL(Node * tree, string result)
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
string BinaryTree<T>::ToStringLKP(Node * tree, string result)
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
void BinaryTree<T>::PrintTree(BinaryTree<T>* tree)
{
	cout << tree->ToString() << endl;
};

template<typename T>
BinaryTree<T>::~BinaryTree<T>()
{
	FreeMem(Root);
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::Map(T* (*Fun)(T*))
{
	BinaryTree<T> *Result = new BinaryTree<T>();
	Result = RoundForMap(Fun, Root, Result);
	return Result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::Where(bool(*Fun)(T*))
{
	BinaryTree<T>* Result = new BinaryTree<T>();
	Result = RoundForWhere(Fun ,Root , Result);
	return Result;
}

template<typename T>
bool BinaryTree<T>::SearchItem(Node* tree, T* Value) 
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
bool BinaryTree<T>::SearchTree(BinaryTree<T>* tree1, BinaryTree<T>* tree2) // �����������
{
	bool result = false;
	result = RoundForSearchTree(tree1->GetRoot(), tree2->GetRoot(), result);
	return result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::Cut(BinaryTree<T>* tree, T* cutElem)
{
	BinaryTree<T>* result = new BinaryTree<T>();
	bool find = false;
	result = RoundForCut(tree->GetRoot(), find, cutElem, result);
	return result;
}

template<typename T>
string BinaryTree<T>::ToString()
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
BinaryTree<T>* BinaryTree<T>::RoundForCut(Node* tree, bool find, T* cutElem, BinaryTree<T>* Result)
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
BinaryTree<T>* BinaryTree<T>::RoundForWhere(bool(*Fun)(T*), Node* Original, BinaryTree<T>* Result)
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
BinaryTree<T>::BinaryTree()
{
	Root = nullptr;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::RoundForMap(T* (*Fun)(T*), Node* Original, BinaryTree<T>* Result)
{
	if (Original != nullptr) {
		Result->Add(Fun(Original->Value));
		Result = RoundForMap(Fun, Original->Left, Result);
		Result = RoundForMap(Fun, Original->Right, Result);
	}
	return Result;
}

template<typename T>
bool BinaryTree<T>::RoundForSearch(Node* tree, Node* Node_value , bool Result)
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
bool BinaryTree<T>::RoundForSearchTree(Node* root1, Node* root2, bool result)
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