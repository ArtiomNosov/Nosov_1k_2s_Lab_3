/*
*	Main.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

// В проекте есть прошитое дерево.
// Сделаны тесты для ThreadedBinaryTree
// TODO: Балансировка дерева. 
// TODO: Атомарные тесты.
// TODO: Тесты на больших данных и графики зависимости.
// TODO: Очередь с приоритетами на основе дерева.

#include <iostream>
#include <locale>
#include "BinaryTree.h"
#include "Test.h"
#include "Complex.h"
#include "Function.h"
#include "Menu.h"
#include <Windows.h>

// Мои include
#include "BinaryHeap.h"
#include "ConstantsBoostTest.h"
#include "ThreadedBinaryTree.h"
#include "GenerateDataset.h"
#include "OperationSpeedTest.h"

int main()
{
	/*HANDLE hwnds = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hwnds, 15);
	setlocale(LC_ALL , "RU");
	menu();*/
	/*BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	cout << hbt->getMax() << endl;
	cout << hbt->getMax() << endl;
	cout << hbt->getMax() << endl;
	delete hbt;*/
	// For treaded tree
	/*ThreadedBinaryTree<int>* tbt = new ThreadedBinaryTree<int>;
	tbt->Add(20);
	tbt->Add(10);
	tbt->Add(30);
	tbt->Add(5);
	tbt->Add(16);
	tbt->Add(14);
	tbt->Add(17);
	tbt->Add(13);
	tbt->PrintThreadedBinaryTree();*/
	test_generator("text1.txt", 100000, 100000);
	SpeedTestBinaryTree(100000, 100);
	system("pause");
}