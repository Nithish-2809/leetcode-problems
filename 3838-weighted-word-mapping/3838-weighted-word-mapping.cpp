class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        int n = words.size();
        unordered_map<int,char>charMap;
        charMap[0] = 'z';
        charMap[1] = 'y';
        charMap[2] = 'x';
        charMap[3] = 'w';
        charMap[4] = 'v';
        charMap[5] = 'u';
        charMap[6] = 't';
        charMap[7] = 's';
        charMap[8] = 'r';
        charMap[9] = 'q';
        charMap[10] = 'p';
        charMap[11] = 'o';
        charMap[12] = 'n';
        charMap[13] = 'm';
        charMap[14] = 'l';
        charMap[15] = 'k';
        charMap[16] = 'j';
        charMap[17] = 'i';
        charMap[18] = 'h';
        charMap[19] = 'g';
        charMap[20] = 'f';
        charMap[21] = 'e';
        charMap[22] = 'd';
        charMap[23] = 'c';
        charMap[24] = 'b';
        charMap[25] = 'a';
        

        for(int s=0;s<n;s++) {
            int sum = 0;
            for(int i = 0; i < words[s].length(); i++) {
                sum += weights[words[s][i] - 'a'];
            }

            sum = sum%26;

            ans +=charMap[sum];
        }

        return ans;
    }
};