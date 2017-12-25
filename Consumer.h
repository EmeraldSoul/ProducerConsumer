#pragma once

#include "Buffer.h"
#include "Cuisine.h"

class Consumer
{
public:
	Consumer(Buffer& buffer)
		: buffer(buffer)
	{}
	void run(string name) {
		while (true) {
			Cuisine& num = buffer.remove();
			buffer.lock();
			uint32_t val = num.consume();
			cout << name << ": Remaining: " << val << endl;
			cout << name << ": Size of vector: " << buffer.size() << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			buffer.unlock();
		}
	}

private:
	Buffer&  buffer;
};