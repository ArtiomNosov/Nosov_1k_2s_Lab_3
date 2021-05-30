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
// ��� ������������ �����
// ������������ ���

// ������������ 
enum Round
{
    TLR,
    LTR,
    LRT,
    RTL,

};

template <typename T>
class PNode
{
private:
    T Value;
    PNode<T>* Left;
    PNode<T>* Right;
public:
    PNode(T value) :
        Value(value),
        Left(nullptr),
        Right(nullptr)
    {

    }
    T GetValue() {
        return Value;
    }
    void SetValue(T value) {
        Value(value);
    }
    PNode<T>* GetLeft�hild() {
        return Left;
    }
    void SetLeft�hild(PNode<T>* leftChild) {
        Left = leftChild;
    }
    PNode<T>* GetRight�hild() {
        return Right;
    }
    void SetRight�hild(PNode<T>* right�hild) {
        Right = right�hild;
    }
};

template <typename T>
class PerfectlyBalancedTree
{
private:
    PNode<T>* Root;
    int Size = 0;
    T ErrorValue;
private:
    void PrintRTL(PNode<T>* node, int n);
public:
	PerfectlyBalancedTree(int n, T errorValue);
    PerfectlyBalancedTree(int n, T* a, T errorValue);
	~PerfectlyBalancedTree();
public:
    void PrintRTL();
    int GetSize();
    T GetValue(int n, Round round);
private:
    // ������ ������ TLR (���), LTR (���), LRT(���)
  // ����� TLR
    template <typename Func, typename A, typename... Args>
    void TLR(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        p(node, args);
        TLR(p, node->GetLeft�hild(), args);
        TLR(p, node->GetRight�hild(), args);
    }
    // ���������
    void TLR(PNode<T>* node, int* n, T* result)
    {
        if (node == nullptr) return;
        if (*result != ErrorValue) return;
        (*n)--;
        if (*n < 0)
        {
            *result = node->GetValue();
            return;
        }
        if (*result == ErrorValue) TLR(node->GetLeft�hild(), n, result);
        if (*result == ErrorValue) TLR(node->GetRight�hild(), n, result);
    }
    // ����� LTR
    template <typename Func, typename A, typename... Args>
    void LTR(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        LTR(p, node->GetLeft�hild(), args);
        p(node, args);
        LTR(p, node->GetRight�hild(), args);
    }
    // ����� LRT
    template <typename Func, typename A, typename... Args>
    void LRT(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        LRT(p, node->GetLeft�hild(), args);
        LRT(p, node->GetRight�hild(), args);
        p(node, args);
    }
    // ����� RTL
    template <typename Func, typename A, typename... Args>
    void RTL(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        RTL(p, node->GetRight�hild(), args);
        p(node, args);
        RTL(p, node->GetLeft�hild(), args);
    }
     // �������� ��� int
    void RTL(int (*p)(PNode<T>*), PNode<T>* node)
    {
        if (node == nullptr) return;
        RTL(p, node->GetRight�hild());
        p(node);
        RTL(p, node->GetLeft�hild());
    }
private:
    // ������� ��� �������
    int PrintValue(PNode<T>* node, int n);
    PNode<T>* CreateTree(PNode<T>* node, int n);
    PNode<T>* CreateTree(PNode<T>* node, int n, T* a);
    int DecreaseNumber(PNode<T>* node, int* n, T* result);
private:
    PNode<T>* GetRoot();
    void SetRoot(PNode<T>* node);
};

template <typename T>
PerfectlyBalancedTree<T>::PerfectlyBalancedTree(int n, T errorValue):
    Root(nullptr),
    Size(n),
    ErrorValue(errorValue)
{
    this->SetRoot(CreateTree(GetRoot(), n));
}

template <typename T>
PerfectlyBalancedTree<T>::PerfectlyBalancedTree(int n, T* a, T errorValue):
    Root(nullptr),
    Size(n),
    ErrorValue(errorValue)
{
    this->CreateTree(GetRoot(), n, a);
    Size = n;
}

template <typename T>
PerfectlyBalancedTree<T>::~PerfectlyBalancedTree()
{
}

template <typename T>
void PerfectlyBalancedTree<T>::PrintRTL(PNode<T>* node, int n)
{
    if (node == nullptr) return;
    PrintRTL(node->GetRight�hild(), n + 1);
    PrintValue(node, n);
    PrintRTL(node->GetLeft�hild(), n + 1);
}

template <typename T>
void PerfectlyBalancedTree<T>::PrintRTL()
{
    this->PrintRTL(this->GetRoot(), 0);
}

template <typename T>
PNode<T>* PerfectlyBalancedTree<T>::GetRoot()
{
    return this->Root;
}

template <typename T>
void PerfectlyBalancedTree<T>::SetRoot(PNode<T>* node)
{
    this->Root = node;
}

 // ������� ��� �������
template <typename T>
int PerfectlyBalancedTree<T>::PrintValue(PNode<T>* node, int n)
{
    std::cout << "Number of node: "<< n * 4 << std::endl;
    std::cout << node->GetValue() << std::endl << std::endl;
    return 0;
}

template <typename T>
int PerfectlyBalancedTree<T>::DecreaseNumber(PNode<T>* node, int* n, T* result)
{
    if (node == nullptr) return 0;
    (*n)--;
    return 0;
}

template <typename T>
PNode<T>* PerfectlyBalancedTree<T>::CreateTree(PNode<T>* node, int n)
{
    if (n <= 0) return nullptr;
    if (node != nullptr) return nullptr;
    int nl, nr;
    nl = n / 2;
    nr = n - nl - 1;
    T value;
    std::cin >> value;
    node = new PNode<T>(value);
    node->SetLeft�hild(CreateTree(node->GetLeft�hild(), nl));
    node->SetRight�hild(CreateTree(node->GetRight�hild(), nr));

    return node;
}

template <typename T>
PNode<T>* PerfectlyBalancedTree<T>::CreateTree(PNode<T>* node, int n, T* a)
{
    if (Size <= 0 || n <= 0) return nullptr;
    if (node != nullptr) return nullptr;
    int nl, nr;
    nl = n / 2;
    nr = n - nl - 1;
    if(node == nullptr)node = new PNode<T>(a[Size - 1]);
    //if (node == GetRoot()) node->SetValue(a[Size - 1]);
    Size--;
    node->SetLeft�hild(CreateTree(node->GetLeft�hild(), nl, a));
    node->SetRight�hild(CreateTree(node->GetRight�hild(), nr, a));
    if (Size <= 0)
    {
        Root = node;
    }
    return node;
}

template <typename T>
int PerfectlyBalancedTree<T>::GetSize()
{
    return this->Size;
}

template <typename T>
T PerfectlyBalancedTree<T>::GetValue(int n, Round round)
{
    if ( n < 0 ) return ErrorValue;
    if ( n >= GetSize() ) return ErrorValue;
    T* result = new T;
    *result = ErrorValue;
    int* ptrN = new int;
    *ptrN = n;
    switch (round)
    {
    case Round::TLR:
        TLR(GetRoot(), ptrN, result);
        break;
    case Round::LTR:
        //this->LTR(DecreaseNumber<T>, GetRoot(), ptrN, result);
        break;
    case Round::LRT:
        //this->LRT(DecreaseNumber<T>, GetRoot(), ptrN, result);
        break;
    case Round::RTL:
        //this->RTL(&DecreaseNumber<T>, GetRoot(), ptrN, result);
        break;
    default:
        break;
    }
    return *result;
}