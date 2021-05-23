/*
*	Main.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

// TODO: Прошить дерево.
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

int main()
{
	/*HANDLE hwnds = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hwnds, 15);
	setlocale(LC_ALL , "RU");
	menu();*/
	BinaryHeap<int>* hbt = new BinaryHeap<int>(ConstArrayIntHeap, SizeConstArrayIntHeap);
	cout << hbt->getMax() << endl;
	cout << hbt->getMax() << endl;
	cout << hbt->getMax() << endl;
	delete hbt;
	
	
	
	system("pause");
}