#include<bits/stdc++.h>
using namespace std;

bool cycleDetectionDFS(vector<vector<int>> &adjList, int i, vector<bool> &visited, vector<bool> &dfsVis){
    if(!visited[i]){
        visited[i] = true;
        dfsVis[i] = true;
        for(auto nbr: adjList[i]){
            if(!visited[nbr]){
                if(cycleDetectionDFS(adjList, nbr, visited, dfsVis)){
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

int main(){
    int n;
    vector<vector<int>> adjList = {{1, 2}, {2}, {0, 3}, {3}};
    vector<bool> visited(n, false);
    vector<bool> dfsVis(n, false);
    return 0;
}
