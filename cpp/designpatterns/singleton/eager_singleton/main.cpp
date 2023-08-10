#include <iostream>
#include <vector>
#include<cassert>
#include"singleton.h"
using namespace std;

int main()
{
	singleton& instance1 = singleton::getInstance();
	singleton& instance2 = singleton::getInstance();
	return 0;
}
