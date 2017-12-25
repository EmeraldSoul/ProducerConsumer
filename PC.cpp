// PC.cpp : Defines the entry point for the console application.
//

#include "PC.h"

int main() 
{
	Buffer b;

	ThreadsPool tp;
	tp.insert("producer thread1", b, PRODUCER_THREAD);
	tp.insert("producer thread2", b, PRODUCER_THREAD);
	//tp.insert("consumer thread1", b, CONSUMER_THREAD);
	//tp.insert("consumer thread2", b, CONSUMER_THREAD);

	tp.join();

	return 0;
}