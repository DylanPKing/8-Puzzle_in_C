#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "utils.h"
#include "astar.h"

#define findLength(arr) (sizeof(arr) / sizeof(arr[0]))

bool enterState(int* start, const int size)
{
	printf("Enter a sequence of numbers from 0 to 8, separated by spaces:\n");
	for (size_t i = 0; i < size; ++i)
	{
		if (scanf("%d", &start[i]) != 1 && (start[i] >= 0 || start[i] <= 8))
		{
			printf("Invalid input. Must be integers between 0 and 8.\n");
			return false;
		}
		if (contains(start, i - 1, start[i]))
		{
			printf("Invalid input. No duplicate numbers.\n");
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
	initNode(startNode, NULL, start, calculateHScore(start, puzzleSize, end), 0);
	Node* finalNode = solve(startNode, end, puzzleSize);
	NodeVector path;
	nodeVecInit(&path);
	Node* next = finalNode;
	do
	{
		nodeVecPush_back(&path, next);
		next = next->parent;
	} while (next->parent != NULL);
	printNode(finalNode, puzzleSize);
	for (size_t i = path.currentSize; i >= 0; --i)
		printNode(&path.vector[i], puzzleSize);
	
	return 0;
}