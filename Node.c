#include "node.h"
#include "utils.h"

void initNode(Node* n, Node* parent, int* state,
			  int hScore, int gScore)
{
	n->parent = parent;
	n->state = state;
	n->hScore = hScore;
	n->gScore = gScore;
	n->fScore = hScore + gScore;
}

int calculateHScore(const int *state, const int size)
{
	return 0;
}

void copyNode(Node* original, Node* copy, int stateSize)
{
	copy->parent = original->parent;
	copyIntArray(original->state, copy->state, stateSize);
	copy->hScore = original->hScore;
	copy->gScore = original->gScore;
	copy->fScore = original->fScore;
}

bool equalsNode(Node* nodeOne, Node* nodeTwo, int stateSize)
{
	return (nodeOne->parent == nodeTwo->parent &&
			arrayEquals(nodeOne->state, nodeTwo->state, stateSize) &&
			nodeOne->hScore == nodeTwo->hScore &&
			nodeOne->gScore == nodeTwo->gScore &&
			nodeOne->fScore == nodeTwo->fScore);
}

void generateNodeChildren(Node* n, NodeVector* open)
{
	nodeVecInit(n->children);
	const int rows = 3;
	const int length = rows * rows;
	int* tempChildState;
	copyIntArray(n->state, tempChildState, length);
	int zeroIndex = 0;
	for (size_t i = 0; i < length; ++i)
	{
		if (tempChildState[i] == 0)
		{
			zeroIndex = i;
			break;
		}
	}
	if (zeroIndex >= rows)	// If top row
	{
		tempChildState[zeroIndex] = tempChildState[zeroIndex - rows];
		tempChildState[zeroIndex - rows] = 0;
		Node* south = malloc(sizeof(Node));
		initNode(south, n, tempChildState,
				 calculateHScore(tempChildState, length), n->gScore + 1);
		nodeVecPush_back(n->children, south);
		nodeVecPush_back(open, south);
	}
	copyIntArray(n->state, tempChildState, length);
	if (zeroIndex <= length - 1 - rows)	// If middle row
	{
		tempChildState[zeroIndex] = tempChildState[zeroIndex + rows];
		tempChildState[zeroIndex + rows] = 0;
		Node* north = malloc(sizeof(Node));
		initNode(north, n, tempChildState,
				 calculateHScore(tempChildState, length), n->gScore + 1);
		nodeVecPush_back(n->children, north);
		nodeVecPush_back(open, north);
	}
	copyIntArray(n->state, tempChildState, length);
	if (zeroIndex % rows != 0) // If not left column
	{
		tempChildState[zeroIndex] = tempChildState[zeroIndex - 1];
		tempChildState[zeroIndex- 1] =  0;
		Node* east = malloc(sizeof(Node));
		initNode(east, n, tempChildState,
				 calculateHScore(tempChildState, length), n->gScore + 1);
		nodeVecPush_back(n->children, east);
		nodeVecPush_back(open, east);
	}
	copyIntArray(n->state, tempChildState, length);
	if (zeroIndex % rows != rows - 1) // If not right column
	{
		tempChildState[zeroIndex] = tempChildState[zeroIndex + 1];
		tempChildState[zeroIndex + 1] = 0;
		Node* west = malloc(sizeof(Node));
		initNode(west, n, tempChildState,
				 calculateHScore(tempChildState, length), n->gScore + 1);
		nodeVecPush_back(n->children, west);
		nodeVecPush_back(open, west);
	}
	nodeVecResize(n->children, n->children->currentSize);
}