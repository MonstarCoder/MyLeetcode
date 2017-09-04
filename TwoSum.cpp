/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum(2, 0);
        for (auto i = 0; i != (nums.size() - 1); ++i)
            for (auto j = i + 1; j != nums.size(); ++j)
                if (nums[i] + nums[j] == target)
                    sum = {i, j};
        return sum;
    }
};
*/

class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target)
{
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end()) {
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}
        
		hash[numbers[i]] = i;
	}
	return result;
}
};
