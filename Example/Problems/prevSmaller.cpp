#include <bits/stdc++.h>
using namespace std;
    
    vector<int> nextSmaller(vector<int>&h, const int& n){
        stack<int>s;
        vector<int>ans(n,n);

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            } 
            if(!s.empty())
                ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }


    vector<int> prevSmaller(vector<int>&h, const int& n){
        stack<int>s;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && h[s.top()] > h[i]){
                s.pop();
            } 
            if(!s.empty())
                ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }


    vector<int> nextGreater(vector<int>&h, const int& n){
        stack<int> st1;

        vector<int> nge(n, n);
        for (int i = n - 1; i >= 0; i--){
                while (!st1.empty() and h[st1.top()] <= h[i])
                    st1.pop();
                if (!st1.empty())
                    nge[i] = st1.top();
                st1.push(i);
            } // O(n)
        return nge;
    }


    vector<int> prevGreater(vector<int>&h, const int& n){

        stack<int>st2;
        vector<int> pge(n, -1);
        
        for (int i = 0; i < n; i++){
            while (!st2.empty() and h[st2.top()] < h[i])
                st2.pop();
            if (!st2.empty())
                pge[i] = st2.top();
            st2.push(i);
        } // O(n)
        return pge;
    }
            
            