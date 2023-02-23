/*
 * Psyduck.hpp
 *
 *  Created on: Nov 29, 2021
 *      Author: micha
 */

#ifndef PSYDUCK_HPP_
#define PSYDUCK_HPP_

#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Psyduck : public Pokemon{
public:
	Psyduck();
	Psyduck(string);

	virtual ~Psyduck();

};



#endif /* PSYDUCK_HPP_ */
