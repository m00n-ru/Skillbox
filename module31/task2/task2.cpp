#include <iostream>
#include <vector>
#include <memory>


class IGraph {
public:
	virtual ~IGraph() {};
	IGraph() {};
	IGraph(IGraph* _oth) {};
	virtual void AddEdge(int from, int to) = 0;
	virtual int VerticesCount() const = 0;
	virtual void GetNextVertices(int index, std::vector<int>& vertices) const = 0;
	virtual void GetPrevVertices(int index, std::vector<int>& vertices) const = 0;
	virtual void print() const = 0;
};


//   1 2 3 
// 1[0 1 0]
// 2[0 0 0]
// 3[1 1 0]

class MatrixGraph : public IGraph {
	bool** matrix;
	int numVert;
public:
	MatrixGraph();
	explicit MatrixGraph(int n);
	MatrixGraph(MatrixGraph& graph);
	~MatrixGraph();
	void AddEdge(int from, int to);
	int VerticesCount() const;
	void GetNextVertices(int index, std::vector<int>& vertices) const;
	void GetPrevVertices(int index, std::vector<int>& vertices) const;
	void print() const;
};

MatrixGraph::MatrixGraph() : matrix(nullptr), numVert(0) {};

MatrixGraph::MatrixGraph(int n) : numVert(n) {
	matrix = new bool* [n];
	for (int i = 0; i < numVert; ++i) {
		matrix[i] = new bool[n];
		for (int j = 0; j < numVert; ++j) {
			matrix[i][j] = false;
		}
	}
};

MatrixGraph::MatrixGraph(MatrixGraph& graph) {
	numVert = graph.numVert;
	matrix = new bool* [numVert];
	for (int i = 0; i < numVert; ++i) {
		matrix[i] = new bool[numVert];
		for (int j = 0; j < numVert; ++j) {
			matrix[i][j] = graph.matrix[i][j];
		}
	}
}

