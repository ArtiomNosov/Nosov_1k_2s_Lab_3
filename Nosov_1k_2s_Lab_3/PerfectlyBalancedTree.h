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
// Ìîè çàãîëîâî÷íûå ôàéëû
// Ïğîñòğàíñòâà èì¸í

// Ïåğå÷èñëåíèÿ 
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
    PNode<T>* GetLeftÑhild() {
        return Left;
    }
    void SetLeftÑhild(PNode<T>* leftChild) {
        Left = leftChild;
    }
    PNode<T>* GetRightÑhild() {
        return Right;
    }
    void SetRightÑhild(PNode<T>* rightÑhild) {
        Right = rightÑhild;
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
    // Îáõîäû äåğåâà TLR (ÊËÏ), LTR (ËÊÏ), LRT(ËÏÊ)
  // Îáõîä TLR
    template <typename Func, typename A, typename... Args>
    void TLR(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        p(node, args);
        TLR(p, node->GetLeftÑhild(), args);
        TLR(p, node->GetRightÑhild(), args);
    }
    // İêçåìïëÿğ
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
        if (*result == ErrorValue) TLR(node->GetLeftÑhild(), n, result);
        if (*result == ErrorValue) TLR(node->GetRightÑhild(), n, result);
    }
    // Îáõîä LTR
    template <typename Func, typename A, typename... Args>
    void LTR(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        LTR(p, node->GetLeftÑhild(), args);
        p(node, args);
        LTR(p, node->GetRightÑhild(), args);
    }
    // Îáõîä LRT
    template <typename Func, typename A, typename... Args>
    void LRT(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        LRT(p, node->GetLeftÑhild(), args);
        LRT(p, node->GetRightÑhild(), args);
        p(node, args);
    }
    // Îáõîä RTL
    template <typename Func, typename A, typename... Args>
    void RTL(Func* p, PNode<T>* node, Args... args)
    {
        if (node == nullptr) return;
        RTL(p, node->GetRightÑhild(), args);
        p(node, args);
        RTL(p, node->GetLeftÑhild(), args);
    }
     // İêçåìëÿğ äëÿ int
    void RTL(int (*p)(PNode<T>*), PNode<T>* node)
    {
        if (node == nullptr) return;
        RTL(p, node->GetRightÑhild());
        p(node);
        RTL(p, node->GetLeftÑhild());
    }
private:
    // Ôóíêöèè äëÿ îáõîäîâ
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
    PrintRTL(node->GetRightÑhild(), n + 1);
    PrintValue(node, n);
    PrintRTL(node->GetLeftÑhild(), n + 1);
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

 // Ôóíêöèè äëÿ îáõîäîâ
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
    node->SetLeftÑhild(CreateTree(node->GetLeftÑhild(), nl));
    node->SetRightÑhild(CreateTree(node->GetRightÑhild(), nr));

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
    node->SetLeftÑhild(CreateTree(node->GetLeftÑhild(), nl, a));
    node->SetRightÑhild(CreateTree(node->GetRightÑhild(), nr, a));
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