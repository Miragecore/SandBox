
// namespace DisjointSet
// {
// 	class DisjointNode
// 	{
// 		public :
// 			DisjointNode(): parent(this), rank(0){}
// 			virtual ~DisjointNode(){}

// 			DisjointNode *parent;
// 			int value;
// 			int rank;
// 	};

// 	DisjointNode *FindRoot(DisjointNode *curNode);
// 	DisjointNode *Union(DisjointNode *x, DisjointNode *y);
// }

#include "DisjointSet.h"

DisjointNode *FindRoot(DisjointNode *curNode)
{
	if(curNode->parent != curNode)
		curNode->parent = FindRoot(curNode->parent);
	return curNode->parent;
}

DisjointNode *Union(DisjointNode *x, DisjointNode *y)
{
	DisjointNode * xRoot = FindRoot(x);
	DisjointNode * yRoot = FindRoot(y);

	if(xRoot == yRoot)
		return xRoot;

	if(xRoot->rank < yRoot->rank)
		xRoot->parent = yRoot;
	else if(xRoot->rank > yRoot->rank)
		yRoot->parent = xRoot;
	else
	{
		yRoot->parent = xRoot;
		xRoot->rank = xRoot->rank + 1;
	} 

}

