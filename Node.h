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

#endif // NODE_H
