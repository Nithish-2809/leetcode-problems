class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;
        long long sum = 0;

        while(n!=0) {
            int ld = n%10;
            sum += ld;
            if(ld!=0) {
                res = res*10 + ld;
            }

            n = n/10;
        }

        long long ans = 0;
        while(res!=0) {
            int ld = res%10;
            ans = ans*10 + ld;
            res /=10;
        }


    return ans*sum;

    }
};