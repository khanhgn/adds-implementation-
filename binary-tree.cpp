#include <iostream>
using namespace std;

// a tree node
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root) {
  if (root != nullptr) {
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
  }
}

void preOrderTraversal(TreeNode* root) {
  if (root != nullptr) {
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void postOrderTraversal(TreeNode* root) {
  if (root != nullptr) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
  }
}

int main() {
  // create a binary tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "In-order Traversal: ";
  inOrderTraversal(root);
  cout << "\n";
  cout << "Pre-order traversal: ";
  preOrderTraversal(root);
  cout << "\n";
  cout << "Post-order traversal: ";
  postOrderTraversal(root);
  cout << "\n";
  cout << endl;
  return 0;
}
