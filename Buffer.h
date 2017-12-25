#pragma once


#include "PC.h"
#include "Cuisine.h"

using std::deque;
using namespace std;

class Buffer
{
public:
	void add(Cuisine& val) {
		while (true) {
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer_.size() < size_; });
			buffer_.push_back(val);
			locker.unlock();
			cond.notify_all();
			return;
		}
	}

	Cuisine remove() {
		while (true)
		{
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer_.size() > 0; });
			Cuisine back = buffer_.back();
			buffer_.pop_back();
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
		return (buffer_.size() + 1);
	}

	Buffer() {}

private:
	// Add them as member variables here
	std::mutex mu;
	std::condition_variable cond;

	// Your normal variables here
	deque<Cuisine> buffer_;
	const unsigned int size_ = 10;
};