#include <stdlib.h>
#include "node.h"

#if !defined(VECTOR_H)
#define VECTOR_H

typedef struct NodeVectorStruct
{
	Node* vector;
	size_t capacity;
	size_t currentSize;
} NodeVector;

int nodeVecInitSize(NodeVector*, size_t);
int nodeVecInit(NodeVector*);
int nodeVecResize(NodeVector*, size_t);
int nodeVecPush_back(NodeVector*, Node*);
int nodeVecRemove(NodeVector*, Node*, int);
bool isVecEmpty(NodeVector*);
void copyNodeArray(Node*, Node*, const int);
void copyNodeVec(NodeVector*, NodeVector*);

#endif // VECTOR_H
