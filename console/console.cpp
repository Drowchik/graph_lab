#include <iostream>
#include <aisd_graph/aisd_graph.h>

using namespace std;
using namespace Graph_lab;

int main() {
	Graph<int> a;
	a.add_vertex(5);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_edge(5, 2, 8);
	a.add_edge(5, 3, 4);
	a.add_edge(2, 7, 4);
	a.add_edge(2, 9, 4);
	a.add_edge(7, 9, 4);
	a.print() << endl <<endl;
	auto vec = a.walk(5);
	for (auto& v : vec) {
		cout << v;
	}

	return 0;
}