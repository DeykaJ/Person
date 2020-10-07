#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
using namespace std;
namespace space {
	class Person {
		public:
			Person();
			string getName();
			int getAge();
			void set(string name, int age);
			void display ();
			Person(string name, int age);
			Person(const Person & P);
			~Person();
		private:
			int _age;
			string _name;
	};
	
};
#endif
