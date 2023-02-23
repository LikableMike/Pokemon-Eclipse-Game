#include"Machop.hpp"

using namespace std;

Machop::Machop() : Pokemon(29,5,5,5,"Machop", "Fighting"){
	attacks.push_back(Attack("Low Kick"));
	attacks.push_back(Attack("Dual Chop"));
	attacks.push_back(Attack("Rock Slide"));
	attacks.push_back(Attack("Protect"));
}

Machop::~Machop(){

}
