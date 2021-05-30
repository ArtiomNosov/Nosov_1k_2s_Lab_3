/*
*	BoostTest.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>

#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

 // Мои include
#include "BinaryTree.h"
#include "Function.h"
#include "ConstantsBoostTest.h"
#include "BinaryHeap.h"
#include "HeapBinaryTree.h"
#include "ThreadedBinaryTree.h"
#include "PerfectlyBalancedTree.h"

 // Тестирование BinaryTree.h - class BinaryTree

 // BinaryTree<T>* RoundForMap(T* (*Fun)(T*), Node* Original, BinaryTree<T>* Result); // Возвращает новую колекцию с использованием на них функцией
BOOST_AUTO_TEST_CASE(Map)
{
	float* a = new float, * b = new float, * c = new float, * d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	BinaryTree<float>* treeFloat = &BinaryTree<float>();
	BinaryTree<float>* treeMapFloat = new BinaryTree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	treeMapFloat = treeFloat->Map(plusOne);
	BOOST_CHECK(*(treeMapFloat->GetRoot()->Value) == *a + 1);
	BOOST_CHECK(*(treeMapFloat->GetRoot()->Right->Value) == *b + 1);
	BOOST_CHECK(*(treeMapFloat->GetRoot()->Left->Value) == *c + 1);
	BOOST_CHECK(*(treeMapFloat->GetRoot()->Right->Left->Value) == *d + 1);
}

 //void Add(T* Value) { AddNode(Value, Root); } // добавления
BOOST_AUTO_TEST_CASE(AddFloat)
{
	float* a = new float, * b = new float, * c = new float, * d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	BinaryTree<float>* treeFloat = new BinaryTree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	BOOST_CHECK(*(treeFloat->GetRoot()->Value) == *a);
	BOOST_CHECK(*(treeFloat->GetRoot()->Right->Value) == *b);
	BOOST_CHECK(*(treeFloat->GetRoot()->Left->Value) == *c);
	BOOST_CHECK(*(treeFloat->GetRoot()->Right->Left->Value) == *d);
}

 //void Add(T* Value) { AddNode(Value, Root); } // добавления для комплексных
BOOST_AUTO_TEST_CASE(TestAddComplex)
{
	complex* a = new complex(10.65, 45);
	complex* b = new complex(12.98, 74);
	complex* c = new complex(8.45, 7);
	complex* d = new complex(11.54, 8);
	BinaryTree<complex>* treeComplex = new BinaryTree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	BOOST_CHECK(*(treeComplex->GetRoot()->Value) == *a);
	BOOST_CHECK(*(treeComplex->GetRoot()->Right->Value) == *b);
	BOOST_CHECK(*(treeComplex->GetRoot()->Left->Value) == *c);
	BOOST_CHECK(*(treeComplex->GetRoot()->Right->Left->Value) == *d);
}

 //void Add(T* Value) { AddNode(Value, Root); } // TestMapComplex
BOOST_AUTO_TEST_CASE(TestMapComplex)
{
	complex* a = new complex(10.65, 45);
	complex* b = new complex(12.98, 74);
	complex* c = new complex(8.4, 7);
	complex* d = new complex(11.54, 8);
	complex* one = new complex(1, 0);
	BinaryTree<complex>* treeComplex = new BinaryTree<complex>();
	BinaryTree<complex>* treeMapComplex = new BinaryTree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	treeMapComplex = treeComplex->Map(plusOne);
	BOOST_CHECK(*(treeMapComplex->GetRoot()->Value) == (*a + *one));
	BOOST_CHECK(*(treeMapComplex->GetRoot()->Right->Value) == (*b + *one));
	BOOST_CHECK(*(treeMapComplex->GetRoot()->Left->Value) == (*c + *one));
	BOOST_CHECK(*(treeMapComplex->GetRoot()->Right->Left->Value) == (*d + *one));
}

 // TestWhereFloat
BOOST_AUTO_TEST_CASE(TestWhereFloat)
{
	float* a = new float, * b = new float, * c = new float, * d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = -8.53;
	*d = -11.98;
	BinaryTree<float>* treeFloat = new BinaryTree<float>();
	BinaryTree<float>* treeWhereFloat = new BinaryTree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	treeWhereFloat = treeFloat->Where(BigZero);
	BOOST_CHECK(*(treeWhereFloat->GetRoot()->Value) == *a);
	BOOST_CHECK(*(treeWhereFloat->GetRoot()->Right->Value) == *b);
	BOOST_CHECK((treeWhereFloat->GetRoot()->Left) == nullptr);
}

 // TestWhereComplex
BOOST_AUTO_TEST_CASE(TestWhereComplex)
{
	//---- Функция Where для complex
	// Добавим 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i 
	complex* a = new complex(10.65, 45);
	complex* b = new complex(12.98, 74);
	complex* c = new complex(-8.45, 7);
	complex* d = new complex(-11.54, 8);
	BinaryTree<complex>* treeComplex = new BinaryTree<complex>();
	BinaryTree<complex>* treeWhereComplex = new BinaryTree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	treeWhereComplex = treeComplex->Where(BigZero);
	BOOST_CHECK(*(treeWhereComplex->GetRoot()->Value) == *a);
	BOOST_CHECK(*(treeWhereComplex->GetRoot()->Right->Value) == *b);
	BOOST_CHECK((treeWhereComplex->GetRoot()->Left) == nullptr);
}

 // TestSearchItemFloat
BOOST_AUTO_TEST_CASE(TestSearchItemFloat)
{
	// ---- Функция Поиск на вхождение элемента для float
	// Добавим 10.91 , 13.52 , 8.53 , 11.98 : 
	float* a = new float, * b = new float, * c = new float, * d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	BinaryTree<float>* treeFloat = new BinaryTree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	// Элементы дерева
	// Найдем 10.91
	BOOST_CHECK(treeFloat->SearchItem(treeFloat->GetRoot(), a));
}

 // TestSearchItemComplex
BOOST_AUTO_TEST_CASE(TestSearchItemComplex)
{
	// ---- Функция Поиск на вхождение элемента для complex
	// Добавим 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i
	complex* a = new complex(10.65, 45);
	complex* b = new complex(12.98, 74);
	complex* c = new complex(8.45, 7);
	complex* d = new complex(11.54, 8);
	BinaryTree<complex>* treeComplex = new BinaryTree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	// Элементы дерева:
	// Найдем 10.65+45i
	BOOST_CHECK(treeComplex->SearchItem(treeComplex->GetRoot(), a));
}

 // TestSearchTreeFloat
BOOST_AUTO_TEST_CASE(TestSearchTreeFloat)
{
	// ---- Функция Поиск на вхождение поддерева для float
	// Добавим 10.91 , 13.52 , 8.53 , 11.98 
	float* a = new float, * b = new float, * c = new float, * d = new float, * e = new float, * f = new float;
	*a = 10.91;
	*e = *b = 13.52;
	*c = 8.53;
	*f = *d = 11.98;
	BinaryTree<float>* treeFloat1 = new BinaryTree<float>();
	BinaryTree<float>* treeFloat2 = new BinaryTree<float>();
	treeFloat1->Add(a);
	treeFloat1->Add(b);
	treeFloat1->Add(c);
	treeFloat1->Add(d);
	treeFloat2->Add(e);
	treeFloat2->Add(f);
	// Добавим 13.52, 11.98 во второе дерево
	// Проверим вхождение второго дерево в первое
	BOOST_CHECK(treeFloat1->SearchTree(treeFloat1, treeFloat2));
}

 // TestSearchTreeComplex
BOOST_AUTO_TEST_CASE(TestSearchTreeComplex)
{
	// ---- Функция Поиск на вхождение элемента для complex
	// Добавим 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i в первое поддерево
	complex* a = new complex(10.65, 45);
	complex* b = new complex(12.98, 74);
	complex* c = new complex(8.45, 7);
	complex* d = new complex(11.54, 8);
	complex* e = new complex(12.98, 74);
	complex* f = new complex(11.54, 8);
	BinaryTree<complex>* treeComplex1 = new BinaryTree<complex>();
	BinaryTree<complex>* treeComplex2 = new BinaryTree<complex>();
	treeComplex1->Add(a);
	treeComplex1->Add(b);
	treeComplex1->Add(c);
	treeComplex1->Add(d);
	treeComplex2->Add(e);
	treeComplex2->Add(f);
	// Добавим 12.98+74i ,11.54+8i во второе дерево: " << endl;
	BOOST_CHECK(treeComplex1->SearchTree(treeComplex1, treeComplex2));
}

 // TestCutFloat
BOOST_AUTO_TEST_CASE(TestCutFloat)
{
	// ---- Функция извлечение поддерева для float
	// Добавим 10.91 , 13.52 , 8.53 , 11.98 в первое дерево
	float* a = new float, * b = new float, * c = new float, * d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	BinaryTree<float>* treeFloat = new BinaryTree<float>();
	BinaryTree<float>* treeCutFloat = new BinaryTree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	// Элементы дерева
	// Извлечем поддерево с 13.52
	treeCutFloat = treeFloat->Cut(treeFloat, b);
	// Элементы поддерева
	BOOST_CHECK(treeFloat->SearchTree(treeFloat, treeCutFloat));
}

BOOST_AUTO_TEST_CASE(TestCutComplex)
{
	// ---- Функция извлечение поддерева для complex
	// Добавим 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i
	complex* a = new complex(10.65, 45);
	complex* b = new complex(12.98, 74);
	complex* c = new complex(8.45, 7);
	complex* d = new complex(11.54, 8);
	BinaryTree<complex>* treeComplex = new BinaryTree<complex>();
	BinaryTree<complex>* treeCutComplex = new BinaryTree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	treeCutComplex = treeComplex->Cut(treeComplex, b);
	// Эдементы дерева: 
	// Извлечем поддерево с 12.98+74i 
	// Элементы поддерева: 
	BOOST_CHECK(treeComplex->SearchTree(treeComplex, treeCutComplex));
}

// Тесты для HeapBinaryTree
/*
	Дерево для тестов 
	Элементы передаваемые в дерево 
	2, 5, 100, 1500, 5050, 13, 14, 27, 70, 150, 40
	Как они должны расположится в куче-дереве
				   5050
			   /	     \
		     150 	     1500
		    /    \      /    \
		  70    100   14     40
		  / \  /  \  /  \   /   \
		  2 5  n  27 n  13 n     n
    HeapBinaryTreePush
	Добавим 15
				  5050
			   /	     \
			 150 	     1500
			/    \      /    \
		  70    100   14     40
		  / \  /  \  /  \   /   \
		  2 5  n  27 n  13 n    n
*/
 // * Добавить элемент (Сложность: O(logN))
