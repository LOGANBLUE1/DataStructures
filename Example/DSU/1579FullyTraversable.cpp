class UF {
    vector<int> rep, compSize;
    int comp;
    
public:
    UF(int n) {
        this->comp = n;
        for (int i = 0; i <= n; i++) {
            rep.push_back(i);
            compSize.push_back(1);
        }
    }
    
    int findrep(int x) {
        if (rep[x] == x) {
            return x;
        }
        return rep[x] = findrep(rep[x]);
    }
    
    bool performUnion(int x, int y) {       
        x = findrep(x); 
        y = findrep(y);
        
        if (x == y) {
            return 0;
        }
        
        if (compSize[x] > compSize[y]) {
            compSize[x] += compSize[y];
            rep[y] = x;
        } else {
            compSize[y] += compSize[x];
            rep[x] = y;
        }
        
        comp--;
        return 1;
    }

    bool isConnected() {
        return comp == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UF Alice(n), Bob(n);

        int edgesRequired = 0;
        for (vector<int>& edge : edges) {//first bidereactional
            if (edge[0] == 3) {
                edgesRequired += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2]));
            }
        }

        for (vector<int>& edge : edges) {//then others
            if (edge[0] == 1) {
                edgesRequired += Alice.performUnion(edge[1], edge[2]);
            } else if (edge[0] == 2) {
                edgesRequired += Bob.performUnion(edge[1], edge[2]);
            }
        }

        if (Alice.isConnected() && Bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};