#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

void copyIntArray(int *old, int *new, const int size)
{
	for (int i = 0; i < size; ++i)
		new[i] = old[i];
}

bool contains(int* arr, const int length, const int check)
{
	for (int i = 0; i < length; ++i)
		if (arr[i] == check)
			return true;
	return false;
}

bool arrayEquals(int* arrOne, int* arrTwo, int length)
{
	for (int i = 0; i < length; ++i)
		if (arrOne[i] != arrTwo[i])
			return false;
	return true;
}