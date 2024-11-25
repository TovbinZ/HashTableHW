#pragma once
#include <iostream>
using namespace std;

enum state { EMPTY, FULL, DELETED };

template<class K,class T>
class HashTable
{
protected:
	class Item
	{
	public:
		T data;			//The record information
		K key;			//The record key
		state flag;		//An indicator for the vacancy of the cell
		//Constructors
		Item(){ flag = EMPTY; }
		Item(K k,T d ) { data = d; key = k; flag = FULL; }
	};

	int size;
	Item* table; //this is root
	Item* next;
	// TODO: Add any additional required attributes
	// TODO: Add here the declaration of the functions h1, h2. 
	// TODO: Based on the functions, define the hash function, using double hashing

public:
	HashTable(int m = 10);
	~HashTable();
	int h1(K key) = 0;
	int h2(K key) = 0;
	int hash(K key, int i);
	// TODO: add here the declaration of the functions insert, search and remove.
	void print();
};
///////////////////////////////////////////////
template<class K, class T >
HashTable<K, T>::HashTable(int m)
{
	this->size = m;
	while(!PrimeUtil.prime(this->size))
	{
		++this->size;
	}
	this->table = new Item()[size];
	
}

template<class K, class T>
HashTable<K, T>::~HashTable()
{
	delete [] table;
}

// TODO: implement here the functions hash, insert, search and remove.

template<class K, class T>
inline void HashTable<K, T>::print()
{
	for (int i = 0; i < size; i++)
		if (table[i].flag == FULL)
			cout << i << ":\t" << table[i].key << '\n';
}


template<class K, class T>
inline int HashTable<K, T>::hash(K key, int i)
{
	if (i = 0)
	{
		if (table[h1(key)].flag == FULL);
			hash(key, 1);
		else
		{	
			return h1(key);
		}
	}
	else
	{
		index = h1(key)
		while(table[index].flag == FULL])
		{
			index = h1(key) + i * h2(key) % size;
			++i;
		}
		return index;
	}
}
