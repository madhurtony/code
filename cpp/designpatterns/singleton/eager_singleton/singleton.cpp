#include "singleton.h"

singleton singleton::instance;

singleton& singleton::getInstance() {
	return instance;
}

