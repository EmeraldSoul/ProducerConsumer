#pragma once

#include "Utils.h"
#include "PC.h"
#include "Meal.h"

#include <memory>

using std::unique_ptr;

class Meal
{
public:
	Meal() {}

	void addItem(Item& item)
	{
		item.setName(item.name());
		item.setPack(item.packing());
		item.setPrice(item.price());

		items.push_back(item);
	}

	float getCost()
	{
		float cost = 0.0f;
		for (auto& item : items)
		{
			cost += item.price();
		}

		return cost;
	}

	void showItems()
	{
		for (auto& item : items)
		{
			FileClass::writeToFile("Item : " + item.name() + "\n");
			FileClass::writeToFile("Packing : " + item.packing()->pack() + "\n");
			FileClass::writeToFile("Price : " + std::to_string(item.price()) + "\n\n");
		}
	}

private:
	list<Item> items;
};

class MealBuilder
{
public:
	Meal prepareVegMeal()
	{
		Meal meal;
		VegBurger vegBurger;
		Coke coke;
		meal.addItem(vegBurger);
		meal.addItem(coke);
		return meal;
	}

	Meal prepareNonVegMeal()
	{
		Meal meal;
		ChickenBurger chickenBurger;
		Pepsi pepsi;
		meal.addItem(chickenBurger);
		meal.addItem(pepsi);
		return meal;
	}
};