class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;
        auto const size_n = timeSeries.size();
        if (size_n == 0) return ret;
        for (auto i = 1; i < size_n; ++i ) {
            int dur = timeSeries[i] - timeSeries[i - 1];
            if (dur >= duration)
                ret += duration;
            else
                ret += dur;
        }
        ret += duration;
        return ret;
    }
};
