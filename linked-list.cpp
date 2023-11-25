#include <iostream>
using namespace std;

class Node {
 public:
  char data;
  Node* next;
};

void deleteNode(Node*& head, char value) {
  Node* temp = head;
  Node* prev = nullptr;

  if (temp != nullptr && temp->data == value) {
    head = temp->next;
    delete temp;
    return;
  }

  // Search for the node to be deleted, keeping track of the previous node
  while (temp != nullptr && temp->data != value) {
    prev = temp;
    temp = temp->next;
  }

  // Unlink the node from the linked list
  prev->next = temp->next;

  // Free the memory of the node to be deleted
  delete temp;

  // If the node with the value was not found
  if (temp == nullptr) return;
}

int main() {
  Node* head;
  Node* first;
  Node* second;
  Node* third;

  first = new Node();
  second = new Node();
  third = new Node();

  first->data = 'y';
  second->data = 'e';
  third->data = 's';

  first->next = second;
  second->next = third;
  third->next = NULL;

  head = first;

  cout << "Original Linked List: ";
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";

  // Delete the node
  deleteNode(first, 'e');

  cout << "Linked List after deleting 'e': ";
  head = first;
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}