//first hard
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        double ret = 0.0;
        if (m + n == 0) return ret;
        int i = 0, j = 0;
        int mid = ceil(double(m + n) / 2);
        while (i < m && j < n && (i + j) < mid )
            ret = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        while (i < m && (i + j) < mid )
            ret = nums1[i++];
        while (j < n && (i + j) < mid)
            ret = nums2[j++];
        if (((m + n) & 0x1) == 0) {
            double rett = 0.0;
            while (i < m && j < n && (i + j - 1) < mid )
                rett = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
            while (i < m && (i + j - 1) < mid)
                rett = nums1[i++];
            while (j < n && (i + j - 1) < mid)
                rett = nums2[j++];
            ret = (ret + rett) / 2;
        }
        return ret;
    }
};
