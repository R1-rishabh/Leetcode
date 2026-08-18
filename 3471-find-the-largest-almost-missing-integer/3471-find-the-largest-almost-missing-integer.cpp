class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> occ;
        for (int i = 0; i < n; i++) occ[nums[i]].push_back(i);

        auto totalCount = [&](int x) {
            vector<int>& idx = occ[x];
            int total = 0, curL = -1, curR = -1;
            for (int i : idx) {
                int L = max(0, i - k + 1);
                int R = min(i, n - k);
                if (curL == -1) {
                    curL = L; curR = R;
                } else if (L <= curR) {
                    curR = max(curR, R);
                } else {
                    total += curR - curL + 1;
                    curL = L; curR = R;
                }
            }
            total += curR - curL + 1;
            return total;
        };

        int ans = -1;

        if (k == 1 || k == n) {
            for (int i = 0; i < n; i++) {
                if (totalCount(nums[i]) == 1) ans = max(ans, nums[i]);
            }
        } else {
            if (totalCount(nums[0]) == 1) ans = max(ans, nums[0]);
            if (totalCount(nums[n - 1]) == 1) ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};