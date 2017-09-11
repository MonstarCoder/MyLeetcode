class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto const size_n = nums.size();
        vector<string> ranges;
        if (size_n == 0) return ranges;
        for (auto i = 0, j = 0; i < size_n; i = j) {
            while (j < size_n && nums[j + 1] == nums[j] + 1) ++j;
                ranges.push_back(j > i ? (to_string(nums[i]) + "->" + to_string(nums[j])) : to_string(nums[i]));
            ++j;
        }
        return ranges;
    }
};

 /*
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto const size_n = nums.size();
        vector<string> ranges;
        if (size_n == 0) return ranges;
        for (auto i = 0, j = 0; i < size_n; i = j) {
            while (j < size_n && nums[j + 1] == nums[j] + 1) ++j;
            if (j > i) 
                ranges.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            else 
                ranges.push_back(to_string(nums[i]));
            ++j;
        }
        return ranges;
    }
};
*/
