#include <stdio.h>
#include <stdlib.h>

#define findLength(arr) (sizeof(arr) / sizeof(arr[0]))

int enterState(int* start, const int size)
{
	int *check = malloc (size * sizeof(int));
	for (size_t i = 0; i < size; ++i)
		check[i] = 0;

	printf("Enter a sequence of numbers from 0 to 9, separated by spaces:\n");
	for (size_t i = 0; i < size; ++i)
	{
		scanf("%d", &start[i]);
		if ( (start[i] >= 0 || start[i] <= 8))
		{
			printf("Invalid input. Must be integers between 0 and 8.");
			return 0;
		}
		else if (++check[i] > 1)
		{
			printf("Invalid input. No duplicate integers.");
			return 0;
		}
	}
	free(check);
	return 1;
}

int main(int argc, char const *argv[])
{
	int *start;
	int end[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	const int puzzleSize = findLength(end);
	start = malloc(puzzleSize * sizeof(int));
	for (size_t i = 0; i < puzzleSize; ++i)
		start[i] = 0;
	
	int valid = 0;
	while (!valid)
		valid = enterState(start, puzzleSize);


	return 0;
}
