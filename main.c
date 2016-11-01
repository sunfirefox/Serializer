#include <stdio.h>
#include <stdlib.h>
#include "serializer.h"

typedef struct Coordinate Coordinate;
struct Coordinate {
	int x;
	int y;
};

int main(int argc, char *argv[]) {
	Coordinate coord[2];
	const char filename[] = "test.bin";
	
	printf("Enter x: ");
	scanf(" %i", &coord[0].x);
	
	printf("Enter y: ");
	scanf(" %i", &coord[0].y);
	
	coord[1].x = coord[0].x + 1;
	coord[1].y = coord[0].y + 1;
	
	printf("Serializing...\n");
	
	if (!serialize(filename, &coord, sizeof(coord[0]), true) || fopen(filename, "rb") == NULL)
	{
		printf("\033[1;31mError: Could not serialize to \"%s\".\033[0m\n", filename);
		return EXIT_FAILURE;
	}
	
	printf("Serialized.\n");
	
	coord[0].x = coord[0].y = coord[1].x = coord[1].y = 0;
	
	printf("Deserializing...\n");
	
	if (!deserialize(filename, &coord, 2, sizeof(coord)))
	{
		printf("\033[1;31mError: Could not deserialize from \"%s\".\033[0m\n", filename);
		return EXIT_FAILURE;
	}
	
	printf("Deserialized.\n");
	printf("Coordinate: (%i, %i)\t(x, y) + (1, 1) = (%i, %i).\n", coord[0].x, coord[0].y, coord[1].x, coord[1].y);
	
	return EXIT_SUCCESS;
}
