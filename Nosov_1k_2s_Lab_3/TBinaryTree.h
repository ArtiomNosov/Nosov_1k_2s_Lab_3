#include "TBinaryTree.h"
#ifndef _TTREE_H_
#define _TTREE_H_

//struct Node { // ����
//		Node* Left; // ��������� �� ����� �������
//		Node* Right; // �� ������ �������
//		bool left_is_thread, right_is_thread; // ������� � ��� ��� ��������� �� ������� ��� ��� �� ����
//		T* Value; // ��������� �� ������� (float || complex)
//	};

template <typename T>
class TTBinaryTree 
{
	struct Node { // ����
		Node* Left; // ��������� �� ����� �������
		Node* Right; // �� ������ �������
		bool left_is_thread, right_is_thread; // ������� � ��� ��� ��������� �� ������� ��� ��� �� ����
		T* Value; // ��������� �� ������� (float || complex)
	};
	TBinaryTree<T>* RoundForMap(T* (*Fun)(T*), Node* Original, TBinaryTree<T>* Result); // ���������� ����� �������� � �������������� �� ��� ��������
	TBinaryTree<T>* RoundForWhere(bool (*Fun)(T*), Node* Original, TBinaryTree<T>* Result); 
	bool RoundForSearch(Node* tree, Node* value , bool); // ����� ��� ������ 
	bool RoundForSearchTree(Node* tree1, Node* tree2 , bool result);
	void TreePrintKPL(Node* tree); // ����� KPL
	void TreePrintLKP(Node* tree); // ����� ���
	void FreeMem(Node *tree); // ������� ������
	string ToStringKPL(Node* tree , string result);
	string ToStringLKP(Node* tree , string result);
	TBinaryTree<T>* RoundForCut(Node* tree, bool find, T* cutElem, TBinaryTree<T>* Result);
	Node* Root; // ������ ������

public:
	Node* GetRoot() { return Root; } // ������ ��� �����
	void PrintTree(TBinaryTree<T>* Root); // ����� ������
	TBinaryTree<T>(); // ����������� 
	~TBinaryTree<T>(); // �������� ������
	void Add(T* Value) { AddNode(Value, Root); } // ����������
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
	TBinaryTree<T>* Map(T* (*Fun)(T*)); // ������ �������������� �������� �� ������ ������� ������
	TBinaryTree<T>* Where(bool (*Fun)(T*)); // ������ �������� ������ ������� ������ ����������
	bool SearchItem(Node *tree,T* Value); // ����� �������� �� ���������
	bool SearchTree(TBinaryTree<T>* tree1 , TBinaryTree<T>* tree2); // ����� ��������� �� ���������
	TBinaryTree<T>* Cut(TBinaryTree<T>* tree, T* cutElem); // ����������
	string ToString(); // ��������� � ������


	Node* fParent(Node* node)
	{
		Node* tmp = node->Left;
		if (node->left_is_tread)
			while (tmp->right_is_thread)
				tmp = tmp->Right; // ������ �� ���� 
		return tmp;
	};

	Node* fSon(Node* node)
	{
		Node* tmp = mode->Right;
		if (node->right_is_thread)
			while (tmp->left_is_thread) // ����� �� ���� 
				tnp = tmp->Left; //{ ������� �� ����� ����� }
		return tmp
	};

	

	void LeftIn(Node* x, Node* p)
	{
		Node* q;
		p->Left = x->Left;
		p->left_is_thread = x->left_is_thread;
		x->Left: = p;
		x->left_is_thread = true;
		p->Right: = x;
		p->right_is_thread = false;
		if (p->left_is_thread)
		{
			//--------������������� ����� � ����������������--------
			q  = Inp(p);    q->Right = p;   q->right_is_thread = false;
		};

	}



};
template<typename T>
void TBinaryTree<T>::TreePrintKPL(Node * tree)
{
	if (tree != nullptr)
	{
		cout << ToStrings(*(tree->Value)) << "\t";
		TreePrintKPL(tree->Right);
		TreePrintKPL(tree->Left);
	}
};

template<typename T>
void TBinaryTree<T>::TreePrintLKP(Node * tree)
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
void TBinaryTree<T>::FreeMem(Node * tree)
{
	if (tree != NULL) {
		FreeMem(tree->Left);
		FreeMem(tree->Right);
		delete tree->Value;
	}
}

template<typename T>
string TBinaryTree<T>::ToStringKPL(Node * tree, string result)
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
string TBinaryTree<T>::ToStringLKP(Node * tree, string result)
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
void TBinaryTree<T>::PrintTree(TBinaryTree<T>* tree)
{
	cout << tree->ToString() << endl;
};

template<typename T>
TBinaryTree<T>::~TBinaryTree<T>()
{
	FreeMem(Root);
}

template<typename T>
TBinaryTree<T>* TBinaryTree<T>::Map(T* (*Fun)(T*))
{
	TBinaryTree<T> *Result = new TBinaryTree<T>();
	Result = RoundForMap(Fun, Root, Result);
	return Result;
}

template<typename T>
TBinaryTree<T>* TBinaryTree<T>::Where(bool(*Fun)(T*))
{
	TBinaryTree<T>* Result = new TBinaryTree<T>();
	Result = RoundForWhere(Fun ,Root , Result);
	return Result;
}

template<typename T>
bool TBinaryTree<T>::SearchItem(Node* tree, T* Value) 
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
bool TBinaryTree<T>::SearchTree(TBinaryTree<T>* tree1, TBinaryTree<T>* tree2) // �����������
{
	bool result = false;
	result = RoundForSearchTree(tree1->GetRoot(), tree2->GetRoot(), result);
	return result;
}

template<typename T>
TBinaryTree<T>* TBinaryTree<T>::Cut(TBinaryTree<T>* tree, T* cutElem)
{
	TBinaryTree<T>* result = new TBinaryTree<T>();
	bool find = false;
	result = RoundForCut(tree->GetRoot(), find, cutElem, result);
	return result;
}

template<typename T>
string TBinaryTree<T>::ToString()
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
TBinaryTree<T>* TBinaryTree<T>::RoundForCut(Node* tree, bool find, T* cutElem, TBinaryTree<T>* Result)
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
TBinaryTree<T>* TBinaryTree<T>::RoundForWhere(bool(*Fun)(T*), Node* Original, TBinaryTree<T>* Result)
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
TBinaryTree<T>::TBinaryTree()
{
	Root = nullptr;
}

template<typename T>
TBinaryTree<T>* TBinaryTree<T>::RoundForMap(T* (*Fun)(T*), Node* Original, TBinaryTree<T>* Result)
{
	if (Original != nullptr) {
		Result->Add(Fun(Original->Value));
		Result = RoundForMap(Fun, Original->Left, Result);
		Result = RoundForMap(Fun, Original->Right, Result);
	}
	return Result;
}

template<typename T>
bool TBinaryTree<T>::RoundForSearch(Node* tree, Node* Node_value , bool Result)
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
bool TBinaryTree<T>::RoundForSearchTree(Node* root1, Node* root2, bool result)
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