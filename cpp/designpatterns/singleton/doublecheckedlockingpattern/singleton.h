#pragma once
#include <iostream>
#include<mutex>
class singleton
{
private:
	singleton() {
		std::cout << "singleton constructor called" << std::endl;
	}
public:
	singleton(const singleton&) = delete;
	singleton& operator = (const singleton&) = delete;

	inline static singleton* ptr{ nullptr };
	static std::mutex m;
	static singleton& getInstance();
	~singleton() {
		std::cout << "singleton destructor called" << std::endl;
	}
};
