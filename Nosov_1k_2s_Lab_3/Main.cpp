/*
*	Main.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

// TODO: ������� ������.
// TODO: ������������ ������.
// TODO: ��������� �����.
// TODO: ����� �� ������� ������ � ������� �����������.
// TODO: ������� � ������������ �� ������ ������.

#include <iostream>
#include <locale>
#include "BinaryTree.h"
#include "Test.h"
#include "Complex.h"
#include "Function.h"
#include "Menu.h"
#include <Windows.h>

// ��� include
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