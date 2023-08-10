#include "singleton.h"

std::mutex singleton::m{};

singleton& singleton::getInstance() {
	if (ptr == nullptr) {
		std::lock_guard lg{ m };
		if (ptr == nullptr) {
			ptr = new singleton();
		}
	}
	std::cout << "Retrieved singleton " << std::endl;
	return *ptr;
}