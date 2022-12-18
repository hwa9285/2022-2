#include <iostream>
using namespace std;

class Animal {

public:
	virtual void speak() {
		cout << "快卡" << endl; 
	}
};

class Dog :public Animal {
public:
	void speak() {
		cout << "港港" << endl;
	}
};

class Cat :public Animal {
public:
	void speak() {
		cout << "具克" << endl;
	}
};


int main() {
	Animal* a1 = new Dog();
	a1->speak();

	Animal* a2 = new Cat();
	a2->speak();

	return 0;
}

