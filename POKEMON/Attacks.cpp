#include"Attacks.hpp"
#include<iostream>

using namespace std;

Attack::Attack(){
	name = "NA";
	damage = 0;
	type = "NA";
}

Attack::Attack(string name) : name(name){
	//Starter Pokemon Attacks and Attack Trees
	if(name == "Tackle" || name == "Scratch"){
		damage = 6;
		type = "Normal";
	}

	if(name == "Ember" || name == "Vine Whip" || name == "Bubble Beam" || name == "Spark"){
		damage = 10;
	}

	if(name == "Water Gun" || name == "Flame Thrower" || name == "Razor Leaf" || name == "Thunder Bolt"){
		damage = 15;
	}

	if(name == "Tail Whip" || name == "Slam" || name == "Take Down"){
		damage = 11;
	}

	if(name == "Water Fall" || name == "Solar Beam" || name == "Thunder" || name == "Dragon Breath"){
		damage = 18;
	}

	if(name == "Blizzard" || name == "Thunder Shock" || name == "Inferno"){
		damage = 20;
	}

	if(name == "Growl" || name == "Protect"){
		damage = 5;
	}

	if(name == "Leech Seed"){
		damage = 10;
	}

	if(name == "Flare Blitz" || name == "Electro Ball"){
		damage = 23;
	}

	if(name == "Bubble Beam" || name == "Water Gun" || name == "Water Fall" || name == "Blizzard"){
		type = "Water";
	}

	if(name == "Ember" || name == "Flame Thrower" || name == "Dragon Breath" || name == "Inferno" || name == "Flare Blitz"){
		type == "Fire";
	}

	if(name == "Vine Whip" || name == "Razor Leaf" || name == "Solar Beam" || name == "Leech Seed"){
		type = "Grass";
	}

	if(name == "Spark" || name == "Thunder Bolt" || name == "Thunder" || name == "Thunder Shock" || name == "Electro Ball") {
		type = "Electric";
	}

	//Snorlax's attacks
	if(name == "Skull Bash"){
		damage = 22;
		type = "Normal";
	}

	if(name == "Body Slam"){
		damage = 25;
		type = "Normal";
	}

	if(name == "Hyper Beam"){
		damage = 27;
		type = "Normal";
	}
	if(name== "Earth Quake"){
		damage = 20;
		type = "Normal";
	}

	//Mew's Attacks
	if(name == "Aura Sphere"){
		damage = 30;
		type = "Psychic";
	}
	if(name == "Ancient Power"){
		damage = 35;
		type = "Ancient";
	}
	if(name == "Dragon Pulse"){
		damage = 32;
		type = "Fire";
	}
	if(name == "Shield"){
		damage = 12;
		type = "Normal";
	}

	//Pidgey Attacks
	if(name == "Sand Attack"){
		damage = 7;
		type = "Normal"	;
	}
	if(name == "Gust"){
		damage = 10;
		type = "Wind";
	}
	if(name == "Quick Attack"){
		damage = 11;
		type = "Normal";
	}

	//Rattata Attack
	if(name == "Bite"){
		damage = 7;
		type = "Normal";
	}

	//Psyduck Attack
	if(name == "Zen HeadButt"){
		damage = 13;
		type = "Psychic";
	}
}

Attack Attack::operator =(const Attack& otherAttack) const{
	Attack result;
	result.damage = otherAttack.damage;
	result.name = otherAttack.name;
	result.type = otherAttack.type;
	return result;
}
