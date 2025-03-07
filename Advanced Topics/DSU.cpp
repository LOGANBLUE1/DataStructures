#include<bits/stdc++.h>
using namespace std;


class DSU {
    vector<int> rep, compSize;
    int comp;
    
public:
    DSU(int n) {
        this->comp = n;
        for (int i = 0; i <= n; i++) {
            rep.push_back(i);
            compSize.push_back(1);
        }
    }
    
    int findParent(int x) {
        if (rep[x] == x) {
            return x;
        }
        return rep[x] = findParent(rep[x]);
    }
    
    bool performUnion(int x, int y) {       
        x = findParent(x); 
        y = findParent(y);
        
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


class UnionFind{
public:
    int n, m;   
    vector < vector <int> > size;
    vector <vector <pair <int, int> > > parent;
    vector < vector <bool> > cross;
    int compCount;
    
    UnionFind(int n, int m) {
        this->n = n;
        this->m = m;
        size.assign(n, vector <int> (m, 1));
        cross.assign(n, vector <bool> (m, true));
        parent.assign(n, vector <pair <int, int> > (m, {-1, -1}));
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) parent[i][j]={i,j};
        compCount = n*m;
    }

    pair <int, int> find(pair <int, int> p) {
        pair <int, int> root = p;
        while (root != parent[root.first][root.second]) {
            root =  parent[root.first][root.second];
        }
        // Armortized Algorithm
        while (p != root) {
            pair <int, int> next = parent[p.first][p.second];
            parent[p.first][p.second] = root;
            p = next;
        }
        return root;
    }

    bool isConnected(pair <int, int> p, pair <int, int> q) {
        return find(p) == find(q);
    }

    int componentsize(pair <int, int> p) {
        pair <int, int> temp = find(p);
        return size[temp.first][temp.second];
    }

    int commponents() {
        return compCount;
    }

    void unify(pair <int, int> p, pair <int, int> q) {
        pair <int, int> root1 = find(p);
        pair <int, int> root2 = find(q);
        if (root1 == root2) return;
        if (size[root1.first][root1.second] > size[root2.first][root2.second]) {
            size[root1.first][root1.second] += size[root2.first][root2.second];
            parent[root2.first][root2.second] = root1;
        } else {
            size[root2.first][root2.second] += size[root1.first][root2.second];
            parent[root1.first][root1.second] = root2;
        }

        compCount--;
    }
};


int main()
{
    int n;
    DSU dsu(n);
    return 0;
}