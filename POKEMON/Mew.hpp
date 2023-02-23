/*
 * Mew.hpp
 *
 *  Created on: Nov 29, 2021
 *      Author: micha
 */

#ifndef MEW_HPP_
#define MEW_HPP_


#include "Pokemon.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Mew : public Pokemon{
public:
	vector<Attack> attacks;

	Mew();
	Mew(string);

	virtual ~Mew();

};


#endif /* MEW_HPP_ */
