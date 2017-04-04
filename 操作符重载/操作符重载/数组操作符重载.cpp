#include <iostream>
#include "Array.h"

using namespace std;

int main() {

	int num = 10;

	Array arr = Array(num);

	for (int i = 0; i < num;i++) {
		//arr.setData(i,i*2);
		arr[i] = i * 2;
	}

	for (int i = 0; i < num;i++ ) {
		cout << arr.getData(i)<<endl;
	}

	for (int i = 0; i < num;i++) {
		cout << arr[i] << endl;
	}
	system("pause");
}