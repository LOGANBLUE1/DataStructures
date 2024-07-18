#include<bits/stdc++.h>
using namespace std;

class Solution {

    int solve(int ind, int amount,vector<int>& coins, vector<vector<int>> &dp){
        if(ind >= coins.size()){
            if(!amount)
                return 0;
            else 
                return 1e9;
        }

        if(dp[ind][amount] != -1)
            return dp[ind][amount];

        int take = INT_MAX;
        if(coins[ind] <= amount)
            take = 1 + solve(ind, amount-coins[ind], coins, dp);

        int not_take = solve(ind+1, amount, coins, dp);
        
        return dp[ind][amount] = min(take, not_take);
    }
    
    // int solveTab(vector<int>& coins, int &amount){
    //     int n = coins.size();
    //     vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
    //     for(int i=0;i<n+1;i++){
    //         dp[i][0] = 0;
    //     }
        
        


    // }






    int solveTab(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;

        int mini = INT_MAX;
        for(int a=1;a<=amount;a++){
            for(int i=0;i<coins.size();i++){
                if(a-coins[i] >= 0 && dp[a-coins[i]] != INT_MAX){
                    dp[a] = min(dp[a], dp[a-coins[i]]+1);
                }
            }
        }
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(0, amount, coins, dp);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int>a;
    string s = "aabaabaaa";
    vector<int>ans;
    ans.push_back(0);
    int cnt = 0;
    for(int i=0,j=1;i<=j&&j<s.size();j++){
        if(s[j] == s[i])
            ans.push_back(++cnt);
    }
    // int x = 0;
    // while(cin>>x)
    //     a.push_back(x);
    // int amount;
    // cin>>amount;
    // cout<<sol.coinChange(a, amount)<<endl;
    return 0;
}