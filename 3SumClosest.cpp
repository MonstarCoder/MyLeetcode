//脑袋不清醒
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return -1;
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for (auto i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int l = i + 1, r = n - 1;
            while ( l < r ) {
                int cur = nums[i] + nums[l] + nums[r];
                if (cur == target) return cur;
                ret = abs(ret - target) <= abs(cur - target) ? ret : cur;
                if (cur < target) ++l;
                if (cur > target) --r;
            }
        }
        return ret;
    }
};
