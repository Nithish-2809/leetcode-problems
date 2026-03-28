class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length()!=goal.length()) return false;

        string combined = s+s;
        bool flag = false;

        if(combined.find(goal)!=-1) {
            flag = true;
        }
       
       return flag;
    }
};