#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "vector.h"

int nodeVecInitSize(NodeVector *v, size_t initCapacity)
{
	v->vector = malloc(initCapacity * sizeof(Node));
	if (!v->vector)
		return -1;	// Fail
	v->currentSize = 0;
	v->capacity = initCapacity;
	return 0;	// Success
}

int nodeVecInit(NodeVector *v)
{
	return nodeVecInitSize(v, 10);
}

int nodeVecResize(NodeVector *v, size_t newCapacity)
{
	int *newVec = realloc(v->vector, newCapacity * sizeof(Node));
	if (!newVec)
		return -1;
	v->capacity = newCapacity;
	return 0;
}

int nodeVecPush_back(NodeVector *v, Node* element)
{
	if (v->currentSize + 1 > v->capacity)
	{
		nodeVecResize(v, v->capacity + 1);
		++v->capacity;
	}
	v->vector[v->currentSize] = *element;
	++v->currentSize;
	return 0;
}

int nodeVecRemove(NodeVector *v, Node* element, int size)
{
	for (size_t i = 0; i < v->currentSize; ++i)
	{
		if (equalsNode(&v->vector[i], element, size))
		{
			for (size_t j = i; j < v->currentSize - 1; ++j)
				v->vector[j] = v->vector[j + 1];
			--v->capacity;
			nodeVecResize(v, v->capacity);
			--v->currentSize;
		}
	}
}

bool isVecEmpty(NodeVector *v)
{
	return v->currentSize == 0;
}

void copyNodeArray(Node* original, Node* copy, const int capacity)
{
	for (size_t i = 0; i < capacity; ++i)
		copy[i] = original[i];
}

void copyNodeVec(NodeVector *original, NodeVector *copy)
{
	copy->vector = malloc(original->capacity * sizeof(Node));
	copyNodeArray(original->vector, copy->vector, original->capacity);
	copy->currentSize = original->currentSize;
	copy->capacity = original->capacity;
}