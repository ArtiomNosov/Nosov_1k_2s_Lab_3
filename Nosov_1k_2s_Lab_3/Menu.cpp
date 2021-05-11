/*
*	Menu.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#include "Menu.h"

void PrintMenu()
{
	cout << "----Menu----" << endl;
	cout << "1. Добавить элемент в дерево." << endl;
	cout << "2. Вывод элементов дерева." << endl;
	cout << "3. Функция Map. (+1)" << endl;
	cout << "4. Функция Where. (>0)" << endl;
	cout << "5. Функция извлечения поддерева." << endl;
	cout << "6. Поиск элемента на вхождения в дерево." << endl;
	cout << "7. Поиск поддерева на вхождения в дерево." << endl;
	cout << "8. Тесты." << endl;
	cout << "9. Выход." << endl;
}

void menuFloat()
{
	int choice = 0;
	BinaryTree<float>* tree = new BinaryTree<float>();
	BinaryTree<float>* tree2 = new BinaryTree<float>();
	BinaryTree<float>* tree3 = new BinaryTree<float>();
	BinaryTree<float>* tree4 = new BinaryTree<float>();
	BinaryTree<float>* tree5 = new BinaryTree<float>();
	float *f = new float;
	float* f1 = new float;
	float * f2 = new float;
	float *f3 = new float;

	while (choice != 9) {

		PrintMenu();
		cin >> choice;
		int i = 1;
		int j = 1;

		switch (choice)
		{
		case 1:			
			while (i == 1) 
			{
				f = new float;
				cout << "Введите элемент: \n(Если он первый , то он будет корнем вашего дерева.)" << endl;
				cin >> *f;
				tree->Add(f);
				cout << "Продолжит ввод? \n1. Да.\n!=1. Нет." << endl;
				cin >> i;
			}
			break;
		case 2:
			tree->PrintTree(tree);
			break;
		case 3:
			tree2 = tree->Map(plusOne);
			tree2->PrintTree(tree2);
			break;
		case 4:
			tree3 = tree->Where(BigZero);
			tree3->PrintTree(tree3);
			break;
		case 5:
			cout << "Введите корень поддерева:" << endl;
			cin >> *f1;
			tree4 = tree->Cut(tree, f1);
			tree4->PrintTree(tree4);
			break;
		case 6:
			cout << "Введите элемент для поиска на вхождение:" << endl;
			cin >> *f2;
			if (tree->SearchItem(tree->GetRoot(), f2))
				cout << "Ваш элемент входит в дерево." << endl;
			else
				cout << "Ваш элемент не входит в дерево." << endl;
			break;
		case 7:
			while (j == 1) {
				f3 = new float;
				cout << "Введите элементы поддерева для поиска: \n(Если он первый , то он будет корнем вашего дерева.)" << endl;
				cin >> *f3;
				tree5->Add(f3);
				cout << "Продолжит ввод? \n1. Да.\n!=1. Нет." << endl;
				cin >> j;
			}
			tree5->PrintTree(tree5);
			if (tree->SearchTree(tree, tree5))
				cout << "Ваше поддерево входит в дерево." << endl;
			else
				cout << "Ваше поддерево не входит в дерево." << endl;
			break;
		case 8:
			Test(1); 
			break;
		case 9: 
			break;
		default:
			cout << "Такой команды нет!" << endl;
			break;
		}
	}
}

void menuComplex()
{
	int choice = 0;
	BinaryTree<complex>* tree = new BinaryTree<complex>();
	BinaryTree<complex>* tree2 = new BinaryTree<complex>();
	BinaryTree<complex>* tree3 = new BinaryTree<complex>();
	BinaryTree<complex>* tree4 = new BinaryTree<complex>();
	BinaryTree<complex>* tree5 = new BinaryTree<complex>();
	complex *f1 = new complex(0, 0);
	complex *f2 = new complex(0, 0);
	complex *f3 = new complex(0, 0);
	complex *f = new complex(0, 0);

	while (choice != 9) {

		PrintMenu();
		cin >> choice;
		int k = 1;
		int j = 1;

		double r = 0, i = 0;
		double r1 = 0, i1 = 0;
		double r2 = 0, i2 = 0;
		double r3 = 0, i3 = 0;


		switch (choice)
		{
		case 1:
			while (k == 1) {
				f = new complex(0, 0);
				cout << "Введите элемент: \n(Если он первый , то он будет корнем вашего дерева.)" << endl;
				cout << "Введите действительную часть: ";
				cin >> r;
				cout << "Введите мнимую часть: ";
				cin >> i;
				f->cin(r, i);
				tree->Add(f);
				cout << "Продолжит ввод? \n1. Да.\n!=1. Нет." << endl;
				cin >> k;
			}
			break;
		case 2:
			tree->PrintTree(tree);
			break;
		case 3:
			
			tree2 = tree->Map(plusOne);
			break;
		case 4:
			
			tree3 = tree->Where(BigZero);
			break;
		case 5:
			
			cout << "Введите корень поддерева:" << endl;
			cout << "Введите действительную часть: ";
			cin >> r1;
			cout << "Введите мнимую часть: ";
			cin >> i1;
			f1->cin(r1, i1);
			tree4 = tree->Cut(tree, f1);
			tree4->PrintTree(tree4);
			break;
		case 6:
			cout << "Введите элемент для поиска на вхождение:" << endl;
			cout << "Введите действительную часть: ";
			cin >> r2;
			cout << "Введите мнимую часть: ";
			cin >> i2;
			f2->cin(r2, i2);
			if (!(tree->SearchItem(tree->GetRoot(), f2)))
				cout << "Ваш элемент не входит в дерево." << endl;
			else
				cout << "Ваш элемент входит в дерево." << endl;
			break;
		case 7:
			
			while (j == 1) {
				cout << "Введите элементы поддерева для поиска: \n(Если он первый , то он будет корнем вашего дерева.)" << endl;
				cout << "Введите действительную часть: ";
				cin >> r3;
				cout << "Введите мнимую часть: ";
				cin >> i3;
				f3->cin(r3, i3);
				tree->Add(f3);
				cout << "Продолжит ввод? \n1. Да.\n!=1. Нет." << endl;
				cin >> i;
			}
			if (!(tree->SearchTree(tree, tree5)))
				cout << "Ваше поддерево не входит в дерево." << endl;
			else
				cout << "Ваше поддерево входит в дерево." << endl;
			break;
		case 8:
			Test(2);
			break;
		case 9:
			break;
		default:
			cout << "Такой команды нет!" << endl;
			break;
		}
	}
}

void menu()
{
	int choice = 0 ;
	cout << "-Menu-" << endl;
	cout << "Тип дерево:" << endl;
	cout << "1. Float\n2. Complex" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		menuFloat();
		break;
	case 2:
		menuComplex();
		break;
	default:
		cout << "Такого типа не сушествует!" << endl;
		break;
	}

}