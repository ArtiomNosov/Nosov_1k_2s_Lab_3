#pragma once

/*
*	PerfectlyBalancedTree.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

// Ñòîğîííèå çàãîëîâî÷íûå ôàéëû
#include <iostream>

template <typename T>
class PerfectlyBalancedTree
{
public:
	PerfectlyBalancedTree(int n);
    PerfectlyBalancedTree(int n, T* a);
	~PerfectlyBalancedTree();
	void PrintRTL();
private:
	class Node
	{
	private:
		T Value;
		Node* Left;
		Node* Right;
	public:
		Node(T value);
		T GetValue();
        void SetValue(T value);
        Node* GetLeftÑhild();
        void SetLeftÑhild(Node* leftChield);
        Node* GetRightÑhild();
        void SetRightÑhild(Node* rightÑhild);
	};
    Node* Root;
private:
    // Îáõîäû äåğåâà TLR (ÊËÏ), LTR (ËÊÏ), LRT(ËÏÊ)
  // Îáõîä TLR
    void TLR(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        p(node, ...);
        TLR(node->GetLeftÑhild());
        TLR(node->GetRightÑhild());
    }
    // Îáõîä LTR
    void LTR(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        LTR(node->GetLeftÑhild());
        p(node, ...);
        LTR(node->GetRightÑhild());
    }
    // Îáõîä LRT
    void LRT(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        LRT(node->GetLeftÑhild());
        LRT(node->GetRightÑhild());
        p(node, ...);
    }
    // Îáõîä RTL
    void RTL(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        LRT(node->GetRightÑhild());
        p(node, ...);
        LRT(node->GetLeftÑhild());
    }
private:
    // Ôóíêöèè äëÿ îáõîäîâ
    void PrintValue(Node* node, int n);
    Node* CreateTree(Node* node, int n);
    Node* CreateTree(Node* node, int n, T* a);
private:
    Node* GetRoot();
    void SetRoot(Node* node);
};

template <typename T>
PerfectlyBalancedTree<T>::PerfectlyBalancedTree(int n):
    Root(nullptr)
{
    this->SetRoot(CreateTree(GetRoot(), n));
}

template <typename T>
PerfectlyBalancedTree<T>::PerfectlyBalancedTree(int n, T* a):
    Root(nullptr)
{
    this->CreateTree(GetRoot(), n, a);
}

template <typename T>
PerfectlyBalancedTree<T>::~PerfectlyBalancedTree()
{
}

template <typename T>
void PerfectlyBalancedTree<T>::PrintRTL()
{
    this->RTL(PrintValue, GetRoot());
}

template <typename T>
PerfectlyBalancedTree<T>::Node* PerfectlyBalancedTree<T>::GetRoot()
{
    return this->Root;
}

template <typename T>
void PerfectlyBalancedTree<T>::SetRoot(PerfectlyBalancedTree<T>::Node* node)
{
    this->Root = node;
}

 // Ôóíêöèè äëÿ îáõîäîâ
template <typename T>
void PerfectlyBalancedTree<T>::PrintValue(Node* node, int n)
{
    std::cout << n * 4 << std::endl;
    std::cout << node->GetValue() << std::endl;
}

template <typename T>
PerfectlyBalancedTree<T>::Node* PerfectlyBalancedTree<T>::CreateTree(PerfectlyBalancedTree<T>::Node* node, int n)
{
    if (n <= 0) return nullptr;
    if (node != nullptr) return nullptr;
    int nl, nr;
    nl = n / 2;
    nr = n - nl - 1;
    T value;
    std::cin >> value;
    node = Node(value);
    node->SetLeftChild(CreateTree(node->GetLeftChild(), nl));
    node->SetRightChild(CreateTree(node->GetRightChild(), nr));
    return node;
}

template <typename T>
PerfectlyBalancedTree<T>::Node* PerfectlyBalancedTree<T>::CreateTree(PerfectlyBalancedTree<T>::Node* node, int n, T* a)
{
    if (n <= 0) return nullptr;
    if (node != nullptr) return nullptr;
    int nl, nr;
    nl = n / 2;
    nr = n - nl - 1;
    node = Node(a[n]);
    node->SetLeftChild(CreateTree(node->GetLeftChild(), nl));
    node->SetRightChild(CreateTree(node->GetRightChild(), nr));
    return node;
}

 // Äëÿ class Node

template <typename T>
PerfectlyBalancedTree<T>::Node::Node(T value):
	Value(value),
    Left(nullptr),
    Right(nullptr)
{

}

template <typename T>
T PerfectlyBalancedTree<T>::Node::GetValue()
{
	return this->Value;
}

template <typename T>
void PerfectlyBalancedTree<T>::Node::SetValue(T value)
{
    this->Value(value);
}

template <typename T>
PerfectlyBalancedTree<T>::Node* PerfectlyBalancedTree<T>::Node::GetLeftÑhild()
{
    return this->Left;
}

template <typename T>
void PerfectlyBalancedTree<T>::Node::SetLeftÑhild(Node* leftChild)
{
    this->Left(leftChild)
}

template <typename T>
PerfectlyBalancedTree<T>::Node* PerfectlyBalancedTree<T>::Node::GetRightÑhild()
{
    return this->Right;
}

template <typename T>
void PerfectlyBalancedTree<T>::Node::SetRightÑhild(Node* rightÑhild)
{
    this->Right(rightÑhild)
}