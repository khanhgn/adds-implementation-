#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
 public:
  Node* head;

  // initialize empty linked list
  LinkedList() : head(nullptr) {}

  void addNode(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  void deleteNode(int value) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == value) {
      head = temp->next;
      delete temp;
      return;
    }

    // search for node to be deleted, keeping track of previous node
    while (temp != nullptr && temp->data != value) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == nullptr) return;

    // unlink the node from linked list
    prev->next = temp->next;
    delete temp;
  }
};

class Graph {
 private:
  int numVertices;
  LinkedList* adjListArray;

 public:
  // initialize graph with a given number of vertices
  Graph(int vertices) : numVertices(vertices) {
    adjListArray = new LinkedList[numVertices];
  }

  // add an edge between two vertices in the graph
  void addEdge(int src, int dest) {
    adjListArray[src].addNode(dest);
    adjListArray[dest].addNode(src);
  }

  // delete an edge between two vertices in the graph
  void deleteEdge(int src, int dest) {
    adjListArray[src].deleteNode(dest);
    adjListArray[dest].deleteNode(src);
  }

  // print adjacency list representation of graph
  void drawGraph() {
    for (int v = 1; v < numVertices; ++v) {
      cout << "\n " << v;

      Node* current = adjListArray[v].head;
      while (current != nullptr) {
        cout << " to " << current->data;
        current = current->next;
      }

      cout << endl;
    }
  }
};

int main() {
  Graph graph(5);

  graph.addEdge(1, 5);
  graph.addEdge(1, 3);
  graph.addEdge(2, 4);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);

  cout << "Initial Graph:\n";
  graph.drawGraph();

  cout << "\nDeleting edge between 0 and 1:\n";
  graph.deleteEdge(3, 4);
  graph.drawGraph();

  return 0;
}
