// Gabriel Leite de Sousa - 31861571
#ifndef __TREE_H_
#define __TREE_H_

#include "Node.h"

class Tree {
public:
	Tree();
	Tree(Node* root);
	~Tree();

	
	Node* GetRoot() const;
	void SetRoot(Node* root);

	
	bool TreeVazia() const;
	
	int GetGrau() const;
	int GetHeight() const;
	

	int GetLevel(Node* node, std::string data);
	int GetHeightNode(Node* node, std::string data);

	std::string TransverseInOrder() const;
	std::string TransversePreOrder() const;
	std::string TransversePostOrder() const;

	void PrintLevelByLevel(Node* root);

private:
	Node* root;
	bool TreeVaziaInternal (const Node* root) const;
	int GetHeightInternal(Node* node) const;
	int GetGrauInternal(Node* node) const;

	std::string TransverseInOrderInternal(const Node* node) const;
	std::string TransversePreOrderInternal(const Node* node) const;
	std::string TransversePostOrderInternal(const Node* node) const;

};


#endif // !__TREE_H_
 