class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> suf(n + 1, 0);
        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;
        int i = 0;
        j = 0;

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                i++;
                j++;
            } else {
                int need = m - j - 1;

                if (suf[i + 1] >= need) {
                    ans.push_back(i);
                    i++;
                    j++;

                    while (i < n && j < m) {
                        if (word1[i] == word2[j]) {
                            ans.push_back(i);
                            j++;
                        }
                        i++;
                    }
                    break;
                }

                i++;
            }
        }

        return j == m ? ans : vector<int>{};
    }
};