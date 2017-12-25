#pragma once

#include "Buffer.h"
#include "Cuisine.h"

class Producer
{
public:
	Producer(Buffer& buffer)
		: buffer(buffer)
	{}

	void run(string name) {
		while (true) {
			Cuisine num;
			buffer.lock();
			uint32_t val = num.produce();
			cout << name << ": Produced: " << val << std::endl;
			cout << name << ": Size of vector: " << buffer.size() << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			buffer.unlock();
			buffer.add(num);
		}
	}

private:
	Buffer&  buffer;
};