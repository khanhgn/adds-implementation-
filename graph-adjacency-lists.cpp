#include <iostream>
#include <vector>
using namespace std;

// Add the edge where a is where the edge came from and b is the destination
void addEdge(vector<int> adj[], int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
}

// Delete the edge
void deleteEdge(vector<int> adj[], int a, int b) {
  // Find and remove 'b' from the adjacency list of 'a'
  auto itA = find(adj[a].begin(), adj[a].end(), b);
  if (itA != adj[a].end()) {
    adj[a].erase(itA);
  }

  // Find and remove 'a' from the adjacency list of 'b'
  auto itB = find(adj[b].begin(), adj[b].end(), a);
  if (itB != adj[b].end()) {
    adj[b].erase(itB);
  }
}

// Draw the graph
void drawGraph(vector<int> adj[], int numVertices) {
  for (int a = 0; a < numVertices; ++a) {
    char vertexLabel = 'A' + a;  // Convert index to character
    cout << "\n " << vertexLabel;
    for (auto x : adj[a]) {
      char neighborLabel = 'A' + x;  // Convert index to character
      cout << " to " << neighborLabel;
    }
    printf("\n");
  }
}

int main() {
  int numVertices = 5;
  vector<int> adj[numVertices];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  addEdge(adj, 4, 3);
  cout << "initial graph: \n";
  drawGraph(adj, numVertices);
  cout << "final deleted graph: \n";
  deleteEdge(adj, 0, 1);
  drawGraph(adj, numVertices);

  return 0;
}
