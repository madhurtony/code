#pragma once
#include<iostream>

// In meyer implementation, singleton will not be created when the app starts. Instead it will be created when getInstance() function is called
// After c++ 11, this implementation is considered threadsafe
class singleton
{
private:

	singleton() {
		std::cout << "singleton constructor called" << std::endl;
	}

public:
	static singleton& getInstance();
	singleton(const singleton&) = delete;
	singleton& operator = (const singleton&) = delete;
	~singleton() {
		std::cout << "singleton destrcutor called" << std::endl;
	}
};
