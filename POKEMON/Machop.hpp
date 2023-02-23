/*
 * Machop.hpp
 *
 *  Created on: Nov 29, 2021
 *      Author: micha
 */

#ifndef MACHOP_HPP_
#define MACHOP_HPP_

#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Machop : public Pokemon{
public:


	Machop();
	Machop(string);

	virtual ~Machop();


};



#endif /* MACHOP_HPP_ */
