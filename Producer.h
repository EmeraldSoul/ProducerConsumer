#pragma once

#include "Buffer.h"
#include "Cuisine.h"

class Producer
{
public:
	Producer(Buffer& buffer)
		: buffer_(buffer)
	{}

	void run(string name) {
		while (true) {
			Cuisine num;
			buffer_.lock();
			uint32_t val = num.produce();
			cout << name << ": Produced: " << val << std::endl;
			cout << name << ": Size of deque: " << buffer_.size() << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			buffer_.unlock();
			buffer_.add(num);
		}
	}

private:
	Buffer&  buffer_;
};