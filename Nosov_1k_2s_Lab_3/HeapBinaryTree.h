/*
*	HeapBinaryTree.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

// #include "BinaryTree.h"

// TODO: Сделать задаеин нулевого элемента для любого typename while (i > 0 && list[parent] < getListItem(i))
template <typename T>
class HeapWithBinaryTree {
private:

    BinaryTree<T>* BinaryTreeInner = nullptr;

    /*T getListItem(long index)
    {
        assert(index < heapSize());
        auto iterator = List.begin();
        for (int i = 0; i < index; i++)
            iterator++;
        return *iterator;
    }*/

    /*const list<int>::iterator getListIterator(long index)
    {
        auto iterator = List.begin();
        for (int i = 0; i < index; i++)
            iterator++;
        return iterator;
    }*/


public:
    // Конструктор для построения из list
    /*BinaryHeap<T>(list<T> list)
    {
        List = list;
        for (int i = heapSize() / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }*/

	HeapWithBinaryTree<T>(T array[], long sizeArray)
    {
        BinaryTreeInner = new BinaryTree<T>;
        for (long i = 0; i < sizeArray; i++)
        {
            T* buf = new T;
            *buf = array[i];
            BinaryTreeInner->Add(buf);
        }
        BinaryTreeInner->heapifyAll();
    }

    /*long heapSize()
    {
        return BinaryTree->;
    }*/

    // TODO: Сделать для отдельного элемента
    void add(T* value)
    {
        BinaryTreeInner->heapifyAll(BinaryTreeInner->AddAndGetPointer(value));
    }

    T getMax()
    {
        T* result = (BinaryTreeInner->GetRoot())->Value;
        BinaryTree<T>* buf = BinaryTreeInner->Cut(BinaryTreeInner, (BinaryTreeInner->GetRoot())->Value);
        delete BinaryTreeInner;
        BinaryTreeInner = buf;
        BinaryTreeInner->heapifyAll();
        return *result;
    }

    T findMax()
    {
        return *(BinaryTreeInner->GetRoot())->Value;
    }

    void reBuildHeap(T sourceArray[], long sourceArraySize)
    {
        delete BinaryTreeInner;
        BinaryTreeInner = new BinaryTree<T>;
        for (long i = 0; i < sourceArraySize; i++)
        {
            T* buf = new T;
            *buf = sourceArray[i];
            BinaryTreeInner->Add(buf);
        }
        BinaryTreeInner->heapifyAll();
    }

    void heapSort(T array[], long sizeArray)
    {
        reBuildHeap(array, sizeArray);
        for (int i = sizeArray - 1; i >= 0; i--)
        {
            array[i] = getMax();
        }
    }
};


#include <iostream>
#include "Function.h"
#include <queue>

using namespace std;

