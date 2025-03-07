const int MAX = 1e4;
const int INF = 1e9 + 7;
vector<bool> is_prime(MAX, true);
class Solution {
public:
    
    vector<int> neighbours(int n){
        vector<int> res;
        for(int base = 1; base <= n; base *= 10){
            int d = (n / base) % 10;
            if(d > 0)
                res.push_back(n - base);
            if(d < 9)
                res.push_back(n + base);
        }
        return res;
    }

    int minOperations(int n, int m) {
        vector<int> dist(MAX, INF);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        dist[n] = 0;
        pq.push({dist[n], n});
        
        while(!pq.empty()){
            auto [dis, u] = pq.top();     pq.pop();
            
            if(dis > dist[u]){
                continue;
            }
            
            for(int v: neighbours(u)){
                if(is_prime[v]){
                    continue;
                }
                if(dist[v] > dist[u] + u){
                    dist[v] = dist[u] + u;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if(dist[m] == INF){
            return -1;
        }
        
        return m + dist[m];
    }
};