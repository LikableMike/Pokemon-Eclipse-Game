#include "Pokemon.hpp"
#include "Squirtle.hpp"
#include "Charmander.hpp"
#include "Pidgey.hpp"
#include"Ratata.hpp"
#include"Bulbasaur.hpp"
#include"Machop.hpp"
#include"Pikachu.hpp"
#include"Psyduck.hpp"
#include"Snorlax.hpp"
#include"Mew.hpp"
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<ctime>

using namespace std;
void displayGame(Pokemon&, Pokemon&, int);
bool gameLoop(vector<Pokemon>& , vector<Pokemon>& , int&);
void pickAttack(Pokemon&, Pokemon&, int);
void enemyAttack(Pokemon&, Pokemon&, int);
string superEffective(Attack);
string resistant(Attack);
int changePokemon(vector<Pokemon>);
void heal(vector<Pokemon>&, int);
vector<Pokemon>	generateEnemy(int);
string findSprite(Pokemon);
string findEnemySprite(Pokemon);
void evolveCheck(vector<Pokemon>&, int);
vector<Pokemon> BossBattle(int);

void CheatCodes(int&);

int main(){
	srand(time(0));
	int start;
	cout << "Updated" << endl;
	cout << "||************************************||" << endl;
	cout << "||*WELCOME TO MY  POKEMON BATTLE GAME*||" << endl;
	cout << "||**Programmed by  Michael Partridge**||" << endl;
	cout << "||**************(- -)*****************||" << endl;
	cout << "||*************[] []/*****************||" << endl;
	cout << "||*************()__()*****************||" << endl;
	cout << "||************************************||" << endl;
	cout << "Enter 1 To START: ";
	cin >> start;

	int lives = 3;
	int level = 1;
	int winningLevel = 20;
	//Enter 323 at start for Cheat codes like level skip!
	if(start == 323){
		CheatCodes(level);
	}
	vector<Pokemon> PlayerTeam;
	PlayerTeam.push_back(Squirtle());
	PlayerTeam.push_back(Pikachu());
	PlayerTeam.push_back(Bulbasaur());

	while(lives > 0){
	if(level > winningLevel){
		int choice;
		cout << endl << endl << "*******Congratulations!!! You Have Beaten the game!!!!*******" << endl;
		cout << "Would You Like To Continue?\n(1) Yes  (2) No" << endl;
		cin >> choice;
		while(choice < 1 || choice > 2){
			cin >> choice;
		}
		if(choice == 1){
			winningLevel = 999;
		}
		else{
			cout << "Thank You For Playing My Game!!!!!" << endl;
			break;
		}
	}
	if(level == 10 || level == 20){
		vector<Pokemon> enemyTeam = BossBattle(level);
		lives += (gameLoop(enemyTeam, PlayerTeam, level) - 1);
	}

	else{
	vector<Pokemon> enemyTeam = generateEnemy(level);
	lives += (gameLoop(enemyTeam, PlayerTeam, level) - 1);
	}


	if(lives > 0){
		cout << "STILL HAVE " << lives << " MORE LIVES!! KEEP BATTLING!!!" << endl;
	}
	}
	return 0;
}

//Displays Game Screen
void displayGame(Pokemon& enemy, Pokemon& player, int level){
	cout << setfill('|') << setw(60) << "\n";
	cout << setfill('@') << setw(4 + (level / 5)) << "\n";
	cout << enemy.name << "(HP)" << setfill('=') << setw(enemy.hp) << "" << endl;
	cout << findEnemySprite(enemy) << endl;

	cout << findSprite(player) << endl;
	cout << player.name << "(HP)" << setfill('=') << setw(player.hp) << "\n";
	cout << setfill('|') << setw(60) << "\n" << endl;
}

//Generates a random enemy team with the amount of Pokemon decided based on the level.
vector<Pokemon> generateEnemy(int level){
	vector<Pokemon> enemyTeam;
	int phase = 3 + (level / 5);

	for(int i = 0; i < phase; i++){

	int pick = rand() % 100 + 1;

	if(pick >= 1 && pick < 14){
		enemyTeam.push_back(Squirtle());
	}
	else if(pick >= 14 && pick < 28){
		enemyTeam.push_back(Charmander());
	}
	else if(pick >= 28 && pick < 42){
		enemyTeam.push_back(Bulbasaur());
	}
	else if(pick >= 42 && pick <= 56){
		enemyTeam.push_back(Pikachu());
	}

	else if(pick >= 56 && pick < 68){
		enemyTeam.push_back(Pidgey());
	}
	else if(pick >= 68 && pick < 80){
		enemyTeam.push_back(Machop());
	}
	else if(pick >= 80 && pick < 92){
		enemyTeam.push_back(Psyduck());
	}
	else if(pick >= 92 && pick <= 100){
		enemyTeam.push_back(Rattata());
	}

	}

	return enemyTeam;
}

