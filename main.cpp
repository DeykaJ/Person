#include <iostream>
#include "person.h"
using namespace std;
using namespace space;
int main() {
	
	string name;
	cout << "\nEscribe tu nombre: \n";
	cin >> name;
	
	int age;
	cout << "Escribe tu edad: \n";
	cin >> age;
	
	Person P;
	cout << P.getName() << "\n";
	cout << P.getAge() << "\n";

	P.set(name, age);
	cout << P.getName() << "\n";
	cout << P.getAge() << "\n";
	
	P.display();
}
