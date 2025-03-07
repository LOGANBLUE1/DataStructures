#include<bits/stdc++.h>
using namespace std;
vector<int> solve(string word){
    word.push_back('$');
    int n = word.size();
    vector<int>ans;
    int curr =1;
    for(int i=1;i<n;i++){
        if(word[i]==word[i-1])
            curr++;
        else{
            ans.push_back(curr);
            curr =1;
        }
    }
    return ans;
}

int main()
{
    for(auto x:solve("aaabbbcc"))
        cout<<x<<" ";cout<<endl;
    return 0;
}