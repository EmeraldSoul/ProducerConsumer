#pragma once

#include <iostream>
#include <list>
#include <stdint.h>
#include <condition_variable>
#include <mutex>

#include "PC.h"
#include "Utils.h"
#include "Cuisine.h"
#include "MealBuilder.h"

using std::list;
using std::mutex;
using std::condition_variable;
using namespace std;

class Buffer
{
public:
	void add(int val) {
		while (true) {
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer.size() < size_; });
			buffer.push_back(val);
			locker.unlock();
			cond.notify_all();
			return;
		}
	}

	int remove() {
		while (true)
		{
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer.size() > 0; });
			int back = buffer.back();
			buffer.pop_back();
			locker.unlock();
			cond.notify_all();
			return back;
		}
	}

	bool checkTypeExists(int type)
	{
		for (auto& b : buffer)
		{
			if (b == type)
				return true;
		}

		return false;
	}

	void lock()
	{
		mu.lock();
	}

	void unlock()
	{
		mu.unlock();
	}

	uint32_t size()
	{
		return (buffer.size());
	}

	Buffer() {}

private:
	std::mutex mu;
	std::condition_variable cond;
	list<int> buffer;
	const unsigned int size_ = 10;
};