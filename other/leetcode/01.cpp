# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> M;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (M.count(target-nums[i])) {
                ret.push_back(M[target-nums[i]]);
                ret.push_back(i+1);
                return ret;
            }
            M[ nums[i] ] = i+1;
        }
    }
};
