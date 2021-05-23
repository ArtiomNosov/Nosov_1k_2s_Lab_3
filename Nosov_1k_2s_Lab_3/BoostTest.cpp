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
