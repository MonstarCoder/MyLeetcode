class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> ret(r, vector<int>(c, 0));
        int m = nums.size(), n = nums[0].size();
        int s = m * n;
        if (s != r * c)
            return nums;
        for (int i = 0; i < s; ++i)
            ret[i / c][i % c] = nums[i / n][i % n];
        return ret;
    }
};

