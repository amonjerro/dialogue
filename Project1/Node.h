#pragma once
#include <string>
#include<iostream>

class Node
{
protected:
	std::string text;
	std::string identifier;
public:
	Node* parent;
	Node* leftChild;
	Node* rightChild;
	virtual void ShowText() = 0;
	virtual Node* ProcessResponse() = 0;
	void setIdentifier(std::string value) {
		identifier = value;
	}
	std::string getIdentifier() { return identifier; }
	void setLeftChild(Node* n) { leftChild = n; }
	void setRightChild(Node* n) { rightChild = n; }
	void setParent(Node* n) { parent = n; }
	Node(std::string nodeText) {
		text = nodeText;
		leftChild = nullptr;
		rightChild = nullptr;
		parent = nullptr;
	};
};

class DecisionNode: public Node {
private:
	char decisionValue;
public:
	void ShowText() {
		std::cout << text << std::endl;
		std::cin >> decisionValue;
	}
	Node* ProcessResponse() {
		if (decisionValue == 'Y') {
			return leftChild;
		}
		else {
			return rightChild;
		}
	}
	DecisionNode(std::string nodeText) : Node(nodeText) {
		decisionValue = '_';
	}
};

class InformationNode: public Node {
public:
	void ShowText() {
		std::cout << text << std::endl;
	}
	Node* ProcessResponse() {
		return leftChild;
	}
	InformationNode(std::string nodeText) : Node(nodeText) {}
};
