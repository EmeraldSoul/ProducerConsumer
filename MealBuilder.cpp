// MealBuilder.cpp : Defines the entry point for the console application.
//

#include "Meal.h"
#include "MealBuilder.h"

#include <conio.h>

int main()
{
	MealBuilder mealBuilder;

	Meal vegMeal = mealBuilder.prepareVegMeal();
	cout << "Veg Meal: " << endl;
	vegMeal.showItems();
	cout << "Total cost: " << vegMeal.getCost();

	Meal nonVegMeal = mealBuilder.prepareNonVegMeal();
	cout << "\n\nNon-Veg Meal: " << endl;
	nonVegMeal.showItems();
	cout << "Total cost: " << nonVegMeal.getCost();

	_getch();
    return 0;
}

