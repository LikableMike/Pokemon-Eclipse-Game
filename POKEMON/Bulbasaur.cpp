#include"Bulbasaur.hpp"
#include<iostream>

using namespace std;

Bulbasaur::Bulbasaur() : Pokemon(30,
5,
5,
5,
"Bulbasaur", "Grass"){
	attacks.push_back(Attack("Tackle"));
	attacks.push_back(Attack("Vine Whip"));
	attacks.push_back(Attack("Protect"));


}

Bulbasaur::Bulbasaur(string n) : Pokemon(30,
5,
5,
5,
n, "Grass"){
	attacks.push_back(Attack("Tackle"));
	attacks.push_back(Attack("Vine Whip"));
	attacks.push_back(Attack("Protect"));

}

Bulbasaur::~Bulbasaur(){

}



