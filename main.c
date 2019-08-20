#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "utils.h"
#include "astar.h"
#include "vector.h"

#define findLength(arr) (sizeof(arr) / sizeof(arr[0]))

bool enterState(int* start, const int size)
{
	for (size_t i = 0; i < size; ++i)
		start[i] = 0;

	printf("Enter a sequence of numbers from 0 to 8, separated by spaces:\n");
	for (size_t i = 0; i < size; ++i)
	{
		if (scanf("%d", &start[i]) != 1 && (start[i] >= 0 || start[i] <= 8))
		{
			printf("Invalid input. Must be integers between 0 and 8.");
			return false;
		}
		if (!(contains(start, i - 1, start[i])))
		{
			printf("Invalid input. No duplicate numbers.");
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int *start;
	int end[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
	const int puzzleSize = findLength(end);
	start = malloc(puzzleSize * sizeof(int));
	for (size_t i = 0; i < puzzleSize; ++i)
		start[i] = 0;
	
	int valid = 0;
	while (!valid)
		valid = enterState(start, puzzleSize);

	Node *startNode = malloc(sizeof(Node));
	startNode->parent = NULL;
	startNode->state = copyIntArray(start, puzzleSize);
	startNode->hScore = calculateHScore(startNode->state, puzzleSize);
	startNode->gScore = 0;
	startNode->fScore = startNode->hScore + startNode->gScore;

	free(start);

	IntVector *open, *closed;
	if (intVecInit(open) == -1 || intVecInit(closed) == -1)
	{
		printf("Error: Could not initialise state lists. Exiting.");
		return 1;
	}

	solve(startNode, end, open, closed);

	return 0;
}
