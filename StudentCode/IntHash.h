#pragma once
#include"HashTable.h"
#include<string>
using namespace std;
template <class T>
class IntHash :public HashTable<int,T>
{
private:
	int h1(int k);
	int h2(int k);
public:
	IntHash(int m = 10) :HashTable<int,T>(m) {}
};

template <class T>
int IntHash<T>::h1(int k)
{

	return k % this->size

}

template <class T>
int IntHash<T>::h2(int k)
{
	return 1 + k % (this->size - 1)
}
