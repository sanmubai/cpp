#include "Goods.h"

Goods::Goods(float weight) {
	this->weight = weight;
	Goods::totalWeight += weight;
}

Goods::~Goods() {
	Goods::totalWeight -= this->weight;
}

float Goods::getTotalWeight() {
	return Goods::totalWeight;
}

float Goods::totalWeight = 0;
