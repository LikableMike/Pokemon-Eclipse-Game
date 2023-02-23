#include"Charmander.hpp"
#include<iostream>

using namespace std;

Charmander::Charmander() : Pokemon(30,
		5,
		5,
		5,
"Charmander", "Fire"){
	attacks.push_back(Attack("Scratch"));
	attacks.push_back(Attack("Ember"));
	attacks.push_back(Attack("Growl"));

}

Charmander::Charmander(string n) : Pokemon(30,
		5,
		5,
		5,
n, "Fire"){
	attacks.push_back(Attack("Scratch"));
	attacks.push_back(Attack("Ember"));
	attacks.push_back(Attack("Growl"));

}

Charmander::~Charmander(){

}

