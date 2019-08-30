#include <math.h>
#include <stdio.h>

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

int findGoalDistance(const int start, const int end)
{
	int distance = fabs(end - start);
	if (distance == 0)
		return 0;
	else if (distance == 1 || distance == 3)
	{
		if ((start % 3 == 2 && end % 3 == 0) ||
			(start % 3 == 0 && end % 3 == 2))
			return 3;
		return 1;
	}
	else if (distance == 5)
		return 3;
	else if (distance > 0 && distance % 2 == 0)
	{
		if ((start == 2 && end == 6) || (start == 6 && end == 2) || distance == 8)
			return 4;
		return 2;
	}
	else if (distance == 7)
	return 3;
}

int findGoalIndex(const int n, const int* end, const int size)
{
	for (size_t i = 0; i < size; i++)
		if (end[i] == n)
			return i;
	return -1;
}

int calculateHScore(const int *state, const int size, int* end)
{
	int hScore = 0;
	for (size_t i = 0; i < size; ++i)
	{
		int num = state[i];
		int goalIndex = findGoalIndex(num, end, size);
		hScore += findGoalDistance(i, goalIndex);
	}
	return hScore;
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

void generateNodeChildren(Node* n, NodeVector* open, int* end)
{
	nodeVecInit(n->children);
	const int rows = 3;
	const int length = rows * rows;
	int* tempChildState;
	initArray(tempChildState, length);
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
		int hScore = calculateHScore(tempChildState, length, end);
		initNode(south, n, tempChildState,
				 hScore, n->gScore + 1);
		nodeVecPush_back(n->children, south);
		nodeVecPush_back(open, south);
	}
	initArray(tempChildState, length);
	copyIntArray(n->state, tempChildState, length);
	if (zeroIndex <= length - 1 - rows)	// If middle row
	{
		tempChildState[zeroIndex] = tempChildState[zeroIndex + rows];
		tempChildState[zeroIndex + rows] = 0;
		Node* north = malloc(sizeof(Node));
		int hScore = calculateHScore(tempChildState, length, end);
		initNode(north, n, tempChildState,
				 hScore, n->gScore + 1);
		nodeVecPush_back(n->children, north);
		nodeVecPush_back(open, north);
	}
	initArray(tempChildState, length);
	copyIntArray(n->state, tempChildState, length);
	if (zeroIndex % rows != 0) // If not left column
	{
		tempChildState[zeroIndex] = tempChildState[zeroIndex - 1];
		tempChildState[zeroIndex- 1] =  0;
		Node* east = malloc(sizeof(Node));
		int hScore = calculateHScore(tempChildState, length, end);
		initNode(east, n, tempChildState,
				 hScore, n->gScore + 1);
		nodeVecPush_back(n->children, east);
		nodeVecPush_back(open, east);
	}
	initArray(tempChildState, length);
	copyIntArray(n->state, tempChildState, length);
	if (zeroIndex % rows != rows - 1) // If not right column
	{
		tempChildState[zeroIndex] = tempChildState[zeroIndex + 1];
		tempChildState[zeroIndex + 1] = 0;
		Node* west = malloc(sizeof(Node));
		int hScore = calculateHScore(tempChildState, length, end);
		initNode(west, n, tempChildState,
				 hScore, n->gScore + 1);
		nodeVecPush_back(n->children, west);
		nodeVecPush_back(open, west);
	}
	nodeVecResize(n->children, n->children->currentSize);
}

void printNode(const Node* n, const int size)
{
	int* state = n->state;
	const int rows = (size == 9) ? 3 : 4;
	for (size_t i = 0; i < size; ++i)
	{
		if (state[i] != 0)
			printf("%d ", state[i]);
		else
			printf("   ");
		if (i % rows == rows - 1)
			printf("\n");
	}
}