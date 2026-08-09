class Solution {
public:
    int n;
    vector<int> suffixSum;
    vector<vector<int>> memo;
    
    int dp(int i, int m, vector<int>& piles) {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffixSum[i];
        if (memo[i][m] != -1) return memo[i][m];
        
        int best = 0;
        for (int x = 1; x <= 2 * m; x++) {
            best = max(best, suffixSum[i] - dp(i + x, max(m, x), piles));
        }
        
        memo[i][m] = best;
        return best;
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        memo.assign(n, vector<int>(n + 1, -1));
        
        return dp(0, 1, piles);
    }
};