//	Бинарное дерево
template <typename T>
class HeapBinaryTree {
private:
	struct Node { // узел
		Node* Left; // указатель на левый потомок
		Node* Right; // на правый потомок
		T* Value; // указатель на знаения (float || complex)
	};
	HeapBinaryTree<T>* RoundForMap(T* (*Fun)(T*), Node* Original, HeapBinaryTree<T>* Result); // Возвращает новую колекцию с использованием на них функцией
	HeapBinaryTree<T>* RoundForMap(T* (&Fun)(HeapBinaryTree<T>*), HeapBinaryTree<T>* Original, Node* OriginalNode, HeapBinaryTree<T>* Result);
	HeapBinaryTree<T>* RoundForWhere(bool (*Fun)(T*), Node* Original, HeapBinaryTree<T>* Result);
	HeapBinaryTree<T>* RoundForWhere(void (*Fun)(Node*), Node* Original, HeapBinaryTree<T>* Result);
	bool RoundForSearch(Node* tree, Node* value, bool); // обход для поиска 
	bool RoundForSearchTree(Node* root1, Node* root2, bool result);
	void TreePrintKPL(Node* tree); // обход KPL
	void TreePrintLKP(Node* tree); // обход ЛКп
	void FreeMem(Node* tree); // Очистка памяти
	void FreeMemWithoutVal(Node* tree);
	string ToStringKPL(Node* tree, string result);
	string ToStringLKP(Node* tree, string result);
	HeapBinaryTree<T>* RoundForCut(Node* tree, bool find, T* cutElem, HeapBinaryTree<T>* Result);
	void heapifyAllInner(Node* Original);
	Node* Root; // корень дерева
	void AddNode(T* Value, Node* New_Node, Node* parent)
	{
		if (New_Node == nullptr)
		{
			New_Node = new Node;
			New_Node->Left = nullptr;
			New_Node->Right = nullptr;
			New_Node->Value = Value;
		}
		if (*Value > *(parent->Value))
		{
			T* buf = New_Node->Value;
			New_Node->Value = parent->Value;
			parent->Value = buf;
			Value = New_Node->Value;
			AddNode(Value, New_Node, Root);
		}
		else if (!(parent->Left) && !(parent->Right))
		{
			parent->Left = New_Node;
		}
		else if (!(parent->Left))
		{
			parent->Left = New_Node;
		}
		else if (!(parent->Right))
		{
			parent->Right = New_Node;
		}
		else if (*(parent->Left->Value) <= *(parent->Right->Value))
		{
			AddNode(Value, New_Node, parent->Right);
		}
		else if (*(parent->Left->Value) > *(parent->Right->Value))
		{
			AddNode(Value, New_Node, parent->Left);
		}
	}
public:
	Node* GetRoot() { return Root; } // геттер для корня
	T findMax() { 
		if (GetRoot()) return *((GetRoot())->Value);
	}
	T getMax();
	void PrintTree(HeapBinaryTree<T>* Root); // вывод дерева
	HeapBinaryTree<T>(); // конструктор 
	HeapBinaryTree<T>(T* DinArr, const long n)
	{
		Root = nullptr;
		for (long i = 0; i < n; i++)
		{
			T* p = new T;
			*p = DinArr[i];
			Add(p);
		}
	}
	~HeapBinaryTree<T>(); // удаление дерева
	void Add(T* Value) 
	{ 
		if (Root == nullptr) 
		{
			Node* New_Node = new Node;
			New_Node->Left = nullptr;
			New_Node->Right = nullptr;
			New_Node->Value = Value;
			Root = New_Node;
		}
		else
		{
			AddNode(Value, nullptr, Root);
		}
	} // добавления

	HeapBinaryTree<T>* Map(T* (*Fun)(T*)); // Должна продействовать функцией на каждый элемент дерева
	HeapBinaryTree<T>* Map(HeapBinaryTree<T>* (&Fun)(HeapBinaryTree<T>*)); // Должна продействовать функцией на каждый элемент дерева
	HeapBinaryTree<T>* Where(bool (*Fun)(T*));
	void Where(void (*Fun)(Node*)); // Должна верунуть дерево которые прошли фильтрацию
	bool SearchItem(Node* tree, T* Value); // поиск элемента на вхождение
	bool SearchTree(HeapBinaryTree<T>* tree1, HeapBinaryTree<T>* tree2); // поиск поддерева на вхождение
	HeapBinaryTree<T>* Cut(HeapBinaryTree<T>* tree, T* cutElem); // извлечение
	string ToString(); // переводит в строку c выводом на экран
	void heapSort(T* array, long size) 
	{
		FreeMem(Root);
		Root = nullptr;
		for (int i = 0; i < size; i++)
		{
			T* p = new T;
			*p = array[i];
			Add(p);
		}
		for (int i = size - 1; i >= 0; i--)
			array[i] = getMax();
	}

	void AddTreeWithNode(Node* node);
	HeapBinaryTree<T>* GetMergedTrees(HeapBinaryTree<T>* tree1, HeapBinaryTree<T>* tree2);
};

template<typename T>
void HeapBinaryTree<T>::TreePrintKPL(Node* tree)
{
	if (tree != nullptr)
	{
		cout << ToStrings(*(tree->Value)) << "\t";
		TreePrintKPL(tree->Right);
		TreePrintKPL(tree->Left);
	}
};

