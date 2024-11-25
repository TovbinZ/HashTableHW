#pragma once

template <class T>
class StringHash :public HashTable<string, T>
{
private:
	int h1(string k);
	int h2(string k);

public:
	StringHash(int m = 10) :HashTable<string, T>(m) {}
};



template <class T>
int StringHash<T>::h1(string k)
{
	m = this -> size

	int result;
	for (int i = 0; i < k.size(); i++)
	{
		result += (int(k[i])**i)%m
	}
	
}


template <class T>
int StringHash<T>::h2(string k)
{

}