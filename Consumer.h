#pragma once

#include "Utils.h"
#include "PC.h"
#include "Cuisine.h"
#include "MealBuilder.h"

class Consumer
{
public:
	Consumer(Buffer& buffer)
		: buffer(buffer)
	{}
	void run(string name) {
		while (true) {
			if (buffer.size() > 0)
			{
				/*if (buffer.checkTypeExists(MEAL_TYPE::VEG_MEAL_READY)
					|| buffer.checkTypeExists(MEAL_TYPE::NONVEG_MEAL_READY))*/
				if (buffer.checkTypeExists(3)
					|| buffer.checkTypeExists(4))
				{
					int num = buffer.remove();
					FileClass::writeToFile(name + ": Order consumed. Remaining: " + std::to_string(buffer.size()) + "\n");
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
				}
			}
			else
			{
				uint32_t rnum = (uint32_t)rand() % 2 + 1;
				buffer.add((int)rnum);
				FileClass::writeToFile(name + ": Order placed. Buffer size: " + std::to_string(buffer.size()) + "\n");
			}

		}
	}

private:
	Buffer& buffer;
};