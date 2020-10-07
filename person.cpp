#include <iostream>
#include "person.h"
namespace space{
	string Person::getName() {
		return _name;
	}
	int Person::getAge() {
		return _age;
	}
	void Person::set(string name, int age) {
		_name = name;
		_age = age;
	}

	void Person::display() {
		cout << _name <<", " << _age;
	}
	
	Person::Person() {
		_name = "";
		_age = 0;
		}
	Person::Person(string name, int age){
		_name = name;
		_age = age;
	}
	Person::Person(const Person & P){
		_name = P._name;
		_age = P._age;
	}
	Person::~Person(){
	}	
}
