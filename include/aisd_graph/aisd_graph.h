#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>

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
			for (const auto& ver : data) {
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

		const vector<pair<Vertex, Distance>>& edges(const Vertex& vertex) const {
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
		
		size_t order() const {
			return data.size();
		}

		size_t degree(const Vertex& v) const {
			return data.at(v).size();
		}

		std::vector<pair<Vertex, Distance>> shortest_path(const Vertex& from, const Vertex& to) const {
			std::unordered_map<Vertex, Distance> distances;
			for (const auto& vertex : data) {
				distances[vertex.first] = std::numeric_limits<Distance>::max();
			}
			distances[from] = 0;

			for (const auto& [vertex, edges] : data) {
				for (const auto& [neighbor, distance] : edges) {
					if (distances[vertex] + distance < distances[neighbor]) {
						distances[neighbor] = distances[vertex] + distance;
					}
				}
			}

			std::vector<pair<Vertex, Distance>> path;
			if (distances[to] != std::numeric_limits<Distance>::max()) {
				Vertex current = to;
				while (current != from) {
					for (const auto& [vertex, edges] : data) {
						for (const auto& [neighbor, distance] : edges) {
							if (current == neighbor && distances[vertex] + distance == distances[current]) {
								path.emplace_back(vertex, distance);
								current = vertex;
								break;
							}
						}
					}
				}
			}

			return path;
		}
		void walk(const Vertex& start_vertex, std::function<void(const Vertex&)> action) const {
			unordered_set<Vertex> visited;
			stack<Vertex> st;
			st.push(start_vertex);
			while (!st.empty()) {
				auto cur = st.top();
				st.pop();
				if (visited.count(cur) > 0) {
					continue;
				}
				visited.insert(cur);
				action(cur);
				for (const auto& ver : data.at(cur)) {
					if (visited.count(ver.first) == 0) {
						st.push(ver.first); 
					}
				}
			}
		}

		Vertex task3() {
			
			unordered_map<Vertex, Distance> distances;
			for (const auto& ver: data) {
				distances[ver.first] = numeric_limits<Distance>::max();
			}

			queue<Vertex> queue;
			queue.push(data.begin()->first);
			distances[data.begin()->first] = 0;

			while (!queue.empty()) {
				Vertex current = queue.front();
				queue.pop();

				for (const auto& [neighbor, distance] : data[current]) {
					int newDistance = distances[current] + distance;
					if (newDistance < distances[neighbor]) {
						distances[neighbor] = newDistance;
						queue.push(neighbor);
					}
				}
			}

			int maxDistance = -1;
			Vertex fracture_clinic;
			for (const auto& [vertex, distance] : distances) {
				if (distance > maxDistance) {
					maxDistance = distance;
					fracture_clinic = vertex;
				}
			}

			return fracture_clinic;
		}
	};

	template <typename Vertex>
	void printVertex(const Vertex& vertex) {
		std::cout << "Visited vertex with id: " << vertex << std::endl;
	}
}
