#if !defined(NODE_H)
#define NODE_H

struct Node
{
	const struct Node *parent;
	int* state;
	int fScore;
	int gScore;
	int hScore;
};

int calculateFScore(const int*, const int);

#endif // NODE_H
