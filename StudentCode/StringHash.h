#pragma once
#include "PrimeUtil.h"
#include"HashTable.h"
#include <cmath>

template <class T>
class StringHash :public HashTable<string, T>
{
private:
	uint64_t h1(string k);
	uint64_t h2(string k);
	int largest_prime_smaller(int n);

public:
	StringHash(int m = 10) :HashTable<string, T>(m) {}
};



template <class T>
int StringHash<T>::largest_prime_smaller(int n)
{
	n = n - 1;
	while(true)
	{
		if (PrimeUtil::prime(n))
		{
			return n;
		}
		else
		{
			n = n - 1;
		}
	}

}




template <class T>
uint64_t StringHash<T>::h1(string k)
{
	int m = this -> size;

	int result = 0;
	for (int i = 0; i < k.size(); i++)
	{
		result += int((int(k[i]) * pow(256,i) )) % m;
	}

	return result;

}


template <class T>
uint64_t StringHash<T>::h2(string k)
{

	int m = this -> size;

	int l = largest_prime_smaller(m);

	return l - (stoi(k) % l);

}


