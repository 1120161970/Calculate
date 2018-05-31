#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sys/timeb.h>
using namespace std;
#define MAXX 50000
#define MINN 0.00001

void Create_problems(char s[]);
bool Judge(char c1, char c2);
void From_Infix_to_Suffix(char* Infix, char* Suffix);
double Suffix_Value(char* Suffix);
bool _Fraction(int &x, int &y, double num);