class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long rev = 0;
        if(x<0) return false;

        while(temp!=0) {
            int ld = temp%10;
            rev = rev*10 +ld;
            temp /= 10;
        }

        return x==rev;
    }
};