#include <iostream>
#include <limits>
#include <tuple>
#include <set>
#include <vector>
#ifndef ALGORITHMMETHODBRUNCHANDBOUND_H
#define ALGORITHMMETHODBRUNCHANDBOUND_H

using namespace std;

struct inf;
struct Node;

void matrixInitialization(struct Node*& head);
void print(struct Node*& node, string information);
unsigned castColumns(struct Node*& node);
unsigned castRows(struct Node*& node);
tuple<unsigned, pair<unsigned short, unsigned short>> penalty(struct Node* node);
void copyLeftNode(struct Node*& node1, struct Node*& node2);
void copyRightNode(struct Node*& node1, struct Node*& node2, pair<short unsigned, short unsigned> rib);
pair<unsigned short, unsigned short> findCurrentMatrixIndex(Node*& lnode, pair<unsigned short, unsigned short> rib);
void excludeEarlyTermination(Node*& lnode, pair<unsigned short, unsigned short> rib);
void runProgram();


#endif // ALGORITHMMETHODBRUNCHANDBOUND_H
