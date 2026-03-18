class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                brackets.push(s[i]);
            }
            else {
                if(brackets.empty()) return false;

                char ch = brackets.top();
                brackets.pop();

                if((s[i] == ')' && ch == '(') ||
                   (s[i] == '}' && ch == '{') ||
                   (s[i] == ']' && ch == '[')) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }

        return brackets.empty(); 
    }
};