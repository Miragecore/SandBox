
	class DisjointNode
	{
		public :
			DisjointNode(): parent(this), rank(0){}
			DisjointNode(int x): parent(this), value(x), rank(0){}
			virtual ~DisjointNode(){}

			DisjointNode *parent;
			int value;
			int rank;
	};

	DisjointNode *FindRoot(DisjointNode *curNode);
	DisjointNode *Union(DisjointNode *x, DisjointNode *y);
