#pragma once

#include <unordered_map>
#include <thread>
#include <string>
#include <iostream>
#include <deque>
#include <condition_variable>

#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"

using namespace std;
using std::string;
using std::unordered_map;

typedef enum __THREAD_TYPE
{
	PRODUCER_THREAD,
	CONSUMER_THREAD
} THREAD_TYPE;

class ThreadsPool
{
public:
	void insert(const string& name, Buffer& b, THREAD_TYPE type)
	{
		switch (type)
		{
		case PRODUCER_THREAD:
		{
			Producer p(b);
			std::thread pthread(&Producer::run, &p, name);
			tp.insert({name, std::move(pthread)});
		}
			break;
		case CONSUMER_THREAD:
		{
			Consumer c(b);
			std::thread cthread(&Consumer::run, &c, name);
			tp.insert({ name, std::move(cthread) });
		}
			break;
		}
	}

	void join()
	{
		for (auto& t : tp)
		{
			t.second.join();
		}
	}

public:
	typedef std::unordered_map<std::string, std::thread> Threads;
	Threads tp;	
};