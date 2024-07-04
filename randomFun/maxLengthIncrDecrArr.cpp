#include<bits/stdc++.h>
using namespace std;
    int maxLEngth(vector<int>& nums) {
        int dir = 0;
        int len = 1, maxlen = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                if(dir == 1)
                len++;
                else{
                    len = 2;
                    dir = 1;
                }
            }
            else if(nums[i] < nums[i-1]){
                if(dir == 1){
                    len = 2;
                    dir = -1;
                }
                else
                    len++;
            }
            else{
                len = 1;
                dir = 0;
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }

int main(){
    
}