BOOST_AUTO_TEST_CASE(BinaryHeapPush)
{
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	BOOST_CHECK(hbt->getMax() == 5050);
	BOOST_CHECK(hbt->getMax() == 1500);
	BOOST_CHECK(hbt->getMax() == 150);
	delete hbt;
}
 // * Найти максимум (Сложность: O(1))
BOOST_AUTO_TEST_CASE(BinaryHeapMax)
{
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	BOOST_CHECK(hbt->findMax() == 5050);
	delete hbt;
}
 // * Извлечь максимальный элемент (Сложность: O(logN))
BOOST_AUTO_TEST_CASE(BinaryHeapPop)
{
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	BOOST_CHECK(hbt->getMax() == 5050);
	BOOST_CHECK(hbt->findMax() == 1500);
	delete hbt;
}

BOOST_AUTO_TEST_CASE(BinaryHeapSize)
{
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	BOOST_CHECK(hbt->heapSize() == 11);
	delete hbt;
}

BOOST_AUTO_TEST_CASE(BinaryHeapAdd)
{
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	hbt->add(505);
	BOOST_CHECK(hbt->heapSize() == 12);
	hbt->add(5051);
	BOOST_CHECK(hbt->findMax() == 5051);
	BOOST_CHECK(hbt->heapSize() == 13);
	delete hbt;
}

