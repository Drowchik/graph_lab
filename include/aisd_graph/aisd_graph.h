#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace Graph_lab {
	template <typename Vertex, typename Distance = double>
	class Graph {
		std::unordered_map <Vertex, std::vector<std::pair<Vertex, Distance>>> data;
	public:
		bool has_vertex(const Vertex& v) const {
			if (data.find(v) == data.end()) {
				return false;
			}
			return true;
		}
		void add_vertex(const Vertex& v) {
			data[v] = vector<pair<Vertex, Distance>>();
		}
		bool remove_vertex(const Vertex& v) {
			for (auto& ver : data) {
				cout << ver.first;
			}
			return true;
		}
	};
}
