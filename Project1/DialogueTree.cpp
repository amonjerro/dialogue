#include "DialogueTree.h";


DataRow translateData(std::vector<std::string> input) {
	DataRow dr;

	dr.nodeType = input[0];
	dr.nodeText = input[1];
	dr.identifier = input[2];
	return dr;
}

void Tree::Load(DataSource src) {
	// Load the data into the tree
	std::fstream fileIn;
	fileIn.open(src.filename, std::ios::in);
	std::vector<std::string> row;
	std::string line, word;
	for (int i = 0; i < src.rows; i++) {
		//Prepare the data
		row.clear();
		getline(fileIn, line);
		std::stringstream s(line);
		while (getline(s, word, '&')) {
			row.push_back(word);
		}
		DataRow dr = translateData(row);

		//Create a node
		Node* n = nullptr;
		if (dr.nodeType == "1") {
			n = new InformationNode(dr.nodeText);
		}
		else {
			n = new DecisionNode(dr.nodeText);
		}
		n->setIdentifier(dr.identifier);


		//Add it to the tree
		if (dr.identifier == "") {
			root = n;
		}
		else {
			Add(n);
		}
	}
}

void Tree::ExecuteDialogue(Node* n) {
	if (n == nullptr) {
		return;
	}
	marker = n;
	n->ShowText();
	ExecuteDialogue(n->ProcessResponse());
}

void Tree::Add(Node* n) {
	Node* current = root;
	Node* previous = nullptr;
	int identifierLength = n->getIdentifier().length();
	int i = 0;

	//Navigate to the corresponding leaf position
	for (i; i < identifierLength; i++) {
		if (n->getIdentifier()[i] == 'L') {
			previous = current;
			current = current->leftChild;
		}
		else {
			previous = current;
			current = current->rightChild;
		}
	}
	current = n;

	//Set up relationships to previous node
	if (current->getIdentifier()[i - 1] == 'L') {
		previous->setLeftChild(current);
	}
	else {
		previous->setRightChild(current);
	}
	current->setParent(previous);
}