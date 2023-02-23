/*
 * Pikachu.hpp
 *
 *  Created on: Nov 29, 2021
 *      Author: micha
 */

#ifndef PIKACHU_HPP_
#define PIKACHU_HPP_

#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Pikachu : public Pokemon{
public:


	Pikachu();
	Pikachu(string);

	virtual ~Pikachu();



};



#endif /* PIKACHU_HPP_ */
