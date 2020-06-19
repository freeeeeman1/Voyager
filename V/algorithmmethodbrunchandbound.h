#include <iostream>
#include <limits>
#include <tuple>
#include <set>
#include <vector>
#include <QTextBrowser>
#ifndef ALGORITHMMETHODBRUNCHANDBOUND_H
#define ALGORITHMMETHODBRUNCHANDBOUND_H

using namespace std;

struct inf;
struct Node;

void matrixInitialization(struct Node*& head, std::pair<std::pair<unsigned short,  unsigned short>, unsigned>** matrix, unsigned short int size);
void print(struct Node*& node, string information, QTextBrowser* browser);
unsigned castColumns(struct Node*& node);
unsigned castRows(struct Node*& node);
tuple<unsigned, pair<unsigned short, unsigned short>> penalty(struct Node* node);
void copyLeftNode(struct Node*& node1, struct Node*& node2);
void copyRightNode(struct Node*& node1, struct Node*& node2, pair<short unsigned, short unsigned> rib);
pair<unsigned short, unsigned short> findCurrentMatrixIndex(Node*& lnode, pair<unsigned short, unsigned short> rib);
void excludeEarlyTermination(Node*& lnode, pair<unsigned short, unsigned short> rib);
void runProgram(std::pair<std::pair<unsigned short,  unsigned short>, unsigned>** matrix, unsigned short int size, QTextBrowser* browser);


#endif // ALGORITHMMETHODBRUNCHANDBOUND_H
