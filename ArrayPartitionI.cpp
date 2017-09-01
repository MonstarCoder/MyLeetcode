#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ret = 0;
        bool flag = true;
	vector<int> buckets(20001, 0);	
        for (const auto n : nums) {
            ++buckets[10000 + n];
        }
        for (auto i = 0; i < 20001;) {
            if (buckets[i] > 0) {
                if (flag) {
                     ret += (i - 10000);
                     --buckets[i];
                     flag = false;
                } else {
                     --buckets[i];
                     flag = true;
                }
            } else
               ++i;
        }
        return ret;
    }
};

int main() {
    vector<int> test = {1, 2, 3, 4};
    Solution s;
    cout << s.arrayPairSum(test) << endl;
    return 0;
}