template<typename T>
void HeapBinaryTree<T>::TreePrintLKP(Node* tree)
{
	if (tree != nullptr)
	{
		cout << " < ";
		TreePrintLKP(tree->Left);
		cout << " > ";
		cout << " [ " << ToStrings(*(tree->Value)) << " ] ( ";
		TreePrintLKP(tree->Right);
		cout << " ) ";
	}

};

template<typename T>
void HeapBinaryTree<T>::FreeMem(Node* tree)
{
	if (tree != NULL) {
		FreeMem(tree->Left);
		FreeMem(tree->Right);
		delete tree->Value;
	}
}


template<typename T>
void HeapBinaryTree<T>::FreeMemWithoutVal(Node* tree)
{
	if (tree != nullptr) {
		if (tree->Left != nullptr && tree->Right != nullptr)
		{
			FreeMemWithoutVal(tree->Left); FreeMemWithoutVal(tree->Right);
		}
		if (tree->Left != nullptr)FreeMemWithoutVal(tree->Left);
		if (tree->Right != nullptr)FreeMemWithoutVal(tree->Right);
		tree->Value = nullptr;
		delete tree;
	}
}

template<typename T>
string HeapBinaryTree<T>::ToStringKPL(Node* tree, string result)
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
string HeapBinaryTree<T>::ToStringLKP(Node* tree, string result)
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
void HeapBinaryTree<T>::PrintTree(HeapBinaryTree<T>* tree)
{
	cout << tree->ToString() << endl;
};

