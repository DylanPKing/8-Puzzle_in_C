#ifndef ASTAR_H
#define ASTAR_H

#include <stdbool.h>

#include "node.h"
#include "vector.h"

Node* solve(Node*, int*, int);
bool stateEquals(int*, int*, const int);
Node* lowestFScore(Node*, NodeVector*);

#endif // ASTAR_H
