#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

// Dynamic array (Vector) class
class Vector
{
	unsigned int elementNum;
	int* pData;

	// global friend operator for printing vector data
	friend std::ostream& operator << (std::ostream& os, const Vector& v);

public:
	// Constructors, destructor
	Vector() { elementNum = 0; pData = NULL; }
	Vector(const Vector& theOther);
	~Vector() {
		if (elementNum != 0)delete[]pData;
		elementNum = 0;
	}
	int  size()const { return elementNum; }
	void clear();
	int max();
	void erase(unsigned int position);
	int& at(unsigned int position);
	const int& at(unsigned int position)const;
	bool insert(unsigned int position, int element);
	const Vector& operator= (const Vector& theOther);
	int& operator [](unsigned int position);
	const int& operator [](unsigned int position)const;
};

std::ostream& operator << (std::ostream& os, const Vector& v);
#endif /*VECTOR_H */
