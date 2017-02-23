
#include <iostream>
#include <ctime>
#include <string>

enum Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX };

const int ZOMBIE_NUM = 10;

class Zombie;

class Player
{

	Weapon weapon;
	float precision;
public:
	int life;

	void attack(Zombie &); //Permet fer dany segons l¡arma i la precisió;
	bool isAlive(); //Funcio que determina si esta viu o mort;

public:

	Player(); // Funcio que inicialitza els valors del jugador;

};

void Player:: attack(Zombie &l)
{
	l.life = l.life - (weapon * precision);
}

bool Player ::isAlive()
{
	
	if (life > 0)
		return true;
	else if (life <= 0)
		return false;
	
}

Player::Player() //Constructor de Player;
{
	weapon = static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX));
	precision = (rand() % 100 / 100.0);
	life = (rand() % 101);

}


// ZOMBIE------------------------------------------------------------------------------------------------------------------------

class Zombie
{

	int distanceToPlayer;
	float speed;
	float damage;
public:
	int life;



	void attack(Player &); //Permet fer dany al player si la distancia entre ells es menor o = a 0, sino avança passes;
	bool isAlive(); //Funcio que determina si es viu o mort;

public:
	Zombie(); //Funcio que inicialitza els valors del jugador;

};

bool Zombie :: isAlive()
{
	if (life > 0)
		return true;
	else if (life <= 0)
		return false;
}

void Zombie::attack(Player &l)
{
	if (distanceToPlayer <= 0)
	{
		l.life = l.life - damage;
	}
	else
	{
		distanceToPlayer= distanceToPlayer-speed;
	}
}

Zombie::Zombie() // Constructor de zombie;
{
	distanceToPlayer = (rand() % 181 + 20);
	speed = (rand() % 200 / 100.0);
	damage = (rand() % 200 / 100.0);
	life = (rand() % 101);
}

void main()
{
	srand(time(nullptr));
	Player player;
	Zombie zombies[ZOMBIE_NUM];
	bool zombiesAreAlive; //Veure si el jugador ha matat TOTS els zombies;




	do {

		zombiesAreAlive = false;

		for (int i = 0; i > ZOMBIE_NUM; i++)
		{
			if (zombies[i].isAlive())
			{
				player.attack(zombies[i]);
				zombies[i].attack(player);
				zombiesAreAlive = true;
			}
		}


	} while (player.isAlive == true && zombiesAreAlive == true);

	if (zombiesAreAlive)
	{
		std::cout << "ZOMBIES WINS";
	}
	else
		std::cout << "PLAYER WINS";

	
}

