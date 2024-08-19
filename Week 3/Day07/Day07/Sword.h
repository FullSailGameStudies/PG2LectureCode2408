#pragma once
enum WeaponMaterial //collection of named ints
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
	float Attack() const;//declaration in the header, definition in the cpp

	//getters (accessors) of the fields
	//	they are just methods. sometimes they are defined in the header file, not the cpp.
	//	they normally do NOT have any parameters
	//	the return type is the same as the field type
	//  they are const methods
	//	naming convention: 
	//		GetFieldName or FieldName
	float GetLength() const
	{
		return length_;
	}
	WeaponMaterial Material() const
	{
		return material_;
	}
	bool IsTwoHanded() const
	{
		return twoHanded_;
	}

	//setters (mutators) of the fields
	//	they are just methods. the purpose is to change the field.
	//	they normally have a parameter that matches the type of the field.
	//	they CANNOT be const b/c they modify the class
	//	they don't have a return type
	//	put protections on the field. don't let anyone just change the field to whatever.
	//	naming convention: 
	//		SetFieldName or FieldName
	void SetLength(float newLength)
	{
		//protect the field with an if block
		if (newLength > 0 && newLength < 2) //meters
		{
			length_ = newLength;
		}
	}
	void Material(WeaponMaterial newMaterial)
	{
		if (material_ != WeaponMaterial::Wood && material_ != WeaponMaterial::Stone &&
			newMaterial != WeaponMaterial::Wood && newMaterial != WeaponMaterial::Stone)
		{
			material_ = newMaterial;
		}
	}

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
	WeaponMaterial material_;

	void SomeMethod(float& length)
	{
		length += 5;
		float swordLength;//camelCasingNamingConvention
		length_ += 0.2;
	}
};

