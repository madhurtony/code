#include "singleton.h"


singleton& singleton::getInstance() {
	static singleton instance;
	return instance;
}
