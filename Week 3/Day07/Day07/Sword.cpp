#include "Sword.h"

float Sword::Attack()
{
	float damage = 0;
	
	switch (material_)
	{
	case Wood:
		damage = 5;
		break;
	case Stone:
		damage = 10;
		break;
	case Copper:
		damage = 15;
		break;
	case Iron:
		damage = 25;
		break;
	case Steel:
		damage = 35;
		break;
	default:
		break;
	}

	return damage;
}