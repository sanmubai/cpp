#pragma once

#ifndef _ARRAY_DEMO_
#define _ARRAY_DEMO_

class Array {
public:
	Array(int num);
	Array(Array &arr);
	~Array();

private:
	int length; 
	int *mySpace;

public:
	int getLength();
	int getData(int index);
	void setData(int index,int value);

	int& operator[](int index);

};

#endif // !_ARRAY_DEMO_

