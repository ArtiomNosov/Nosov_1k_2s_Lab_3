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

BOOST_AUTO_TEST_CASE(Test_1)
{
	BinaryTree<int>* bt_p_1 = &BinaryTree<int>();
	int* arrayInteger = new int[SizeConstArrayInt10];
		
	for (int i = 0; i < SizeConstArrayInt10; i++)
		arrayInteger[i] = ConstArrayInt10[i];
	for(int i = 0; i< SizeConstArrayInt10;i++)
		bt_p_1->Add(&arrayInteger[i]);
	bt_p_1->Map(plusOne);
	for (int i = 0; i < SizeConstArrayInt10; i++)
		bt_p_1->SearchItem(&ConstArrayInt10[i]);
}