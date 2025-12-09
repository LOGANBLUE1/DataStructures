#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<pair<int,int>>> &adj) {
    int n = adj.size();
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto &[nbr, _] : adj[i])
            ++indeg[nbr];
    }

    vector<int> ts;
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indeg[i]==0) q.push(i);
        
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ts.push_back(u);
        for (auto [v,_] : adj[u])
            if (--indeg[v] == 0) q.push(v);
    }
    return ts;
}

int main() {
    int n;

    vector<vector<int>> graph(n);
    
    vector<int> sortedOrder = topologicalSort(graph);

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