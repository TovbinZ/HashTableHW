#pragma once
#include <iostream>
#include "PrimeUtil.h"
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
	// TODO: Add any additional required attributes
	// TODO: Add here the declaration of the functions h1, h2. 
	// TODO: Based on the functions, define the hash function, using double hashing

public:
	HashTable(int m = 10);
	~HashTable();
	virtual uint64_t h1(K key) = 0;
	virtual uint64_t h2(K key) = 0;
	int hash(K key, int i);
	void insert(K key, T val);
	T& search(K key);
	void remove (K key);
	// TODO: add here the declaration of the functions insert, search and remove.
	void print();
};
///////////////////////////////////////////////
template<class K, class T >
HashTable<K, T>::HashTable(int m)
{
	this->size = m;
	while(!(PrimeUtil::prime(this->size)))
	{
		++this->size;
	}
	table = new Item[size];
	
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
		else if (table[i].flag == DELETED)
			cout << i << ":\t" << "DELETED" << '\n';
}


template<class K, class T>
inline int HashTable<K, T>::hash(K key, int i)
{
	uint64_t hash1 = h1(key) % this->size;
	uint64_t hash2 = h2(key) % this->size;
	if (table[hash1].key == key)
		return hash1 % this->size;
	if (i == 0)
	{
		
		if (table[hash1].flag == FULL)
		{
			return hash(key, 1);
		}
		else
		{	
			return hash1 % this->size;
		}
	}
	
	else
	{
		i = 0;
		int index = hash1 % this->size;
		while(table[index].flag == FULL)
		{
			if (table[index].key == key)
				return index % this->size;
			index = (hash1 + i * hash2) % this->size;
			++i;
			//if (table[index].key == key)
			//	return index % this->size;
		}
		return index % this->size;
	}
}

template<class K, class T>
inline void HashTable<K,T>::insert(K key, T val)
{
	uint64_t index = hash(key, 0);
	table[index].flag = FULL;
	//string var = "hello";
	/*if (typeid(key).name() == typeid(var).name())
	{
		
	}
	else
	{
		table[index].key = key;

	}*/
	
	//cout << "TESTING" << endl;
	
	//cout << key << endl;
		//	table[index].key = var;
	//cout << typeid(this->table[index].key).name() << endl;;
	this->table[index].key = key;
	this->table[index].data = val;
	return;
}


template<class K, class T>
inline T& HashTable<K,T>::search(K key)
{
	int hash1 = h1(key);
	int hash2 = h2(key);
	if (table[hash1].key == key and table[hash1].flag != DELETED)
		return table[hash1].data;
	else
		{	
			//int i = 0;
			int index = hash1 % this->size;
			//while(table[index].flag != EMPTY)
			for(int i = 0; i <= this->size; ++i)
			{
				
				index = (hash1 + i * hash2) % size;
				if (table[index].key == key and table[index].flag != DELETED)
					return table[index].data;

				else if (table[index].key == key)
					throw ("key does not exist in table");
				//++i;
			}
			if (table[index].flag != FULL)
				throw ("key does not exist in table"); //THERE MIGHT BE AN ISSUE OF FORMATTING IN \n
				
		}
	return table[hash1].data; //catching warning
}

template<class K, class T>
inline void HashTable<K, T>::remove(K key)
{
	/*try {
		T val = search(key);
	}
	catch (const char* e)
	{
		return;
	}
	if (table[h1(key)].key == key)
		table[h1(key)].flag = DELETED;
	else
		{	
			int i = 0;
			int index = h1(key);
			while(table[index].flag != EMPTY)
			{
				
				index = h1(key) + i * h2(key) % size;
				if (table[index].key == key)
					table[index].flag == DELETED;
				++i;

			}
		}*/
	int index = hash(key, 0);
	if (table[index].flag == FULL)
		table[index].flag = DELETED;
	return;
}
