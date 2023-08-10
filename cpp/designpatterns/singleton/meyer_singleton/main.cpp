#include <iostream>
#include "singleton.h"
int main()
{
	singleton& instance1 = singleton::getInstance();
	singleton& instance2 = singleton::getInstance();
}
