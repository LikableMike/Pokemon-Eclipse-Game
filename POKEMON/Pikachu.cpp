#include"Pikachu.hpp"
#include<iostream>

using namespace std;

Pikachu::Pikachu() : Pokemon(30,5,5,5,"Pikachu", "Electric"){
	attacks.push_back(Attack("Tackle"));
	attacks.push_back(Attack("Spark"));
	attacks.push_back(Attack("Thunder Bolt"));


}

Pikachu::Pikachu(string n) : Pokemon(30,
5,
5,
5,
n, "Electric"){
	attacks.push_back(Attack("Tackle"));
	attacks.push_back(Attack("Spark"));
	attacks.push_back(Attack("Thunder Bolt"));

}

Pikachu::~Pikachu(){

}
