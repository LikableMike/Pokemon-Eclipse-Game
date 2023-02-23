#include "Squirtle.hpp"
#include<vector>

using namespace std;

Squirtle::Squirtle(string n) : Pokemon(30,5,5,5,n, "Water"){
attacks.push_back(Attack("Bubble Beam"));
attacks.push_back(Attack("Tackle"));
attacks.push_back(Attack("Protect"));

}

Squirtle::Squirtle() : Pokemon(30,5,5,5,"Squirtle", "Water"){
	attacks.push_back(Attack("Bubble Beam"));
	attacks.push_back(Attack("Tackle"));
	attacks.push_back(Attack("Protect"));

}

Squirtle::~Squirtle(){

}


