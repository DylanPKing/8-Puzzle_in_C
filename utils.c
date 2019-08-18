#include "utils.h"

void copyIntArray(int *old, int *new, const int size)
{
	for (int i = 0; i < size; ++i)
		new[i] = old[i];
}