BOOST_AUTO_TEST_CASE(BinaryHeapReBuildHeap)
{
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	hbt->add(5051);
	BOOST_CHECK(hbt->findMax() == 5051);
	BOOST_CHECK(hbt->heapSize() == 12);
	hbt->reBuildHeap(ConstArrayIntHeap, SizeConstArrayIntHeap);
	BOOST_CHECK(hbt->findMax() == 5050);
	BOOST_CHECK(hbt->heapSize() == 11);
	delete hbt;
}

BOOST_AUTO_TEST_CASE(BinaryHeapHeapSort)
{
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	int* arrayInt = new int[SizeConstArrayIntHeap];
	for (int i = 0; i < SizeConstArrayIntHeap; i++)
		arrayInt[i] = ConstArrayIntHeap[i];
	hbt->heapSort(arrayInt, SizeConstArrayIntHeap);
	BOOST_CHECK(arrayInt[0] == 2);
	BOOST_CHECK(arrayInt[SizeConstArrayIntHeap - 1] == 5050);
	delete[] arrayInt;
	delete hbt;
}

 // Тесты для HeapBinaryTree
 // Build
BOOST_AUTO_TEST_CASE(HeapBinaryTreeBuild)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	BOOST_CHECK(hbt->findMax() > 5050.0 - Epsilon && hbt->findMax() < 5050.0 + Epsilon);
	delete hbt;
}

