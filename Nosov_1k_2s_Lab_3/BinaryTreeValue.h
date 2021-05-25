#include <iostream>
#include "Function.h"
#include <queue>

using namespace std;

//	Бинарное дерево
template <typename T>
class BinaryTreeVal {
private:
	struct Node { // узел
		Node* Left; // указатель на левый потомок
		Node* Right; // на правый потомок
		Node* Parent;
		T Value; // указатель на знаения (float || complex)
	};
	BinaryTreeVal<T>* RoundForMap(T (*Fun)(T), Node* Original, BinaryTreeVal<T>* Result); // Возвращает новую колекцию с использованием на них функцией
	BinaryTreeVal<T>* RoundForMap(T (&Fun)(BinaryTreeVal<T>*), BinaryTreeVal<T>* Original, Node* OriginalNode, BinaryTreeVal<T>* Result);
	BinaryTreeVal<T>* RoundForWhere(bool (*Fun)(T), Node* Original, BinaryTreeVal<T>* Result);
	BinaryTreeVal<T>* RoundForWhere(void (*Fun)(Node*), Node* Original, BinaryTreeVal<T>* Result);
	bool RoundForSearch(Node* tree, Node* value, bool); // обход для поиска 
	bool RoundForSearchTree(Node* root1, Node* root2, bool result);
	void TreePrintKPL(Node* tree); // обход KPL
	void TreePrintLKP(Node* tree); // обход ЛКп
	void FreeMem(Node* tree); // Очистка памяти
	string ToStringKPL(Node* tree, string result);
	string ToStringLKP(Node* tree, string result);
	BinaryTreeVal<T>* RoundForCut(Node* tree, bool find, T cutElem, BinaryTreeVal<T>* Result);
	void heapifyAllInner(Node* Original);
	Node* Root; // корень дерева

public:
	Node* GetRoot() { return Root; } // геттер для корня
	void PrintTree(BinaryTreeVal<T>* Root); // вывод дерева
	BinaryTreeVal<T>(); // конструктор 
	~BinaryTreeVal<T>() ; // удаление дерева
	void Add(T Value) { AddNode(Value, Root, nullptr); } // добавления
	Node* AddAndGetPointer(T Value)
	{
		return AddNode(Value, Root, nullptr);
	}
	Node* AddNode(T Value, Node* New_Node, Node* parent)
	{
		if (New_Node == nullptr)
		{
			New_Node = new Node;
			New_Node->Right = New_Node->Left = nullptr;
			New_Node->Value = Value;
			New_Node->Parent = parent;
			if (Root == nullptr)
				Root = New_Node;
		}
		else if (Value < (New_Node->Value))
		{
			New_Node->Left = AddNode(Value, New_Node->Left, New_Node);
		}
		else if (Value >= (New_Node->Value))
		{
			New_Node->Right = AddNode(Value, New_Node->Right, New_Node);
		}
		return New_Node;
	}

	// Должна продействовать функцией на каждый элемент дерева
	BinaryTreeVal<T>* Map(T(*Fun)(T)); // Должна продействовать функцией на каждый элемент дерева
	BinaryTreeVal<T>* Where(bool (*Fun)(T));
	// void Where(void (*Fun)(Node*)); // Должна верунуть дерево которые прошли фильтрацию
	bool SearchItem(Node* tree, T Value); // поиск элемента на вхождение
	bool SearchTree(BinaryTreeVal<T>* tree1, BinaryTreeVal<T>* tree2); // поиск поддерева на вхождение
	BinaryTreeVal<T>* Cut(BinaryTreeVal<T>* tree, T cutElem); // извлечение
	string ToString(); // переводит в строку
	void heapifyAll(Node* node)
	{
		heapifyAllInner(node);
	}
	void heapifyAll()
	{
		heapifyAllInner(GetRoot());
	}
};

template<typename T>
void BinaryTreeVal<T>::TreePrintKPL(Node* tree)
{
	if (tree != nullptr)
	{
		cout << ToStrings((tree->Value)) << "\t";
		TreePrintKPL(tree->Right);
		TreePrintKPL(tree->Left);
	}
};

template<typename T>
void BinaryTreeVal<T>::TreePrintLKP(Node* tree)
{
	if (tree != nullptr)
	{
		cout << " < ";
		TreePrintLKP(tree->Left);
		cout << " > ";
		cout << " [ " << ToStrings((tree->Value)) << " ] ( ";
		TreePrintLKP(tree->Right);
		cout << " ) ";
	}

};

template<typename T>
void BinaryTreeVal<T>::FreeMem(Node* tree)
{
	if (tree != NULL) {
		FreeMem(tree->Left);
		FreeMem(tree->Right);
	}
}

template<typename T>
string BinaryTreeVal<T>::ToStringKPL(Node* tree, string result)
{
	if (tree != nullptr) {
		result += "<" + ToStrings((tree->Value)) + "> ( ";
		result = ToStringKPL(tree->Right, result);
		result += ") [ ";
		result = ToStringKPL(tree->Left, result);
		result += "] ";
	}
	return result;
}

template<typename T>
string BinaryTreeVal<T>::ToStringLKP(Node* tree, string result)
{
	if (tree != nullptr)
	{
		result += " ( ";
		result = ToStringLKP(tree->Left, result);
		result += " ) < " + ToStrings((tree->Value)) + " > [ ";
		result = ToStringLKP(tree->Right, result);
		result += " ] ";

	}
	return result;
}

template<typename T>
void BinaryTreeVal<T>::PrintTree(BinaryTreeVal<T>* tree)
{
	cout << tree->ToString() << endl;
};

template<typename T>
BinaryTreeVal<T>::~BinaryTreeVal<T>()
{
	FreeMem(Root);
}

