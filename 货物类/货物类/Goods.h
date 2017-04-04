#pragma once
class Goods {
public:
	Goods(float wieght);
	~Goods();
	static float getTotalWeight();
	Goods *next;
private:
	float weight;
	static float totalWeight;

};