BOOST_AUTO_TEST_CASE(HeapBinaryTreePush)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	float tmp = hbt->getMax();
	BOOST_CHECK(tmp > 5050.0 - Epsilon && tmp < 5050.0 + Epsilon);
	tmp = hbt->getMax();
	BOOST_CHECK(tmp > 1500.0 - Epsilon && tmp < 1500.0 + Epsilon);
	tmp = hbt->getMax();
	BOOST_CHECK(tmp > 150.0 - Epsilon && tmp < 150.0 + Epsilon);
	delete hbt;
}
// * Найти максимум (Сложность: O(1))
BOOST_AUTO_TEST_CASE(HeapBinaryTreeMax)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	BOOST_CHECK(hbt->findMax() > 5050.0 - Epsilon && hbt->findMax() < 5050.0 + Epsilon);
	delete hbt;
}
// * Извлечь максимальный элемент (Сложность: O(logN))
BOOST_AUTO_TEST_CASE(HeapBinaryTreePop)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	float tmp = hbt->getMax();
	BOOST_CHECK(tmp > 5050.0 - Epsilon && tmp < 5050.0 + Epsilon);
	BOOST_CHECK(hbt->findMax() > 1500.0 - Epsilon && hbt->findMax() < 1500.0 + Epsilon);
	delete hbt;
}

//BOOST_AUTO_TEST_CASE(BinaryHeapSize)
//{
//	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
//	BOOST_CHECK(hbt->heapSize() == 11);
//	delete hbt;
//}

BOOST_AUTO_TEST_CASE(HeapBinaryTreeAdd)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	float* a = new float;
	*a = 505.0;
	float* b = new float;
	*b = 5051.0;
	hbt->Add(a);
	//BOOST_CHECK(hbt->heapSize() == 12);
	hbt->Add(b);
	BOOST_CHECK(hbt->findMax() > 5051.0 - Epsilon && hbt->findMax() < 5051.0 + Epsilon);
	//BOOST_CHECK(hbt->heapSize() == 13);
	delete hbt;
}

BOOST_AUTO_TEST_CASE(HeapBinaryTreeReBuildHeap)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	float* a = new float;
	*a = 5051.0;
	hbt->Add(a);
	float tmp = hbt->getMax();
	BOOST_CHECK(tmp > 5051.0 - Epsilon && tmp < 5051.0 + Epsilon);
	//BOOST_CHECK(hbt->heapSize() == 12);
	BOOST_CHECK(hbt->findMax() > 5050.0 - Epsilon && hbt->findMax() < 5050.0 + Epsilon);
	/*BOOST_CHECK(hbt->heapSize() == 11);*/
	delete hbt;
}

