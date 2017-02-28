
#include <iostream>
#include <ctime>
#include <string>

enum Weapon { FISTS, GUNSHOT, MACHINEGUN, KNIFE, SWORD, SNIPER, MAX};



class Zombie;

class Player
{
public:
	Weapon weapon;
	float precision;
	int life;

	void attack(Zombie &); //Permet fer dany segons l¡arma i la precisió;
	bool isAlive(); //Funcio que determina si esta viu o mort;



	Player(); // Funcio que inicialitza els valors del jugador;

};

class Zombie
{

public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;



	void attack(Player &); //Permet fer dany al player si la distancia entre ells es menor o = a 0, sino avança passes;
	bool isAlive(); //Funcio que determina si es viu o mort;

public:
	Zombie(); //Funcio que inicialitza els valors del jugador;

};




void Player::attack(Zombie &l)
{
	l.life = l.life - (weapon * precision);
}

bool Player::isAlive()
{

	if (life > 0)
		return true;
	else 
		return false;

}

Player::Player() //Constructor de Player;
{
	weapon= static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX));
	precision= (rand() % 10 / 10.f);
	life = 100;

}





bool Zombie::isAlive()
{
	return life < 0;   

	/*if (life > 0)
	return true;
	else
	return false;*/
}

void Zombie::attack(Player &l)
{
	if (distanceToPlayer <= 0)
	{
		l.life = l.life - damage;
	}
	else
	{
		distanceToPlayer = distanceToPlayer - speed;
	}
}

Zombie::Zombie() // Constructor de zombie;
{
	distanceToPlayer = (rand() % 100);
	speed = (rand() % 100 / 10.0);
	damage = (rand() % 100 / 10.0);
	life = (rand() % 101);
}

void main()
{
	srand(time(nullptr));

	Player player; //LLAMADA AL CONSTRUCTOR
	std::cout << "PLAYER STATS: --------------//" "Weapon: " << player.weapon<< "//-------------- Precision: " 
		<< player.precision<< "//-------------- Life: "<< player.life <<std::endl;
	
	const int ZOMBIE_NUM = 10;
	Zombie zombies[ZOMBIE_NUM];

	int counter = 1;
	for (int c = 0; c < ZOMBIE_NUM; c++)
	{
		std::cout << "ZOMBIE  [" <<counter<< "]  STATS:--------------//" "Distance " << zombies[c].distanceToPlayer << "//--------------Speed: " 
		<< zombies[c].speed << "//--------------Life: " << zombies[c].life << std::endl;
		counter++;
	}

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


	} while (player.isAlive()  && zombiesAreAlive);

	

	if (zombiesAreAlive)
	{
		std::cout << "ZOMBIES WINS";
	}
	else
		std::cout << "PLAYER WINS";


}



