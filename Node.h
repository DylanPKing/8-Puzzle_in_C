#include <stdbool.h>

#if !defined(NODE_H)
#define NODE_H

typedef struct NodeStruct
{
	struct NodeStruct *parent;
	int* state;
	int hScore;
	int gScore;
	int fScore;

} Node;

int calculateHScore(const int*, const int);
void copyNode(Node*, Node*, int);
bool equalsNode(Node*, Node*, int);

#endif // NODE_H
