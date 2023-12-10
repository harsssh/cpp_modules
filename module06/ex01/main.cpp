#include <iostream>
#include "Data.h"
#include "Serializer.h"

int main() {
	Data data("42");
	std::cout << data << std::endl;
	std::cout << "&data: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);
	std::cout << *ptr << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
}
