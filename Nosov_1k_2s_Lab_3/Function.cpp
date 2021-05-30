/*
*	Functions.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#include "Function.h"

string ToStrings(float value) 
{
	return to_string(value);
}

string ToStrings(complex value)
{
	string tmp = " " + to_string(value.real);
	if (value.image >= 0)
		tmp = tmp + " + ";
	tmp = tmp + to_string(value.image);
	return tmp;
}

bool BigZero(float* value)
{
	if (*value > 0) 
		return true;
	return false;
}

bool BigZero(complex* value)
{
	complex zero(0,0);
	if (*value > zero)
		return true;
	return false;
}

bool BigZero(int* value)
{
	if (*value > 0)
		return true;
	return false;
}

bool BigZero(int value) {
	return value > 0;
}

complex* plusOne(complex* value)
{
	complex* result = new complex(value->real+1 , value->image);
	return result; 
}

float* plusOne(float* value)
{
	float* result = new float;
	*result = *value + 1.0;
	return result;
}

int* plusOne(int* value)
{
	int* result = new int;
	*result = *value + 1;
	return result;
}

int plusOne(int value) {
	return ++value;
}