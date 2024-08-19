#pragma once
enum Material //collection of named ints
{
	Wood,
	Stone,
	Copper,
	Iron,
	Steel
};
class Sword
{
	//OOD (object-oriented DESIGN)
	//data (fields) describe the object. think PRIVATE for your data.
	//	length, material, durability, twoHanded, doubleBladed
	//methods (behavior) are what the object can DO
	//	attack, block

	//DESIGN decision: visibility of the members (data,methods)
	//	WHO should be able to see them
	//	any number of these sections

public://anyone can see it
	//methods: the behavior of an object
	//naming convention: PascalNamingConvention
	float Attack();//declaration in the header, definition in the cpp

protected://only ME and my descendents can see it
private://ONLY ME

	//fields: the data or variables of the class (object)
	//naming convention: camelCasingNamingConvention
	//	sets the field apart from parameters or local variables in a method
	//	so developers can visually tell the difference
	//	different naming conventions in the industry:
		//	m_fLength, m_length, _length, mLength, length_
	//	whatever convention you use, BE CONSISTENT
	float length_;
	bool twoHanded_;
	Material material_;

	void SomeMethod(float& length)
	{
		length += 5;
		float swordLength;//camelCasingNamingConvention
		length_ += 0.2;
	}
};

