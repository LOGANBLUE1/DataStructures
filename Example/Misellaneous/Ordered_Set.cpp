#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

class Solution {
    template <class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                             tree_order_statistics_node_update>;
    int getStrictlySmaller(ordered_set<pair<int,int>>&os, int key){
        return os.order_of_key({key, 0});
    }
    int getStrictlyLarger(ordered_set<pair<int,int>>&os, int key){
        return os.size() - os.order_of_key({key+1, 0});
    }
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set<pair<int,int>> os;
        long long inv_count = 0;
        long long ans = LLONG_MAX;

        // first window [0..k-1]
        for (int i = 0; i < k; i++) {
            int in = nums[i];
            // count elements strictly greater than in
            int greater = getStrictlyLarger(os, in);
            inv_count += greater;
            os.insert({in, i});
            if (i >= k - 1) {
                ans = min(ans, inv_count);
            }
        }

        // slide window
        for (int i = k; i < n; i++) {
            int in = nums[i];
            int out = nums[i - k];
            
            int smaller = getStrictlySmaller(os, out);
            os.erase({out, i - k});

            // add contribution of 'in'
            int greater = getStrictlyLarger(os, in);
            os.insert({in, i});

            inv_count += (long long)greater - (long long)smaller;
            ans = min(ans, inv_count);
        }

        return ans;
    }
};