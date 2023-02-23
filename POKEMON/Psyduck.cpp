#include"Psyduck.hpp"

using namespace std;

Psyduck::Psyduck() : Pokemon(28,5,5,5,"Psyduck", "Water"){
	attacks.push_back(Attack("Scratch"));
	attacks.push_back(Attack("Tackle"));
	attacks.push_back(Attack("Water Gun"));
	attacks.push_back(Attack("Zen HeadButt"));
}

Psyduck::~Psyduck(){

}