template<typename T>
BinaryTreeVal<T>* BinaryTreeVal<T>::Map(T (*Fun)(T))
{
	BinaryTreeVal<T>* Result = new BinaryTreeVal<T>();
	Result = RoundForMap(Fun, Root, Result);
	return Result;
}

template<typename T>
BinaryTreeVal<T>* BinaryTreeVal<T>::Where(bool(*Fun)(T))
{
	BinaryTreeVal<T>* Result = new BinaryTreeVal<T>();
	RoundForWhere(Fun, Root, Result);
	return Result;
}

//template<typename T>
//void BinaryTree<T>::Where(void (*Fun)(Node*))
//{
//	//BinaryTree<T>* Result;
//	//RoundForWhere(Fun, GetRoot(), Result);
//	//delete Result;
//}

template<typename T>
bool BinaryTreeVal<T>::SearchItem(Node* tree, T Value)
{
	Node* New_node = new Node;
	New_node->Value = Value;
	New_node->Left = nullptr;
	New_node->Right = nullptr;
	bool result = false;
	result = RoundForSearch(tree, New_node, result);
	return result;
}

template<typename T>
bool BinaryTreeVal<T>::SearchTree(BinaryTreeVal<T>* tree1, BinaryTreeVal<T>* tree2) // переделеать
{
	bool result = false;
	result = RoundForSearchTree(tree1->GetRoot(), tree2->GetRoot(), result);
	return result;
}

template<typename T>
BinaryTreeVal<T>* BinaryTreeVal<T>::Cut(BinaryTreeVal<T>* tree, T cutElem)
{
	BinaryTreeVal<T>* result = new BinaryTree<T>();
	bool find = false;
	result = RoundForCut(tree->GetRoot(), find, cutElem, result);
	return result;
}

template<typename T>
string BinaryTreeVal<T>::ToString()
{
	int choise;
	cout << "Выбирете обход для вывода дерева в строке\n() - левый \t<>-корень \t[] - правый:\n1. ЛКП\n2. КПЛ\n";
	cin >> choise;
	string result = "";
	switch (choise)
	{
	case 1:
		result = ToStringLKP(Root, result);
		return result;
		break;
	case 2:
		result = ToStringKPL(Root, result);
		return result;
		break;
	default:
		cout << "Такого обхода не существует!";
		return 0;
		break;
	}

}

template<typename T>
BinaryTreeVal<T>* BinaryTreeVal<T>::RoundForCut(Node* tree, bool find, T cutElem, BinaryTreeVal<T>* Result)
// find - был ли найден элемент , Result - извлеченное поддерево
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
BinaryTreeVal<T>* BinaryTreeVal<T>::RoundForWhere(bool (*Fun)(T), Node* Original, BinaryTreeVal<T>* Result)
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
BinaryTreeVal<T>* BinaryTreeVal<T>::RoundForWhere(void (*Fun)(Node*), Node* Original, BinaryTreeVal<T>* Result)
{
	if (Original != nullptr) {
		if (Fun(Original))
			Result->Add(Original->Value);
		Result = RoundForWhere(Fun, Original->Left, Result);
		Result = RoundForWhere(Fun, Original->Right, Result);
	}
	return Result;
}

template<typename T>
void BinaryTreeVal<T>::heapifyAllInner(Node* node)
{
	auto tree = node;
	if (tree != nullptr) {
		Node* leftChild;
		Node* rightChild;
		Node* largestChild;;
		for (; ; )
		{
			leftChild = tree->Left;
			rightChild = tree->Right;
			largestChild = tree;

			if (leftChild != nullptr)
			{
				if (*(leftChild->Value) > *(largestChild->Value))
				{
					largestChild->Value = leftChild->Value;
				}
			}

			if (rightChild != nullptr)
			{
				if (*(rightChild->Value) >= *(largestChild->Value))
				{
					largestChild->Value = rightChild->Value;
				}
			}

			if (largestChild->Value == tree->Value)
			{
				break;
			}

			T* temp = tree->Value;
			tree->Value = largestChild->Value;
			largestChild->Value = temp;
			tree = tree->Parent;
		}
		heapifyAllInner(node->Left);
		heapifyAllInner(node->Right);
	}
}

template<typename T>
BinaryTreeVal<T>::BinaryTreeVal()
{
	Root = nullptr;
}

template<typename T>
BinaryTreeVal<T>* BinaryTreeVal<T>::RoundForMap(T (*Fun)(T), Node* Original, BinaryTreeVal<T>* Result)
{
	if (Original != nullptr) {
		Result->Add(Fun(Original->Value));
		Result = RoundForMap(Fun, Original->Left, Result);
		Result = RoundForMap(Fun, Original->Right, Result);
	}
	return Result;
}

template<typename T>
BinaryTreeVal<T>* BinaryTreeVal<T>::RoundForMap(T (&Fun)(BinaryTreeVal<T>*), BinaryTreeVal<T>* Original, Node* OriginalNode, BinaryTreeVal<T>* Result)
{
	if (Original != nullptr) {
		Result->Add(Fun(Original->GetRoot));
		BinaryTreeVal<T>* buf = new BinaryTreeVal<T>;
		buf->Add();
		Result = RoundForMap(Fun, (Original->GetRoot), OriginalNode->Left, Result);
		Result = RoundForMap(Fun, (Original->GetRoot), OriginalNode->Right, Result);
	}
	return Result;
}

template<typename T>
bool BinaryTreeVal<T>::RoundForSearch(Node* tree, Node* Node_value, bool Result)
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
bool BinaryTreeVal<T>::RoundForSearchTree(Node* root1, Node* root2, bool result)
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