BOOST_AUTO_TEST_CASE(HeapBinaryTreeHeapSort)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	float* arrayInt = new float[SizeConstArrayIntHeap];
	for (int i = 0; i < SizeConstArrayIntHeap; i++)
		arrayInt[i] = ConstArrayIntHeap[i];
	hbt->heapSort(arrayInt, SizeConstArrayFloatHeap);
	BOOST_CHECK(arrayInt[0] > 2.0 - Epsilon && arrayInt[0] < 2.0 + Epsilon);
	BOOST_CHECK(arrayInt[SizeConstArrayIntHeap - 1] > 5050.0 - Epsilon && arrayInt[SizeConstArrayIntHeap - 1] < 5050.0 + Epsilon);
	delete[] arrayInt;
	delete hbt;
}
 // Map
BOOST_AUTO_TEST_CASE(HeapBinaryTreeHeapMap)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	float* a = new float;
	*a = 5051.0;
	hbt->Add(a);
	HeapBinaryTree<float>* hbt2 = hbt->Map(plusOne);
	float tmp = hbt2->getMax();
	BOOST_CHECK(tmp > 5052.0 - Epsilon && tmp < 5052.0 + Epsilon);
	BOOST_CHECK(hbt2->findMax() > 5051.0 - Epsilon && hbt2->findMax() < 5051.0 + Epsilon);
	delete hbt;
	delete hbt2;
}
// Where
BOOST_AUTO_TEST_CASE(HeapBinaryTreeWhere)
{
	HeapBinaryTree<float>* hbt = new HeapBinaryTree<float>(ConstArrayFloatHeap, SizeConstArrayFloatHeap);
	float* a = new float;
	*a = 0.0;
	hbt->Add(a);
	HeapBinaryTree<float>* hbt2 = hbt->Where(BigZero);
	BOOST_CHECK(((hbt2->GetRoot())->Right->Right->Right->Right->Right->Left) == nullptr);
	delete hbt;
}
// SearchItem
BOOST_AUTO_TEST_CASE(HeapBinaryTreeSearchItem)
{
	HeapBinaryTree<int>* hbt = new HeapBinaryTree<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	int* a = new int;
	*a = 0;
	hbt->Add(a);
	HeapBinaryTree<int>* hbt2;
	BOOST_CHECK(hbt->SearchItem( hbt->GetRoot(), a) );
	hbt2 = hbt->Where(BigZero);
	BOOST_CHECK(!( hbt2->SearchItem(hbt2->GetRoot(), a) ));
	delete hbt;
}

// SearchTree
BOOST_AUTO_TEST_CASE(HeapBinaryTreeSearchTree)
{
	HeapBinaryTree<int>* hbt = new HeapBinaryTree<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	int* a = new int;
	*a = 0;
	int* b = new int;
	*b = 70;
	int* c = new int;
	*c = 14;
	int* d = new int;
	*d = 100;
	hbt->Add(a);
	HeapBinaryTree<int>* hbt2 = new HeapBinaryTree<int>;
	hbt2->Add(d);
	hbt2->Add(c);
	hbt2->Add(b);
	BOOST_CHECK(hbt->SearchTree(hbt, hbt2));
	hbt2->Add(a);
	BOOST_CHECK(!(  hbt->SearchTree(hbt, hbt2) ));
	delete hbt2;
	delete hbt;
}
 // Cut
BOOST_AUTO_TEST_CASE(HeapBinaryTreeCut)
{
	int* a = new int;
	*a = 1500;
	HeapBinaryTree<int>* hbt = new HeapBinaryTree<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	HeapBinaryTree<int>* hbt2 = (hbt->Cut(hbt, a));
	BOOST_CHECK(hbt->SearchTree(hbt, hbt2));
	delete hbt2;
	delete hbt;
}
 // AddTreeWithNode
