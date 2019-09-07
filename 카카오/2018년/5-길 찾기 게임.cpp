#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int id;
	int x, y;
	Node* left;
	Node* right;
};
bool comp(Node& a, Node& b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}

void addNode(Node* parent, Node* child) {
	if (child->x < parent->x) {
		if (parent->left == NULL)
			parent->left = child;
		else
			addNode(parent->left, child);
	}
	else {
		if (parent->right == NULL)
			parent->right = child;
		else
			addNode(parent->right, child);
	}
}

void preorder(vector<int>& ans, Node *node) {
	if (node == NULL) return;

	ans.push_back(node->id);
	preorder(ans, node->left);
	preorder(ans, node->right);
}

void postorder(vector<int>& ans, Node *node) {
	if (node == NULL) return;

	postorder(ans, node->left);
	postorder(ans, node->right);
	ans.push_back(node->id);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	int size = nodeinfo.size();
	vector <Node> nodes;

	for (int i = 0; i < size; i++) {
		nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
	}
	sort(nodes.begin(), nodes.end(), comp);

	Node* root = &nodes[0];
	for (int i = 1; i < size; i++) {
		addNode(root, &nodes[i]);
	}

	vector<vector<int>> answer(2);
	preorder(answer[0], root);
	postorder(answer[1], root);

	return answer;
}