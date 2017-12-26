// PC.cpp : Defines the entry point for the console application.
//

#include "Utils.h"
#include "PC.h"

int main()
{
	Buffer b;
	Producer p1(b);
	Consumer c1(b);
	Consumer c2(b);

	std::thread cthread1(&Consumer::run, &c1, "consumer thread1");
	std::thread cthread2(&Consumer::run, &c2, "consumer thread2");
	std::thread pthread1(&Producer::run, &p1, "producer thread1");
	std::thread pthread2(&Producer::run, &p1, "producer thread2");
	
	cthread1.join();
	cthread2.join();
	pthread1.join();
	pthread2.join();

	return 0;
}