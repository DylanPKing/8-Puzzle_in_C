#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

int initArray(int *arr, const int length)
{
	arr = malloc(length * sizeof(int));
	if (!arr)
		return -1;
	for (size_t i = 0; i < length; ++i)
		arr[i] = 0;
	return 0;
}

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