MatrixGraph::~MatrixGraph() {
	for (int i = 0; i < numVert; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void MatrixGraph::AddEdge(int from, int to) {
	if (from < 1) from = 1;
	if (from > numVert) from = numVert;
	if (to < 1) to = 1;
	if (to > numVert) to = numVert;
	matrix[from - 1][to - 1] = true;
}

int MatrixGraph::VerticesCount() const {
	return numVert;
}

void MatrixGraph::GetNextVertices(int index, std::vector<int>& vertices) const {
	if (index < 1 || index > numVert) {
		return;
	}
	for (int i = 0; i < numVert; ++i) {
		if (matrix[index - 1][i])
			vertices.push_back(i + 1);
	}
}

void MatrixGraph::GetPrevVertices(int index, std::vector<int>& vertices) const {
	if (index < 1 || index > numVert) {
		return;
	}
	for (int i = 0; i < numVert; ++i) {
		if (matrix[i][index - 1])
			vertices.push_back(i + 1);
	}
}

void MatrixGraph::print() const {
	std::cout << "Matrix graph" << std::endl;
	for (int i = 0; i < numVert; ++i) {
		for (int j = 0; j < numVert; ++j) {
			std::cout << ((matrix[i][j]) ? ('1') : ('0')) << " ";
		}
		std::cout << std::endl;
	}
}

// 1 - 3
// 2 - 1 - 3
// 3 -

class ListGraph : public IGraph {
	struct Vert {
		int numV = 0;
		Vert* nextV = nullptr;
		Vert* preV = nullptr;
	};
	Vert** listV;
	int numVert;
public:
	ListGraph();
	explicit ListGraph(int n);
	ListGraph(ListGraph& graph);
	~ListGraph();
	void AddEdge(int from, int to);
	int VerticesCount() const;
	void GetNextVertices(int index, std::vector<int>& vertices) const;
	void GetPrevVertices(int index, std::vector<int>& vertices) const;
	void print() const;
};

ListGraph::ListGraph() : listV(nullptr), numVert(0) {}

ListGraph::ListGraph(int n) : numVert(n) {
	listV = new Vert * [n];
	for (int i = 0; i < n; ++i) {
		listV[i] = nullptr;
	}
}

ListGraph::ListGraph(ListGraph& graph) {
	numVert = graph.numVert;
	listV = new Vert * [numVert];
	for (int i = 0; i < numVert; ++i) {
		if (graph.listV[i] == nullptr) {
			listV[i] = nullptr;
		} else {
			auto startV = graph.listV[i];
			auto startVcopy = listV[i];
			do {
				startVcopy = new Vert;
				startVcopy->numV = startV->numV;
				startVcopy->nextV = startV->nextV;
				startVcopy->preV = startV->preV;

				if (startV->nextV) {
					startV = graph.listV[i]->nextV;
				}
			} while (startV->nextV != nullptr);
		}
	}
}

ListGraph::~ListGraph() {
	for (int i = 0; i < numVert; ++i) {
		if (listV[i] != nullptr) {
			auto next = listV[i]->nextV;
			while (next != nullptr) {
				auto buf = next;
				next = next->nextV;
				delete buf;
			}
			delete listV[i];
		}
	}
	delete[] listV;
}

void ListGraph::AddEdge(int from, int to) {
	if (from < 1) from = 1;
	if (from > numVert) from = numVert;
	if (to < 1) to = 1;
	if (to > numVert) to = numVert;

	if (listV[from - 1] == nullptr) {
		listV[from - 1] = new Vert;
		listV[from - 1]->numV = to;
	} else {
		auto startV = listV[from - 1];
		do {
			if (startV->numV == to) {
				return;
			} else if (startV->numV > to) {
				auto newV = new Vert;
				newV->numV = to;
				newV->nextV = startV;
				if (startV->preV == nullptr) {
					listV[from - 1] = newV;
				} else {
					startV->preV = newV;
				}
				return;
			} else if (startV->numV < to && startV->nextV == nullptr) {
				auto newV = new Vert;
				newV->numV = to;
				newV->preV = startV;
				startV->nextV = newV;
				return;
			}
			startV = startV->nextV;
		} while (startV->nextV != nullptr);
	}
}

int ListGraph::VerticesCount() const {
	return numVert;
}

void ListGraph::GetNextVertices(int index, std::vector<int>& vertices) const {
	if (index < 0 || index >= numVert) {
		return;
	}
	if (listV[index - 1]) {
		auto start = listV[index - 1];
		while (start) {
			vertices.push_back(start->numV);
			start = start->nextV;
		}
	}
}

void ListGraph::GetPrevVertices(int index, std::vector<int>& vertices) const {
	if (index < 1 || index > numVert) {
		return;
	}
	for (int i = 0; i < numVert; ++i) {
		if (listV[i]) {
			auto start = listV[i];
			while (start) {
				if (start->numV == index) {
					vertices.push_back(i + 1);
				}
				start = start->nextV;
			}
		}
	}
}

void ListGraph::print() const {
	std::cout << "List graph" << std::endl;
	for (int i = 0; i < numVert; ++i) {
		std::cout << i + 1 << ": ";
		if (listV[i] != nullptr) {
			std::cout << listV[i]->numV << " ";
			auto nV = listV[i]->nextV;
			while (nV != nullptr) {
				std::cout << nV->numV << " ";
				nV = nV->nextV;
			}
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<int> fromM;
	std::vector<int> toM;
	std::vector<int> fromL;
	std::vector<int> toL;



	IGraph* arrGraph[2];
	arrGraph[0] = new MatrixGraph(4);
	arrGraph[1] = new ListGraph(4);

	for (auto& i : arrGraph) {
		i->AddEdge(1, 3);
		i->AddEdge(2, 3);
		i->AddEdge(2, 2);
		i->AddEdge(1, 3);
		i->AddEdge(4, 1);
	}
	std::cout << std::endl;

	for (auto& i : arrGraph) {
		i->print();
		std::cout << std::endl;
		std::vector<int> from;
		std::vector<int> to;

		i->GetNextVertices(3, from);
		std::cout << "From 3: ";
		for (auto& i : from) {
			std::cout << i << " ";
		}
		std::cout << std::endl;

		i->GetPrevVertices(2, to);
		std::cout << "To 2: ";
		for (auto& i : to) {
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << "Vertices count= " << i->VerticesCount() << std::endl << std::endl;
	}
}