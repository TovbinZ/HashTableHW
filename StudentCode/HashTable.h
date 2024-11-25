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
	Item* table;
	// TODO: Add any additional required attributes
	// TODO: Add here the declaration of the functions h1, h2. 
	// TODO: Based on the functions, define the hash function, using double hashing

public:
	HashTable(int m = 10);
	~HashTable();
	// TODO: add here the declaration of the functions insert, search and remove.
	void print();
};
///////////////////////////////////////////////
template<class K, class T >
HashTable<K, T>::HashTable(int m)
{
	// TODO: implement
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



