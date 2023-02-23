#include<cmath>
#include<ctime>
#include "Pokemon.hpp"

using namespace std;

Pokemon::Pokemon() : hp(0), atk(0), def(0), spd(0), name(string("NA")), type(string("NA")){

}

Pokemon::Pokemon(int h, unsigned a, unsigned d, unsigned s, string n, string t) :
hp(int(h)),
atk(unsigned(a)),
def(unsigned(d)),
spd(unsigned(s)),
name(string(n)),
type(string(t)){


}

Pokemon::~Pokemon(){

}





Pokemon Pokemon::operator =(const Pokemon &otherPoke) const{
	Pokemon result;
	result.atk = otherPoke.atk;
	result.def = otherPoke.def;
	result.spd = otherPoke.spd;
	result.name = otherPoke.name;
	result.type = otherPoke.type;
	result.attacks = otherPoke.attacks;
	return result;
}

void Pokemon::Evolve(Pokemon& playerPokemon){
	int userChoice;
	if(playerPokemon.name == "Squirtle"){
		cout << "---------------------------------------" << endl;
		cout << "%%%%%%% Squirtle is Evolving!!! %%%%%%%" << endl;
		cout << "%%%%%% Squirtle is now WarTortle %%%%%%" << endl;
		cout << "---------------------------------------" << endl;
		playerPokemon.name = "WarTortle";

		cout << "Which attack would you like to learn?" << endl;
		cout << "(1) Water Gun  (2) Tail Whip" << endl;

		cin >> userChoice;
		while(userChoice < 0 && userChoice > 3){
			cin >> userChoice;
		}
		if(userChoice == 1){
		playerPokemon.attacks.push_back(Attack("Water Gun"));
		}
		else if(userChoice == 2){
			playerPokemon.attacks.push_back(Attack("Tail Whip"));
		}
	}
	else if(playerPokemon.name == "Bulbasaur"){
		cout << "---------------------------------------" << endl;
		cout << "%%%%%%% Bulbasaur is Evolving!!! %%%%%%%" << endl;
		cout << "%%%%%% Bulbasaur is now IvySaur %%%%%%" << endl;
		cout << "---------------------------------------" << endl;
		playerPokemon.name = "Ivysaur";

		cout << "Which attack would you like to learn?" << endl;
		cout << "(1) Razor Leaf  (2) Take Down" << endl;

		cin >> userChoice;
		while(userChoice < 0 && userChoice > 3){
			cin >> userChoice;
		}
		if(userChoice == 1){
		playerPokemon.attacks.push_back(Attack("Razor Leaf"));
		}
		else if(userChoice == 2){
			playerPokemon.attacks.push_back(Attack("Take Down"));
		}
	}
	else if(playerPokemon.name == "Charmander"){
		cout << "---------------------------------------" << endl;
		cout << "%%%%%%% Charmander is Evolving!!! %%%%%%%" << endl;
		cout << "%%%%%% Charmeleon is now WarTortle %%%%%%" << endl;
		cout << "---------------------------------------" << endl;
		playerPokemon.name = "Charmeleon";

		cout << "Which attack would you like to learn?" << endl;
		cout << "(1) Flame Thrower  (2) Slam" << endl;

		cin >> userChoice;
		while(userChoice < 0 && userChoice > 3){
			cin >> userChoice;
		}
		if(userChoice == 1){
		playerPokemon.attacks.push_back(Attack("Flame Thrower"));
		}
		else if(userChoice == 2){
			playerPokemon.attacks.push_back(Attack("Slam"));
		}
	}
	else if(playerPokemon.name == "WarTortle"){
		int replace;
		cout << "---------------------------------------" << endl;
		cout << "%%%%%%% WarTortle is Evolving!!! %%%%%%%" << endl;
		cout << "%%%%%% WarTortle is now Blastoise %%%%%%" << endl;
		cout << "---------------------------------------" << endl;
		playerPokemon.name = "Blastoise";

		cout << "Which attack would you like to learn?" << endl;
		cout << "(1) Water Fall  (2) Blizzard (3) Shield" << endl;

		cin >> userChoice;
		while(userChoice < 0 && userChoice > 4){
			cin >> userChoice;
		}

		cout << "What attack would you like to get rid of?" << endl;
		for(unsigned i = 0; i < playerPokemon.attacks.size(); i++){
			cout << "(" << i + 1 << ") " << playerPokemon.attacks.at(i).name << "  ";
		}
		cout << endl;
		cin >> replace;
		while(userChoice < 0 && userChoice > 5){
			cin >> replace;
		}
		cout << replace;
		if(userChoice == 1){
		playerPokemon.attacks.at(replace - 1).name = "Water Fall";
		}
		else if(userChoice == 2){
		playerPokemon.attacks.at(replace - 1).name = "Blizzard";
		}
		else if(userChoice == 3){
		playerPokemon.attacks.at(replace - 1).name = "Shield";
		}
	}

	else if(playerPokemon.name == "Ivysaur"){
			int replace;
			cout << "---------------------------------------" << endl;
			cout << "%%%%%%% Ivysaur is Evolving!!! %%%%%%%" << endl;
			cout << "%%%%%% Ivysaur is now Venasaur %%%%%%" << endl;
			cout << "---------------------------------------" << endl;
			playerPokemon.name = "Venasaur";

			cout << "Which attack would you like to learn?" << endl;
			cout << "(1) Solar Beam  (2) Leech Seed (3) Shield" << endl;

			cin >> userChoice;
			while(userChoice < 0 && userChoice > 4){
				cin >> userChoice;
			}

			cout << "What attack would you like to get rid of?" << endl;
			for(unsigned i = 0; i < playerPokemon.attacks.size(); i++){
				cout << "(" << i + 1 << ") " << playerPokemon.attacks.at(i).name << "  ";
			}
			cout << endl;
			cin >> replace;
			while(userChoice < 0 && userChoice > 5){
				cin >> replace;
			}
			cout << replace;
			if(userChoice == 1){
			playerPokemon.attacks.at(replace - 1).name = "Solar Beam";
			}
			else if(userChoice == 2){
			playerPokemon.attacks.at(replace - 1).name = "Leech Seed";
			}
			else if(userChoice == 3){
			playerPokemon.attacks.at(replace - 1).name = "Shield";
			}
		}

	else if(playerPokemon.name == "Charmeleon"){
				int replace;
				cout << "---------------------------------------" << endl;
				cout << "%%%%%%% Charmeleon is Evolving!!! %%%%%%%" << endl;
				cout << "%%%%%% Charmeleon is now Charizard %%%%%%" << endl;
				cout << "---------------------------------------" << endl;
				playerPokemon.name = "Charizard";

				cout << "Which attack would you like to learn?" << endl;
				cout << "(1)Dragon Breath  (2) Flare Blitz (3) Inferno" << endl;

				cin >> userChoice;
				while(userChoice < 0 && userChoice > 4){
					cin >> userChoice;
				}

				cout << "What attack would you like to get rid of?" << endl;
				for(unsigned i = 0; i < playerPokemon.attacks.size(); i++){
					cout << "(" << i + 1 << ") " << playerPokemon.attacks.at(i).name << "  ";
				}
				cout << endl;
				cin >> replace;
				while(userChoice < 0 && userChoice > 5){
					cin >> replace;
				}
				cout << replace;
				if(userChoice == 1){
				playerPokemon.attacks.at(replace - 1).name = "Dragon Breath";
				}
				else if(userChoice == 2){
				playerPokemon.attacks.at(replace - 1).name = "Flare Blitz";
				}
				else if(userChoice == 3){
				playerPokemon.attacks.at(replace - 1).name = "Inferno";
				}
			}

}