bool gameLoop(vector<Pokemon> &enemyTeam, vector<Pokemon> &playerTeam, int &level){
	bool CONTINUE = true;
	int chosen = 1;
	int enemyCurrent = 0;
	unsigned enemyFaintCounter = 0;
	unsigned playerFaintCounter = 0;
	bool GameOver = false;




	cout << "Challenger sends out " << enemyTeam.at(0).name << "!" << endl << endl;
	displayGame(enemyTeam.at(enemyCurrent), playerTeam.at(chosen - 1), level);
	cout << "You send out " << playerTeam.at(chosen - 1).name	<< "!" << endl;

	while(GameOver == false){
	int userInput = -1;
	while(userInput <= 0 || userInput > 3){
		cout << "**What is your move?**" << endl;
		cout << "1. Attack \t 2. Change Pokemon \t 3. Give up " << endl;
		cin >> userInput;
		if(userInput == 1){
			pickAttack(playerTeam.at(chosen - 1), enemyTeam.at(enemyCurrent), level);
			displayGame(enemyTeam.at(enemyCurrent), playerTeam.at(chosen - 1), level);
		}
		if(userInput == 2){
			chosen = changePokemon(playerTeam);
		}
		if(userInput== 3){
			cout << "You Forfeit The Match..." << endl;
			GameOver = true;
			CONTINUE = false;
			break;
		}

		if(enemyTeam.at(enemyCurrent).hp <= 0){
			enemyTeam.at(enemyCurrent).hp = 0;
			enemyFaintCounter += 1;
			enemyCurrent += 1;
			cout << "Enemy Pokemon has fainted!" << endl;
			if(enemyFaintCounter >= enemyTeam.size()){
				cout << "Enemy is out of Pokemon!" << endl << endl << "*****Player Wins this battle!!!*****" << endl << endl;
				cout << "####PLAYER LEVELS UP#### Lvl: " << level + 1 << endl;
				enemyTeam.empty();
				level += 1;
				heal(playerTeam, level);
				GameOver = true;
			}
			else{
			cout << "Enemy sends out " << enemyTeam.at(enemyCurrent).name << "!" << endl;
			}
			}
		else{
		enemyAttack(playerTeam.at(chosen - 1), enemyTeam.at(enemyCurrent), level);
		displayGame(enemyTeam.at(enemyCurrent), playerTeam.at(chosen - 1), level);
		}
		if(playerTeam.at(chosen - 1).hp <= 0){
			cout << "Player's Pokemon has fainted!! \n";
			playerFaintCounter += 1;
			if(playerFaintCounter >= playerTeam.size()){
				cout << "Player Loses this battle!!!" << endl;
				heal(playerTeam, level);
				CONTINUE = false;
				GameOver = true;
			}
			else{
			cout << "Who will you send out?? \n";
			chosen = changePokemon(playerTeam);
			}
		}


	}
	}
	evolveCheck(playerTeam, level);
	return CONTINUE;
}

void pickAttack(Pokemon &playerPokemon, Pokemon &enemyPokemon, int level){
Attack playerAtk;
	string supEfct;
	string resist;
	unsigned userChoice = 0;

	//Allows user to pick which attack to use
	cout << "Choose Attack: " << endl;
	for(unsigned i = 0; i < playerPokemon.attacks.size(); i++){
		cout << "(" << i + 1 << ") " << playerPokemon.attacks.at(i).name << "  ";
	}
	cout << endl;
	cin >> userChoice;
	while(userChoice <= 0 || userChoice > playerPokemon.attacks.size()){
		cin >> userChoice;
	}
	playerAtk.damage = playerPokemon.attacks.at(userChoice - 1).damage;
	playerAtk.type = playerPokemon.attacks.at(userChoice - 1).type;
	playerAtk.name = playerPokemon.attacks.at(userChoice - 1).name;
	supEfct = superEffective(playerAtk);
	resist	= resistant(playerAtk);

	//Determine what the Attack does
	if(playerAtk.name == "Protect"){
		playerPokemon.def += playerAtk.damage;
	}
	else if(playerAtk.name == "Growl"){
		enemyPokemon.def -= playerAtk.damage;
	}
	else if(playerAtk.name == "Leech Seed"){
		playerPokemon.hp =+ (playerAtk.damage / 2);
		if(enemyPokemon.type == supEfct){
			enemyPokemon.hp -= (playerAtk.damage * 2);
		}
		else if(enemyPokemon.type == resist){
			enemyPokemon.hp -= (playerAtk.damage / 2);
		}
		else{
		enemyPokemon.hp -= playerAtk.damage;
		}
	}
	else{
		cout << "*****" << playerPokemon.name << " uses " << playerAtk.name << "!*****" << endl;
		if(enemyPokemon.type == supEfct){
			cout << "*****It was Super Effective!!!*****" << endl;
			enemyPokemon.hp -= (playerAtk.damage * 2);
		}
		else if(enemyPokemon.type == resist){
			cout << "*****It was Not Very Effective*****" << endl;
			enemyPokemon.hp -= (playerAtk.damage / 2);
		}
		else{

		enemyPokemon.hp -= playerAtk.damage;
		}
	}
	cout << endl;
}

