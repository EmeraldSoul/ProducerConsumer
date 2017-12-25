#pragma once

#include "Buffer.h"
#include "Cuisine.h"

class Consumer
{
public:
	Consumer(Buffer& buffer)
		: buffer_(buffer)
	{}
	void run(string name) {
		while (true) {
			Cuisine& num = buffer_.remove();
			buffer_.lock();
			uint32_t val = num.consume();
			cout << name << ": Remaining: " << val << endl;
			cout << name << ": Size of deque: " << buffer_.size() << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			buffer_.unlock();
		}
	}

private:
	Buffer&  buffer_;
};