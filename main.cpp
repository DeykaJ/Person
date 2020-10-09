#include <iostream>
#include <cstring>
#include <string.h>
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
	
	
	int f = 0;
	int cant = 0;
    if (age >= 18){
        f = f+1;
    }
	cout << "\nHay " << f << " Personas Mayores de edad" << "\n";
	
	for(int i = 0; i < name.length(); i++)
	{
		if(name[i] == 's'){
			cant++;
		}
	}
	
	if(cant > 0){
		cout << "\n" <<name << "\n";
		cant = 0;
	} 
	
	
}
