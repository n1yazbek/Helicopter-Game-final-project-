#include "Vector.h"
#include <new>


Vector::Vector(const Vector& theOther)
{
	elementNum = theOther.elementNum;
	pData = new int[elementNum];
	for (int i = 0; i < elementNum; i++)
	{
		pData[i] = theOther.pData[i];
	}
}

void Vector::clear()
{
	elementNum = 0;
	delete[] pData;
	pData = NULL;
}


int Vector::max() {
	int n = 0;
	for (int i = 0; i <= elementNum; i++) {
		if (pData != NULL && pData[i] >= n)
			n = pData[i];
	}
	return n;
}

void Vector::erase(unsigned int position)
{
	int* temp;
	if (position < elementNum)
	{
		elementNum--;
		temp = new int[elementNum];
		for (int i = 0; i < position; i++)
		{
			temp[i] = pData[i];
		}
		for (int i = position; i < elementNum; i++)
		{
			temp[i] = pData[i + 1];
		}
		delete[] pData;
		pData = temp;
	}
}

int& Vector::at(unsigned int position)
{
	if (position < elementNum)
	{
		return pData[position];
	}
	else
	{
		throw;
	}
}

const int& Vector::at(unsigned int position) const
{
	if (position < elementNum)
	{
		return pData[position];
	}
	else
	{
		throw;
	}
}

bool Vector::insert(unsigned int position, int element)
{
	bool state = true;
	int* temp;

	if (position < elementNum)
	{
		elementNum++;
		temp = new (std::nothrow) int[elementNum];
		if (temp == 0)
		{
			state = false;
		}

		for (int i = 0; i < position; i++)
		{
			temp[i] = pData[i];
		}
		temp[position] = element;
		for (int i = position + 1; i < elementNum; i++)
		{
			temp[i] = pData[i - 1];
		}
		delete[] pData;
		pData = temp;

		return state;
	}
	else
	{
		state = false;
		temp = new int[position + 1];
		for (int i = 0; i < elementNum; i++)
		{
			temp[i] = pData[i];
		}
		for (int i = elementNum; i < position; i++)
		{
			temp[i] = 0;
		}
		temp[position] = element;
		elementNum = position + 1;
		delete[] pData;
		pData = temp;
		return state;
	}
}

const Vector& Vector::operator= (const Vector& theOther)
{
	if (this != &theOther)
	{
		elementNum = theOther.elementNum;
		int* temp = new int[elementNum];
		for (int i = 0; i <= elementNum-1; i++)
		{
			temp[i] = theOther.pData[i];
		}
		pData = temp;
	}
	return *this;
}

int& Vector::operator [](unsigned int position)
{
	if (position < elementNum)
	{
		return pData[position];
	}
	else
	{
		throw;
	}
}

const int& Vector::operator [](unsigned int position)const
{
	if (position < elementNum)
	{
		return pData[position];
	}
	else
	{
		throw;
	}
}

std::ostream& operator << (std::ostream& os, const Vector& v)
{
	os << "The vector's elements: ";
	for (int i = 0; i < v.elementNum; i++)
	{
		os << v.pData[i];
		os << " ";
	}
	os << std::endl;
	return os;
}


