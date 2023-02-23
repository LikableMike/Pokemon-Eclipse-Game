#include"Ratata.hpp"

using namespace std;

Rattata::Rattata() : Pokemon(19,5,5,5,"Rattata", "Normal"){
attacks.push_back(Attack("Bite"));
attacks.push_back(Attack("Tackle"));
attacks.push_back(Attack("Quick Attack"));
attacks.push_back(Attack("Growl"));
}

Rattata::~Rattata(){

}
