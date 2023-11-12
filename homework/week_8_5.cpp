#include <iostream>

using std::cin; using std::cout;
using std::endl;


struct Graph {
	int blocks[500][500]={0};// lowerleft coordinate to represent the block
};
struct matrix {
	int x1, x2, y1, y2;
};

// right is covered by the left
bool is_covered(Graph& g,matrix right)
{
	for (int x=right.x1; x<right.x2; ++x) {
		for (int y=right.y1; y<right.y2; ++y) {
			if (g.blocks[x][y]!=1)
				return false;
		}
	}
	return true;
}
void fill_in(Graph& g, matrix right)
{
	for (int x=right.x1; x<right.x2; ++x) {
		for (int y=right.y1; y<right.y2; ++y) {
			g.blocks[x][y]=1;
		}
	}
}
int main()
{
	int n, order;
	cin >> n;
	matrix current;
	Graph graph;
	for (int i=0; i!=n; ++i) {
		cin >> order >> current.x1 >> current.y1 >> current.x2 >> current.y2;
		if (order==0) {
			fill_in(graph, current);
		}
		else if (order==1) {
			if (is_covered(graph, current)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
