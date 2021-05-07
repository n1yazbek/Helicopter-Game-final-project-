#include "Vector.h"

std::ostream &operator<<(std::ostream &os, const Vector &v){
    os << "[";
    for (int i = 0; i < v.elementNum; i++){
        os << v.pData[i] << ' ';
    }
    os << "]";
    return os;
}

Vector::Vector(const Vector& theOther){
    elementNum=theOther.elementNum;
    pData= new int[elementNum];
    for(int i=0; i<elementNum; i++){
        pData[i]=theOther.pData[i];
    }
}


void Vector::clear(){
    elementNum = 0;
    delete[] pData;
}

int Vector::max() {
    int n = 0;
    for (int i = 0; i <= elementNum; i++) {
        if (pData!=NULL&&pData[i] >= n)
            n = pData[i];
    }
    return n;
}


int &Vector::at(unsigned int position)
{
    int &data = pData[position];
    return data;
}

void Vector::erase(unsigned int position)
{
    if (position < elementNum && position >= 0){
        elementNum--;
        int *temp = new int[elementNum];
        int i = 0;
        for (i = 0; i < position; i++){
            temp[i] = pData[i];
        }
        for (i = position + 1; i <= elementNum; i++){
            temp[i - 1] = pData[i];
        }
        delete[] pData;
        pData = new int[elementNum];

        for (int j = 0; j < elementNum; j++){
            pData[j] = temp[j];
        }
        delete[] temp;
    }
}

// returns the array element with the given index, without possibility to modify the element (see const keyword)
// valid indices: between 0 and size()-1
const int &Vector::at(unsigned int position) const{
    const int &data = pData[position];
    return data;
}

// inserts a new element into a place with the given index;
// if the index exceeds the array size, then the size should be increased, and the empty places should be filled with 0 (zero)
bool Vector::insert(unsigned int position, int element){
    if (position > UINT32_MAX)
        return false;
    int *temp;
    if (position >= elementNum){
        temp = new int[position + 1];
        for (unsigned int i = 0; i < position; i++){
            if (i < elementNum){
                temp[i] = pData[i];
            }
            else{
                temp[i] = 0;
            }
        }
        temp[position] = element;
        elementNum = position + 1;
    }
    else{
        temp = new int[elementNum + 1];
        for (unsigned int i = 0, j = 0; i < elementNum; i++, j++)
        {
            if (i == position){
                temp[j] = element;
                temp[j + 1] = pData[i];
                j++;
                continue;
            }
            temp[j] = pData[i];
        }
        elementNum++;
    }
    pData = new int[elementNum];
    pData = temp;
    return true;
}

const Vector &Vector::operator=(const Vector &theOther)
{
    if (this != &theOther)
    {
        elementNum = theOther.elementNum;
        pData = new int[elementNum];
        for (int i = 0; i < elementNum; i++){
            pData[i] = theOther.pData[i];
        }
    }
    return *this;
}

int &Vector::operator[](unsigned int position){
    int &data = pData[position];
    return data;
}
const int &Vector::operator[](unsigned int position) const{
    const int &data = pData[position];
    return data;
}