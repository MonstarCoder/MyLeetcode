//time limit exceeded!
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size();
        for (auto i = 0; i < n -1; ++i)
            for (auto j = 1; j < n; ++j) {
                int newArea = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                area = newArea > area ? newArea : area;
            }
        return area;
    }
};
*/

//改进,击败0.9% =_=
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size();
        for (auto i = 0; i < n -1; ++i) {
            for (auto j = n - 1; j > 0;) {
                int newArea = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                area = newArea > area ? newArea : area;
                if (height[j] >= height[i]) break;
                else --j;
            }
            if (height[i + 1] <= height[i]) continue;
        }
        return area;
    }
};
*/

//参考讨论
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int i = 0, j = height.size() - 1;
	while (i < j) {
	    int h = min(height[i], height[j]);
	    area = max(area, (j - i) * h);
	    while (height[i] <= h && i < j) ++i;
	    while (height[j] <= h && i < j) --j;
	}
        return area;
    }
};
