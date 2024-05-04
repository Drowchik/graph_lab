#include <iostream>
#include <aisd_graph/aisd_graph.h>

using namespace std;
using namespace Graph_lab;

int main() {
	Graph<int> a;
	a.add_vertex(5);
	a.add_vertex(2);
	a.add_vertex(3);
	cout<<a.has_vertex(5)<<endl;
	a.remove_vertex(5);

	return 0;
}