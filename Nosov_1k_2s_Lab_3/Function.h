/*
*	Functions.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <string>
#include "Complex.h"
using namespace std;

string ToStrings(float value);
string ToStrings(complex value);
bool BigZero(float* value);
bool BigZero(complex* value);
bool BigZero(int* value);
bool BigZero(int value);
float* plusOne(float* value);
complex* plusOne(complex* value);
int* plusOne(int* value);
int plusOne(int value);

#endif

