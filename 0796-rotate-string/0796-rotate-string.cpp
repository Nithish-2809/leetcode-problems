class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;

         string combined = s+s;

        if(combined.find(goal)!=-1) return true;

        return false;
    }
};