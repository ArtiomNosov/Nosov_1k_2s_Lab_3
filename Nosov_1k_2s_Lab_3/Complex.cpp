/*
*	Complex.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#include "Complex.h"

complex::complex(double real = 0, double image = 0)
{
	this->real = real;
	this->image = image;
}

void complex::cin(double real, double image)
{
	this->real = real;
	this->image = image;
}

void complex::cout()
{
	std::cout << this->real;
	if (this->image > 0) std::cout << "+";
	std::cout << this->image << "i" << std::endl;
}

bool complex::operator<(const complex other)
{
	return this->real < other.real;
}

bool complex::operator<=(const complex other)
{
	return this->real <= other.real;
}

bool complex::operator==(const complex other)
{
	return this->real == other.real && this->image == other.image;
}

complex complex::operator+(const complex other)
{
	complex tmp;
	tmp.image = this->image + other.image;
	tmp.real = this->real + other.real;
	return tmp;
}

complex & complex::operator++()
{
	this->real += 1;
	return *this;
}

bool complex::operator>(const complex other)
{
	return this->real > other.real;
}

bool complex::operator>=(const complex other)
{
	return this->real >= other.real;
}