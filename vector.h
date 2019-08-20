#include <stdlib.h>

#if !defined(VECTOR_H)
#define VECTOR_H

typedef struct IntVectorStruct
{
	int* vector;
	size_t capacity;
	size_t currentSize;
} IntVector;

int intVecInitSize(IntVector*, size_t);
int intVecInit(IntVector*);
int intVecResize(IntVector*, size_t);
int intVecPush_back(IntVector*, int);

#endif // VECTOR_H
