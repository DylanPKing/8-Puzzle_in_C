#include "node.h"
#include "utils.h"

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