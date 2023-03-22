#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;


class IHerbivours abstract
{
public:
	virtual void EatGrass() abstract;
	virtual double GetWeight() abstract;
	virtual bool IsAlive() {
		return isAlive;
	};
	virtual void Die() abstract;
	bool isAlive = true;
	double weight = 0;
};

class Wildebeest:public IHerbivours {

public:
	void EatGrass() override {
		if (IsAlive()) {
			weight += 10;
			cout << "Wildebeest eats grass his weight is " << weight << " now!";
		}
		else cout << "Wildebeest is literally dead.";
	}
	double GetWeight() override {
		if (!IsAlive())return 0;
		return weight;
	}
	void Die() override {
		isAlive = false;
	}
};

class Bison :public IHerbivours {

public:
	void EatGrass() override {
		if (IsAlive()) {
			weight += 10;
			cout << "Bison eats grass his weight is " << weight << " now!";
		}
		else cout << "Bison is literally dead.";
	}
	double GetWeight() override {
		if (!IsAlive())return 0;
		return weight;
	}
	void Die() override {
		isAlive = false;
	}
};

class Elk :public IHerbivours {

public:
	void EatGrass() override {
		if (IsAlive()) {
			weight += 10;
			cout << "Elk eats grass his weight is " << weight << " now!";
		}
		else cout << "Elk is literally dead.";
	}
	double GetWeight() override {
		if (!IsAlive())return 0;
		return weight;
	}
	void Die() override {
		isAlive = false;
	}
	
};

class ICarnivore abstract {
	
public:
	virtual void Eat(IHerbivours* herbivours) abstract;
	double power = 0;
};

class Lion : public ICarnivore {
public:
	void Eat(IHerbivours* herbivours)override {
		if (!herbivours->IsAlive()) return;
		if (herbivours->GetWeight() > power)power -= 10;
		else {
			herbivours->Die();
			power += 10;
		}
	}
};
class Wolf : public ICarnivore {
public:
	void Eat(IHerbivours* herbivours)override {
		if (!herbivours->IsAlive()) return;
		if (herbivours->GetWeight() > power)power -= 10;
		else {
			herbivours->Die();
			power += 10;
		}
	}
};

class Tiger : public ICarnivore {
public:
	void Eat(IHerbivours* herbivours)override {
		if (!herbivours->IsAlive()) return;
		if (herbivours->GetWeight() > power)power -= 10;
		else {
			herbivours->Die();
			power += 10;
		}
	}
};

class AnimalWorld abstract
{
public:
	virtual ICarnivore* CreateCarnivore() abstract;
	virtual IHerbivours* CreateHerbivours() abstract;
};


class Africa : public AnimalWorld {

public:
	ICarnivore* CreateCarnivore() override {
		return new Lion();
	}
	IHerbivours* CreateHerbivours() override {
		return new Wildebeest();
	}
};

class NorthAmerica : public AnimalWorld {

public:
	ICarnivore* CreateCarnivore() override {
		return new Wolf();
	}
	IHerbivours* CreateHerbivours() override {
		return new Bison();
	}
};

class Eurasia : public AnimalWorld {

public:
	ICarnivore* CreateCarnivore() override {
		return new Tiger();
	}
	IHerbivours* CreateHerbivours() override {
		return new Elk();
	}
};