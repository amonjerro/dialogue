#include "Node.h"
#include <fstream>
#include <sstream>
#include <ios>
#include <vector>

struct DataSource {
	std::string filename;
	int columns = 0;
	int rows = 0;
};


struct DataRow {
	std::string nodeType;
	std::string nodeText;
	std::string identifier;
};

class Tree {
public:
	Node* root;
	Node* marker;
	void Load(DataSource src);
	void Add(Node* n);
	void ExecuteDialogue(Node* n);
};