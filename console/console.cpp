#include <iostream>
#include <aisd_graph/aisd_graph.h>

using namespace std;
using namespace Graph_lab;

int main() {
	Graph<int> a;
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_vertex(6);
	a.add_vertex(7);
	a.add_edge(1, 2, 2);
	a.add_edge(2, 3, 1);
	a.add_edge(2, 5, 9);
	a.add_edge(2, 4, 4);
	a.add_edge(2, 6, 5);
	a.add_edge(3, 7, 1);
	a.add_edge(7, 6, 2);
	a.print() << endl <<endl;
	vector<pair<int, double>> b = a.shortest_path(2, 6);
	for (auto& vec : b) {
		cout << vec.first << " " << vec.second << endl;
	}
	return 0;
}