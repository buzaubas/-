#include <iostream>
using namespace std;

class MyArray {
public:
	MyArray();
	explicit MyArray(const size_t size);
	MyArray(const MyArray& obj);
	MyArray(MyArray&& obj);
	MyArray operator=(const MyArray& obj);
	MyArray operator=(MyArray&& obj);
	MyArray operator+ (const MyArray& obj) const;
	void begin();
	bool end() const;
	void next();
	int	get() const;
	void set(const int data, const size_t pos = 0);
	void resize(const size_t new_size);
	void revers();
	void sort();
	size_t lenght() const;
	friend ostream& operator<< (ostream& os, const MyArray obj); //работа с потоком
	~MyArray();
private:
	size_t size;
	int* masiv;
	size_t index;
};
