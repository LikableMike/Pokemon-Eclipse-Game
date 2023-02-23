#ifndef SQUIRTLE_HPP_
#define SQUIRTLE_HPP_

#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Squirtle : public Pokemon{
public:

	Squirtle();
	Squirtle(string);

	virtual ~Squirtle();

	void Evolve(Squirtle);
};

#endif