BOOST_AUTO_TEST_CASE(HeapBinaryTreeAddTreeWithNode)
{
	int* a = new int;
	*a = 10000;
	int* b = new int;
	*b = 6000;
	int* c = new int;
	*c = 5700;
	HeapBinaryTree<int>* hbt = new HeapBinaryTree<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	HeapBinaryTree<int>* hbt2 = new HeapBinaryTree<int>;
	hbt2->Add(a); hbt2->Add(b); hbt2->Add(c);
	hbt->AddTreeWithNode(hbt2->GetRoot());
	BOOST_CHECK(hbt->SearchTree(hbt, hbt2));
	delete hbt2;
	delete hbt;
}
// GetMergedTrees
BOOST_AUTO_TEST_CASE(HeapBinaryTreeGetMergedTrees)
{
	int* a = new int;
	*a = 10000;
	int* b = new int;
	*b = 6000;
	int* c = new int;
	*c = 5700;
	HeapBinaryTree<int>* hbt = new HeapBinaryTree<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	HeapBinaryTree<int>* hbt2 = new HeapBinaryTree<int>;
	hbt2->Add(a); hbt2->Add(b); hbt2->Add(c);
	hbt->AddTreeWithNode(hbt2->GetRoot());
	HeapBinaryTree<int>* hbt3 = (hbt2->GetMergedTrees(hbt, hbt2));
	hbt3->getMax();
	BOOST_CHECK(hbt3->getMax() == 10000);
	BOOST_CHECK(hbt3->getMax() == 6000);
	BOOST_CHECK(hbt3->getMax() == 6000);
	BOOST_CHECK(hbt3->getMax() == 5700);
	delete hbt2;
	delete hbt;
	delete hbt3;
}

// Тесты для IRunnerBinaryTree
// Build
//----------------

// Тесты для ThreadedBinaryTree
// Build
BOOST_AUTO_TEST_CASE(ThreadedBinaryTreeBuild)
{
	auto* tbt = new ThreadedBinaryTree<int>(-1);
	BOOST_CHECK(tbt != nullptr);
	delete tbt;
}
 // Add
BOOST_AUTO_TEST_CASE(ThreadedBinaryTreeAdd)
{
	auto* tbt = new ThreadedBinaryTree<int>(-1);
	for (int i = 0; i < SAI9; i++) tbt->Add(AInt9[i]);
	BOOST_CHECK(tbt->GetNodeCount() == 9);
	delete tbt;
}
 // GetValue
BOOST_AUTO_TEST_CASE(ThreadedBinaryTreeGetValue)
{
	auto* tbt = new ThreadedBinaryTree<int>(-1);
	for (int i = 0; i < SAI9; i++) tbt->Add(AInt9[i]);
	BOOST_CHECK(tbt->GetNodeCount() == 9);
	for (int i = 0; i < SAI9; i++)
		BOOST_CHECK(tbt->GetValue(i) == AInt9[i]);
	BOOST_CHECK(tbt->GetValue(-1) == -1);
	BOOST_CHECK(tbt->GetValue(SAI9 + 1) == -1);
	delete tbt;
}

// GetNodeCount
BOOST_AUTO_TEST_CASE(ThreadedBinaryTreeGetNodeCount)
{
	auto* tbt = new ThreadedBinaryTree<int>(-1);
	for (int i = 0; i < SAI9 - 1; i++) tbt->Add(AInt9[i]);
	BOOST_CHECK(tbt->GetNodeCount() == SAI9 - 1);
	tbt->Add(AInt9[SAI9 - 1]);
	BOOST_CHECK(tbt->GetNodeCount() == SAI9);
	delete tbt;
}

// Тесты для PerfectlyBalancedTree.h
 // Build
BOOST_AUTO_TEST_CASE(PerfectlyBalancedTreeBuild)
{
	auto* pbt = new PerfectlyBalancedTree<int>(SAI9, AInt9, -1);
	BOOST_CHECK(pbt->GetSize() == SAI9);
	pbt->~PerfectlyBalancedTree();
}
 // GetValue
BOOST_AUTO_TEST_CASE(PerfectlyBalancedTreeGetValue)
{
	auto* pbt = new PerfectlyBalancedTree<int>(SAI9, AInt9, -1);
	BOOST_CHECK(pbt->GetValue(0, Round::TLR) == AInt9[SAI9 - 1]);
	BOOST_CHECK(pbt->GetValue(SAI9, Round::TLR) == -1);
	for (int i = 0; i < SAI9;i++) BOOST_CHECK(pbt->GetValue(i, Round::TLR) == AInt9[SAI9 - 1 - i]);
	pbt->~PerfectlyBalancedTree();
}