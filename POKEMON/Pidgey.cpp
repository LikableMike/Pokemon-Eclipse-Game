#include "Pidgey.hpp"

using namespace std;

Pidgey::Pidgey() : Pokemon (20,5,5,5,"Pidgey", "Normal"){
	attacks.push_back(Attack("Sand Attack"));
	attacks.push_back(Attack("Tackle"));
	attacks.push_back(Attack("Gust"));
	attacks.push_back(Attack("Quick Attack"));
}

Pidgey::~Pidgey(){

}
