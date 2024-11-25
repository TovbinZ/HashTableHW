#pragma once
#include"HashTable.h"
#include<string>
using namespace std;
template <class T>
class IntHash :public HashTable<int,T>
{
private:
	//TODO: implement h1 and h2
public:
	IntHash(int m = 10) :HashTable<int,T>(m) {}
};

