#include "Sword.h"

Sword::Sword(WeaponMaterial material, float length, bool isTwoHanded) :
	// member initialization list (PREFERRED way)
	// why preferred? this happens BEFORE the { } code
	material_(material),
	//length_(length),  //there are no protections here
	twoHanded_(isTwoHanded)
{
	SetLength(length);//call the setter to utilize the protections

	//field = parameter
	//material_ = material;
	// 
	//NEVER do parameter = field
	//material = material_; //WRONG!!
}

Sword::Sword(WeaponMaterial material) :
	material_(material),
	length_(1.0f),
	twoHanded_(false)
{
}

float Sword::Attack() const
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