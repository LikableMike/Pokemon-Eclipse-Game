/*
 * Attacks.hpp
 *
 *  Created on: Nov 30, 2021
 *      Author: micha
 */

#ifndef ATTACKS_HPP_
#define ATTACKS_HPP_

#include<iostream>
#include<string>

using namespace std;

class Attack{
public:
	Attack();
	Attack(string);

	int damage;
	string type;
	string name;

	Attack operator=(const Attack&) const;
};


#endif /* ATTACKS_HPP_ */
