#include <iostream>
#include "Animal.h"
#include <list>
using namespace std;

class Client {
	AnimalWorld* factory;
	list<ICarnivore*> carnivores;
	list<IHerbivours*> herbivours;
public:
	Client(AnimalWorld* factory) {
		this->factory = factory;
	}
	void CreateNewCarnivore() {
		carnivores.push_back(factory->CreateCarnivore());
	}
	void CreateNewHerbivour() {
		herbivours.push_back(factory->CreateHerbivours());
	}
	void Mealsherbivores() {
		for (auto it = herbivours.begin(); it != herbivours.end(); it++)
		{
			(*it)->EatGrass();
			cout << endl;
		}
	}
	void Mealcarnivore() {
		for (auto it = carnivores.begin(); it != carnivores.end(); it++)
		{
			for (auto her = herbivours.begin(); her!= herbivours.end(); her++)
			{
				if ((*her)->IsAlive())break;
				(*it)->Eat(*her);
				cout << endl;
			}
		}
	}
	~Client() {
		if (factory != nullptr)factory = nullptr;
	}
};
int main() {

	Client cl (new Africa());

	cl.CreateNewHerbivour();
	cl.CreateNewHerbivour();
	cl.CreateNewCarnivore();
	cl.Mealsherbivores();

	cl.Mealcarnivore();
	

}