
#include <iostream>
#include"singleton.h"
#include<thread>
int main()
{
	std::thread t1{ []() {singleton& instance = singleton::getInstance(); } };
	std::thread t2{ []() {singleton& instance = singleton::getInstance(); } };
	std::thread t3{ []() {singleton& instance = singleton::getInstance(); } };
	
	t1.join();
	t2.join();
	t3.join();
}

