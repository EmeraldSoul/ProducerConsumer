// PC.cpp : Defines the entry point for the console application.
//

#include <unordered_map>
#include <thread>
#include <string>
#include <iostream>
#include <vector>
#include <condition_variable>

#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"

using namespace std;
using std::string;
using std::vector;
using std::unordered_map;

int main()
{
	Buffer b;
	Producer p1(b);
	Producer p2(b);
	Consumer c1(b);
	Consumer c2(b);

	std::thread pthread1(&Producer::run, &p1, "producer thread1");
	std::thread pthread2(&Producer::run, &p2, "producer thread2");
	std::thread cthread1(&Consumer::run, &c1, "consumer thread1");
	std::thread cthread2(&Consumer::run, &c2, "consumer thread2");
	
	pthread1.join();
	pthread2.join();
	cthread1.join();
	cthread2.join();

	return 0;
}