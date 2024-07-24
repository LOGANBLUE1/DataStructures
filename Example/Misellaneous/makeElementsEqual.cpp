class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long res = 0;
        int incr = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - target[i];

            if (diff > 0 && incr < 0 || diff < 0 && incr > 0) {
                res += abs(diff);
            }
            else if (abs(diff) - abs(incr) > 0) {
                res += abs(diff - incr);
            }

            incr = diff;
        }

        return res;
    }
};// choose i,j increase or decrease all the elements in subarray by 1