int sumOfdigits(int n) {
    int sum = 0;
    while(n!=0) {
        int ld = n%10;
        sum += ld;
        n /= 10;
    }

    return sum;
}

int productOfDigits(int n) {
    int product = 1;

    while(n!=0) {
        int ld = n%10;
        product *= ld;
        n = n/10;
    }

    return product;
}


class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = sumOfdigits(n);
        int product = productOfDigits(n);

        return n%(sum+product)==0;
    }
};