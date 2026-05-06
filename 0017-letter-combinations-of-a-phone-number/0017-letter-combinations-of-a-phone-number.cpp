class Solution {
public:
    
    void generate(int index, string digits, string &current, 
                  vector<string> &ans, vector<string> &mapping) {
        
        if(index == digits.length()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for(char ch : letters) {
            current.push_back(ch);
            generate(index + 1, digits, current, ans, mapping);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string current;

        generate(0, digits, current, ans, mapping);

        return ans;
    }
};