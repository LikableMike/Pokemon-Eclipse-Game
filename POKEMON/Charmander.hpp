
#ifndef CHARMANDER_HPP_
#define CHARMANDER_HPP_


#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Charmander : public Pokemon{
public:

	Charmander();
	Charmander(string);

	virtual ~Charmander();



};
#endif /* CHARMANDER_HPP_ */
