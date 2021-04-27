/*
*	Complex.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

class complex
{
public:
	complex(double real, double image);
	double real, image;
	void cin(double real, double image);
	void cout();
	bool operator < (const complex other);
	bool operator > (const complex other);
	bool operator >= (const complex other);
	bool operator <= (const complex other);
	bool operator == (const complex other);
	complex operator +(const complex other);
	complex &operator ++();
};


#endif