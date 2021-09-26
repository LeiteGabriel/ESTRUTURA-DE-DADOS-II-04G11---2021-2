// Gabriel Leite de Sousa - 31861571
#include "Tree.h"
#include <sstream>
#include <iostream>
#include <queue>

Tree::Tree() 
	:root(nullptr)
{
}

Tree::Tree(Node* root) 
	:root(root)
{}

Tree::~Tree() {
	root = nullptr;
}

Node* Tree::GetRoot() const {
	return root;
}

void Tree::SetRoot(Node* root) {
	this->root = root;

}

int GetHeight(Node* node) {
	if (node == nullptr) return 0;
	else {
		int lHeight = GetHeight(node->GetLeft());
		int rHeight = GetHeight(node->GetRight());

		return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
	}

}

bool Tree::TreeVazia() const {
	return TreeVaziaInternal(root);
}

int Tree::GetHeight() const {
	return GetHeightInternal(root);
}

int Tree::GetGrau() const {
	return GetGrauInternal(root);
}



std::string Tree::TransverseInOrder() const {
	return TransverseInOrderInternal(root);
}

std::string Tree::TransversePreOrder() const {
	return TransversePreOrderInternal(root);
}

std::string Tree::TransversePostOrder() const {
	return TransversePostOrderInternal(root);
}



std::string Tree::TransverseInOrderInternal(const Node* node) const {
	if (node != nullptr) {


		std::ostringstream oss;
		oss << TransverseInOrderInternal(node->GetLeft());
		oss << node->GetData() << ' '; 
		oss << TransverseInOrderInternal(node->GetRight()); 
		return oss.str();
	}

	return "";
}

std::string Tree::TransversePreOrderInternal(const Node* node) const {
	if (node != nullptr) {

	
		std::ostringstream oss;
		oss << node->GetData() << ' ';
		oss << TransversePreOrderInternal(node->GetLeft());
		oss << TransversePreOrderInternal(node->GetRight());
		return oss.str();
	}

	return "";
}

std::string Tree::TransversePostOrderInternal(const Node* node) const {
	if (node != nullptr) {


		std::ostringstream oss;
		oss << TransversePostOrderInternal(node->GetLeft());
		oss << TransversePostOrderInternal(node->GetRight());
		oss << node->GetData() << ' ';
		return oss.str();
	}

	return "";
}


bool Tree::TreeVaziaInternal(const Node* root) const{
	if (root == nullptr) return true;
	else return false;

}

int Tree::GetHeightInternal(Node* node) const{
	if (node == nullptr) return 0;
	else {
		int lHeight = GetHeightInternal(node->GetLeft());
		int rHeight = GetHeightInternal(node->GetRight());

		return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
	}

}

int Tree::GetGrauInternal(Node* node) const {
	if (node == NULL)
		return 0;
	else
	{

		int lDepth = GetGrauInternal(node->GetLeft());
		int rDepth = GetGrauInternal(node->GetRight());


		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}


int Tree::GetLevel(Node* node, std::string data) {
	return (node->GetLevelUntil(node, data, 1) - 1);
}

int Tree::GetHeightNode(Node* node, std::string data) {
	return node->GetHeightUntil(node, data, 1);
}

void Tree::PrintLevelByLevel(Node* root) {
	if (root == NULL) return;

	std::queue<Node*> q;

	q.push(root);

	while (q.empty() == false)
	{

		int nodeCount = q.size();

		while (nodeCount > 0)
		{
			Node* node = q.front();
			std::cout << node->GetData() << " ";
			q.pop();
			if (node->GetLeft() != NULL)
				q.push(node->GetLeft());
			if (node->GetRight() != NULL)
				q.push(node->GetRight());
			nodeCount--;
		}
		std::cout << "\n";
	}
}