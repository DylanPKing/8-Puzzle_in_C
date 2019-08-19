#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

int *copyIntArray(int *old, const int size)
{
	int *new = malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i)
		new[i] = old[i];
	return new;
}

bool contains(int* arr, const int length, const int check)
{
	for (int i = 0; i < length; ++i)
		if (arr[i] == check)
			return false;
	return true;
}