template<typename T>
HeapBinaryTree<T>::~HeapBinaryTree<T>()
{
	FreeMem(Root);
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::Map(T* (*Fun)(T*))
{
	HeapBinaryTree<T>* Result = new HeapBinaryTree<T>();
	Result = RoundForMap(Fun, Root, Result);
	return Result;
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::Where(bool(*Fun)(T*))
{
	HeapBinaryTree<T>* Result = new HeapBinaryTree<T>();
	RoundForWhere(Fun, Root, Result);
	return Result;
}

template<typename T>
void HeapBinaryTree<T>::Where(void (*Fun)(Node*))
{
	HeapBinaryTree<T>* Result
		RoundForWhere(Fun, GetRoot(), Result);;
	delete Result;
}

template<typename T>
bool HeapBinaryTree<T>::SearchItem(Node* tree, T* Value)
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
bool HeapBinaryTree<T>::SearchTree(HeapBinaryTree<T>* tree1, HeapBinaryTree<T>* tree2) // переделеать
{
	bool result = false;
	result = RoundForSearchTree(tree1->GetRoot(), tree2->GetRoot(), result);
	return result;
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::Cut(HeapBinaryTree<T>* tree, T* cutElem)
{
	HeapBinaryTree<T>* result = new HeapBinaryTree<T>();
	bool find = false;
	result = RoundForCut(tree->GetRoot(), find, cutElem, result);
	return result;
}

template<typename T>
string HeapBinaryTree<T>::ToString()
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
HeapBinaryTree<T>* HeapBinaryTree<T>::RoundForCut(Node* tree, bool find, T* cutElem, HeapBinaryTree<T>* Result)// find - был ли найден элемент , Result - извлеченное поддерево
{
	if (tree != nullptr)
	{
		if (*(tree->Value) == *cutElem || find)
		{
			find = true;
			T* p = new T;
			*p = *(tree->Value);
			Result->Add(p);
		}
		Result = RoundForCut(tree->Left, find, cutElem, Result);
		Result = RoundForCut(tree->Right, find, cutElem, Result);
	}
	return Result;
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::RoundForWhere(bool(*Fun)(T*), Node* Original, HeapBinaryTree<T>* Result)
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
HeapBinaryTree<T>* HeapBinaryTree<T>::RoundForWhere(void (*Fun)(Node*), Node* Original, HeapBinaryTree<T>* Result)
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
void HeapBinaryTree<T>::heapifyAllInner(Node* node)
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
HeapBinaryTree<T>::HeapBinaryTree()
{
	Root = nullptr;
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::RoundForMap(T* (*Fun)(T*), Node* Original, HeapBinaryTree<T>* Result)
{
	if (Original != nullptr) {
		Result->Add(Fun(Original->Value));
		Result = RoundForMap(Fun, Original->Left, Result);
		Result = RoundForMap(Fun, Original->Right, Result);
	}
	return Result;
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::RoundForMap(T* (&Fun)(HeapBinaryTree<T>*), HeapBinaryTree<T>* Original, Node* OriginalNode, HeapBinaryTree<T>* Result)
{
	if (Original != nullptr) {
		Result->Add(Fun(Original->GetRoot));
		HeapBinaryTree<T>* buf = new HeapBinaryTree<T>;
		buf->Add()
			Result = RoundForMap(Fun, (Original->GetRoot), OriginalNode->Left, Result);
		Result = RoundForMap(Fun, (Original->GetRoot), OriginalNode->Right, Result);
	}
	return Result;
}

template<typename T>
bool HeapBinaryTree<T>::RoundForSearch(Node* tree, Node* Node_value, bool Result)
{
	if (tree == nullptr || Result == true)
	{
		return Result;
	}
	if (*(tree->Value) == *(Node_value->Value))
	{
		Result = true;
		return Result;
	}
	if (tree->Left != nullptr && tree->Right != nullptr)
	{

		Result = (RoundForSearch(tree->Left, Node_value, Result) || RoundForSearch(tree->Right, Node_value, Result));
	}
	else if (tree->Left != nullptr)
	{
		Result = RoundForSearch(tree->Left, Node_value, Result);
	}
	else if (tree->Right != nullptr)
	{
		Result = RoundForSearch(tree->Right, Node_value, Result);
	}
	return Result;
}

template<typename T>
bool HeapBinaryTree<T>::RoundForSearchTree(Node* root1, Node* root2, bool result)
{
	if (root2 == nullptr || result) {
		return true;
	}
	else if ((root1 == nullptr) && (root2 != nullptr)) {
		return false;
	}
	else if (root1 != nullptr) {
		if (*(root1->Value) == *(root2->Value)) {
			if (RoundForSearchTree(root1->Left, root2->Left, result) && RoundForSearchTree(root1->Right, root2->Right, result)) {
				result = true;
				return true;
			}
		}
		result = RoundForSearchTree(root1->Left, root2, result) || RoundForSearchTree(root1->Right, root2, result);
	}
	return result;
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::Map(HeapBinaryTree<T>* (&Fun)(HeapBinaryTree<T>*))
{
	HeapBinaryTree<T>* Result = new HeapBinaryTree<T>();
	Result = RoundForMap(Fun, this, Root, Result);
	return Result;
}

template<typename T>
T HeapBinaryTree<T>::getMax()
{
	T result;
	if (GetRoot() != nullptr)
	{
		result = *(GetRoot()->Value);
		//bdelete GetRoot();
		Node* root1 = (GetRoot())->Left;
		Node* root2 = (GetRoot())->Right;
		Root->Value = nullptr;
		Root->Left = nullptr;
		Root->Right = nullptr;
		delete Root;
		Root = nullptr;
		AddTreeWithNode(root1);
		AddTreeWithNode(root2);
		
		return result;
	}
	else
	{
		assert(true);
		return result;
	}
}

template<typename T>
void HeapBinaryTree<T>::AddTreeWithNode(Node* node)
{
	if (node != nullptr)
	{
		T* p = new T;
		*p = *(node->Value);
		Add(p);
	}
	else
	{
		return;
	}
	if (node->Left != nullptr && node->Right != nullptr)
	{
		AddTreeWithNode(node->Left);
		AddTreeWithNode(node->Right);
	}
	else if (node->Left != nullptr)
	{
		AddTreeWithNode(node->Left);
	}
	else if (node->Right != nullptr)
	{
		AddTreeWithNode(node->Right);
	}
}

template<typename T>
HeapBinaryTree<T>* HeapBinaryTree<T>::GetMergedTrees(HeapBinaryTree<T>* tree1, HeapBinaryTree<T>* tree2)
{
	HeapBinaryTree<T>* r = new HeapBinaryTree<T>;
	if (tree1->GetRoot() != nullptr) r->AddTreeWithNode(tree1->GetRoot());
	if (tree2->GetRoot() != nullptr) r->AddTreeWithNode(tree2->GetRoot());
	return r;
}