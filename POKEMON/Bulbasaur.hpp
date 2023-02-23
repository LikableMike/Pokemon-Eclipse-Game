/*
 * Bulbasaur.hpp
 *
 *  Created on: Nov 29, 2021
 *      Author: micha
 */

#ifndef BULBASAUR_HPP_
#define BULBASAUR_HPP_

#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Bulbasaur : public Pokemon{
public:

	Bulbasaur();
	Bulbasaur(string);

	virtual ~Bulbasaur();

};



#endif /* BULBASAUR_HPP_ */
