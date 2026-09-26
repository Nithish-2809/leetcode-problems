int calculateWaviness(int n) {

    string num = to_string(n);
    int waviness = 0;

    int k = num.length();

    for(int i=1;i<k-1;i++) {
        if((num[i-1]-'0'>num[i]-'0' && num[i+1]-'0'>num[i]-'0') ||
            (num[i-1]-'0'<num[i]-'0' && num[i+1]-'0'<num[i]-'0')) {
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
            int currWaviness = calculateWaviness(i);
            totalWaviness += currWaviness;
        }

    return totalWaviness;
    }
};