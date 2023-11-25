#include <iostream>
#include <queue>
using namespace std;

// a tree node
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// bfs with using recursion
void bfs(TreeNode* root) {
  if (root == nullptr) {
    return;
  }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* current = q.front();
    q.pop();

    // process the current node
    cout << current->data << " ";

    // enqueue the left child if it exists
    if (current->left != nullptr) {
      q.push(current->left);
    }

    // enqueue the right child if it exists
    if (current->right != nullptr) {
      q.push(current->right);
    }
  }
}

// in order traversal to print out tree
void inOrder(TreeNode* root) {
  if (root != nullptr) {
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }
}

int main() {
  // create a binary tree
  TreeNode* root = new TreeNode(15);
  root->left = new TreeNode(26);
  root->right = new TreeNode(33);
  root->left->left = new TreeNode(43);
  root->left->right = new TreeNode(52);
  root->right->left = new TreeNode(68);
  root->right->right = new TreeNode(79);

  cout << "In-order Traversal: ";
  inOrder(root);
  cout << endl;

  cout << "DFS Traversal: ";
  bfs(root);
  cout << endl;

  return 0;
}
