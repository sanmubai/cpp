#include <iostream>
#include "Array.h"

Array::Array(int num) {
	this->length = num;
	this->mySpace = new int[num];

	for (int i = 0; i < num; i++ ) {
		this->mySpace[i] = i + 1;
	}
}

Array::Array(Array &obj) {
	this->length = obj.getLength();
	this->mySpace = new int[obj.getLength()];

	for (int i = 0; i < obj.getLength();i++) {
		this->mySpace[i] = i+1;
	}
}

Array::~Array() {
	delete[] this->mySpace;
}

int Array::getLength() {

	return this->length;
}

int Array::getData(int index) {

	return this->mySpace[index];
}

void Array::setData(int index,int value) {

	this->mySpace[index] = value;

}

int& Array::operator[](int index) {
	return this->mySpace[index];

}
