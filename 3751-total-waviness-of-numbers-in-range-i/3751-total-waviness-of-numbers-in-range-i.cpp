int calculateWaviness(int num) {
    string s = to_string(num);

    int n = s.size();

    int waviness = 0;

    for(int i=1;i<n-1;i++) {
        if(s[i]-'0'>s[i-1]-'0' && s[i]-'0'>s[i+1]-'0') {
            waviness++;
        }
        else if(s[i]-'0'<s[i-1]-'0' && s[i]-'0'<s[i+1]-'0') {
            waviness++;
        }
    }

    return waviness;
}



class Solution {
public:
    int totalWaviness(int num1, int num2) {
        
        int totalWaviness = 0;

        for(int i=num1;i<=num2;i++) {
            totalWaviness += calculateWaviness(i);
        }

    return totalWaviness;
    }
};