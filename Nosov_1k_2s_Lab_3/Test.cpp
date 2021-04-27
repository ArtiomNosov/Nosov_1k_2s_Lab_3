/*
*	Test.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company: 
*	Email: artiom-nj@mail.ru
*/

#include "Test.h"
HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

int TestAddFloat() 
{
	cout << "---- ���������� float ���������" << endl;
	cout << "������� 10.91 , 13.52 , 8.53 , 11.98 : " << endl; 
	float *a = new float, *b = new float, *c = new float , *d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	Tree<float>* treeFloat = new Tree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	treeFloat->PrintTree(treeFloat);
	if (*(treeFloat->GetRoot()->Value) == *a &&
		*(treeFloat->GetRoot()->Right->Value) == *b &&
		*(treeFloat->GetRoot()->Left->Value) == *c &&
		*(treeFloat->GetRoot()->Right->Left->Value) == *d) 
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestAddComplex()
{
	cout << "---- ���������� complex ���������" << endl;
	cout << "������� 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i : " << endl;
	complex *a = new complex(10.65 , 45); 
	complex *b = new complex(12.98 , 74);
	complex *c = new complex(8.45, 7);
	complex *d = new complex(11.54, 8);
	Tree<complex>* treeComplex = new Tree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	treeComplex->PrintTree(treeComplex);
	if (*(treeComplex->GetRoot()->Value) == *a &&
		*(treeComplex->GetRoot()->Right->Value) == *b &&
		*(treeComplex->GetRoot()->Left->Value) == *c &&
		*(treeComplex->GetRoot()->Right->Left->Value) == *d)
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestMapFloat() 
{
	cout << "---- ������� Map ��� float" << endl; 
	cout << "������� 10.91 , 13.52 , 8.53 , 11.98 : " << endl;
	float *a = new float, *b = new float, *c = new float, *d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	Tree<float>* treeFloat = new Tree<float>(); 
	Tree<float>* treeMapFloat = new Tree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	treeMapFloat = treeFloat->Map(plusOne);
	cout << "�� ������������� ������� Map:" << endl;
	treeFloat->PrintTree(treeFloat);
	cout << "����� ������������� ������� Map:" << endl;
	treeMapFloat->PrintTree(treeMapFloat);
	if (*(treeMapFloat->GetRoot()->Value) == *a+1 &&
		*(treeMapFloat->GetRoot()->Right->Value) == *b+1 &&
		*(treeMapFloat->GetRoot()->Left->Value) == *c+1 &&
		*(treeMapFloat->GetRoot()->Right->Left->Value) == *d+1)
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestMapComplex()
{
	cout << "---- ������� Map ��� complex" << endl;
	cout << "������� 10.65+45i , 12.98+74i , 8.4+7i , 11.54+8i : " << endl;
	complex *a = new complex(10.65, 45);
	complex *b = new complex(12.98, 74);
	complex *c = new complex(8.4, 7);
	complex *d = new complex(11.54, 8);
	complex *one = new complex(1 ,0);
	Tree<complex>* treeComplex = new Tree<complex>();
	Tree<complex>* treeMapComplex = new Tree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	treeMapComplex = treeComplex->Map(plusOne);
	cout << "�� ������������� ������� Map:" << endl;
	treeComplex->PrintTree(treeComplex);
	cout << "����� ������������� ������� Map:" << endl;
	treeMapComplex->PrintTree(treeMapComplex);
	if (*(treeMapComplex->GetRoot()->Value) == (*a + *one) &&
		*(treeMapComplex->GetRoot()->Right->Value) == (*b + *one) &&
		*(treeMapComplex->GetRoot()->Left->Value) == (*c + *one) &&
		*(treeMapComplex->GetRoot()->Right->Left->Value) == (*d + *one)
		)
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
		return 1;
}

int TestWhereFloat()
{
	cout << "---- ������� Where ��� float" << endl;
	cout << "������� 10.91 , 13.52 , -8.53 , -11.98 : " << endl;
	float *a = new float, *b = new float, *c = new float, *d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = -8.53;
	*d = -11.98;
	Tree<float>* treeFloat = new Tree<float>();
	Tree<float>* treeWhereFloat = new Tree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	treeWhereFloat = treeFloat->Where(BigZero);
	cout << "�� ������������� ������� Where:" << endl;
	treeFloat->PrintTree(treeFloat);
	cout << "����� ������������� ������� Where:" << endl;
	treeWhereFloat->PrintTree(treeWhereFloat);
	if (*(treeWhereFloat->GetRoot()->Value) == *a &&
		*(treeWhereFloat->GetRoot()->Right->Value) == *b &&
		(treeWhereFloat->GetRoot()->Left) == nullptr)
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestWhereComplex()
{
	cout << "---- ������� Where ��� complex" << endl;
	cout << "������� 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i : " << endl;
	complex *a = new complex(10.65, 45);
	complex *b = new complex(12.98, 74);
	complex *c = new complex(-8.45, 7);
	complex *d = new complex(-11.54, 8);
	Tree<complex>* treeComplex = new Tree<complex>();
	Tree<complex>* treeWhereComplex = new Tree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	treeWhereComplex = treeComplex->Where(BigZero);
	cout << "�� ������������� ������� Where:" << endl;
	treeComplex->PrintTree(treeComplex);
	cout << "����� ������������� ������� Where:" << endl;
	treeWhereComplex->PrintTree(treeWhereComplex);
	if (*(treeWhereComplex->GetRoot()->Value) == *a &&
		*(treeWhereComplex->GetRoot()->Right->Value) == *b &&
		(treeWhereComplex->GetRoot()->Left) == nullptr)
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestSearchItemFloat()
{
	cout << "---- ������� ����� �� ��������� �������� ��� float" << endl;
	cout << "������� 10.91 , 13.52 , 8.53 , 11.98 : " << endl;
	float *a = new float, *b = new float, *c = new float, *d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	Tree<float>* treeFloat = new Tree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	cout << "�������� ������: " << endl;
	treeFloat->PrintTree(treeFloat);
	cout << "������ 10.91 " << endl;
	if (treeFloat->SearchItem(treeFloat->GetRoot(), a)) 
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestSearchItemComplex()
{
	cout << "---- ������� ����� �� ��������� �������� ��� complex" << endl;
	cout << "������� 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i : " << endl;
	complex *a = new complex(10.65, 45);
	complex *b = new complex(12.98, 74);
	complex *c = new complex(8.45, 7);
	complex *d = new complex(11.54, 8);
	Tree<complex>* treeComplex = new Tree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	cout << "�������� ������: " << endl;
	treeComplex->PrintTree(treeComplex);
	cout << "������ 10.65+45i " << endl;
	if (treeComplex->SearchItem(treeComplex->GetRoot(), a)) 
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestSearchTreeFloat()
{
	cout << "---- ������� ����� �� ��������� ��������� ��� float" << endl;
	cout << "������� 10.91 , 13.52 , 8.53 , 11.98 � ������ ������: " << endl;
	float *a = new float, *b = new float, *c = new float, *d = new float , *e = new float , *f = new float ;
	*a = 10.91;
	*e = *b = 13.52;
	*c = 8.53;
	*f = *d = 11.98;
	Tree<float>* treeFloat1 = new Tree<float>();
	Tree<float>* treeFloat2 = new Tree<float>();
	treeFloat1->Add(a);
	treeFloat1->Add(b);
	treeFloat1->Add(c);
	treeFloat1->Add(d);
	treeFloat2->Add(e); 
	treeFloat2->Add(f);
	treeFloat1->PrintTree(treeFloat1);
	cout << "������� 13.52, 11.98 �� ������ ������: " << endl;
	treeFloat2->PrintTree(treeFloat2);
	cout << "�������� ��������� ������� ������ � ������: " << endl;
	if (treeFloat1->SearchTree(treeFloat1, treeFloat2))
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestSearchTreeComplex()
{
	cout << "---- ������� ����� �� ��������� �������� ��� complex" << endl;
	cout << "������� 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i � ������ ���������: " << endl;
	complex *a = new complex(10.65, 45);
	complex *b = new complex(12.98, 74);
	complex *c = new complex(8.45, 7);
	complex *d = new complex(11.54, 8);

	complex *e = new complex(12.98, 74);
	complex *f = new complex(11.54, 8);
	Tree<complex>* treeComplex1 = new Tree<complex>();
	Tree<complex>* treeComplex2 = new Tree<complex>();
	treeComplex1->Add(a);
	treeComplex1->Add(b);
	treeComplex1->Add(c);
	treeComplex1->Add(d);
	treeComplex2->Add(e);
	treeComplex2->Add(f);
	treeComplex1->PrintTree(treeComplex1);
	cout << "������� 12.98+74i ,11.54+8i �� ������ ������: " << endl;
	treeComplex2->PrintTree(treeComplex2);
	if (treeComplex1->SearchTree(treeComplex1 , treeComplex2))
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestCutFloat()
{
	cout << "---- ������� ���������� ��������� ��� float" << endl;
	cout << "������� 10.91 , 13.52 , 8.53 , 11.98 � ������ ������: " << endl;
	float *a = new float, *b = new float, *c = new float, *d = new float;
	*a = 10.91;
	*b = 13.52;
	*c = 8.53;
	*d = 11.98;
	Tree<float>* treeFloat = new Tree<float>();
	Tree<float>* treeCutFloat = new Tree<float>();
	treeFloat->Add(a);
	treeFloat->Add(b);
	treeFloat->Add(c);
	treeFloat->Add(d);
	cout << "�������� ������: " << endl;
	treeFloat->PrintTree(treeFloat);
	cout << "�������� ��������� � 13.52 " << endl;
	treeCutFloat = treeFloat->Cut(treeFloat , b);
	cout << "�������� ���������: " << endl;
	treeCutFloat->PrintTree(treeCutFloat);
	if (treeFloat->SearchTree(treeFloat, treeCutFloat))
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

int TestCutComplex()
{
	cout << "---- ������� ���������� ��������� ��� complex" << endl;
	cout << "������� 10.65+45i , 12.98+74i , 8.45+7i , 11.54+8i : " << endl;
	complex *a = new complex(10.65, 45);
	complex *b = new complex(12.98, 74);
	complex *c = new complex(8.45, 7);
	complex *d = new complex(11.54, 8);
	Tree<complex>* treeComplex = new Tree<complex>();
	Tree<complex>* treeCutComplex = new Tree<complex>();
	treeComplex->Add(a);
	treeComplex->Add(b);
	treeComplex->Add(c);
	treeComplex->Add(d);
	treeCutComplex = treeComplex->Cut(treeComplex, b);
	cout << "�������� ������: " << endl;
	treeComplex->PrintTree(treeComplex);
	cout << "�������� ��������� � 12.98+74i " << endl;
	cout << "�������� ���������: " << endl;
	treeCutComplex->PrintTree(treeCutComplex);
	if (treeComplex->SearchTree(treeComplex, treeCutComplex))
	{
		SetConsoleTextAttribute(hwnd, 10);
		cout << "������� ����������!" << endl << endl << endl;
		SetConsoleTextAttribute(hwnd, 15);
		return 0;
	}
	return 1;
}

void Test(int i) 
{
	if(i == 1)
	{
		TestAddFloat();
		TestMapFloat();
		TestWhereFloat(); 
		TestSearchItemFloat(); 
		TestSearchTreeFloat(); 
		TestCutFloat();
	}
	else
	{
		TestAddComplex();
		TestMapComplex();
		TestWhereComplex();
		TestSearchItemComplex();
		TestSearchTreeComplex();
		TestCutComplex();
	}
}