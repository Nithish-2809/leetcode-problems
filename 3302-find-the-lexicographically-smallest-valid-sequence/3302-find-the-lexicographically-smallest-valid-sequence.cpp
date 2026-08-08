class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> rightSideMatch(n + 1, 0);

        int j = m - 1;
        int matchedCharacters = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                matchedCharacters++;
                j--;
            }

            rightSideMatch[i] = matchedCharacters;
        }
        vector<int> ans;
        bool powerUsed = false;

        int i = 0;
        j = 0;

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                i++;
                j++;
            } else if (!powerUsed && rightSideMatch[i + 1] >= (m - j - 1)) {
                powerUsed = true;
                ans.push_back(i);
                i++;
                j++;
            } else {
                i++;
            }
        }

        return (j == m) ? ans : vector<int>{};
    }
};