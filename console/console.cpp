#include <iostream>
#include <aisd_graph/aisd_graph.h>

using namespace std;
using namespace Graph_lab;

int main() {
	Graph<int> a;
	a.add_vertex(5);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_edge(5, 7, 8);
	a.add_edge(5, 2, 4);
	cout << a.has_edge(5, 7, 8) << endl<<endl;
	a.print() << endl;
	a.remove_edge(5, 7);
	a.print() << endl;
	return 0;
}