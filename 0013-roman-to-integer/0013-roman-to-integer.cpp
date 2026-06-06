int getNumber(char c) {
    if(c=='I') return 1;
    if(c=='V') return 5;
    if(c=='X') return 10;
    if(c=='L') return 50;
    if(c=='C') return 100;
    if(c=='D') return 500;
    return 1000;
}






class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int sum = 0;
        int num = getNumber(s[0]);

        sum += num;

        for(int i=1;i<n;i++) {
            
            int num = getNumber(s[i]);

            if(num>getNumber(s[i-1])) {
                sum += abs(getNumber(s[i-1])-num);
                sum -= getNumber(s[i-1]);
            }
            else {
                sum += num;
            }
        }

        return sum;
    }
};