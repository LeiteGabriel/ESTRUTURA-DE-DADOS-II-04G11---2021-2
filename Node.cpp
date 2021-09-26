// Gabriel Leite de Sousa - 31861571
#include "Node.h"
#include "Tree.h"

Node::Node() 
	:data("")
	, parent(nullptr)
	, left(nullptr)
	, right(nullptr)
{
}
Node:: ~Node() {
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

std::string Node::GetData() const {
	return data;
}
void Node::SetData(const std::string& data) {
	this->data = data;

}

Node* Node::GetParent() const {
	return parent;
}
void Node::SetParent(Node* parent) {
	this->parent = parent;
}

Node* Node::GetLeft() const {
	return left;
}
void Node::SetLeft(Node* left) {
	this->left = left;
}

Node* Node::GetRight() const {
	return right;
}
void Node::SetRigth(Node* right) {
	this->right = right;
}

bool Node::IsRoot() const {
	if (GetParent() != nullptr) return true;
	else return false;
}
bool Node::IsLeaf() const {
	if (GetParent() == nullptr) return true;
	else return false;
}


int Node::GetLevelUntil(Node* node, std::string data, int level) {
	if (node == nullptr) return 0;

	if (node->GetData() == data) return level;


	int downlevel = GetLevelUntil(node->GetLeft(), data, level + 1);

	if (downlevel != 0) return downlevel;

	downlevel = GetLevelUntil(node->GetRight(), data, level + 1);
	return downlevel;
}

int Node::GetHeightUntil(Node* node, std::string data, int level) {
	if (node == nullptr) return 0;

	if (node->GetData() == data) return level;


	int downlevel = GetHeightUntil(node->GetLeft(), data, level + 1);

	if (downlevel != 0) return downlevel;

	downlevel = GetHeightUntil(node->GetRight(), data, level + 1);
	return downlevel;
}

int Node::GetGrauNode(Node* node) {
		if (node == NULL)
			return 0;
		else
		{

			int lDepth = GetGrauNode(node->GetLeft());
			int rDepth = GetGrauNode(node->GetRight());

			if (lDepth > rDepth)
				return(lDepth + 1);
			else return(rDepth + 1);
		}
}