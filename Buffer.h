#pragma once

#include "Cuisine.h"

using std::vector;
using namespace std;

class Buffer
{
public:
	void add(Cuisine& val) {
		while (true) {
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer.size() < size_; });
			buffer.push_back(val);
			locker.unlock();
			cond.notify_all();
			return;
		}
	}

	Cuisine remove() {
		while (true)
		{
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer.size() > 0; });
			Cuisine back = buffer.back();
			buffer.pop_back();
			locker.unlock();
			cond.notify_all();
			return back;
		}
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
		return (buffer.size() + 1);
	}

	Buffer() {}

private:
	std::mutex mu;
	std::condition_variable cond;
	vector<Cuisine> buffer;
	const unsigned int size_ = 10;
};