void enemyAttack(Pokemon& playerPokemon, Pokemon &enemyPokemon, int level){
	Attack enemyAttack;
	string supEfct;
	string resist;

	//Randomly chooses enemy's attack
	unsigned userChoice = (rand() % enemyPokemon.attacks.size() + 1);
	while(userChoice <= 0 || userChoice > enemyPokemon.attacks.size()){
		cin >> userChoice;
	}
		enemyAttack.damage = enemyPokemon.attacks.at(userChoice - 1).damage;
		enemyAttack.type = enemyPokemon.attacks.at(userChoice - 1).type;
		enemyAttack.name = enemyPokemon.attacks.at(userChoice - 1).name;
		supEfct = superEffective(enemyAttack);
		resist	= resistant(enemyAttack);

	//Determines what the attack does
	if(enemyAttack.name == "Protect"){
		cout << enemyPokemon.name << " uses Protect!" << endl;
		playerPokemon.def += enemyAttack.damage;
	}
	else if(enemyAttack.name == "Growl"){
		cout << enemyPokemon.name << " uses Growl!" << endl;
		playerPokemon.def -= enemyAttack.damage;
	}
	else if(enemyAttack.name == "Leech Seed"){
		cout << enemyPokemon.name << " uses Leech Seed!!!" << endl;
		if(playerPokemon.type == supEfct){
			cout << "It was Super Effective!!!" << endl;
			playerPokemon.hp -= (enemyAttack.damage * 2);
		}
		else if(playerPokemon.type == resist){
			cout << "It was Not Very Effective" << endl;
			playerPokemon.hp -= (enemyAttack.damage / 2);
		}
		else{
			enemyPokemon.hp =+ (enemyAttack.damage / 2);
			playerPokemon.hp -= enemyAttack.damage;
		}
		}
	else{
		cout << enemyPokemon.name << " uses " << enemyAttack.name << "!" << endl;
		if(playerPokemon.type == supEfct){
			cout << "It was Super Effective!!!" << endl;
			playerPokemon.hp -= (enemyAttack.damage * 2);
		}
		else if(playerPokemon.type == resist){
			cout << "It was Not Very Effective" << endl;
			playerPokemon.hp -= (enemyAttack.damage / 2);
		}
		else{

		playerPokemon.hp -= enemyAttack.damage;
		}
	}
	cout << endl;

}

//Determines what type the attack is super effective against (Doubles damage)
string superEffective(Attack playerAtk){
	string superEfct;
	if(playerAtk.type == "Water"){
		superEfct = "Fire";
	}
	else if(playerAtk.type == "Fire"){
		superEfct = "Grass";
	}
	else if(playerAtk.type == "Grass"){
		superEfct = "Water";
	}
	else if(playerAtk.type == "Electric"){
		superEfct = "Water";
	}
	else{
		superEfct = "None";
	}
	return superEfct;
}

//Determines what type the attack is Not Very Effective against (Halves damage)
string resistant(Attack playerAtk){
	string resist;
	if(playerAtk.type == "Water"){
		resist = "Grass";
	}
	else if(playerAtk.type == "Fire" ){
		resist = "Water";
	}
	else if(playerAtk.type == "Grass"){
		resist = "Fire";
	}
	else if(playerAtk.type == "Electric"){
		resist = "Grass";
	}
	else{
		resist = "None";
	}
	return resist;
}

