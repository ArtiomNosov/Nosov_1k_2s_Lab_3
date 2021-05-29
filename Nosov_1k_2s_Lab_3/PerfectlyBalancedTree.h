#pragma once

/*
*	PerfectlyBalancedTree.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

// ��������� ������������ �����
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
        Node* GetLeft�hild();
        void SetLeft�hild(Node* leftChield);
        Node* GetRight�hild();
        void SetRight�hild(Node* right�hild);
	};
    Node* Root;
private:
    // ������ ������ TLR (���), LTR (���), LRT(���)
  // ����� TLR
    void TLR(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        p(node, ...);
        TLR(node->GetLeft�hild());
        TLR(node->GetRight�hild());
    }
    // ����� LTR
    void LTR(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        LTR(node->GetLeft�hild());
        p(node, ...);
        LTR(node->GetRight�hild());
    }
    // ����� LRT
    void LRT(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        LRT(node->GetLeft�hild());
        LRT(node->GetRight�hild());
        p(node, ...);
    }
    // ����� RTL
    void RTL(auto (*p)(Node*, ...), Node* node)
    {
        if (node == nullptr) return;
        LRT(node->GetRight�hild());
        p(node, ...);
        LRT(node->GetLeft�hild());
    }
private:
    // ������� ��� �������
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

 // ������� ��� �������
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

 // ��� class Node

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
PerfectlyBalancedTree<T>::Node* PerfectlyBalancedTree<T>::Node::GetLeft�hild()
{
    return this->Left;
}

template <typename T>
void PerfectlyBalancedTree<T>::Node::SetLeft�hild(Node* leftChild)
{
    this->Left(leftChild)
}

template <typename T>
PerfectlyBalancedTree<T>::Node* PerfectlyBalancedTree<T>::Node::GetRight�hild()
{
    return this->Right;
}

template <typename T>
void PerfectlyBalancedTree<T>::Node::SetRight�hild(Node* right�hild)
{
    this->Right(right�hild)
}