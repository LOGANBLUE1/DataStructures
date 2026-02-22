// HLD / Heavy Light Decomposition
class Solution {
public:
    int n, cur_pos;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavyChild, topParentOfChain;
    vector<int> pos, seg, value;

    // Segment Tree
    int querySeg(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return seg[node];
        int mid = (start + end) / 2;
        return querySeg(2*node, start, mid, l, r)
             ^ querySeg(2*node+1, mid+1, end, l, r);
    }

    void updateSeg(int node, int start, int end, int idx, int val) {
        if (start == end) {
            seg[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            updateSeg(2*node, start, mid, idx, val);
        else
            updateSeg(2*node+1, mid+1, end, idx, val);
        seg[node] = seg[2*node] ^ seg[2*node+1];
    }

    int dfs(int u, int p) {
        int size = 1, maxSize = 0;
        for (int v : adj[u]) {
            if (v != p) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                int childSize = dfs(v, u);
                if (childSize > maxSize) {
                    maxSize = childSize;
                    heavyChild[u] = v;
                }
                size += childSize;
            }
        }
        return size;
    }

    void decompose(int u, int h) {
        topParentOfChain[u] = h;
        pos[u] = cur_pos++;
        updateSeg(1, 0, n-1, pos[u], value[u]);

        if (heavyChild[u] != -1)
            decompose(heavyChild[u], h);

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavyChild[u])
                decompose(v, v);
        }
    }

    int queryPath(int u, int v) {
        int res = 0;
        while (topParentOfChain[u] != topParentOfChain[v]) {
            if (depth[topParentOfChain[u]] < depth[topParentOfChain[v]])
                swap(u, v);
            res ^= querySeg(1, 0, n-1, pos[topParentOfChain[u]], pos[u]);
            u = parent[topParentOfChain[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res ^= querySeg(1, 0, n-1, pos[u], pos[v]);
        return res;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavyChild.assign(n, -1);
        topParentOfChain.assign(n, 0);
        pos.assign(n, 0);
        value.assign(n, 0);
        seg.assign(4*n, 0);
        cur_pos = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
            value[i] = 1 << (s[i] - 'a');

        dfs(0, -1);
        decompose(0, 0);

        vector<bool> ans;

        for (auto &q : queries) {
            string type, a, b;
            stringstream ss(q);
            ss >> type >> a >> b;

            if (type == "query") {
                int u = stoi(a);
                int v = stoi(b);
                int mask = queryPath(u, v);
                ans.push_back(__builtin_popcount(mask) <= 1);
            } else {
                int idx = stoi(a);
                s[idx] = b[0];
                int newMask = 1 << (s[idx] - 'a');
                updateSeg(1, 0, n-1, pos[idx], newMask);
            }
        }

        return ans;
    }
};