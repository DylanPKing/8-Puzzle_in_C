#include <stdlib.h>
#include <math.h>

#include "vector.h"

int intVecInitSize(IntVector *v, size_t initCapacity)
{
	v->vector = malloc(initCapacity * sizeof(int));
	if (!v->vector)
		return -1;	// Fail
	v->currentSize = 0;
	v->capacity = initCapacity;
	return 0;	// Success
}

int intVecInit(IntVector *v)
{
	return intVecInitSize(v, 10);
}

int intVecResize(IntVector *v, size_t newCapacity)
{
	int *newVec = realloc(v->vector, newCapacity * sizeof(int));
	if (!newVec)
		return -1;
	v->capacity = newCapacity;
	return 0;
}

int intVecPush_back(IntVector *v, int element)
{
	if (v->currentSize + 1 > v->capacity)
		intVecInitResize(v, v->capacity + 1);
	v->vector[v->currentSize] = element;
	++v->currentSize;
	return 0;
}