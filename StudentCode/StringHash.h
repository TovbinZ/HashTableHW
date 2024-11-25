#pragma once

template <class T>
class StringHash :public HashTable<string, T>
{
private:
	//TODO: implement h1 and h2

public:
	StringHash(int m = 10) :HashTable<string, T>(m) {}
};
