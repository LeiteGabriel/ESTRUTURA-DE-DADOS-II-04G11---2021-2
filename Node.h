
// Gabriel Leite de Sousa - 31861571
#ifndef __NODE_H_
#define __NODE_H_

#include <string>


class Node {
public:
	Node();
	~Node();

	std::string GetData() const;
	void SetData(const std::string& data);
	
	Node* GetParent() const;
	void SetParent(Node* parent);

	Node* GetLeft() const;
	void SetLeft(Node* left);

	Node* GetRight() const;
	void SetRigth(Node* right);

	bool IsRoot() const;
	bool IsLeaf() const;
	
	int GetGrauNode(Node* node);
	int GetLevelUntil(Node* node, std::string data, int level);
	int GetHeightUntil(Node* node, std::string data, int level);
	

private:
	std::string data;


	Node* parent; // se parente é nulo, entao é a raiz
	Node* left;
	Node* right;

	int GetDepthInternal();
};

#endif
