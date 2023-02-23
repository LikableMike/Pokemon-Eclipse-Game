#include"Mew.hpp"

using namespace std;

Mew::Mew() : Pokemon(150,5,5,5,"Mew", "Psychic"){
	attacks.push_back(Attack("Aura Sphere"));
	attacks.push_back(Attack("Ancient Power"));
	attacks.push_back(Attack("Dragon Pulse"));
	attacks.push_back(Attack("Shield"));
}

Mew::~Mew() {

}
