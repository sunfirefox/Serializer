#ifndef __SERIALIZER_H__
#define  __SERIALIZER_H__

#include <stdio.h>
#include "boolean.h"

bool serialize(const char* filename, void* element, size_t size, bool overwrite);
bool deserialize(const char* filename, void* pointer, int number, size_t size);

#endif
