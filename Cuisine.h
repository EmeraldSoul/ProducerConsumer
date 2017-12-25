#pragma once

#include <iostream>
#include <stdint.h>

using namespace std;

class Cuisine
{
public:
	Cuisine()
	{
		starters = 0;
		meals = 0;
		desserts = 0;
	}

	uint8_t produce()
	{
		produceMeals();
		cout << "Total items: " << items << endl;
		return items;
	}

	uint8_t consume()
	{
		consumeMeals();
		cout << "Total items: " << items << endl;
		return items;
	}

private:
	void produceMeals()
	{
		starters++;
		meals++;
		desserts++;

		items += 3;
	}

	void consumeMeals()
	{
		starters--;
		meals--;
		desserts--;

		items -= 3;
	}

protected:
	uint8_t starters;
	uint8_t meals;
	uint8_t desserts;

	static uint32_t items;
};

uint32_t Cuisine::items = 0;