#ifndef CPP_MODULES_SERIALIZER_H
#define CPP_MODULES_SERIALIZER_H

#include "Data.h"
#include <cstdint>

class Serializer {
public:
	static uintptr_t serialize(Data *ptr);

	static Data *deserialize(uintptr_t raw);
};

#endif //CPP_MODULES_SERIALIZER_H
