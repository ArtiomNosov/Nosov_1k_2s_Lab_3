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