class Solution {
public:
    bool sumGame(string num) {
        int leftHalfSum = 0;
        int rightHalfSum = 0;
        int n = num.length();
        int leftHalfQuestionMarks = 0;
        int rightHalfQuestionMarks = 0;

        for(int i=0;i<n;i++) {
            if(num[i]=='?') {
                if(i<n/2) {
                    leftHalfQuestionMarks++;
                }
                else {
                    rightHalfQuestionMarks++;
                }
            }
            else {
                if(i<n/2) {
                    leftHalfSum += num[i]-'0';
                }
                else {
                    rightHalfSum += num[i]-'0';
                }
            }
        }

        int totalQuestionMarks = rightHalfQuestionMarks + leftHalfQuestionMarks;

        if(totalQuestionMarks%2==1) return true;

        int RIGHT = 2*rightHalfSum+9*rightHalfQuestionMarks;
        int LEFT = 2*leftHalfSum+9*leftHalfQuestionMarks;

        return RIGHT!=LEFT;
    }
};