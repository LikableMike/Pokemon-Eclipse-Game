#ifndef POKEMON_HPP_
#define POKEMON_HPP_

#include <string>
#include <iostream>
#include <ctime>
#include<vector>
#include"Attacks.hpp"

using namespace std;
class Pokemon{
public:
	vector<Attack> attacks;
	int hp;
	unsigned atk;
	unsigned def;
	unsigned spd;
	string name;
	string type;


		Pokemon();
		Pokemon(int, unsigned, unsigned, unsigned, string, string);
		virtual ~Pokemon();

		void Evolve(Pokemon&);
	Pokemon operator=(const Pokemon&) const;


};

#endif
