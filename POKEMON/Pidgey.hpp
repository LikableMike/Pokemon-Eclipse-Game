/*
 * Pidgey.hpp
 *
 *  Created on: Nov 29, 2021
 *      Author: micha
 */

#ifndef PIDGEY_HPP_
#define PIDGEY_HPP_

#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Pidgey : public Pokemon{
public:
	Pidgey();
	Pidgey(string);

	virtual ~Pidgey();

};



#endif /* PIDGEY_HPP_ */
