
    
    
    int sumOfMax(vector<int>&arr){
        stack<int> st1, st2;
        vector<int> nge(n, n);
        vector<int> pge(n, -1);
        for (int i = n - 1; i >= 0; i--){
            
            while (!st1.empty() and arr[st1.top()] <= arr[i])
                st1.pop();
            if (!st1.empty())
                nge[i] = st1.top();
            st1.push(i);
        } // O(n)
        for (int i = 0; i < n; i++){
            
            while (!st2.empty() and arr[st2.top()] < arr[i])
                st2.pop();
            if (!st2.empty())
                pge[i] = st2.top();
            st2.push(i);
        } // O(n)


        int ans = 0;
        for (int i = 0; i < n; i++){
            // maximum contribution
            int left = (i - pge[i]), right = (nge[i] - i);
            ans += arr[i] * left * right;
        } // O(n)
        return ans;
    }