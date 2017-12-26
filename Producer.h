#pragma once

#include "Utils.h"
#include "PC.h"
#include "Cuisine.h"
#include "MealBuilder.h"

class Producer
{
public:
	Producer(Buffer& buffer)
		: buffer(buffer)
	{}

	void run(string name) {
		while (true) {
			if (buffer.size() > 0)
			{
				if (buffer.checkTypeExists(1)
					|| buffer.checkTypeExists(2))
				{
					MealBuilder mealBuilder;

					int num = buffer.remove();
					if (num == 1)
					{
						Meal vegMeal = mealBuilder.prepareVegMeal();
						FileClass::writeToFile("Veg Meal: \n");
						vegMeal.showItems();
						FileClass::writeToFile("Total cost: " + std::to_string(vegMeal.getCost()));
						buffer.add(3);
					}
					else
					{
						Meal nonVegMeal = mealBuilder.prepareNonVegMeal();
						FileClass::writeToFile("\n\nNon-Veg Meal: \n");
						nonVegMeal.showItems();
						FileClass::writeToFile("Total cost: " + std::to_string(nonVegMeal.getCost()));
						buffer.add(4);
					}
					FileClass::writeToFile(name + ": Order Ready. Remaining: " + std::to_string(buffer.size()) + "\n");
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
				}
			}
		}
	}

private:
	Buffer& buffer;
};