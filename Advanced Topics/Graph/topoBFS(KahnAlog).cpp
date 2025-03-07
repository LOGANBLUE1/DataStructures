#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topoSortBFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    for(auto adj: graph){
        for(auto nbr: adj){
            inDegree[nbr]++;
        }
    }

    vector<int> result;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        // Reduce in-degree of adjacent nodes
        for (int neighbor : graph[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != n) {
        result.clear(); // Clear the result vector
    }

    return result;
}

int main() {
    int n;

    vector<vector<int>> graph(n);
    
    vector<int> sortedOrder = topoSortBFS(graph);

    if (sortedOrder.empty()) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "Topological order: ";
        for (int node : sortedOrder) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}