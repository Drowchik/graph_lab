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
			if (has_vertex(v)) {
				for (auto& ver : data) {
					for (auto it = ver.second.begin(); it != ver.second.end(); it++) {
						if (it->first == v) {
							ver.second.erase(it);
							break;
						}
					}
				}
				data.erase(v);
				return true;
			}
			return false;
		}
		vector<Vertex> verteces() const {
			vector<Vertex> result;
			for (auto& ver : data) {
				result.push_back(ver.first);
			}
			return result;
		}

		void add_edge(const Vertex& v_from, const Vertex& v_to, const Distance& d) {
			if (!has_vertex(v_to)){
				add_vertex(v_to);
			}
			data[v_from].push_back(make_pair(v_to, d));
		}

		bool has_edge(const Vertex& v_from, const Vertex& v_to) const {
			for (const auto& ver : data.at(v_from)) {
				if (ver.first == v_to)
					return true;
			}
			return false;
		}

		bool remove_edge(const Vertex& from, const Vertex& to, const Distance& d) {
			if (has_edge(from, to)) {
				data[from].erase(remove(data[from].begin(), data[from].end(), make_pair(to, d)));
				return true;
			}
			return false;
		}

		bool remove_edge(const Vertex& from, const Vertex& to) {
			for (auto it = data[from].begin(); it != data[from].end(); it++) {
				if (it->first == to) {
					data[from].erase(it);
					return true;
				}
			}
			return false;
		}

		bool has_edge(const Vertex& v_from, const Vertex& v_to, const Distance& d) const {
			for (const auto& ver : data.at(v_from)) {
				if (ver.first == v_to && ver.second==d)
					return true;
			}
			return false;
		}

		vector<pair<Vertex, Distance>> edges(const Vertex& vertex) const {
			return data.at(vertex);
		}
		ostream& print(ostream& os = std::cout) {
			for (auto& ver : data) {
				os << ver.first << " : ";
				for (auto edge : ver.second) {
					os << edge.first << " ";
				}
				os << endl;
			}
			return os;
		}
	};
}
