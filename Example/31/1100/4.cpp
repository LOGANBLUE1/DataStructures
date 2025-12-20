int getSum(vector<int>& nums) {
    int currSum = 0, maxSum = INT_MIN, parity = -1;
    for(auto it: nums){
        if(parity == -1 || parity^(it&1))
            currSum += it;
        else 
            currSum = it;
        parity = it&1;

        if(currSum > maxSum){
            maxSum = currSum;
        }
        if(currSum < 0){
            currSum = 0;
            parity = -1;
        }
    }
    return maxSum;
}
void solve(){
    int n;
    cin>>n;
    vi a(n);
    input(a);
    int s = getSum(a);
    cout<<s<<endl;
}