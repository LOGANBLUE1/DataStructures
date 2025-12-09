#include<bits/stdc++.h>
using namespace std;

// connected & directed
bool dfsCycle(vector<vector<int>> &adjList, int i, vector<bool> &visited, vector<bool> &dfsVis){
    if(!visited[i]){
        visited[i] = true;
        dfsVis[i] = true;
        for(auto nbr: adjList[i]){
            if(!visited[nbr]){
                if(dfsCycle(adjList, nbr, visited, dfsVis)){
                    return true;
                }
            }else if(dfsVis[nbr]){
                return true;
            }
        }
    }
    dfsVis[i] = false;
    return false;
}

// disconnected & directed
bool detectCycle(int n, vector<vector<int>> &adj){
    vector<bool> visited(n, 0), dfsVis(n, 0);
    for(int i=0;i<n;i++){
        if(dfsCycle(adj, i, visited, dfsVis))  return true;
    }
    return false;
}

void convertToAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>>adj(n);
    for(auto task : edges){
        adj[task[1]].push_back(task[0]);
    }
}

int main(){
    int n;
    vector<vector<int>> adjList = {{1, 2}, {2}, {0, 3}, {3}};
    vector<bool> visited(n, false);
    vector<bool> dfsVis(n, false);
    return 0;
}
