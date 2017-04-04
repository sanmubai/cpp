#include <iostream>
#include "Goods.h"

using namespace std;

void purchase(Goods * &h,Goods * &c,float w) {
	Goods *temp =new Goods(w);
	temp->next = NULL;

	if (h == NULL) {
		h = c = temp;
		return;
	}
	c->next = temp;
	c = temp;
}

void sail(Goods * &h) {
	if (h == NULL) {
		cout << "no goods" << endl;
		return;
	}
	Goods *temp = h;
	h = h->next;
	delete temp;

}

int main() {
	Goods *h = NULL, *c = NULL;
	int num;
	float w;

	do{
		cout<<"1 purchase£¬2 sail,0 quit:"<< endl;
		cin >> num;
		
		switch (num) {
		case 1:
			cout << "ÇëÊäÈëÖØÁ¿£º" << endl;
			cin >> w;

			purchase(h,c,w);
			break;

		case 2:
			sail(h);
			break;

		case 0:
			break;

		default:
			break;
		}

		cout << "now totalWeight" << Goods::getTotalWeight() << endl;
	} while (num);

}