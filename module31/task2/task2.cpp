#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <typeinfo>

class IGraph {
public:
	IGraph() {};
	IGraph(const IGraph& _oth) {};
	virtual ~IGraph() {};
	virtual void AddEdge(int from, int to) = 0;
	virtual int VerticesCount() const = 0;
	virtual std::vector<int> Vertices() const = 0;
	virtual std::vector<int> GetNextVertices(int vert) const = 0;
	virtual std::vector<int> GetPrevVertices(int vert) const = 0;
	virtual void print() const = 0;
};

class MatrixGraph : public IGraph {
	std::vector<std::vector<bool>> matrix;
	std::map<int, int> idByVert;
	std::vector<int> vertById;
	int fnId(int vert);
public:
	MatrixGraph();
	MatrixGraph(const MatrixGraph& graph);
	MatrixGraph(const IGraph& graph);
	~MatrixGraph() override;
	void AddEdge(int from, int to) override;
	int VerticesCount()  const;
	std::vector<int> Vertices()  const override;
	std::vector<int> GetNextVertices(int vert) const override;
	std::vector<int> GetPrevVertices(int vert) const override;
	void print()  const override;
};

MatrixGraph::MatrixGraph() {}

MatrixGraph::MatrixGraph(const MatrixGraph& graph) {}

MatrixGraph::MatrixGraph(const IGraph& graph) {
	if (typeid(graph) != typeid(*this)) {
		for (auto& a : graph.Vertices()) {
			for (auto& b : graph.GetNextVertices(a)) {
				AddEdge(a, b);
			}
		}
	} else {
		MatrixGraph(graph);
	}
}

MatrixGraph::~MatrixGraph() {}

int MatrixGraph::fnId(int vert) {
	if (auto pos = idByVert.find(vert); pos != idByVert.end()) {
		return pos->second;
	}

	const int newId = vertById.size();
	vertById.push_back(vert);
	idByVert[vert] = newId;

	for (auto& a : matrix) {
		a.push_back(false);
	}

	matrix.push_back(std::vector<bool>(newId + 1, false));
	return newId;
}

void MatrixGraph::AddEdge(int from, int to) {
	int i = fnId(from);
	int j = fnId(to);

	matrix[i][j] = true;
}

int MatrixGraph::VerticesCount() const {
	return vertById.size() - 1;
};

std::vector<int> MatrixGraph::Vertices()const {
	return vertById;
}

std::vector<int> MatrixGraph::GetNextVertices(int vert) const {
	int id = idByVert.find(vert)->second;
	std::vector<int> nextVert;
	for (int i = 0; i < matrix[id].size(); ++i) {
		if (matrix[id][i]) {
			nextVert.push_back(vertById[i]);
		}
	}
	return nextVert;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vert) const {
	int id = idByVert.find(vert)->second;
	std::vector<int> nextVert;
	for (int i = 0; i < matrix[id].size(); ++i) {
		if (matrix[i][id]) {
			nextVert.push_back(vertById[i]);
		}
	}
	return nextVert;
}

void MatrixGraph::print()  const {
	std::cout << "MatrixGrap" << std::endl;
	for (int i = 0; i < matrix.size(); ++i) {
		std::cout << std::setw(3) << vertById[i] << " | ";
		for (int j = 0; j < matrix.size(); ++j) {
			std::cout << ((matrix[i][j]) ? ('1') : ('0')) << " ";
		}
		std::cout << std::endl;
	}

}

class ListGraph : public IGraph {
	std::map<int, std::vector<int>> fromVert;
	std::map<int, std::vector<int>> toVert;
public:
	ListGraph();
	ListGraph(const ListGraph& graph);
	ListGraph(const IGraph& graph);
	~ListGraph() override;
	void AddEdge(int from, int to) override;
	int VerticesCount()  const;
	std::vector<int> Vertices()  const override;
	std::vector<int> GetNextVertices(int vert) const override;
	std::vector<int> GetPrevVertices(int vert) const override;
	void print()  const override;
};

ListGraph::ListGraph() {}

ListGraph::ListGraph(const ListGraph& graph) {}

ListGraph::ListGraph(const IGraph& graph) {
	if (typeid(graph) != typeid(*this)) {
		for (auto& a : graph.Vertices()) {
			for (auto& b : graph.GetNextVertices(a)) {
				AddEdge(a, b);
			}
		}
	} else {
		ListGraph(graph);
	}
}

ListGraph::~ListGraph() {}

void ListGraph::AddEdge(int from, int to) {
	if (auto pos = fromVert.find(from); pos != fromVert.end()) {
		bool push = true;
		for (auto& a : pos->second) {
			if (a == to) {
				push = false;
				break;
			}
		}
		if (push) {
			fromVert[from].push_back(to);
		}
	} else {
		fromVert[from].push_back(to);
	}

	if (auto pos = toVert.find(to); pos != toVert.end()) {
		bool push = true;
		for (auto& a : pos->second) {
			if (a == from) {
				push = false;
				break;
			}
		}
		if (push) {
			toVert[to].push_back(from);
		}
	} else {
		toVert[to].push_back(from);
	}

}

int ListGraph::VerticesCount() const {
	return fromVert.size();
}

std::vector<int> ListGraph::Vertices() const {
	std::vector<int> allVert;
	for (auto& a : fromVert) {
		allVert.push_back(a.first);
	}

	for (auto& a : toVert) {
		if (fromVert.find(a.first) == fromVert.end()) {
			allVert.push_back(a.first);
		}
	}
	return allVert;
}

std::vector<int> ListGraph::GetNextVertices(int vert) const {
	if (fromVert.find(vert) != fromVert.end()) {
		return fromVert.find(vert)->second;
	}
	return std::vector<int>();
}

std::vector<int> ListGraph::GetPrevVertices(int vert) const {
	if (toVert.find(vert) != toVert.end()) {
		return toVert.find(vert)->second;
	}
	return std::vector<int>();
}

void ListGraph::print()  const {
	std::cout << "List Grap" << std::endl;
	for (auto& a : Vertices()) {
		std::cout << std::setw(3) << a << " | ";
		if (auto pos = fromVert.find(a); pos != fromVert.end()) {
			for (auto& b : pos->second) {
				std::cout << b << " ";
			}
		}
		std::cout << std::endl;
	}
}


int main() {
	MatrixGraph test1;
	ListGraph test2;
	MatrixGraph test3;

	test1.AddEdge(2, 3);
	test1.AddEdge(42, 6);
	test1.AddEdge(-32, 3);
	test1.AddEdge(6, 3);
	test1.AddEdge(2, 3);
	test1.AddEdge(2, -23);

	test2 = test1;
	test3 = test1;

	test1.print();
	std::cout << std::endl;
	test2.print();
	std::cout << std::endl;
	test3.print();

	std::cout << std::endl;
	std::cout << "from 2 | ";
	std::vector<int> from = test1.GetNextVertices(2);
	for (auto& i : from) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	std::cout << "to 3 | ";
	std::vector<int> to = test2.GetPrevVertices(3);
	for (auto& i : to) {
		std::cout << i << " ";
	}
}