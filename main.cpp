#include <iostream>
#include "MyArray.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const auto SIZE = 10;

	MyArray first(SIZE), second(SIZE), third;

	for (auto i = 0; i < SIZE; i++)
	{
		first.set(i, i);
		second.set(SIZE - i, i);
	}

	for (first.begin(); first.end(); first.next())
		cout << first.get() << ", ";
	cout << endl;

	cout << first << endl << second << endl << endl;

	third = first = second;
	cout << first << endl << second << endl << third << endl << endl;

	third = first + second;
	cout << first << endl << second << endl << third << endl << endl;

	third.resize(30);
	cout << third << endl;

	third.resize(20);
	cout << third << endl;

	third.revers();
	cout << third << endl;

	third.sort();
	cout << third << endl;

	return 0;
}
