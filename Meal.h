#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;
using std::string;
using std::list;

class Packing
{
public:
	virtual string pack() = 0;
};

class Item
{
public:
	Item() 
	{ 
		this->Name = "";
		this->Pack = nullptr;
		this->Price = 0.0f;
	}
	virtual string name();
	virtual Packing* packing();
	virtual float price();

	void setName(string n) { this->Name = n; }
	void setPack(Packing* n) { this->Pack = n; }
	void setPrice(float n) { this->Price = n; }

private:
	string Name;
	Packing* Pack;
	float Price;
};

string Item::name()
{
	return Name;
}

Packing* Item::packing()
{
	return Pack;
}

float Item::price()
{
	return Price;
}

class Wrapper : public Packing
{
public:
	string pack() override
	{
		return "Wrapper";
	}
};

class Bottle : public Packing
{
public:
	string pack() override
	{
		return "Bottle";
	}
};

class Burger : public Item
{
public:
	Packing* packing() override;
};

Packing* Burger::packing()
{
	return (new Wrapper());
}

class ColdDrink : public Item
{
public:
	Packing* packing() override;
};

Packing* ColdDrink::packing()
{
	return (new Bottle());
}

class VegBurger : public Burger
{
public:
	float price() override
	{
		return 25.0f;
	}

	string name() override
	{
		return "Veg Burger";
	}
};

class ChickenBurger : public Burger
{
public:
	float price() override
	{
		return 50.5f;
	}

	string name() override
	{
		return "Chicken Burger";
	}
};

class Coke : public ColdDrink
{
public:
	float price() override
	{
		return 30.0f;
	}

	string name() override
	{
		return "Coke";
	}
};

class Pepsi : public ColdDrink
{
public:
	float price() override
	{
		return 35.0f;
	}

	string name() override
	{
		return "Pepsi";
	}
};