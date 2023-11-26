#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
 private:
  Node* root;

  Node* insert(Node* currentNode, int value) {
    // if it is at the root
    if (currentNode == nullptr) {
      return new Node(value);
    }

    if (value < currentNode->data) {
      currentNode->left = insert(currentNode->left, value);
    } else if (value > currentNode->data) {
      currentNode->right = insert(currentNode->right, value);
    }

    return currentNode;
  }

  void inOrderTraversal(Node* currentNode) {
    if (currentNode != nullptr) {
      inOrderTraversal(currentNode->left);
      cout << currentNode->data << " ";
      inOrderTraversal(currentNode->right);
    }
  }

  void preOrderTraversal(Node* currentNode) {
    if (currentNode != nullptr) {
      cout << currentNode->data << " ";
      preOrderTraversal(currentNode->left);
      preOrderTraversal(currentNode->right);
    }
  }

  void postOrderTraversal(Node* currentNode) {
    if (currentNode != nullptr) {
      postOrderTraversal(currentNode->left);
      postOrderTraversal(currentNode->right);
      cout << currentNode->data << " ";
    }
  }

  bool search(Node* currentNode, int value) {
    if (currentNode == nullptr) {
      return false;
    }

    if (currentNode->data == value) {
      return true;
    } else if (value < currentNode->data) {
      return search(currentNode->left, value);
    } else {
      return search(currentNode->right, value);
    }
  }

 public:
  BinaryTree() : root(nullptr) {}

  void insert(int value) { root = insert(root, value); }

  void inOrderTraversal() {
    inOrderTraversal(root);
    cout << "\n";
  }

  void preOrderTraversal() {
    preOrderTraversal(root);
    cout << "\n";
  }

  void postOrderTraversal() {
    postOrderTraversal(root);
    cout << "\n";
  }

  bool search(int value) { return search(root, value); }
};

int main() {
  BinaryTree binaryTree;
  binaryTree.insert(1);
  binaryTree.insert(2);
  binaryTree.insert(3);
  binaryTree.insert(4);
  binaryTree.insert(5);
  binaryTree.insert(6);
  binaryTree.insert(7);

  cout << "In-order traversal: ";
  binaryTree.inOrderTraversal();

  cout << "Pre-order traversal: ";
  binaryTree.preOrderTraversal();

  cout << "Post-order traversal: ";
  binaryTree.postOrderTraversal();

  int valueToSearch = 90;
  if (binaryTree.search(valueToSearch)) {
    cout << valueToSearch << " found in the binary tree.\n";
  } else {
    cout << valueToSearch << " not found in the binary tree.\n";
  }

  return 0;
}
