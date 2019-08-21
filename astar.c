#include <stdio.h>

#include "astar.h"
#include "utils.h"

Node* solve(Node* currentNode, int* endState, int size)
{
	NodeVector *open, *closed;
	if (nodeVecInit(open) == -1 || nodeVecInit(closed) == -1)
	{
		printf("Error: Could not initialise state lists. Exiting.");
		exit(1);
	}

	Node finalNode;

	while (isVecEmpty(open))
	{
		if (stateEquals(currentNode->state, endState, size))
		{
			copyNode(currentNode, &finalNode, size);
			currentNode = lowestFScore(&finalNode, open);
			if (equalsNode(currentNode, &finalNode, size))
				return currentNode;
		}
		else
		{
			nodeVecRemove(open, currentNode, size);
			nodeVecPush_back(closed, currentNode);
			generateNodeChildren(currentNode, open);
			for (size_t i = open->currentSize - currentNode->children->currentSize;
				 i < open->currentSize; ++i)
			{
				Node* nOne = &open->vector[i];
				for (size_t j = 0; j < closed->currentSize; ++j)
				{
					Node* nTwo = &closed->vector[j];
					if (arrayEquals(nOne->state, nTwo->state, size))
					{
						if (nOne->fScore < nTwo->fScore)
							nodeVecRemove(closed, nTwo, size);
						else
							nodeVecRemove(open, nOne, size);
					}
				}
			}
			currentNode = lowestFScore(&open->vector[0], open);
		}
	}
}

bool stateEquals(int* current, int* goal, const int size)
{
	for (size_t i = 0; i < size; ++i)
		if (current[i] != goal[i])
			return false;
	return true;
}

Node* lowestFScore(Node* aNode, NodeVector* list)
{
	for (size_t i = 0; i < list->currentSize; ++i)
		if (aNode->fScore > list->vector[i].fScore)
			return &list->vector[i];
	return aNode;
}