class Solution {
public:
    long long sumAndMultiply(int n) {
        
        string num = "";
        string res = to_string(n);
        int k = res.length();

        for(int i=0;i<k;i++) {
            if(res[i]!='0') num += res[i];
        }

        if(num=="") return 0;

        int sum = 0;
        int x = stoll(num);
        int temp = x;

        while(temp!=0) {
            int ld = temp%10;
            sum += ld;
            temp /= 10;
        }

    return 1LL*x*sum;
    }
};