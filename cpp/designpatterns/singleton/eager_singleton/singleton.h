#pragma once
#include<iostream>

// In Eager implementation, singleton will be created when the app starts even if singleton is not used anywhere 
class singleton
{
private:

	singleton() {
		std::cout << "singleton constructor called" << std::endl;
	}

	static singleton instance;
public:

	static singleton& getInstance();
	singleton(const singleton&) = delete;
	singleton& operator = (const singleton&) = delete;
	~singleton() {
		std::cout << "singleton destrcutor called" << std::endl;
	}
};
