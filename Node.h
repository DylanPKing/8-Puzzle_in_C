#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

typedef struct NodeVectorStruct NodeVector;

#include "vector.h"

typedef struct NodeStruct
{
	struct NodeStruct *parent;
	int* state;
	int hScore;
	int gScore;
	int fScore;
	NodeVector* children;
} Node;

void initNode(Node*, Node*, int*, int, int);
int calculateHScore(const int*, const int);
void copyNode(Node*, Node*, int);
bool equalsNode(Node*, Node*, int);
void generateNodeChildren(Node*, NodeVector*);

#endif // NODE_H