// Allows Player to change their current pokemon mid battle
int changePokemon(vector<Pokemon> playerTeam){
	int userChoice = -1;
	cout << "**Who Would You Like To Send Out?**" << endl;
	cout << "(1) " << playerTeam.at(0).name << "  (2) " << playerTeam.at(1).name << "  (3) " << playerTeam.at(2).name << endl;

	cin >> userChoice;
	while(userChoice <= 0 || userChoice > 3){
		cout << "++Invalid Choice++" << endl;
		cout << "Enter Choice: ";
		cin >> userChoice;
	}

	return userChoice;
}

//Heals all of the players pokemon before the next battle
void heal(vector<Pokemon> &playerTeam , int level){
	for(unsigned i = 0; i < playerTeam.size(); i++){
		playerTeam.at(i).hp = (30 + ((level - 1) * 2));

	}
}

//Finds which sprite to use for the Player's currently out pokemon to display on the battle screen
string findSprite(Pokemon player){
	string playerSprite;
	if(player.name == "Snorlax"){
		playerSprite = " (- -) \n[] []/\n()__()";
	}

	else if(player.name == "Pikachu"){
	 playerSprite = " /  / \n(^ ^) \n(O O)%";
	}

	else if(player.name == "Squirtle" || player.name == "WarTortle"){
	playerSprite = " (0 0)\n()()/#\n[]_[]#";
	}
	else if(player.name == "Bulbasaur" || player.name == "Ivysaur"){
	playerSprite = " _{  }\n(* *)/\n[]_[]/";
	}
	else if(player.name == "Charmander" || player.name == "Charmeleon"){
	playerSprite = "(o_o)$\nc c )/\n() () ";
	}


	return playerSprite;
}

//Finds which sprite to use for the Enemy's currently out pokemon to display on the battle screen
string findEnemySprite(Pokemon enemy){
	string enemySprite;
	if(enemy.name == "Snorlax"){
		enemySprite = "\t\t\t\t\t (- -) \n\t\t\t\t\t[] []/\n\t\t\t\t\t()__()";
	}

	else if(enemy.name == "Pikachu"){
	 enemySprite = "\t\t\t\t\t /  / \n\t\t\t\t\t(^ ^) \n\t\t\t\t\t(O O)%";
	}

	else if(enemy.name == "Squirtle"){
	enemySprite = "\t\t\t\t\t (0 0)\n\t\t\t\t\t()()/#\n\t\t\t\t\t[]_[]#";
	}
	else if(enemy.name == "Bulbasaur"){
	enemySprite = "\t\t\t\t\t _{  }\n\t\t\t\t\t(* *)/\n\t\t\t\t\t[]_[]/";
	}
	else if(enemy.name == "Charmander"){
	enemySprite = "\t\t\t\t\t(o_o)$\n\t\t\t\t\tc c )/\n\t\t\t\t\t() () ";
	}
	else if(enemy.name == "Mew"){
		enemySprite = "\t\t\t\t\t\t\t\t(o o) \n\t\t\t\t\t\t\t\t-( )-/\n\t\t\t\t\t\t\t\t v v/ ";
	}
	else if(enemy.name == "Rattata"){
		enemySprite = "\t\t\t\t\t  ,  ,\n\t\t\t\t\t[o_o]'\n\t\t\t\t\tv v )^";
	}
	else if(enemy.name == "Psyduck"){
		enemySprite = "\t\t\t\t\t(0vO) \n\t\t\t\t\tu u |#\n\t\t\t\t\tY Y-)#";
	}
	else if(enemy.name == "Pidgey"){
		enemySprite = "\t\t\t\t\t v   F\n\t\t\t\t\tOvO)/ \n\t\t\t\t\tT-T   ";
	}
	else if(enemy.name == "Machop"){
		enemySprite = "\t\t\t\t\t (0-0)\n\t\t\t\t\t-( *-)\n\t\t\t\t\t /--| ";
	}

	return enemySprite;
}

//Checks if any of the Pokemon can evolve
void evolveCheck(vector<Pokemon>& playerTeam, int level){
	if(level == 14 || level == 15){
		for(unsigned i = 0; i < playerTeam.size(); i++){
			playerTeam.at(i).Evolve(playerTeam.at(i));
		}
	}
}

vector<Pokemon> BossBattle(int level){
	vector<Pokemon> theTeam;
	if(level == 10){
		theTeam.push_back(Snorlax());
	}
	if(level == 20){
		theTeam.empty();
		theTeam.push_back(Mew());
	}

	return theTeam;
}

void CheatCodes(int &level){
	cout << "What Level Would You Like To Skip To??" << endl;
	cin >> level;
}
