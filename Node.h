#if !defined(NODE_H)
#define NODE_H

struct Node
{
	const struct Node *parent;
	const int* state;
	const int fScore;
	const int gScore;
	const int hScore;
};

int calculateFScore(const int*, const int);

#endif // NODE_H
