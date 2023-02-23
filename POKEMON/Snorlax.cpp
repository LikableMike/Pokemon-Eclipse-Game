#include"Snorlax.hpp"
#include<iostream>
#include<vector>

using namespace std;

Snorlax::Snorlax() : Pokemon(100,5,5,5,"Snorlax", "Normal"){
	attacks.push_back(Attack("Skull Bash"));
	attacks.push_back(Attack("Body Slam"));
	attacks.push_back(Attack("Hyper Beam"));
	attacks.push_back(Attack("Earth Quake"));
}

Snorlax::Snorlax(int hp) : Pokemon(hp,5,5,5,"Snorlax", "Normal"){
	attacks.push_back(Attack("Skull Bash"));
	attacks.push_back(Attack("Body Slam"));
	attacks.push_back(Attack("Hyper Beam"));
	attacks.push_back(Attack("Earth Quake"));
}

Snorlax::~Snorlax(){

}
