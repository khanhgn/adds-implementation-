#include <iostream>
using namespace std;

// a tree node
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// dfs with using recursion
void dfs(TreeNode* root) {
  if (root != nullptr) {
    // Process the current node
    cout << root->data << " ";

    // Recursively traverse the left subtree
    dfs(root->left);

    // Recursively traverse the right subtree
    dfs(root->right);
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
  dfs(root);
  cout << endl;

  return 0;
}
