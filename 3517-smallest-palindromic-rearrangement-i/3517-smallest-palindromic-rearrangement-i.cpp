class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> hashh(26, 0);

        for (char ch : s)
            hashh[ch - 'a']++;

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            left += string(hashh[i] / 2, char(i + 'a'));

            if (hashh[i] % 2 == 1)
                mid = char(i + 'a');
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};