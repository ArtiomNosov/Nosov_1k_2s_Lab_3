/*
*	Main.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

// � ������� ���� �������� ������.
// ������� ����� ��� ThreadedBinaryTree
// ��������� �������� ���������������� ������.
// ������� ����� �� �������� ���������������� ������
// ��������� ������� � ������������ �� ������ ������.
// ������� ����� ��������� � ������������ �� ������ ������.
// TODO: ��������� ����� ��� ��������� ������������ �������.
// ������� ����� �� ������� ������ � ������� ����������� ��� BinaryTreeValue.

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
#include "ThreadedBinaryTree.h"
#include "GenerateDataset.h"
#include "PerfectlyBalancedTree.h"
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
	int Number = 100000;
	int dotNumber = 100;
	test_generator("text1.txt", Number, Number);
	SpeedTestBinaryTree(Number, dotNumber);
	//auto* pbt = new PerfectlyBalancedTree<int>(9, AInt9, -1);
	//// auto* pbt = new PerfectlyBalancedTree<int>(5, -1);
	//pbt->PrintRTL();
	//pbt->~PerfectlyBalancedTree();
	system("pause");
}