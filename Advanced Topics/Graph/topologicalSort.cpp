#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, result);
        }
    }

    result.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, result);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    vector<vector<int>> graph(n);

    vector<int> sortedNodes = topologicalSort(graph, n);

    cout << "Topological order: ";
    for (int node : sortedNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}