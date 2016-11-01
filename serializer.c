#include <stdlib.h>

#include "serializer.h"

bool serialize(const char* filename, void* element, size_t size, bool overwrite) {
	FILE* stream = fopen(filename, "rb");
	
	if (stream != NULL && !overwrite)
		return false;
	
	stream = fopen(filename, "wb");
	
	if (stream == NULL)
	{
		perror(filename);
		return false;
	}
	
	fwrite(element, size, sizeof(element)/size, stream);
	fclose(stream);
	
	return true;
}

bool deserialize(const char* filename, void* pointer, int number, size_t size) {
	FILE* stream = fopen(filename, "rb");
	
	if (stream == NULL)
	{
		perror(filename);
		return false;
	}
	
	fread(pointer, size, number, stream);
	fclose(stream);
	
	return true;
}
