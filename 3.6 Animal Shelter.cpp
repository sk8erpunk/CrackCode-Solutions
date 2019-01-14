/******************************************************************************
Animal Shelter
An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
that type). They cannot select which specific animal they would like. Create the data structures to
maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
and dequeueCat. You may use the built-in Linkedlist data structure.
*******************************************************************************/
#include <iostream>
#include <list>
#include <typeinfo>

using namespace std;


// Animal Class
class Animal {
private:
	string name;
	int order;
	
public:
	Animal(string n) : name(n) {}
	void setOrder(int ord) {order=ord;}
	int getOrder() {return order;}
	bool isOlderThan(Animal* a){ return  this->order< a->getOrder();}
	string getName() {return name;}
	virtual ~Animal() {};
};

// Cat Class
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
};

// Dog Class
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
};

// Animal Shelter Class
class AnimalShelter {
private:	
	int order;
	list<Cat*> cats;
	list<Dog*> dogs;

public:	
	AnimalShelter() : order(0) {}
	
	void enqueue(Animal* a){
		a->setOrder(order);
		order++;
		if(typeid(*a) == typeid(Dog))
		    dogs.push_back(dynamic_cast<Dog*>(a));
        else 
            cats.push_back(dynamic_cast<Cat*>(a));
	}
	
	Cat* dequeueCats(){
		if(cats.empty())
			throw "There is no cats in the shelter";
		Cat* cat = cats.front();
		cats.pop_front();
		return cat;
	}
	
	Dog* dequeueDogs(){
		if(dogs.empty())
			throw "There is no dogs in the shelter";
		Dog* dog = dogs.front();
		dogs.pop_front();
		return dog;
	}

	Animal* dequeueAny(){
		if(cats.size() == 0)
			return dequeueDogs();
		if(dogs.size() == 0)
			return dequeueCats();
		
		Cat* oldCat = cats.front();
		Dog* oldDog = dogs.front();
		
		if(oldCat->isOlderThan(oldDog))
			return dequeueCats();
		else
			return dequeueDogs();
	}
	
};


int main()
{
    AnimalShelter as;
	as.enqueue(new Dog("waffles"));
	as.enqueue(new Dog("growls"));
	as.enqueue(new Cat("meow"));
	as.enqueue(new Cat("dolly"));
	as.enqueue(new Dog("woof"));
	
	Dog* d = as.dequeueDogs();
	cout << d->getName() << endl;
	Cat* c = as.dequeueCats();
	cout << c->getName() << endl;
	Animal* a = as.dequeueAny();
	cout << a->getName() << endl;
	a = as.dequeueAny();
	cout << a->getName() << endl;
    return 0;
}
